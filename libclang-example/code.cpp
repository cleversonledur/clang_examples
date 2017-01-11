#include <iostream>

void func(int &a, char &c){
        a=10;
        c='C';
}
int main(){
        int a;
        char c;
        func(a,c);
        func(a,c);
        std::cout << "a Value: " << a << c << std::endl;
        func(a,c);
        printf("%d",a);
}


