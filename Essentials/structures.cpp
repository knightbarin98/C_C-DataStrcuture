#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle 
{
    int length; //4 bytes in latest compilers
    int breatdth; //4 bytes
    char x; // 1 byte
}; 
// total size of is 12 bytes, easy for the machine read 4 in 4, it is call pairing, in structures it happens

struct complex 
{
    int real;
    int img;
};

struct student
{
    int id; // 4 bytes
    char name[25]; // 25 bytes
    char dept[10]; // 10 bytes
    char address[50]; // 50 bytes
};

struct card
{
    int face;
    int shape;
    int color;
//} r1, r2, r3;
};

//struct Rectangle r1,r2,r3;

int main (){
    /*struct Rectangle r; 
    struct Rectangle r = {10,5};
    r.length = 15;
    r.breatdth = 10;

    printf("Area of rectangle is %d\n", r.length * r.breatdth);

    struct student s;
    s.id = 2;
    s.name="Ivan";

    struct card c;
    c.face =1;
    c.shape=0;
    c.color=0;

    struct card cr = {1,0,0};

    //struct card deck[52];
    //struct card deck[52]={{1,0,0},{2,0,0}, ... {}};*/

    struct Rectangle r1 = {10,5};

    r1.length = 15;
    r1.breatdth = 7;

    //printf("%ld\n", sizeof(r1));
    cout<<r1.length<<endl;
    cout<<r1.breatdth<<endl;

    return 0;
}