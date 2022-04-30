            /********************* Iterator TRONG C++ *********************\

+, Trong bài STL containers, ta đã biết một số class được sử dụng để tạo ra các container với  những cách tổ chức dữ liệu khác nhau. 
Tuy nhiên, tập hợp các phần tử được chứa bên trong container vẫn có một trật tự nhất định (tùy vào thuật toán sắp xếp được chọn), và để duyệt 
qua các phần tử trong các container chúng ta sẽ sử dụng các STL Iterator tương ứng.
    --> Iterator dùng để duyệt dữ liệu trong các container.

+, Một Iterator là một đối tượng có thể đi qua (iterate over) một container class mà không cần biết trật tự các phần tử bên trong mảng.
Iterator còn là một cách để truy cập dữ liệu bên trong các container.

--> Ta có thể hình dùng Iterator giống như một con trỏ trỏ đến một phần tử nào đó bên trong container với một số toán tử đã được định nghĩa:
    +, Operator* cereference và trả về giá trị bên trong container tại vị trí mà iterator được đặt.
    +, Operator++ di chuyển iterator đến phần tử tiếp theo trong container.
    +, Operator-- ngược lại so với operator++.
    +, Operator== và operator!= dùng để so sánh vị trí tương đối của 2 phần tử đang được trỏ đến bởi 2 iterator.
    +, Operator= dùng để gán vị trí mà iterator trỏ đến.

I, Sử dụng Iterator

1.1, Khai báo một iterate:
    --> Với mỗi container class chúng ta sẽ có một kiểu iterator tương ứng. 
        Vd: Với class vector:    std::vector<int>::iterator iter;
        Vd: Với class ListL:     std::list<int>::iterator position;


1.2 Các phương thức trả về kiểu Iterator của các container class:
    -->  muốn gán địa chỉ (vị trí) của một phần tử trong container cho một iterator thì chúng ta cũng cần có những phương thức trả về giá trị kiểu iterator tương ứng.
        +, Và những container có chứa định nghĩa class iterator sẽ có những phương thức trả về giá trị kiểu iterator tương ứng:
            +, begin() trả về một iterator đại diện cho vị trí của phần tử đầu tiên trong container.
            +, end() trả về một iterator đại diện cho vị trí đứng ngay sau phần tử cuối cùng trong container.
            +, cbegin() trả về một hằng (read-only) iterator đại diện cho vị trí của phần tử đầu tiên trong container.
            +, cend() trả về một hằng (read-only) iterator đại diện cho vị trí đứng ngay sau phần tử cuối cùng trong container.


    --> Tóm lại ta có ví dụ:
        std::vector<__int32> vec;
        for (int i = 0; i < 10; i++)
            vec.push_back(i);

        std::vector<__int32>::iterator iter = vec.begin();
    --> Thì lúc này iter đang chỉ tới phần tử đầu tiên của vector
        --> Ta sẽ sử dụng các Operator đã ghi trên kia(*, ++, --, ==, =) và kết hợp với iter.
        Vd, Muốn lấy giá trị đầu tiên của vector 
            --> Sử dụng Operator*
                    std::vector<int> my_vec;
                    for(int i = 3; i < 10; i++) {
                        my_vec.push_back(i);
                    }

                    vector<int> :: iterator my_iterator = my_vec.begin();
                    cout << "Value first in my_vec: " <<*my_iterator << endl;
            --> Kết quả: Value first in my_vec: 3

        Vd; Muốn trỏ tới phần tử thứ 2
                std::vector<int> my_vec;
                for(int i = 3; i < 10; i++) {
                    my_vec.push_back(i);
                }
                vector<int> :: iterator my_iterator = my_vec.begin();
                my_iterator++;
                cout << "Value second in my_vec: " << *(my_iterator) << endl;
            
            --> Kết quả: Value first in my_vec: 4

    Chú ý: end() trả về một iterator đại diện cho vị trí đứng ngay sau phần tử cuối cùng trong container.
            --> Chứ không phải chỉ vào phần tử cuối cùng
            --> Tại sao lại chỉ vào phần tử đứng ngay sau ???
                --> Vì họ muốn sử dụng end() để đại diện cho việc đã xét duyệt xong mảng.

        Vd:     std::vector<int> my_vec;
                for(int i = 3; i < 10; i++) {
                    my_vec.push_back(i);
                }
                vector<int> :: iterator my_iterator = my_vec.end();
                for(my_iterator = my_vec.begin(); my_iterator != my_vec.end(); my_iterator++) {
                    cout << *my_iterator << endl;
                }

            --> Kết quả: 
                        3
                        4
                        5
                        6
                        7
                        8
                        9
    
    Chú ý: Ta không thể sử dụng các Operator khác ngoài các Operator đã nêu trên:
            Vd: my_iterator = my_iterator + 1; --> Sai



