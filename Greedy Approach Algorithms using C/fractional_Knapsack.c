#include <stdio.h>
#include <stdlib.h>
//creating a structure of items
typedef struct
{
    int item_no;
    float weight;
    float profit;
    float ratio;
    float fraction_in_Knapsack;
}Item;
//sorting the items according to the descending order of their ratio of profit/weight
void Bubble_Sort(Item *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ptr[i].ratio < ptr[j].ratio)
            {
                Item temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

int minimum(float *a, float *b)
{
    if (*a > *b)
    {
        return *b;
    }
    else
    {
        return *a;
    }
}

int main()
{
    printf("No. of Items present & the capacity of the Knapsack: ");
    int n, x = 0;

    float total_profit=0.0,W;
    scanf("%d %f", &n, &W);
    Item *arr = malloc(n * sizeof(Item));//creating an array of all the items
    printf("Enter the weight and profit of the item: ");
    for (int i = 0; i < n; i++)
    {//taking the weight and profit of each item from the user
        arr[i].item_no = i + 1;
        scanf("%f %f", &arr[i].weight, &arr[i].profit);
        arr[i].ratio = arr[i].profit / arr[i].weight;
        arr[i].fraction_in_Knapsack = 0.0;
    }
    Bubble_Sort(arr, n);
    float amount=0.0;
    while (W > 0.0) // iterating till all the knapsack doesn't have more capacity left
    { 
        amount = minimum(&W, &arr[x].weight);
        if (amount == arr[x].weight)
        { // if the remaining weight of the knapsack is more than the item's weight than pick up the whole item
            arr[x].fraction_in_Knapsack = 1.0;
        }
        else 
        {//else pick up a fraction of the item
            arr[x].fraction_in_Knapsack = (W / arr[x].weight);
        }
        total_profit += (arr[x].fraction_in_Knapsack * arr[x].profit);//calculating the total profit after each item is picked
        W -= amount ;//reducing the remaining capacity of knapsack after each item is picked
        x++;
    }
    printf("Item No\tOriginal weight\tOriginal Profit\tWeight in Knapsack Actual Profit Earned\n");
    for (int i = 0; i < n;i++){//Printing all the details of the item
        printf("%d\t\t%.2f\t\t%.2f\t\t", arr[i].item_no, arr[i].weight,arr[i].profit);
        if(arr[i].fraction_in_Knapsack==1){
            printf("%.2f\t\t%.2f\n", arr[i].weight,arr[i].profit);
        }
        else{
            printf("%.2f\t\t%.2f\n", (arr[i].weight * arr[i].fraction_in_Knapsack), (arr[i].profit * arr[i].fraction_in_Knapsack));
        }
    }
    printf("The total profit earned %.2f", total_profit);
    free(arr);
    return 0;
}
