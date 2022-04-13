                    /****************** BASIC C++ ******************\

    I. Ép kiểu 
          
1. Ép kiểu ngầm định (implicit type conversion)

II. Ép kiểu rõ ràng (explicit type conversion)
   +, Ép kiểu rõ ràng (explicit type conversion) là việc chuyển đổi kiểu dữ liệu một cách rõ ràng bởi yêu cầu của lập trình viên.

   --> Có 5 cách khác nhau trong việc ép kiểu rõ ràng:
        +, C-Style casts.
        +, Static casts.
        +, Const casts.
        +, Dynamic casts.
        +, Reinterpret casts.

        Ta có ví dụ:
            int i_value1 = 10;
            int i_value2 = 4;
            float f_value = i_value1 / i_value2;
        --> Biến f_value sẽ được gán giá trị là 2.0 vì phép chia hai số nguyên sẽ trả về kết quả là một giá trị số nguyên. 
            Làm thế nào chúng ta có thể nói với compiler rằng chúng ta muốn có kết quả trả về là số thực?
    
    1. C-style casts
        +, Trong chuẩn ngôn ngữ C, casting được thực hiện thông qua toán tử () với tên của kiểu dữ liệu bạn muốn chuyển đổi về được đặt bên trong.
            int i_value1 = 10;
            int i_value2 = 4;
            float f_value = (float)i_value1 / i_value2;
        --> Biến i_value1 sẽ được cast thành kiểu float, sau đó biến i_value2 cũng sẽ được cast theo để thực hiện phép chia
            --> Kết quả là 1 số float.
        
        +, Ngôn ngữ C++ cho phép thực hiện C-style cast giống với cách gọi hàm:
            f_value = float(i_value1) / i_value2;

    2. Static casts
        Vd: int i { 48 };
            char ch { static_cast<char>(i) };
        --> Nếu ép kiểu gặp lỗi, nó sẽ bắn lỗi trong lúc compile.


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

    IV. Kế thừa - Inheritance
    1. Vấn đề constructor
        --> Class con bắt buộc phải gọi 1 constructor lớp cha.
        --> Nếu lớp cha không khai báo constructor thì lớp con sẽ tự động gọi constructor nguyên thủy của lớp cha.
            class people {
                protected:
                    string Name;
                    int Age;

                public:
                    people() {
                        cout << "Hello world" << endl;
                    }

                    void printAge() {
                        cout << " Tuoi cua " << Name << ": " << Age << endl;
                    }
            };

            class wibu : public people{
                public:
                    wibu(string Film) 
                        :film(Film)
                    {}
                    void printAge() {
                        cout << " Tuoi  " << Name << ": " << Age << endl;
                    }
                private:
                    string film;    
            };

            int main()
            {
                wibu Huy("onepiece");
            }
        
        --> Kết quả:    Hello world

    Chú ý 1: constructor là cách khởi tạo 1 biến.
        --> Nên nếu class khai báo nhiều constructor thì sẽ có nhiều kiểu khởi tạo biến.
        Vd:
            class wibu : public people{
            public:
                wibu(string name, int age)
                     :people(name, age)
                {}
                wibu(string Film) 
                    :film(Film)
                {}
            };
        --> Lúc này ta có thể khởi tạo biến theo 2 cách như vd dưới:
                wibu Huy("onepiece");
                wibu Huy("Truong Van Huy", 22);
        
        --> Ta không thể khai báo: wibu Huy; wibu("Truong van Huy", "Film doraemon", 22);
                --> Vì ta không làm tường mình constructor nguyên thủy, và cũng không có construct tương ứng.

    Chú ý 2: Với các object thuộc protected ở lớp cha, các biến object đó chỉ được sử dụng trực tiếp ở các function không phải construct.
        --> Muốn sử dụng các biến đó ở construct lớp con, ta phải sử dụng thông qua construct lớp cha.
        
    II. Vấn đề overiding

    --> Khi lớp con kế thừa lớp cha thì các thuộc tính và phương thức của lớp cha sẽ có thể sử dụng ở lớp con.
    Tuy nhiên, khi mà lớp con lại khai báo một phương thức có tên và tham số giống với phương thức của lớp cha thì phương thức của lớp 
    cha sẽ bị ghi đè.

    vd:
        class people {
            protected:
                string Name;
                int Age;

            public:
                people(string name, int age) 
                    :Name(name), Age(age)
                {}
                people() {
                    cout << "Hello world" << endl;
                }

                void printAge() {
                    cout << " Tuoi cua " << Name << ": " << Age << endl;
                }
        };

        class wibu : public people{
            public:
                wibu(string name, int age, string Film) 
                    :people(name, age), film(Film)
                {}

                void printAge() {
                    cout << " Tuoi  " << Name << ": " << Age << endl;
                }

            private:
                string film;    
        };

        int main()
        {
            wibu Huy{"Truong van Huy", 25, "onepiece"};
            Huy.printAge();
        }

        --> Kết quả: 
             Tuoi  Truong van Huy: 25
            --> Ta thấy kết quả ko phải là "Tuoi cua Truong van Huy: 25"
                --> phương thức của lớp cha đã bị ghi đè.


        --> Nhưng khi sử dụng con trỏ thì việc ghi đè này không được thực thi nữa.
        Vd:
            (Vẫn với class như trên)
            int main()
            {
                people *Viet;
                wibu Huy{"Truong van Huy", 25, "onepiece"};
                Viet = &Huy;
                Viet->printAge();
            }
        -->  Tuoi  Truong van Huy: 25
                --> Không bị ghi đè.
        

    --> Để giải quyết vấn đề này, C++ cung cấp cho chúng ta 2 từ khoá đó là virtual và override, từ khoá virtual sẽ được thêm vào phương
     thức bị ghi đè của lớp cha, từ khoá override sẽ được them vào phương thức của lớp con nhằm thể hiện nó sẽ ghi đè phương thức của lớp cha.
    +, Từ khóa override có cũng được, ko có cũng được.
     Vd:    
        class people {
            protected:
                string Name;
                int Age;

            public:
                people(string name, int age) 
                    :Name(name), Age(age)
                {}
                people() {
                    cout << "Hello world" << endl;
                }

                virtual void printAge() {
                    cout << " Tuoi cua " << Name << ": " << Age << endl;
                }
        };

        class wibu : public people{
            public:
                wibu(string name, int age, string Film) 
                    :people(name, age), film(Film)
                {}

                void printAge() override {
                    cout << " Tuoi  " << Name << ": " << Age << endl;
                }

                void printName() {
                    cout << " Ten  " << Name << endl;
                }
            private:
                string film;    
        };
        
            int main()
            {
                people *Viet;
                wibu Huy{"Truong van Huy", 25, "onepiece"};
                Viet = &Huy;
                Viet->printAge();
            }

        --> Kết quả:  Tuoi  Truong van Huy: 25  
                --> Đã bị ghi đè.


IV. Vấn đề 1 hàm được thực thi nhiều lần trong kế thừa
    Khi class B kế thừa Class A, Class C kế thừa Class A
    --> Sau đó Class D kế thừa CLass B và C --> Dẫn đến vấn đề khi sử dụng construct ở class D thì class A được gọi 2 lần
        --> SLide 47
    --> Để ngăn ngừa vấn đề đó ta thêm từ khóa virtual vào trước đoạn public class A.
    Vd:
        class B : virtual public A {};
        class C : virtual public A {};
        class D : public B, C {};

V. Sự mập mờ trong đa kế thừa.
    --> Khi class C kế thừa class A và class B, mà class B và C có cùng phương thức giống nhau
            --> Sinh ra hiện tượng mập mờ trong đa kế thừa.
            Vd: class A {
                    public: 
                        void print() {
                            cout << "I'm class A" << endl;
                        }  
                        void hello() {
                            cout << "hello" << endl;
                        }
                };

                class B {
                    public:
                        void print() {
                            cout << "I'm class B " << endl;
                        }
                };

                class C : public A, public B {
                    
                };

                int main()
                {
                    C Vietpro;
                    Vietpro.print();
                }

        --> Lỗi, ko biết sử dụng phương thức của lớp nào.

    --> Để giải quyết vấn đề này, ta có 2 cách:
            +, Cách 1: int main()
                        {
                            C Vietpro;
                            Vietpro.B::print();
                        }
                    --> Sử dụng toán hạng phân giải phạm vi

            +, Cách 2: Ghi đề phương thức, rồi sử dụng toán hạng phân giải phạm vi:
                class C : public A, public B {
                    public:
                        void print() {
                            A::print();
                        }
                };

                int main()
                {
                    C Vietpro;
                    Vietpro.print();
                }
            
                --> Kết quả: "I'm class A".


