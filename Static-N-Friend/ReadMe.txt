                    /******************* STATIC FUNCTION IN C++ *******************\
    
    1. Static function chỉ có thể truy cập vào các biến static và các static function khác và bất kì các hàm nào bên ngoài class

    --> Bởi vì static function có thể được gọi bất cứ đâu trong hệ thống bởi ::, nên nó ko thể truy cập bừa bài vào các biến object mà ko phải 
là static bên trong class.

    2. Một function non-static có thể gọi được 1 static function
    3. Một static function không thể gọi được 1 non-static function