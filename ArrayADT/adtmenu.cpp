#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
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

struct Array * Union(struct Array *arr1, struct Array *arr2)
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
        else if( arr2->A[j]< arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for(;i< arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for(;j< arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length= k;
    arr3->size = k;
    
    return arr3;        
}

struct Array * Intersection(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if( arr2->A[j]< arr1->A[i])
        {
            j++;
        }
        else if ( arr2->A[j] == arr1->A[i])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length= k;
    arr3->size = k;
    
    return arr3;        
}

struct Array * Difference(struct Array *arr1, struct Array *arr2)
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
        else if( arr2->A[j]< arr1->A[i])
        {
            j++;
        }
        else if ( arr2->A[j] == arr1->A[i])
        {
            i++;
            j++;
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length= k;
    arr3->size = k;
    
    return arr3;        
}

int main()
{
    struct Array arr1;
    int ch;
    int x, index;
    printf("Enter size of Array:");
    scanf("%d\n", &arr1.size);
    arr1.A = (int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;
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
                Insert(&arr1, index, x);
                break;
            case 2:
                printf("Enter index");
                scanf("%d\n", &index);
                Delete(&arr1, index);
                break;
            case 3:
                printf("Enter an element to search");
                scanf("%d\n", &x);
                index = LinearSearch(&arr1,x);
                printf("Element index %d\n", index);
                break;
            case 4:
                printf("Sum is : %d\n", Sum(arr1));
                break;
            case 5:
                Display(arr1);
                break;                
        }
    } while (ch < 6);
    
    return 0;
}