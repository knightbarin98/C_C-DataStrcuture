#include<iostream>
using namespace std;

/*class Rectangle
{
    private:
        int length;
        int breadth;
    
    public:

        Rectangle()
        {
            length = breadth = 1;
        }

        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area();

        int perimeter();

        int getLength()
        {
            return length;
        }

        void setLength(int l)
        {
            length = l;
        }

        ~Rectangle();
};

//:: scope resolution
Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle::area()
{
    return length *  breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

Rectangle::~Rectangle()
{
    
}

int main()
{
    Rectangle r(10,5);
    cout<<r.area();
    cout<<r.perimeter();

    r.setLength(20);
    cout<<r.getLength();

    return 0;
}*/

class Rectangle
{
    private:
        int length;
        int breadth;
    
    public:

        Rectangle()
        {
            length = breadth = 1;
        }

        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area()
        {
            return length *  breadth;
        }

        int perimeter()
        {
            return 2 * (length + breadth);
        }

        int getLength()
        {
            return length;
        }

        void setLength(int l)
        {
            length = l;
        }

        ~Rectangle()
        {
            cout<<"Destructor";
        }
};


int main()
{
    Rectangle r(10,5);
    cout<<r.area();
    cout<<r.perimeter();

    r.setLength(20);
    cout<<r.getLength();

    return 0;
}