#include <Arduino.h>

#include "secrets/wifi.h"
#include "wifi_connect.h"
#include <WiFiClientSecure.h>

#include "ca_cert_hivemq.h"
#include "secrets/mqtt.h"
#include <PubSubClient.h>
#include "MQTT.h"

#include <Ticker.h>

namespace
{
    const char *ssid = WiFiSecrets::ssid;
    const char *password = WiFiSecrets::pass;
    const char *echo_topic = "esp32/echo_test";
    unsigned int publish_count = 0;
    const char * client_id = (String("esp32-client") + WiFi.macAddress()).c_str();
}

WiFiClientSecure tlsClient;
PubSubClient mqttClient(tlsClient);

Ticker mqttPulishTicker;

void mqttPublish()
{
    Serial.print("Publishing: ");
    Serial.println(publish_count);
    mqttClient.publish(echo_topic, String(publish_count).c_str(), false);
    publish_count++;
}

void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    Serial.printf("From %s:  ", topic);
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}

void setup()
{
    Serial.begin(115200);
    delay(10);
    setup_wifi(ssid, password);
    tlsClient.setCACert(ca_cert);

    mqttClient.setCallback(mqttCallback);
    mqttClient.setServer(HiveMQ::broker, HiveMQ::port);
    mqttPulishTicker.attach(1, mqttPublish);
}

void loop()
{
    MQTT::reconnect(mqttClient, client_id, HiveMQ::username, HiveMQ::password, echo_topic);
    mqttClient.loop();
    delay(10);
}
