#include <stdio.h>
#include <stdlib.h>

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

int Binary_Search(int *arr, int n, int x)
{
    int i = 0, mid;
    int j = n - 1;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (*(arr + mid) == x)
        {
            return i + 1;
        }
        else if (*(arr + mid) < x)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &x);
    Bubble_Sort(arr, n);
    int result = Binary_Search(arr, n, x);
    (result != -1) ? printf("Element %d found in the array at %d position", x, result) : printf("Element %d not found in the array", x);
    free(arr);
    return 0;
}
