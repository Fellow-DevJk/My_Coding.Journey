#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void ins_beg(struct node *);
void del_beg();
void trav_beg();
void ins_end(struct node *);
void del_end();
struct node *head=NULL;
int main(){
    struct node *ptr;
    int choice;
    while(1){
        printf("1.Insert at beginning  2.Delete at beginning  3.Traverse from beginning  4.Insert at the end  5.Delete at the end  6.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            ptr=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&ptr->data);
            ptr->next=NULL;
            ins_beg(ptr);
            break;
        case 2: del_beg();
            break;
        case 3: trav_beg();
            break;
        case 4:
            ptr=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&ptr->data);
            ptr->next=NULL;
            ins_end(ptr);
            break;
        case 5: del_end();
            break;
        default:
            exit(1);
        }
    }
}
void ins_beg(struct node *new1){
    struct node *temp=head;
    if(head==NULL){
        head=new1;
        new1->next=head;
    }
    else{
        new1->next=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new1;
        head=new1; 
    }
}
void del_beg(){
    struct node *t1,*t2;
    t1=head;t2=head;
    if(head==NULL){
        printf("Empty\n");
    }
    else if(head->next==head){
        // free(head);
        head=NULL;
    }
    else{
        while(t1->next!=head){
            t1=t1->next;
        }
        head=head->next;
        t1->next=head;
        free(t2);
        t2=NULL;
    }
}
void trav_beg(){
    struct node *t2=head;
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        do{
            printf("%d\n",t2->data);
            t2=t2->next;
        } while(t2!=head);
    }
}
void ins_end(struct node *new1){
    struct node *temp=head;
    if(head==NULL){
        head=new1;
        new1->next=head;
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new1;
        new1->next=head;
    }
}
void del_end(){
    struct node *temp1,*temp2;
    temp1=head;
    temp2=head;
    if(head==NULL){
        printf("Empty\n");
    }
    else if(head->next==head){
       // free(head);
        head=NULL;
    }
    else{
        while(temp1->next!=head){
            temp1=temp1->next;
        }
        while(temp2->next!=temp1){
            temp2=temp2->next;
        }
    temp2->next=head;
    temp1->next=NULL;
    free(temp1);
    temp1=NULL;
    }
}
