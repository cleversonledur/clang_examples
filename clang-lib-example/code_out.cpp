#include <iostream>

typedef struct{
	int a;
	char c;
}data_t;
void func(int &a, char &c){
        a=10;
        c='C';
}
int main(){
        int a;
        char c;
        data_t *d = new data_t[1];
	d->a = a;
d->c = c;
func(d->a,d->c);
        func(d->a,d->c);
        std::cout << "a Value: " << a << c << std::endl;
        func(d->a,d->c);
        printf("%d",a);
}


