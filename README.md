# Bảng điều khiển IoT bằng Dashboard UI trong Node-RED 

Các dự án thực hành, học tập việc tạo bảng điều khiển và giám sát cho các dự án IoT bằng Dashboard UI trên Node-RED 

## Dự án 1: Đồng hồ đo và Đồ thị 

- Sử dụng Gauge node (đồng hồ đo) và Chart node (đồ thị) để hiển thị các thông số nhiệt độ và độ ẩm
- Nhiệt độ và độ ẩm được mô phỏng bằng hàm Math.random trong function nodes
- Các thao tác học tập trong dự án này:
    + Cài đặt `node-red-dash-board` Palette (một bảng các node để tạo giao diện bảng điều khiển)
    + Thiết kế một bảng điều khiển đơn giản từ thiết kế flow với các nodes
    + Các thành phần cơ bản của dashboard: Layout >> Tabs >> Groups >> Widget 
    + Một số cách tùy biến hiển thị trên dashboard ... 
- [Kho mã dự án](./TempGaugeChartUI/)

## Dự án 2: Thanh điều khiển slider 

- Dashboard ngoài chức năng hiển thị (giám sát thông số) còn có chức năng điều khiển 
- Dự án này sử dụng một thanh điều khiển (slider) để điều khiển tham số hiện lên đồ thị 
- Một số node điều khiển khác như nút bấm, bạn có thể tự khám phá 
- [Kho mã dự án](./TempGaugeChartUI/)

## Dự án 3: Giao tiếp hiển thị số liệu qua MQTT Broker 

Dự án này bao gồm hai kho mã nguồn 
1. Dashboard cho hiển thị nhiệt độ, độ ẩm, và thanh điều khiển độ sáng trên Node-RED. [Link](./DHT22_LED_Dashboard/) 
2. Mã nguồn firmware trên ESP32, kèm các file thiết lập mô phỏng Wokwi trên VS-Code. [Link](./DHT22_MQTT_LED_ESP32/)