                /********************* Container TRONG C++ *********************\

+, Ta đã biết C++ 1 class thuộc STL đó là std::array và std::string
     --> Hai mảng kí tự này thường xảy ra lỗi khai báo thừa kí tự và dữ liệu

--> Để khắc phục vụ vấn đề này STL đã hổ trợ cho chúng ta các container class khác dùng để lưu trữ, xử lý các phần
tử với kích thước vùng nhớ tự động thay đổi để phù hợp với yêu cầu người dùng.

+,  Ta phân STL  thành 3 loại container khác nhau:
    +, Sequence container:  là tập hợp các container class nó duy trì trật tự của các phần tử bên trong container.
Một đặc tính của Sequence container là các bạn có thể chọn ví trí muốn chèn thêm phần tử vào container.
--> Ngôn ngữ C++11 cung cấp cho chúng ta 6 sequence containers: std::vector, std::deque, std::array, std::list, std::forward_list, std::basic_string.

    +, Associative container: là các container được thiết kế kèm theo cơ chế tự động sắp xếp dữ liệu đầu vào khi chúng được đưa vào container.
Cơ chế tổ chức dữ liệu của các container này sẽ quyết định vị trí của các phần tử trong container. 
--> Một số associative container được sử dụng phổ biến là: std::set, std::map...

+, Container adapter: 
    --> Container adapter là các container được sử dụng cho các cấu trúc lưu trữ đặc biệt: std::stack, std::queue, ...

    