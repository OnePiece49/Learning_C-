III. Lớp vector
        --> C++ cung cấp lớp std::vector hỗ trợ việc thao tác với mảng động an toàn và dễ dàng hơn.
            +, Ta có thể tạo các mảng động mà không cần phải cấp phát và thu hồi vùng nhớ bằng cách sử dụng toán tử new và delete.
            +, Ta cần include thư viện <vector>
            +, Sử dụng vector tránh rò rỉ bộ nhớ: bộ nhớ sẽ được giải phóng ngay khi thoát khỏi hàm mà không cần qua lệnh delete.
    
        +, Khai báo:
            Vd: (using namespace std;)
            // không cần cung cấp độ dài mảng tại thời điểm biên dịch.
                vector<int> array;
                vector<int> array2 = { 9, 7, 5, 3, 1 };
                vector<int> array3{ 9, 7, 5, 3, 1 };
            --> Khi một biến vector ra khỏi phạm vi được định nghĩa, nó sẽ tự động giải phóng vùng nhớ mà nó nắm giữ.

        +, Một số thao tác với vector.
                vector<int> array{ 2, 5, 8, 3, 1 }; // mảng 5 phần tử
	            array.resize(10);                   // thay đổi độ dài mảng thành 10 phần tử

            +, Ta có truy nhập vào từ phần tử của mnagr theo 2 cách:
                    Vd: array2.at(2);
                        array2[2];
                        --> Tưởng đương nhau.

            +,  std::vector chứa hai thuộc tính riêng biệt: kích thước (size) và dung lượng (capacity).
                --> Kích thước (size) trả về số lượng phần tử đang được sử dụng trong mảng.
                --> Dung lượng (capacity) trả về số lượng phần tử được cấp phát cho vector trong bộ nhớ.

                Vd: 
                    vector<int> array;
	                array = { 0, 1, 2, 3, 4 }; // length = 5, cap = 5
	                cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n';

	                array = { 9, 8, 7 }; // length = 3, cap = 5
	                cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n';

                --> Kết quả: length: 3 capacity: 5
                             length: 5 capacity: 5
        
                Chú ý: khi ta gán lại array = { 9, 8, 7 };
                        --> Thì số lượng phần tử của mảng trở thành 3 và khi truy cập đến phần tử thứ 4 thì gây ra lỗi.
                                --> Nghĩa là lúc này bản chất mảng vector chỉ còn 3 phần tử.
                                và array2.capacity() vẫn in ra 5 là vì nó được khởi tạo(được cấp phát) 5 phần tử.
                
                        --> Ta có thể cấp phát dung lượng ban đầu cho mảng qua hàm reserve()
                            Vd: array2.reserve(20);
                        
                        --> Ta có thể thay đổi số phần tử vector qua hàm resize();
                            Vd: array2.resize(10);
                            --> Lúc này ta có thể sử dụng các ptu thứ 5 6 7 8
                                Vd: array2.at(6) = 8; --> Đúng.

            +, Hành vi ngăn xếp trên std::vector
                --> Std::vector cung cấp 3 phương thức:
                    +, push_back() thêm một phần tử vào cuối vector.
                    +, front() lấy phần tử đầu của vector
                    +, back() trả về giá trị của phần tử cuối vector.
                    +, pop_back() xóa một phần tử cuối vector.
                
                +, push_back()
                    Vd:
                            vector<string> Mystring{"Huy ngu", "Viet vipppro"};
                            Mystring.push_back("Linh ml");
                            for(int i = 0; i < Mystring.size(); i++) {
                                cout << Mystring.at(i) << endl;
                            }
                        
                        --> Kết quả: 
                                Huy ngu
                                Viet vipppro
                                Linh ml
                
                +, front()
                    Vd:    vector<string> Mystring{"Huy ngu", "Viet vipppro"};
                            Mystring.pop_back();
                            cout<< Mystring.front() << endl;
                        
                        --> Kết quả: 
                                Huy ngu

                +, back()
                    Vd:
                            vector<string> Mystring{"Huy ngu", "Viet vipppro"};
                            cout<< Mystring.back() << endl;

                        --> Kết quả:
                                Viet vipppro

                +, pop_back():
                    Vd:
                            vector<string> Mystring{"Huy ngu", "Viet vipppro"};
                            Mystring.pop_back();
                            cout<< Mystring.back() << endl;

                        --> Kết quả:
                                Huy ngu
                            --> ptu cuối bây giờ là "Huy ngu"