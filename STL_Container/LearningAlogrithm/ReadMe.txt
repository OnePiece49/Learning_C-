                /********************* ALOGRITHM TRONG C++ *********************\

I. Thư viện Alogrithm
    +, Thư viện algorithm trong C++ là một thư viện có sẵn được thiết kế đặc biệt để thao tác với dữ liệu mảng theo phạm vi.
    --> Phạm vi có thể hiểu là một chuỗi các đối tượng có thể truy cập thông qua "biến lặp hoặc con trỏ". Các hàm này sẽ thực thi trực tiếp 
trên giá trị và sẽ không tác động đến cấu trúc dữ liệu của đối tượng nó tác động đến(không làm thay đổi kích thước và không gian bộ nhớ của đối tượng

    +, Các hàm của thư viện Alogrithm.

1. Sorting
    --> C++ cung cấp hàm sort để xắp xếp một mảng hoặc vector theo thứ tự.
    Có 2 loại hàm Sorting()
    +, loại 1: sort(addr_first, addr_end);

        --> addr_first: là vị trí của mảng mà bạn muốn bắt đầu sắp xếp
        --> addr_end: là vị trí cuối của mảng mà bạn muốn bắt đầu sắp xếp
        Vd:
            int main()
            {
                int arr[] = {1, 3, 9, 0, 9, 8, -5, 9, 20};
                sort(arr + 1, arr + 7);
                for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
                    cout << arr[i] << " ";
                }
            }
        --> Kết quả: 1 -5 0 3 8 9 9 9 20.
            --> Sắp xếp từ vị trí thứ nhất là số 3 đến vị trí thứ 7 là -5
        
        +, Với vector:
            int main()
            {
                vector<int> arr = {9, 25, -1 , 30, 35, 88};
                sort(arr.begin(), arr.end() - 5);
                for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
                    cout << arr[i] << " ";
                }
            }
    
    +, loại 2: sort(addr_first, addr_end +, fun_compare);
                        bool compare(int a, int b) {
                    return a < b ? false : true;
                }

                int main()
                {
                    int arr[] = {1, 3, 9, 0, 9, 8, -5, 9, 20};
                    sort(arr, arr + 8, compare);
                    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
                        cout << arr[i] << " ";
                    }
                }

        --> Kết quả: 9 9 9 8 3 1 0 -5 20 


2. Searching.
    --> Để tìm kiếm trong một mảng hoặc một vector, C++ sử dụng thuật toán binary search.
    --> Chú ý: Để tìm kiếm chính xác, mảng nhập vào đã phải là 1 mảng đã được sắp xếp.
    Có 2 loại hàm binary_search().
    +, Loại 1: binary_search(first_ele, last_ele, match_value);

    Vd:         int arr[] = {9, 9, -5, 0, 17, -8};
                sort(arr, arr + 6);                             // Sắp xếp mảng
                if (binary_search(arr, arr + 9, -5) ) {
                    cout << "yes";
                } else {
                    cout << "no";
                }
    
    +, Loại 2: có thêm object compare --> chưa đọc :))

3. Các thuật toán sử dụng trong mảng
    +, Hàm partition:
        --> partition(beg, end, condition) --> Hàm này cho phép xây dựng vách ngăn dựa trên điều kiện
        --> is_partitioned(beg, end, condition) --> Hàm này return true nếu như container(là các mảng, vector) đã được phân đoạn.
                            --> Chú ý là hàm is_partitioned() không phân đoạn, nó chỉ kiểm tra mảng đã phân đoạn hay chưa thôi.

    Vd1:
        bool function(int a) {
            return a % 2;
        }

        int main()
        {
            vector<int> arr = {9, 8, 20, 31, 35, -6, 7};

            partition(arr.begin(), arr.end(), function);
            for(int i = 0; i < sizeof(arr) / sizeof(int) + 1; i++) {
                cout << arr[i] << " ";
            }
        }

    Vd2:
            partition(arr.begin(), arr.end(), [](int x) { return x % 2;});
    --> Phân đoạn nhóm chia hết cho 2 và ko chia hết cho 2
        --> Kết quả: 9 7 35 31 20 -6 8




    
        