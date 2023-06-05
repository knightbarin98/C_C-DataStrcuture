#include<stdio.h>
#include<stdlib.h>
#include<iostream>

class Array
{
    //data memebers
    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);
    public:
        Array() //constructor
        {
            size=10;
            length=0;
            A = new int[size];
        }
        Array(int sz)
        {
            size=sz;
            length=0;
            A = new int[size];
        }
        ~Array() //destructor
        {
            delete []A;
        }
        void Display();
        void Append( int value);
        void Insert( int index, int value);
        int Delete( int index);
        int LinearSearch( int key);
        int BinarySearch( int key);
        //int RBinarySearch( int l, int h, int key);
        int Get( int index);
        void Set( int index, int value);
        int Max ();
        int Min ();
        int Sum();
        float Avg();
        void Reverse();
        void Reverse2();
        Array * Merge(Array arr2);
        Array * Union(Array arr2);
        Array * Intersection(Array arr2);
        Array * Difference(Array arr2);            
};



void Array::Display()
{
    int i;
    printf("Elements are: \n");
    for(i=0;i<length;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void Array::Append(int value)
{   
    if(length < size )
    {
        A[length++] = value;
    } 
}

void Array::Insert(int index, int value)
{
    if(index<0 || index >= length) return;
    int i;
    for(i=length; i>index; i--)
    {
        A[i] = A[i-1];
    }
    A[index] = value;
    length++;
}

int Array::Delete(int index)
{
    int deletedValue = 0;
    
    if(index>=0 && index < length)
    {
        deletedValue = A[index];
        for(int i = index; i< length-1;i++)
        {
            A[i] = A[i+1];
        }

        length--;
    }

    return deletedValue;
}

void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int Array::LinearSearch( int key)
{
    for (int i = 0; i < length; i++)
    {
        if(key==A[i])
        {
            swap(&A[i],&A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int Array::BinarySearch( int key)
{
    int l, mid, h;
    l = 0;
    h = length;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;        
    }
    return -1;
}

/*int RBinarySearch( int l, int h, int key)
{
    if(l <= h)
    {
        int mid = (l+h)/2;
        if(key = A[mid])
            return mid;
        else if (key < A[mid])
            return RBinarySearch(arr, l, mid-1, key );
        else
            return RBinarySearch(arr, mid+1, h, key);       
    }
    return -1;
}*/

int Array::Get( int index)
{
    if(index >= 0 && index < length)
    {
        return A[index];
    }

    return -1;
}

void Array::Set( int index, int value)
{
    if(index >= 0 && index < length)
    {
        A[index] = value;
    }
}

int Array::Max ()
{
    int max = A[0];
    for(int i =1; i< length; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int Array::Min ()
{
    int min = A[0];
    for(int i =1; i< length; i++)
    {
        if(A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int Array::Sum()
{
    int total = 0;
    for(int i = 0; i<length; i++)
    {
        total += A[i];
    }

    return total;
}

float Array::Avg()
{
    return (float)Sum()/length;
}

void Array::Reverse()
{
    int *B;
    int i,j;
    B = (int *) malloc(length*sizeof(int));
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    }

    for(i=0;i<length;i++)
    {
        A[i]=B[i]; 
    }
}

void Array::Reverse2()
{
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        swap(&A[i],&A[j]);
    }
}

Array * Array::Merge(Array arr2)
{
    int i,j,k;
    i = j = k = 0;
    //struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }

    for(;i< length; i++)
        arr3->A[k++] = A[i];

    for(;j< arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    
    arr3->length= length + arr2.length;
    
    return arr3;        
}

Array *  Array::Union(Array arr2)
{
    int i,j,k;
    i = j = k = 0;
    //struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if( arr2.A[j]< A[i])
        {
            arr3->A[k++] = arr2.A[j++];
        }
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for(;i< length; i++)
        arr3->A[k++] = A[i];

    for(;j< arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    
    arr3->length= k;
    
    return arr3;        
}

Array * Array::Intersection(Array arr2)
{
    int i,j,k;
    i = j = k = 0;
    //struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length+arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])
        {
            i++;
        }
        else if( arr2.A[j]< A[i])
        {
            j++;
        }
        else if ( arr2.A[j] == A[i])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length= k;
    arr3->size = k;
    
    return arr3;        
}

Array * Array::Difference(Array arr2)
{
    int i,j,k;
    i = j = k = 0;
    //struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length+arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if( arr2.A[j]< A[i])
        {
            j++;
        }
        else if ( arr2.A[j] == A[i])
        {
            i++;
            j++;
        }
    }

    for(;i<length;i++)
        arr3->A[k++] = A[i];

    arr3->length= k;
    arr3->size = k;
    
    return arr3;        
}

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;
    printf("Enter size of Array:");
    scanf("%d\n", &sz);
    arr1 = new Array(sz);
    //arr1.A = (int *)malloc(arr1.size*sizeof(int));
    //arr1.length=0;
    do
    {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice:");
        scanf("%d\n", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter an element and index");
                scanf("%d%d\n", &x, &index);
                arr1->Insert(index, x);
                break;
            case 2:
                printf("Enter index");
                scanf("%d\n", &index);
                arr1->Delete(index);
                break;
            case 3:
                printf("Enter an element to search");
                scanf("%d\n", &x);
                index = arr1->LinearSearch(x);
                printf("Element index %d\n", index);
                break;
            case 4:
                printf("Sum is : %d\n", arr1->Sum());
                break;
            case 5:
                arr1->Display();
                break;                
        }
    } while (ch < 6);
    
    return 0;
}