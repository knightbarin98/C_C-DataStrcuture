#include<iostream>

class Array
{
    private:
        int *A;
        int size;
        int length;
    public:
        Array()
        {
            size = 10;
            length = 0;
            A = new int[10];
        }
        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array()
        {
            delete []A;
        }
        void Display();
        void Insert(int index, int value);
        void Delete(int index);
};

int main( int argc, const char * argv[])
{
    return 0;
}