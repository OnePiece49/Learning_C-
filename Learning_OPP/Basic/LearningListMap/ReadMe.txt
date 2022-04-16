                        /****************** MAP TRONG C++ ******************\

    +, Các lớp vector, list thuộc cấu trúc Sequence Containers (cấu trúc tuần tự).
    +,  lớp map thuộc 1 cấu trúc khác đó là Associative Containers (cấu trúc liên kết)
        -->  Là kiểu dữ liệu cho phép quản lý 1 cặp key/value - khóa và giá trị, nghĩa là muốn xác định được nội dung value thì phải biết 
    được vị trí key mà map đang quản lý.


                        /****************** SỬ DỤNG MAP ******************\
--> Lớp map nằm trong thư viện map vì vậy muốn sử dụng trước tiên phải #include <map>
        +, Cú pháp khai báo: map<valueType1, valueType2> variableName;
                +, Với valueType1 và valueType2 là kiểu dữ liệu của biến thứ nhất và thứ 2
                +, variableName là tên của biến.

        Vd:     map<string, string> dictionary;
                dictionary["eat"] = "an";
                dictionary["sleep"] = "ngu";
            +,Biến dictionary được khai báo với cặp dữ liệu là <string, string>, vì vậy:
                --> key của dictionary phải là kiểu string - "eat" "sleep"...
                --> value của dictionary phải là kiểu string - "an" "ngu"...

        +, Chú ý: map cũng là 1 mảng được quản lý bởi key, lấy key thì được value.
            VD1, mảng thông thường: int arr[10] = {3, 5, 9, 21};
                    --> Truy cập vào mảng arr[1], arr[2], ...
            --> Nhưng với map, ta có:
                    map<string, int> A; // Khởi tạo một map A
                    A["One"] = 1;       // Thêm vào map A một số phần tử.
                    A["Two"] = 2;
                    A["Three"] = 3;
            --> Lúc này phần tử đầu tiên có "key" là "One" và "value" là 1.
                        --> Và nếu ta lại gán tiếp A["One"] = 25;
                                --> Thì phần tử đầu tiên A["One"] = 25; chứ ko phải là thêm phần tử A["One"] = 25 vào cuối mảng map.
                                --> Vì map quy định các key với nhau ko được trùng.

--> Duyệt map(" Lấy các giá trị trong map"):
                Lớp map quản lý value bằng key, nếu trường hợp quên map thì làm sao có thể truy xuất để lấy dữ liệu value.
        --> Để giải quyết vấn đề trên trong lớp map định nghĩa thao tác iterators cho phép truy xuất đến phần tử trong map để lấy dữ liệu value
        và key cần thiết.
        --> các iterators đã được cung cấp như: begin(), end(), rbegin(), rend(), ... 
                Vd:
                        map<char, int> character0;
                        character0['a'] = 97;
                        character0['b'] = 98;
                        character0['c'] = 99;
                        character0['d'] = 100;

                        map<char, int> character1(character0.begin(), character0.end());
                        map<char, int>::iterator it;
                        for (it = character1.begin(); it != character1.end(); it++) {
                                cout << it->first << ": " << it->second << endl;
                        }
        
                --> Kết quả:
                                a: 97
                                b: 98
                                c: 99
                                d: 100

--> Lấy kích thước của map:
        map<int, char*> mymap;
        mymap[0] = "a";
        mymap[1] = "b";
        mymap[0] = "c";

        cout << mymap.size(); --> 3

--> Kiểm tra map có rỗng hay không?
        map<int, char*> copymymap;

        if (copymymap.empty()) cout << "copymymap is empty";
                --> Kết quả: copymymap is empty

--> Truy xuất theo chỉ số
        +, Ta có: [index] hay at(index) cho phép truy xuất trực tiếp đến giá trị từng phần tử.
        VD:     map<int, string> mymap, copymymap;
                mymap[0] = "hello luong";
                mymap[1] = "hello wibu";

                cout << mymap[1] << " " << mymap.at(0);

        --> Kết quả: hello wibu hello luong

--> Thêm dữ liệu vào map
        +, insert() cho phép chèn thêm 1 đối tượng hoặc cả 1 map
        VD1:     --> Chèn 1 đối tượng.   
                map<string, int> myMap, mapInsert;
                myMap["Viet"] = 13;
                myMap["Long"] = 20;
                myMap.insert (myMap.begin(), pair<string, int>("Huy", 5)); --> Chèn vào đầu.
                // myMap.insert(pair<string, int>("Huy ngu", 5)); --> Cũng chèn vào đầu
                map<string, int> :: iterator i;
                for(i = myMap.begin(); i != myMap.end(); i++) {
                        cout << i->first << " : " << i->second << endl;
                }

        --> Kết quả: 
                Huy : 5
                Long : 20
                Viet : 13

        VD2:    --> Chèn cả 1 

--> Tìm kiếm phần tử trong map()
        +, find() cho phép tìm kiếm theo key của cặp giá trị key/value
        VD:       map<int, char*> mymap;
                mymap[0] = "a";
                mymap[1] = "b";
                mymap[5] = "c";
                mymap[9] = "e";
                map<int, char*>::iterator var = mymap.find(5);
                // var -> (5,"c")

--> Xóa bỏ phần tử trong map
        +, erase() cho phép xóa 1 phần tử.
        VD:     map<int, char*> mymap, copymymap;
                mymap[0] = "a";
                mymap[1] = "b";
                mymap[5] = "c";
                mymap[7] = "d";
                mymap[9] = "e";

                // xóa cặp đối tượng với "key" là 5
                mymap.erase(5);		
                // => mymap =  {(0,"a"),(1,"b"),(7,"d"),(9,"e")}
                        
                map<int, char*>::iterator var = mymap.begin();
                // xóa cặp đối tượng mà var đang truy cập
                mymap.erase(var); // => mymap =  {(1,"b"),(7,"d"),(9,"e")}

                var = mymap.find(7); // => var truy cập đến (7,"d")

                // xóa từ vị trí var đang truy cập cho đến (9,"e") 
                mymap.erase(var, mymap.end()); // => mymap = {(1,"b")}