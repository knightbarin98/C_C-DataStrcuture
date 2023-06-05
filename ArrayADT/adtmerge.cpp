#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are: \n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int value)
{   
    if(arr->length < arr ->size )
    {
        arr->A[arr->length++] = value;
    } 
}

void Insert(struct Array *arr, int index, int value)
{
    if(index<0 || index >= arr->length) return;
    int i;
    for(i=arr->length; i>index; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = value;
    arr->length++;
}

int Delete(struct Array *arr, int index)
{
    int deletedValue = 0;
    
    if(index>=0 && index < arr->length)
    {
        deletedValue = arr->A[index];
        for(int i = index; i< arr->length-1;i++)
        {
            arr->A[i] = arr->A[i+1];
        }

        arr->length--;
    }

    return deletedValue;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;        
    }
    return -1;
}

int RBinarySearch(struct Array arr, int l, int h, int key)
{
    if(l <= h)
    {
        int mid = (l+h)/2;
        if(key = arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return RBinarySearch(arr, l, mid-1, key );
        else
            return RBinarySearch(arr, mid+1, h, key);       
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }

    return -1;
}

void Set(struct Array *arr, int index, int value)
{
    if(index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
}

int Max (struct Array arr)
{
    int max = arr.A[0];
    for(int i =1; i< arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min (struct Array arr)
{
    int min = arr.A[0];
    for(int i =1; i< arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int total = 0;
    for(int i = 0; i<arr.length; i++)
    {
        total += arr.A[i];
    }

    return total;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B = (int *) malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j]=arr->A[i];
    }

    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=B[i]; 
    }
}

void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array * Merge(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(;i< arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for(;j< arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length= arr1->length + arr2->length;
    arr3->size = k;
    
    return arr3;        
}

int main()
{
    struct Array arr1 = {{2,6,10,15,25},20,5};
    struct Array arr2 = {{3,4,7,18,20},20,5};
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);

    return 0;
}