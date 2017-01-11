## Clang Lib Source to Source Transformation Example

This is a simple example of source-to-source transformation.

The objective here was to use an auxiliar struct to pass variables to a function. Then, this tries to perform the following transformation:

### Original Code:
void func(int &a, char &c){
        a=10;
        c='C';
}
int main(){
        int a;
        char c;
        func(a,c);
        std::cout << "a Value: " << a << c << std::endl;
        func(a,c);
        std::cout << "a Value: " << a << c << std::endl;
}
 
### Transformed Code:

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
        if(a=0)
                c='f';
        else
                c='t';
        
        data_t *d = new data_t[1];
        d->a=a;
        d->c=c;
        func(d->a, d->c);
        std::cout << "a Value: " << d->a << d->c << std::endl;
}
