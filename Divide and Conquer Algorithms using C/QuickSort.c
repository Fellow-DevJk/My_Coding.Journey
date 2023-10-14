#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int* arr, int low, int high)
{
    int i = low, j = high;
    int Pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= Pivot && i < high)
        {
            i++;
            
        }
        while (arr[j] > Pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void QuickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int j = Partition(arr, low, high);
        QuickSort(arr, low, j - 1);
        QuickSort(arr, j + 1, high);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int low = 0, high = n-1;
    QuickSort(arr, low, high);
    printf("after sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}