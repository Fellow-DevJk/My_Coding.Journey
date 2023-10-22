#include <stdio.h>
#include <stdlib.h>

int current_time;//to keep the track of time
int arrival_count = 0;//to keep track if all processes have arrived or not

typedef struct
{
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
} Task;

typedef struct rq
{//structure of the node of the Ready Queue which will be maintained as a circular linked list 
    Task data;
    struct rq *next;
} Ready_Queue;

Ready_Queue *front = NULL;//points to the 1st element of the queue
Ready_Queue *rear = NULL;//points to the last element of the queue

void enqueue(Task process);// adds the element to the last of the queue
void dequeue();//removes the first element of the queue (FIFO)
void Arrival_Check(Task *cpu, int input);//checks whether a process is arriving or not and if it is enqueues it in the queue
void Bubble_Sort(Task *cpu, int inputs);//sorts the process according to the arrival times
void Calculations(Task *cpu, int inputs);//calculates the completion, turnaround and waiting times
void PrintData(Task *cpu, int input);//prints all the data on the output console

int main()
{
    printf("Enter how many processes do you want and enter the time quantum: ");
    int input, time_quantum;
    scanf("%d %d", &input, &time_quantum);
    Task *cpu = malloc(input * sizeof(Task));// a struct array consisting of all the processes
    if (cpu == NULL)
    {//error handling
        perror("Failed to allocate memory");
        exit(1);
    }
    printf("Enter your id, arrival time, and burst: ");
    for (int i = 0; i < input; i++)
    {//taking the input from the user and intitalising the completion, turnaround and waiting times
        scanf("%d %d %d", &cpu[i].id, &cpu[i].arrival, &cpu[i].burst);
        cpu[i].completion = 0;
        cpu[i].turnaround = 0;
        cpu[i].waiting = 0;
    }
    Bubble_Sort(cpu, input);
    current_time = 0;
    int remaining_processes = input;//keeps track of remaining processes

    while (remaining_processes > 0)
    {//this loop runs till all processes have completed their execution
        Arrival_Check(cpu, input);

        if (front != NULL)//if the queue is not empty
        {
            if (front->data.burst <= time_quantum)
            {//if the burst time of the process is less than equal to the time quantum we completely execute the process and remove it from the queue
                current_time += front->data.burst;
                front->data.completion = current_time;
                // printf("%d ", current_time);
                Calculations(cpu, input);
                dequeue();
                remaining_processes -= 1;
            }
            else
            {//if the burst time is more than time quantum we run it for its time quantum and remove it from the queue and add it to the end
                current_time += time_quantum;
                front->data.burst -= time_quantum;
                Arrival_Check(cpu, input);
                if (front->next != NULL)
                {
                    enqueue(front->data);
                    dequeue();
                }
            }
        }
        else
        {//for handling when there are no processes in the queue
            current_time++;
        }
    }
    PrintData(cpu, input);
    free(cpu);
    return 0;
}

void enqueue(Task process)
{
    Ready_Queue *node = malloc(sizeof(Ready_Queue));
    node->data = process;
    node->next = NULL;
    if (rear == NULL)
    {
        rear = front = node;
        node->next = front;
    }
    else
    {
        rear->next = node;
        rear = node;
        node->next = front;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        return; // Queue is empty, nothing to dequeue
    }
    Ready_Queue *temp = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    free(temp);
    temp = NULL;
}
void Arrival_Check(Task *cpu, int input)
{
    if (arrival_count < input)
    {
        while (cpu[arrival_count].arrival <= current_time)
        {
            enqueue(cpu[arrival_count]);
            arrival_count++;
        }
    }
    else
    {
        return;
    }
}
void Bubble_Sort(Task *cpu, int inputs)
{
    for (int i = 0; i < inputs; i++)
    {
        for (int j = i + 1; j < inputs; j++)
        {
            if (cpu[i].arrival > cpu[j].arrival)
            {
                Task temp = cpu[i];
                cpu[i] = cpu[j];
                cpu[j] = temp;
            }
        }
    }
}
void Calculations(Task *cpu, int inputs){
    for (int j = 0; j < inputs; j++)
    {
        if (front->data.id == cpu[j].id)
        {
            cpu[j].completion = front->data.completion;
            cpu[j].turnaround = cpu[j].completion - cpu[j].arrival;
            cpu[j].waiting = cpu[j].turnaround - cpu[j].burst;
        }
    }
}
void PrintData(Task *cpu, int input){
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    float avg_turnaround = 0.0, avg_waiting = 0.0;
    for (int i = 0; i < input; i++)
    {
        avg_turnaround += cpu[i].turnaround;
        avg_waiting += cpu[i].waiting;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", cpu[i].id, cpu[i].arrival, cpu[i].burst, cpu[i].completion, cpu[i].turnaround, cpu[i].waiting);
    }

    avg_turnaround /= input;
    avg_waiting /= input;

    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}
