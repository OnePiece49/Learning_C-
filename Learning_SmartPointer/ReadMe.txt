        /*********** SMART POINTER TRONG C++ ***********\

    1. Vì chúng ta hay quên việc free poiter khi sử dụng xong
        --> Leak memory

    --> Nên ta cần Smart Poiter xử lí vấn đề này và nhiều vấn đề khác nữa

    2.Smart pointer
        +, Có 2 loại chính: unique_ptr 
                            shared_ptr
    
    --> Cách gọi: Loại_smart_poiter<Tên_kiểu_dữ_liểu : class, struct, int,..>Tên_biến.
    Vd: unique_ptr<Rectangle> P1(new Rectangle(10, 5));
        2.1, Smart Poiter: "unique_ptr"
    
    --> Có ý nghĩa là với cùng 1 đối tượng, chỉ có duy nhất 1 smart pointer unique_ptr chỉ được tới nó
        class Rectangle {
            int length;
            int breadth;
        
        public:
            Rectangle(int l, int b) {
                length = l;
                breadth = b;
            }
        
            int area(){
                return length * breadth;
            }
        };
        
        int main(){
        
            unique_ptr<Rectangle> P1(new Rectangle(10, 5));
            cout << P1->area() << endl; // This'll print 50
        
            // unique_ptr<Rectangle> P2(P1);
            unique_ptr<Rectangle> P2;
            P2 = move(P1);
        
            // This'll print 50
            cout << P2->area() << endl;
            cout << P1->area() << endl;
            // cout<<P1->area()<<endl;
            return 0;
        }

    --> Kết quả:    50
                    50
                    Segmentation fault (core dumped)
        --> ta thấy lúc này ko thể in ra được P1->area()
            Vì lúc này p2 đã trỏ tới object đó nên P1 ko trỏ tới được nữa

    +, Để trỏ Khi nói đến std::unique_ptr chúng ta cần biết đến một hàm đi kèm là std::make_unique(). Hàm này cho phép khởi tạo một đối tượng với kiểu được yêu cầu.
    chúng ta sử dụng toán tử ( * ) để lấy được đối tượng đang được quản lý. Chúng ta cần lưu ý nên kiểm tra xem res có đang quản lý một đối tượng hay không trước khi truy xuất
        struct Fraction
        {
            int m_numerator = 0;
            int m_denominator = 1;

            Fraction(int numerator = 0, int denominator = 1) :
                m_numerator(numerator), m_denominator(denominator)
            {
            }
        };


        int main()
        {
            // Create a single dynamically allocated Fraction with numerator 3 and denominator 5
            std::unique_ptr<Fraction> f1 = std::make_unique<Fraction>(3, 5);
            std::cout << (*f1).m_numerator << "/" << (*f1).m_denominator << std::endl;

            // Create a dynamically allocated a Fraction here
            // We can also use automatic type deduction to good effect here
            auto f2 = std::make_unique<Fraction>(4, 6);
            std::cout << (*f2).m_numerator << "/" << (*f2).m_denominator << std::endl;

            return 0;
        }

        --> Kết quả: 
                3/5
                4/6

        2.2 Smart Poiter: "shared_ptr"
        --> Khi sử dụng shared_ptr thì nhiều poiter có thể trỏ tới 1 object tại cùng 1 thời điểm
            --> Ta có thể sử dụng phương thức use_count() để xem có bao nhiêu poiter chỉ vào object đó.

                class Rectangle {
                    int length;
                    int breadth;
                    
                    public:
                        Rectangle(int l, int b)
                        {
                            length = l;
                            breadth = b;
                        }
                    
                        int area()
                        {
                            return length * breadth;
                        }
                    };
                    
                    int main()
                    {
                    
                        shared_ptr<Rectangle> P1(new Rectangle(10, 5));
                        // This'll print 50
                        cout << P1->area() << endl;
                    
                        shared_ptr<Rectangle> P2;
                        P2 = P1;
                    
                        // This'll print 50
                        cout << P2->area() << endl;
                    
                        // This'll now not give an error,
                        cout << P1->area() << endl;
                    
                        // This'll also print 50 now
                        // This'll print 2 as Reference Counter is 2
                        cout << P1.use_count() << endl;
                        cout << P2.use_count() << endl;
                        return 0;
                    }
        --> Kết quả:    50
                        50
                        50
                        2
                        2
    
    +, Chú ý về thu hồi dữ liệu của shared_ptr:
        +, Ta đã nói với smart pointer thì khi dữ liệu bị ra khỏi scope thì biến đó tự động được thu hồi.
            struct Resource
            {
            public:
                Resource() { std::cout << "Resource acquired\n"; }
                ~Resource() { std::cout << "Resource destroyed\n"; }
            };
            
            int main()
            {
                // allocate a Resource object and have it owned by std::shared_ptr
                Resource *res = new Resource;
                Resource hello;
                std::shared_ptr<Resource> ptr1(res);
                {
                    std::shared_ptr<Resource> ptr2(ptr1); // use copy initialization to make another std::shared_ptr pointing to the same thing
            
                    std::cout << "Killing one shared pointer\n";
                } // ptr2 goes out of scope here, but nothing happens
            
                std::cout << "Killing another shared pointer\n";
            
                return 0;
            } 

        --> Chúng ta tạo ra một đối tượng kiểu Resource, và dùng một đối tượng std::shared_ptr để quản lý nó. Trong một khối lệnh con khác, đối tượng ptr2 
        cũng với kiểu std::shared_ptr trỏ đến cùng một đối tượng Resource. Khi đối tượng ptr2 ra khỏi khối lệnh, đối tượng Resource không bị thu hồi, vì đối tượng ptr1 vẫn đang quản lý nó. Khi đối tượng ptr1 ra khỏi khối lệnh hàm main, đối tượng ptr1 thông báo rằng nó không còn chia sẻ tài nguyên với đối tượng std::shared_ptr nào khác, nên đối tượng Resource bị thu hồi.
            --> 2 biến shared_ptr cùng chỉ đến 1 object, mà chỉ 1 object bị hủy thì object kia vẫn được giữ lại.

            *Ta lại có:
                struct Resource
                {
                public:
                    Resource() { std::cout << "Resource acquired\n"; }
                    ~Resource() { std::cout << "Resource destroyed\n"; }
                };
                
                int main()
                {
                    Resource *res = new Resource;
                    std::shared_ptr<Resource> ptr1(res);
                    {
                        std::shared_ptr<Resource> ptr2(res); // create ptr2 directly from res (instead of ptr1)
                
                        std::cout << "Killing one shared pointer\n";
                    } // ptr2 goes out of scope here, and the allocated Resource is destroyed
                
                    std::cout << "Killing another shared pointer\n";
                
                    return 0;
                } 
            --> Chương trình trên bị crash vì con trỏ res bị hủy 2 lần.
                Vì lúc này khi ra khỏi scope thì biến res đã bị thu hồi, sau đó kết thúc main biến res bị thu hồi 1 lần nữa

                --> Thế nên tùy lúc mà ta gán shared_ptr<Resource> ptr2(res);
                                        or: shared_ptr<Resource> ptr2(ptr1);