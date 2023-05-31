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

int main()
{
    struct Array arr = {{2,3,4,5,6},20,5};
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

    Append(&arr,10);
    Display(arr);
    Insert(&arr,3,13);
    Display(arr);

    return 0;
}