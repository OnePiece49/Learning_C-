         /****************** SET TRONG C++ ******************\

    +, Set là một dạng cấu trúc dữ liệu dùng để lưu trữ các phần tử không trùng lặp và được sắp xếp theo thứ tự tăng dần hoặc giảm dần
            --> Mặc định trong set là tăng dần.
            --> Chúng ta có thể viết lại hàm so sánh để phù hợp với mục đích của chúng ta.


    --> Để sử dụng set ta cần include
            #include <set>
        
    --> Để khai báo một biến kiểu setset, ta có công thức chung sau:
            set<kiểu dữ liệu> tên biến;
        
        Vd: set<int> val; // defining an empty set
            set<int> val = {6, 10, 5, 1}; // defining a set with values

    +, Các giá trị được thêm vào trong Set không thể bị sửa đổi, mặc dù ta có thể thêm và xóa các phần tử trong set.
    +, Các giá trị trong Set là duy nhất, ko trùng nhau, và được tự động mặc định sắp theo thứ tự

        Vd1:     set<int> linh_ngu {0, 5, 5, 8, 9};
                set<int>:: iterator my_iterator = linh_ngu.begin();
                for(my_iterator; my_iterator != linh_ngu.end(); my_iterator++) {
                    cout << *my_iterator << endl;
                }

            --> Kết quả:                    
                    0
                    5
                    8
                    9
            --> Kết quả thu được chỉ có duy nhất một số 5 và đã tự động được sắp theo thứ tự tăng dần.

        Vd2:      set<string> linh_ngu {"hello", "hello aeee", "Hello ae", "hihi"};
                  set<string>:: iterator my_iterator = linh_ngu.begin();
                  for(my_iterator; my_iterator != linh_ngu.end(); my_iterator++) {
                      cout << *my_iterator << endl;
                  }

            --> Kết quả:            
                    Hello ae
                    hello
                    hello aeee
                    hihi
        
        --> Cái string này họ sắp xếp theo kiểu so sánh từng kí tự đầu, sau đó so sánh kí tự sau
                --> Kí tự nào bé hơn sẽ lập tức sếp lên trước luôn.

        

        +, Các phương thức của Set:
            +, Phương thức insert:
                linh_ngu.insert("ngu vl);
            +, Kiểm tra setset rỗng hoặc không:
                linh_ngu.empty();
            +, Xóa tất cả phần tử của setset:
                linh_ngu.clear();
            +, Kiểm tra một giá trị có tồn tại trong setset hoặc không, nếu có sẻ trả về con trỏ trỏ đến xx, nếu không trả về s.end()
                linh_ngu.find(x);

                Vd:     set<string> linh_ngu {"hello", "hello aeee", "Hello ae", "hihi"};
                        set<string>:: iterator my_iterator = linh_ngu.begin();
                        my_iterator = linh_ngu.find("hello");
                        if(my_iterator != linh_ngu.end())
                            cout << "Exist hello" << endl;
                        else 
                            cout << "hello not exist" << endl;
                
                --> Kết quả: hello not exist

            +, Để xóa phần tử x trong set:
                linh_ngu.erase(x);
            Vd:     set<string> linh_ngu {"hello", "hello aeee", "Hello ae", "hihi"};
                    set<string>:: iterator my_iterator = linh_ngu.begin();
                    my_iterator = linh_ngu.find("hello");
                    if(my_iterator != linh_ngu.end())
                        cout << "Exist hello" << endl;
                    else 
                        cout << "hello not exist" << endl;
                
                --> Kết quả: hello not exist
            --> Nếu phần tử x không thuộc set thì cũng ko sao(ko xóa gì cả).

            +, Xóa phần tử thứ k trong set:
                Vd:
                        set<string> linh_ngu {"hello", "hello aeee", "Hello ae", "hihi"};
                        set<string>:: iterator my_iterator = linh_ngu.begin();
                        advance(my_iterator, 2);
                        linh_ngu.erase(my_iterator);
                        my_iterator = linh_ngu.find("hello aeee");
                        if(my_iterator != linh_ngu.end())
                            cout << "Exist hello aeee" << endl;
                        else 
                            cout << "hello aeee not exist" << endl;
                        return 0;

                --> Từ khóa advance() giúp iterator trỏ đến vị trí thứ 2 trong set là "hello aeee"

            +, Con trỏ trỏ đến vị trí phần tử nhỏ nhất mà lớn hơn x, nếu không tìm thấy trả về vị trí s.end():
                +, linh_ngu.upper_bound(x);

                Vd:    set<string> linh_ngu {"hello", "heblo aeee", "Hello ae", "hihi"};
                        set<string>:: iterator my_iterator = linh_ngu.begin();
                        my_iterator = linh_ngu.upper_bound("hea");
                        cout << *my_iterator << endl;
                --> Kết quả: heblo aeee
            
            +, Con trỏ trỏ đến vị trí phần tử nhỏ nhất mà lớn hơn hoặc bằng x, nếu không tìm thấy trả về vị trí s.end():
                +, linh_ngu.lower_bound(x);


