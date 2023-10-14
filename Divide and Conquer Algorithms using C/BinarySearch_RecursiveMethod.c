#include <stdio.h>
#include <malloc.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Bubble_Sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int Binary_Search(int *arr, int i, int j, int x)
{
    if (i <= j)
    {
        int mid = (i + j) / 2;
        if (*(arr + mid) == x)
        {
            return i+1;
        }
        else if (*(arr + mid) < x)
        {
            return Binary_Search(arr, mid + 1, j, x);
        }
        else
        {
            return Binary_Search(arr, i, mid - 1, x);
        }
    }
    return -1;
}

int main()
{
    int n, x;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &x);
    Bubble_Sort(arr, n);
    int result = Binary_Search(arr, 0, n - 1, x);
    (result != -1) ? printf("Element %d found in the array at %d position", x,result) : printf("Element %d not found in the array", x);
    free(arr);
    return 0;
}