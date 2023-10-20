// Single Linked-List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void ins_beg(struct node *);
void del_beg();
void traverse();
void ins_end(struct node *);
void del_end();
void reverse_ll_iterate();
void reverse_ll_recurse(struct node *);

int main()
{
    struct node *ptr;
    int choice;
    while (1)
    {
        printf("1.Insert from Beginning  2.Delete from Beginning  3.Traverse  4.Insert from end  5.Delete from end  6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ptr = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &ptr->data);
            ptr->next = NULL;
            ins_beg(ptr);
            break;
        case 2:
            del_beg();
            break;
        case 3:
            traverse();
            break;
        case 4:
            ptr = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &ptr->data);
            ptr->next = NULL;
            ins_end(ptr);
            break;
        case 5:
            del_end();
            break;
        case 6:
            reverse_ll_iterate();
            break;
        case 7:
            reverse_ll_recurse(head);
            break;
        default:
            exit(1);
        }
    }
}
void ins_beg(struct node *new1)
{
    if (head == NULL)
    {
        head = new1;
    }
    else
    {
        new1->next = head;
        head = new1;
    }
}
void del_beg()
{
    struct node *t = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        head = head->next;
        free(t);
        t = NULL;
    }
}
void traverse()
{
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        struct node *t1 = head;
        while (t1 != NULL)
        {
            printf("%d\n", t1->data);
            t1 = t1->next;
        }
    }
}
void ins_end(struct node *new1)
{
    struct node *temp = head;
    if (head == NULL)
    {
        head = new1;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new1;
    }
}
void del_end()
{
    struct node *temp, *temp1;
    temp = head;
    temp1 = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp1->next != temp)
        {
            temp1 = temp1->next;
        }
        temp1->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void reverse_ll_iterate(){
    struct node *current = head, *prev = NULL, *temp;
    if(head==NULL){
        printf("Empty");
    }
    else{
        while(current!=NULL){
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
}

void reverse_ll_recurse(struct node *ptr)
{
    if(ptr->next==NULL){
        head = ptr;
        return;
    }
    reverse_ll_recurse(ptr->next);
    struct node *temp = ptr->next;
    temp->next = ptr;
    ptr->next = NULL;
}
