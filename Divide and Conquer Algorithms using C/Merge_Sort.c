#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int low, int mid, int high,int n)
{
    int index_sub = low;
    int i = low;
    int j = mid + 1;
    int sub_arr[n];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            sub_arr[index_sub] = arr[i];
            i++;
        }
        else
        {
            sub_arr[index_sub] = arr[j];
            j++;
        }
        index_sub++;
    }

    if (i > mid)
    {
        for (int k = j; k <= high; k++)
        {
            sub_arr[index_sub] = arr[k];
            index_sub++;
        }
    }
    else
    {
        for (int k = i; k <= mid; k++)
        {
            sub_arr[index_sub] = arr[k];
            index_sub++;
        }
    }

    for (int x = low; x <= high; x++)
    {
        arr[x] = sub_arr[x];
    }
}

void Merge_Sort(int *arr, int low, int high,int n)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        Merge_Sort(arr, low, mid,n);
        Merge_Sort(arr, mid + 1, high,n);
        Merge(arr, low, mid, high,n);
    }
}

int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    Merge_Sort(arr, 0, n - 1,n);
    printf("After sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}