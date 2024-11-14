## Dashboard UI trên Node-RED 

- Sử dụng các node MQTT in và out để kết nối với EMQX broker qua kết nối bảo mật TLS (nhớ thiết lập ca_cert và username password cho server của mình)
- Các node UI: gauge, chart, slider được quy hoạch thành 3 group trên một tab duy nhất
- Việc chia lưới mặc định trên Dashboard UI đảm bảo việc tự động bố trí lại các group thành cột khi xem trên màn hình điện thoại thông minh.
- Có thể truy cập bảng điều khiển qua điện thoại thông minh qua qua địa chỉ IP của máy đang chạy Node-RED. (tự tìm hiểu và làm thử)