#include<iostream>
using namespace std;

/*
    C++ support generic classes
    Generic functions are template functions
    Generic classes are template classes

    class Arithmetic
    {
        private:
            int a;
            int b;

        public:
            Arithmetic(int a,int b);
            int add();
            int sub();
    };

    Arithmetic::Arithmetic(int a, int b)
    {
        this->a = a; //this is a pointer
        this->b = b;
    }

    int Arithmetic:: add()
    {
        int c;
        c = a + b;
        return c;
    }

    int Arithmetic::sub()
    {
        int c;
        c= a-b;
        return c;
    }
*/
template<class T>
class Arithmetic
{
    private:
        T a;
        T b;

    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a; //this is a pointer
    this->b = b;
}

template<class T>
T Arithmetic<T>:: add()
{
    T c;
    c = a + b;
    return c;
}

template<class T>
T Arithmetic<T>::sub()
{
    T c;
    c= a-b;
    return c;
}

int main()
{
    Arithmetic<int> ar(10,5);
    cout<<ar.add();
    Arithmetic<float> ar2(1.5,1.2);
    cout<<ar2.add();
}