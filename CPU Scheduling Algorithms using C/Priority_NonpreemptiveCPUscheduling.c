#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int arrival;
    int burst;
    int priority;
}Process;

void Bubble_Sort(Process *cpu, int inputs)
{
    for (int i = 0; i < inputs; i++)
    {
        for (int j = i + 1; j < inputs; j++)
        {
            if (cpu[i].arrival > cpu[j].arrival)
            {
                Process temp = cpu[i];
                cpu[i] = cpu[j];
                cpu[j] = temp;
            }
        }
    }
}

int main()
{
    printf("Enter how many processes do you want: ");
    int input;
    int total_time = 0;
    scanf("%d", &input);
    Process cpu[input];
    // struct Process *cpu = malloc(input * sizeof(struct Process));
    printf("Enter your id, arrival time and burst and priority: ");
    for (int i = 0; i < input; i++)
    {
        scanf("%d %d %d %d", &cpu[i].id, &cpu[i].arrival, &cpu[i].burst, &cpu[i].priority);
        total_time += cpu[i].burst;
    }
    Bubble_Sort(cpu, input);
    int *completion = calloc(input, sizeof(int));
    int turnaround[input], waiting[input];
    int current_time = 0;
    int empty = 0; // No. of processes that have been completed
    float avg_turnaround = 0.0, avg_waiting = 0.0;

    while (empty < input)
    {
        int max_index = -1, maximum = -1;

        for (int i = 0; i < input; i++)
        {
            if (cpu[i].arrival <= current_time && completion[i] <= 0 && cpu[i].priority > maximum)
            {
                max_index = i;
                maximum = cpu[i].priority;
            }
        }
        if (max_index != -1)
        {
            completion[max_index] = current_time + cpu[max_index].burst;
            current_time = completion[max_index];
            empty++;
        }
        else
        {
            current_time++;
        }
    }
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < input; i++)
    {
        turnaround[i] = completion[i] - cpu[i].arrival;
        waiting[i] = turnaround[i] - cpu[i].burst;
        avg_turnaround += turnaround[i];
        avg_waiting += waiting[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", cpu[i].id, cpu[i].arrival, cpu[i].burst,cpu[i].priority, completion[i], turnaround[i], waiting[i]);
    }
    avg_turnaround /= input;
    avg_waiting /= input;
    printf("Total Time: %d\n", total_time);
    printf("Average Time: %.2f\n", (float)total_time / input);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);

    free(cpu);

    return 0;
}
