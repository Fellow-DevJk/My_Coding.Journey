#include <stdio.h>
#include <stdlib.h>
// Creating a structure to contain the id arrival time and burst time
struct Process
{
    int id;
    int arrival;
    int burst;
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
    printf("Enter how many processes do you want: ");
    int input;
    int total_time = 0;
    scanf("%d", &input);
    struct Process *cpu = malloc(input * sizeof(struct Process)); // Creating an array of processes
    printf("Enter your id, arrival time and burst: ");
    for (int i = 0; i < input; i++)
    {
        scanf("%d %d %d", &cpu[i].id, &cpu[i].arrival, &cpu[i].burst); // taking the input process id, the arrival and burst time from the user
        total_time += cpu[i].burst;
    }
    Bubble_Sort(cpu, input);
    int *completion = calloc(input, sizeof(int)); // using calloc to initialise all the values at address to be 0
    int turnaround[input], waiting[input];        // creating arrays for containing the turnaround and waiting time of all the processes
    int current_time = 0;
    int empty = 0; // No. of processes that have been completed
    float avg_turnaround = 0.0, avg_waiting = 0.0;

    while (empty < input) // running till all processes are completed
    {
        int min_index = -1, minimum = total_time;

        for (int i = 0; i < input; i++)
        {
            if (cpu[i].arrival <= current_time && completion[i] <= 0 && cpu[i].burst < minimum) // checking for arrival times then finding the shortest burst time
            {
                min_index = i;
                minimum = cpu[i].burst;
            }
        }
        if (min_index != -1)
        {
            completion[min_index] = current_time + cpu[min_index].burst; // running the process till it gets completed
            current_time = completion[min_index];                        // current time will change to the time a process was completed
            empty++;                                                     // incrementing the no.of processes completed
        }
        else
        {
            current_time++; // for when CPU is idle
        }
    }
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < input; i++)
    { // Calculating the turnaround and waiting times and simultaneously printing it
        turnaround[i] = completion[i] - cpu[i].arrival;
        waiting[i] = turnaround[i] - cpu[i].burst;
        avg_turnaround += turnaround[i];
        avg_waiting += waiting[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", cpu[i].id, cpu[i].arrival, cpu[i].burst, completion[i], turnaround[i], waiting[i]);
    }
    avg_turnaround /= input;
    avg_waiting /= input;
    printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avg_waiting, avg_turnaround);

    // freeing the dynamically allocated memory to avoid memory leaks
    free(completion);
    free(cpu);

    return 0;
}
