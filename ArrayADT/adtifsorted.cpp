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

void InsertSort(struct Array *arr, int value)
{   
    int i = arr->length -1;
    if(arr->length == arr->size) 
        return;
    while(i>= 0 && arr->A[i]>value)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = value;
    arr->length++;    

}

int isSorted(struct Array arr)
{
    for(int i=0; i < arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void REarrange(struct Array *arr)
{
    int i=0, j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;
        if(i<j)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

int main()
{
    struct Array arr = {{2,3,5,10, 15},20,5};
    struct Array arr2 = {{2,-3,25,10,-15,-7},20,5};
    /*int n,i;

    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    arr.A = (int *) malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter all elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length = n;*/

    /*Append(&arr,10);
    Display(arr);
    Insert(&arr,3,13);
    Display(arr);
    int x = Delete(&arr,3);
    printf("Deleted value %d\n", x);
    Display(arr);
    int value = LinearSearch(&arr,4);
    printf("%d\n", value);
    Display(arr);
    printf("%d\n", BinarySearch(arr, 15));
    printf("%d\n", RBinarySearch(arr,0, arr.length,5));
    printf("Get: %d\n", Get(arr,2));
    printf("Get: \n");
    Set(&arr,3,15);
    Display(arr);
    printf("Max: %d\n", Max(arr));
    printf("Min: %d\n",Min(arr));
    printf("Sum: %d\n",Sum(arr));
    printf("Avg: %2f\n",Avg(arr));
    printf("Reverse\n");
    Reverse(&arr);
     Display(arr);
    Reverse2(&arr);
    Display(arr);*/

    InsertSort(&arr, 12);
    Display(arr);
    printf("isSorted: %d \n", isSorted(arr));
    REarrange(&arr2);
    Display(arr2);

    return 0;
}