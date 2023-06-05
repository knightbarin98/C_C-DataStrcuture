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
    int x = Delete(&arr,3);
    printf("Deleted value %d\n", x);
    Display(arr);
    int value = LinearSearch(&arr,4);
    printf("%d\n", value);
    Display(arr);

    return 0;
}