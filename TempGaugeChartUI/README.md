## Flow 1: Đồng hồ đo và Đồ thị 

- Sử dụng Gauge node (đồng hồ đo) và Chart node (đồ thị) để hiển thị các thông số nhiệt độ và độ ẩm
- Nhiệt độ và độ ẩm được mô phỏng bằng hàm Math.random trong function nodes
- Các thao tác học tập trong dự án này:
    + Cài đặt `node-red-dash-board` Palette (một bảng các node để tạo giao diện bảng điều khiển)
    + Thiết kế một bảng điều khiển đơn giản từ thiết kế flow với các nodes
    + Các thành phần cơ bản của dashboard: Layout >> Tabs >> Groups >> Widget 
    + Một số cách tùy biến hiển thị trên dashboard ... 

## Flow 2: Thanh điều khiển slider 

- Dashboard ngoài chức năng hiển thị (giám sát thông số) còn có chức năng điều khiển 
- Dự án này sử dụng một thanh điều khiển (slider) để điều khiển tham số hiện lên đồ thị và đồng hồ đo trong cùng một Group
- Một số node điều khiển khác như nút bấm, bạn có thể tự khám phá 

## Hướng dẫn tải mã và khởi chạy 

- Fork repo này về tài khoản github của bạn
- Clone dự án đã fork trên github của bạn về máy tính cá nhân 
- Vào thư mục dự án tải về `cd TempGaugeChartUI`
- Chạy lệnh `npm install` để cài đặt các "thư viện" cần thiết của dự án (được xác định trong `package.json`) 
- `node-red -u .` để khởi chạy node-red tại thư mục chứa mã nguồn này, bấm vào đường dẫn địa chỉ để vào trình duyệt soạn thảo flow.