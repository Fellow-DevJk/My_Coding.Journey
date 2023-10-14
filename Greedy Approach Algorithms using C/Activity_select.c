#include <stdio.h>
#include <stdlib.h>
int activity_count=0;
typedef struct
{
    int act_no;
    int start_time;
    int finish_time;
} Activity;

void Bubble_Sort(Activity *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ptr[i].finish_time > ptr[j].finish_time)
            {
                Activity temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

void Activity_Select(Activity *ptr, int n)
{
    int A[n];
    int index = 0,m=1,j=0;
    A[0] = ptr[0].act_no;
    activity_count += 1;
    printf("The processes that can be completed are: \n");
    //printf("%d ", ptr[0].act_no);
    for (int i = 1; i < n; i++)
    {
        if (ptr[i].start_time >= ptr[index].finish_time)
        {
            //printf("%d ", ptr[i].act_no);
            A[m] = ptr[i].act_no;
            m++;
            index = i;
            activity_count += 1;
        }
    }
    while(A[j] != 0){
        printf("Activity %d\n", A[j]);
        j++;
    }
    printf("The no. of activities selected are: %d", activity_count);
}

int main()
{
    printf("Enter the no. of activities there are: ");
    int n;
    scanf("%d", &n);
    Activity *arr = malloc(n * sizeof(Activity));
    printf("Enter the start and the finish times of the activities respectively: ");
    for (int i = 0; i < n; i++)
    {
        arr[i].act_no = i + 1;
        scanf("%d %d", &arr[i].start_time, &arr[i].finish_time);
    }
    Bubble_Sort(arr, n);
    Activity_Select(arr, n);
    free(arr);
    return 0;
}