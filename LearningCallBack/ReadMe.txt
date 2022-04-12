                /************************ CÁCH SỬ DỤNG 1 FUNCTION CALLBACK ************************\

    I. Các bước khởi tạo 1 function callback 
        B1, khởi tạo hàm để gọi callback
            Vd: int principalFn(char ch[], void *(*ptr)(int));
            or int principalFn(char ch[], void (ptr)(int));
        
        Hàm callback sữ có dạng *ptr(int ) với vd1 hoặc (ptr)(int ) với dạng 2.
            Hàm callback sẽ được thực thi khi ta gọi (*ptr)(int).
    

    Vd1: 
        int principalFn(char ch[], void *(*ptr)(int))
        {
            int id1 = 1;
            int id2 = 2;
            (*ptr)(id2);
            cout << "principal function: "<< id1 << endl;
            return id1;
        }

        void *cb(int iden)
        {
            cout<<"callback function"<<'\n';
            return NULL;
        }

        int main()
        {
            char cha[] = "and";
            principalFn(cha, cb);
            return 0;
        }

    --> Kết quả: callback function
                 principal function: 1
        --> Hàm callback (*ptr)(int) được gọi trước lệnh in cout << "principal function: "<< id1 << endl.


    Vd2. 
        int principalFn(char ch[], void (*ptr)(int))
        {
            int id1 = 1;
            int id2 = 2;
            cout << "principal function: "<< id1 << endl;
            (*ptr)(id2);
            return id1;
        }

        void cb(int iden)
        {
            cout<<"callback function"<<'\n';
        }

        int main()
        {
            char cha[] = "and";
            principalFn(cha, cb);
            return 0;
        }

    --> Kết quả: principal function: 1 
                 callback function
        --> Hàm callback (*ptr)(int) được gọi sau lệnh in cout << "principal function: "<< id1 << endl.