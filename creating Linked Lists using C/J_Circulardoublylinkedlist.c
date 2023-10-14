#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void ins_beg(struct node *);
void del_beg();
void trav_beg();
void ins_end(struct node *);
void del_end();
void trav_end();
struct node *head = NULL;
int main()
{
    struct node *ptr;
    int choice;
    while (1)
    {
        printf("1.Insert at beginning  2.delete from  beginning  3.Traverse from beginning  4.Insert at the end  5.Delete from end  6.traverse from end  7.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ptr = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &ptr->data);
            ptr->next = NULL;
            ptr->prev = NULL;
            ins_beg(ptr);
            break;
        case 2:
            del_beg();
            break;
        case 3:
            trav_beg();
            break;
        case 4:
            ptr = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &ptr->data);
            ptr->next = NULL;
            ptr->prev = NULL;
            ins_end(ptr);
            break;
        case 5:
            del_end();
            break;
        case 6:
            trav_end();
            break;
        default:
            exit(1);
        }
    }
}
void ins_beg(struct node *new1)
{
    struct node *temp = head;
    if (head == NULL)
    {
        head = new1;
        new1->next = head;
        head->prev = new1;
    }
    else
    {
        new1->next = head;
        head->prev = new1;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new1;
        head = new1;
    }
}
void del_beg()
{
    struct node *t1, *t2;
    t1 = head;
    t2 = head;
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        while (t1->next != head)
        {
            t1 = t1->next;
        }
        head = head->next;
        head->prev = t1;
        t1->next = head;
        free(t2);
        t2 = NULL;
    }
}
void trav_beg()
{
    struct node *t2 = head;
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while (t2->next != head)
        {
            printf("%d ", t2->data);
            t2 = t2->next;
        }
        printf("%d\n", t2->data);
    }
}
void ins_end(struct node *new1)
{
    struct node *temp = head;
    if (head == NULL)
    {
        head = new1;
        new1->next = head;
        head->prev = new1;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new1;
        new1->prev = temp;
        new1->next = head;
        head->prev = new1;
    }
}
void del_end()
{
    struct node *temp1, *temp2;
    temp1 = head;
    temp2 = head;
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp1->next != head)
        {
            temp1 = temp1->next;
        }
        while (temp2->next != temp1)
        {
            temp2 = temp2->next;
        }
        temp2->next = head;
        head->prev = temp2;
        free(temp1);
        temp1 = NULL;
    }
}
void trav_end()
{
    struct node *t3 = head;
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while (t3->next != head)
        {
            t3 = t3->next;
        }
        while (t3 != head)
        {
            printf("%d ", t3->data);
            t3 = t3->prev;
        }
        printf("%d\n", t3->data);
    }
}