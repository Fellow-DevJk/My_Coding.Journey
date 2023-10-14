#include <stdio.h>
#include <stdlib.h>
//Creating a structure containing the activity number, its start time and finish time
typedef struct
{
    int act_no;
    int start_time;
    int finish_time;
} Activity;
// creating a bubble sort function to sort accordind to the ascending order of the finish time
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
//function to select the activity and print the output on the console that which activities can be conducted
void Activity_Select(Activity *ptr, int n)
{
    int index = 0,j=0;
    printf("The processes that can be completed are: \n");
    printf("%d ", ptr[0].act_no);
    for (int i = 1; i < n; i++)
    {//Comparing the start time of the actvities from the previous earliest finish and whether they are overlappig or not
        if (ptr[i].start_time >= ptr[index].finish_time)
        {
            printf("%d ", ptr[i].act_no);
            index = i;
        }
    }
}

int main()
{
    printf("Enter the no. of activities there are: ");
    int n;
    scanf("%d", &n);
    Activity *arr = malloc(n * sizeof(Activity));//an array of activities
    printf("Enter the start and the finish times of the activities respectively: ");
    for (int i = 0; i < n; i++)
    {
        arr[i].act_no = i + 1;
        scanf("%d %d", &arr[i].start_time, &arr[i].finish_time);//taking input from the user
    }
    Bubble_Sort(arr, n);//sorting the activities
    Activity_Select(arr, n);
    free(arr);//freeing the dynamically allocated memory
    return 0;
}
