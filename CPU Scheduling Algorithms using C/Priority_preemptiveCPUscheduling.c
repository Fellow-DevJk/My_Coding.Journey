#include <stdio.h>
#include <stdlib.h>
// Creating a structure to contain the id arrival time, burst time and priority of the process
typedef struct
{
    int id;
    int arrival;
    int burst;
    int priority;
}Process;
// Sorting the process given by the user according to their arrival times
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
    Process *cpu = malloc(input * sizeof(Process)); // Creating an array of processes
    printf("Enter your id, arrival time and burst and priority: ");
    for (int i = 0; i < input; i++)
    { // taking the input process id, the arrival, burst time and the priority of the process from the user
        scanf("%d %d %d", &cpu[i].id, &cpu[i].arrival, &cpu[i].burst);
        total_time += cpu[i].burst;
    }
    Bubble_Sort(cpu, input);
    int *remaining = malloc(input * sizeof(int)); // creating an array for containing the remaining times after the process is preempted or over
    int *completion = calloc(input, sizeof(int)); // using calloc to initialise all the values at address to be 0
    int turnaround[input], waiting[input];        // creating arrays for containing the turnaround and waiting time of all the processes
    for (int i = 0; i < input; i++)
    {
        remaining[i] = cpu[i].burst;
    }
    int current_time = 0;
    int empty = 0; // No. of processes that have been completed
    while (empty != input) // running till all processes are completed
    {
        int max_index = -1, maximum = -1;
        for (int i = 0; i < input; i++)
        { // checking for arrival times then finding the process with the highest priortity
            if (cpu[i].arrival <= current_time && remaining[i] > 0 && cpu[i].priority > maximum)
            {
                maximum = cpu[i].priority;
                max_index = i;
            }
        }
        if (max_index != -1)
        {
            remaining[max_index] -= 1; // running the process till it gets preempted over
            current_time++;
            completion[max_index] = current_time;
            if (remaining[max_index] == 0)
            {
                empty++; // incrementing the no.of processes completed
            }
        }
        else
        {
            current_time++; // for when CPU is idle
        }
    }
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    float avg_turnaround = 0.0, avg_waiting = 0.0;
    for (int i = 0; i < input; i++)
    { // Calculating the turnaround and waiting times and simultaneously printing it
        turnaround[i] = completion[i] - cpu[i].arrival;
        waiting[i] = turnaround[i] - cpu[i].burst;
        avg_turnaround += turnaround[i];
        avg_waiting += waiting[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", cpu[i].id, cpu[i].arrival, cpu[i].burst, cpu[i].priority, completion[i], turnaround[i], waiting[i]);
    }
    avg_turnaround /= input;
    avg_waiting /= input;
    printf("Total Time: %d\n", total_time);
    printf("Average Time: %.2f\n", (float)total_time / input);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
    // freeing the dynamically allocated memory to avoid memory leaks
    free(remaining);
    free(completion);
    free(cpu);

    return 0;
}
