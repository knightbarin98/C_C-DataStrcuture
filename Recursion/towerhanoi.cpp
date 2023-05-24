#include<stdio.h>

void TOH(int disks, char inception, char aux, char reception)
{
    if(disks > 0)
    {
        TOH(disks-1,inception,reception, aux);
        printf("%c to %c\n", inception,reception);
        TOH(disks-1,aux,inception,reception);
    }   
}


int main()
{
    TOH(3,'A','B','C');
    return 1;
}