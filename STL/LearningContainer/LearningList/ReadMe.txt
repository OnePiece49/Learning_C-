I. LearningList:
    +, std::list containers mô phỏng lại cấu trúc dữ liệu doubly-linked lists; Doubly-linked list có thể lưu trữ các
phần tử không liên tiếp nhau trên vùng nhớ nhưng vẫn đảm bảo được thứ tự của các phần tử khi truy xuất. Trật tự 
của các phần tử được giữ bởi những sự kết nối giữa các cặp phần tử.

--> Cấu trúc dữ liệu doubly-linked list cho phép người dùng thêm và xóa phần tử tại vị trí bất kỳ trong container, nhưng không hổ trợ truy cập ngẫu nhiên.
    --> Giống kiểu danh sách liên kết đơn.


II. SỬ dụng list    
    --> Cần include thư viện: #include <list>

+, Cú pháp khai báo một đối tượng của lớp std:: list    
    std::list<data_type> list_name;

Vd: std::list<int> my_list;
    std::list<__int32> list2(5); --> List được khai báo có  phần tử
    std::list<__int32> list3(list2); --> Khởi tạo list3 = list2
    std::list<__int32> list4(4, 201); --> Khởi tạo list4 có 4 phần tử đều có giá trị là 201.

2.1, Sử dụng các phương thức của List
    +, Truy xuất phần tử(Element access):
        --> Đối với cấu trúc dữ liệu doubly-linked list, chúng ta chỉ có thể truy xuất giá trị ở vị trí đầu tiên và cuối cùng trong container
        
        +, std::list::front(): Phương thức trả về giá trị của phần tử đầu tiên trong list container.
            std::list<int> my_list(5);
            std::cout << my_list.front() << std::endl;
        
        +, std::list::back(): Phương thức back trả về giá trị của phần tử cuối cùng trong list container.
            std::list<__int32> my_list(5);
            std::cout << my_list.back() << std::endl;
    
    +, Chỉnh xửa dữ liệu trong List.
        +, std::list::push_back(const list_type &value)
            --> Phương thức này cho phép thêm một phần tử vào sau phần tử có vị trí "cuối cùng" trong container, phần tử mới được thêm vào sẽ trở thành phần tử có chỉ số cao nhất trong container
                    int a = 9;
                    list<int> my_list(5, 2);
                    my_list.push_back(a);
                    cout << "Value in the end of List: " << my_list.back() << ", size List : "  <<my_list.size() << endl;
            --> Kết quả: Value in the end of List: 9, size List : 6

        +, std::list::push_front(const list_type &value)
            -->  phương thức này dùng để thêm một phần tử có cùng kiểu với list vào vị trí đầu tiên trong container.
                list<int> my_list(5, 2);
                my_list.push_front(110);
                cout << "Value in the first of List: " << my_list.front() << ", size List : "  <<my_list.size() << endl;
            --> Kết quả: Value in the first of List: 110, size List : 6

        +, std::list::pop_back()
            --> Xóa một phần tử cuối cùng trong list container:
                    list<int> my_list(5, 2);
                    my_list.push_back(110);
                    my_list.push_back(200);
                    my_list.pop_back();
                    cout << "Value in the end of List: " << my_list.back() << ", size List : "  <<my_list.size() << endl;
            --> Kết quả: Value in the end of List: 110, size List : 6
        
        +, std::list::pop_front():
            --> Xóa một phần tử trong list container tại vị trí đầu tiên.
                    list<int> my_list(5, 2);
                    my_list.push_front(110);
                    my_list.pop_front();
                    cout << "Value in the first of List: " << my_list.front() << ", size List : "  <<my_list.size() << endl;
            --> Kết quả: Value in the first of List: 2, size List : 5

    +, Chèn dữ liệu vào trong list
            +,iterator insert (iterator position, const value_type& val);
                --> Chèn giá trị val vào vị trí position

                Vd:     list<int> my_list;
                        my_list.push_back(110);
                        my_list.push_back(20);
                        my_list.push_back(35);
                        list<int>:: iterator my_iterator = my_list.begin();
                        my_iterator++;
                        my_iterator++;
                        cout << *my_iterator << endl;
                        my_list.insert(my_iterator, 30);
                        my_iterator--;
                        cout << *my_iterator << endl;
                        cout << "Value in the first of List: " << my_list.front() << ", size List : "  << my_list.size() << endl;
            
            --> Kết quả: 
                        35
                        30
                        Value in the first of List: 110, size List : 4

                --> Ta thấy list ban đầu là: 110(0), 20(1), 35(2). 
                    --> Iterator sau hai lần my_iterator++ trỏ đến vị trí thứ (2).
                    --> Khi insert vào vị trí thứ 2 thì ta được: 110 20 30 35;
                
                    list<int> my_list;
                    my_list.push_back(110);
                    my_list.push_back(20);
                    my_list.push_back(35);
                    list<int>:: iterator my_iterator = my_list.begin();
                    my_iterator++;
                    my_list.insert(my_iterator, 30);
                    my_list.insert(my_iterator, 40);
                    my_list.insert(my_iterator, 45);
                    for(my_iterator = my_list.begin(); my_iterator != my_list.end(); my_iterator++) {
                        cout << *my_iterator << endl;
                    }

                --> Kết quả:
                        20
                        110
                        30
                        40
                        45
                        20
                        35
            -->  Ta có giá trị của iterator sau mỗi lệnh insert là không thay đổi, nghĩa là nó vẫn đang trỏ vào địa chỉ của phần tử có giá trị là 20.
                    --> Nên khi insert thì nó sẽ insert vào vị trí ở vị trí ở địa chỉ có giá trị 20.
                    --> Nên kết quả mới xảy ra như vậy


    +, Xóa dữ liệu trong list 
        --> Phương thức erase():    --> Xóa tại vị trí nào đó.
                list<int> hello;
                hello.push_back(30);
                hello.push_back(45);
                hello.push_back(99);
                list<int>:: iterator my_iterator = hello.begin();
                hello.erase(my_iterator);
                my_iterator = hello.begin();
                cout << *(my_iterator) << endl;
            
            --> Kết quả: 45.
            --> Ta thấy nếu ko có hàm my_iterator = hello.begin();
                    --> thì lúc này iterator vẫn chỉ vào địa chỉ có giá trị 30, tuy địa chỉ đó đã được erase ra khỏi hàm.
                    --> Nên để đọc chính xác địa chỉ đầu tiên ta cần gọi my_iterator = hello.begin();
        
        --> Phương thức remove():   --> Xóa giá trị của list có giá trị bằng giá trị của "val"
                    list<int> hello;
                    hello.push_back(30);
                    hello.push_back(45);
                    hello.push_back(99);
                    hello.remove(30);
                    cout << hello.front() << endl;
            
            --> Kết quả: 45

    +, Các toán tử trong List:
        +, std::list::sort()
            --> Phương thức này sẽ sắp xếp lại dữ liệu bên trong container theo thứ tự tăng dần (mặc định là vậy).
                my_list.push_back(4);
                my_list.push_back(6);
                my_list.push_back(-2);
                my_list.push_back(-1);
                my_list.push_back(7);

                //container = { 4, 6, -2, -1, 7 }
                my_list.sort();
            --> Kết quả: container = { -2, -1, 4, 6, 7 }
        
            --> Ta có thể thay đổi điều kiện so sánh của phương thức sort bằng cách tự tạo một hàm so sánh 2 phần tử cùng kiểu dữ liệu với list
                bool my_comparison(__int32 n1, __int32 n2)
                {
                    return n2 < n1;
                }

                int main()
                {
                    std::list<__int32> my_list;
                    std::list<__int32>::iterator iter;
                    my_list.push_back(4);
                    my_list.push_back(6);
                    my_list.push_back(-2);
                    my_list.push_back(-1);
                    my_list.push_back(7);
                    
                    //container = { 4, 6, -2, -1, 7 }

                    my_list.sort(my_comparison);

                    //container = { 7, 6, 4, -1, -2 }
                    
                    return 0;
                }
            --> return về True thì dữ nguyên, fail thì đổi vị trí.