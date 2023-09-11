#include <stdio.h>
#include <stdlib.h>

// Creating a structure to contain all the information related to the process
struct Process
{
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

// Sorting the process given by the user according to their arrival times
void Bubble_Sort(struct Process *cpu, int inputs)
{
    for (int i = 0; i < inputs; i++)
    {
        for (int j = i + 1; j < inputs; j++)
        {
            if (cpu[i].arrival > cpu[j].arrival)
            {
                struct Process temp = cpu[i];
                cpu[i] = cpu[j];
                cpu[j] = temp;
            }
        }
    }
}
int main()
{
    int inputs;

    printf("Enter the number of processes you want to run: ");
    scanf("%d", &inputs);

    struct Process *cpu = malloc(inputs * sizeof(struct Process));

    printf("Enter process id & arrival and burst times for each process:\n");//taking the input process id, the arrival and burst time from the user
    for (int i = 0; i < inputs; i++)
    {
        scanf("%d %d %d", &cpu[i].id, &cpu[i].arrival, &cpu[i].burst);
    }

    Bubble_Sort(cpu, inputs);

    int total_time = 0;
    float avg_turnaround = 0.0, avg_waiting = 0.0;

    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    //Logics to calculate the completion,turnaround and waiting times
    for (int i = 0; i < inputs; i++)
    {
        if (total_time < cpu[i].arrival)
        {
            total_time = cpu[i].arrival;
        }
        total_time += cpu[i].burst;
        cpu[i].completion = total_time;
        cpu[i].turnaround = cpu[i].completion - cpu[i].arrival;
        cpu[i].waiting = cpu[i].turnaround - cpu[i].burst;
        avg_turnaround += cpu[i].turnaround;
        avg_waiting += cpu[i].waiting;
    // In the same loop simultaneously making a table containing all the information of the process
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", cpu[i].id, cpu[i].arrival, cpu[i].burst, cpu[i].completion, cpu[i].turnaround, cpu[i].waiting);
    }

    avg_turnaround /= inputs;
    avg_waiting /= inputs;

    printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avg_waiting, avg_turnaround);

    free(cpu); //freeing the dynamically allocated memory to avoid memory leaks
    return 0;
}
