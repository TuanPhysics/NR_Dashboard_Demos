#include <Arduino.h>

#include "secrets/wifi.h"
#include "wifi_connect.h"
#include <WiFiClientSecure.h>

#include "ca_cert_emqx.h"
#include "secrets/mqtt.h"
#include <PubSubClient.h>
#include "MQTT.h"

#include <Ticker.h>

#include <DHT.h>
#define DHT22PIN 13U
#define LED_PIN 15U

namespace
{
    const char *ssid = WiFiSecrets::ssid;
    const char *password = WiFiSecrets::pass;
    const char *client_id = (String("esp32-client") + WiFi.macAddress()).c_str();

    DHT dht(DHT22PIN, DHT22);
    WiFiClientSecure tlsClient;
    PubSubClient mqttClient(tlsClient);

    Ticker dhtTicker; // 2 seconds interval for DHT22 reading then publising MQTT topics
    const char *temperature_topic = "home/temperature";
    const char *humidity_topic = "home/humidity";

    const char *LED_brightness_topic = "home/LED_brightness"; // ten-level brightness control received from MQTT
}

void dhtReadPublish()
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C, Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    mqttClient.publish(temperature_topic, String(temperature).c_str(), false);
    mqttClient.publish(humidity_topic, String(humidity).c_str(), false);
}

void mqttCallback(char *topic, uint8_t *payload, unsigned int length)
{
    if (strcmp(topic, LED_brightness_topic) == 0)
    {
        char brightnessStr[length + 1];
        memcpy(brightnessStr, payload, length);
        brightnessStr[length] = '\0';
        int brightness = atoi(brightnessStr);

        Serial.print("LED brightness: ");
        Serial.println(brightness);
        analogWrite(LED_PIN, brightness * 25);
    }
}

void setup()
{
    Serial.begin(115200);
    delay(10);
    setup_wifi(ssid, password);
    tlsClient.setCACert(ca_cert);

    pinMode(LED_PIN, OUTPUT);

    mqttClient.setCallback(mqttCallback);
    mqttClient.setServer(EMQX::broker, EMQX::port);
    dhtTicker.attach(1, dhtReadPublish);
}

void loop()
{
    MQTT::reconnect(mqttClient, client_id, EMQX::username, EMQX::password, LED_brightness_topic);
    mqttClient.loop();
    delay(10);
}
