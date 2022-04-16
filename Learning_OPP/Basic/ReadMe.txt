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


    

    