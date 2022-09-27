# Các kiến thức cơ bản của C++

1. Khai báo:
- Ta có khí khai báo int *array[20]; thì là ta tạo ra 1 mảng 20 con trỏ.
- Khi khai báo int (*array)[20] thì ta tạo ra chỉ 1 con trỏ và chỉ trỏ vào 1 mảng gồm 20 phần tử. 
</br>
- Ta có khí khai báo int *fun(void); thì là ta khai báo 1 function và trả về 1 con trỏ int.
- Ta có khí khai báo int (*fun)(void); thì là ta khai báo 1 con trỏ hàm, trỏ vào 1 function khác có dạng int fun_test(void) và trả về 1 giá trị int. 