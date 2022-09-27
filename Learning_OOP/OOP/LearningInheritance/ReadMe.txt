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


