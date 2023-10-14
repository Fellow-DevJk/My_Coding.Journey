//Double-Linked list
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;   
};
struct node *head=NULL;
void ins_beg(struct node *);
void del_beg();
void ins_end(struct node *);
void del_end();
void trav_beg();
void trav_end();
int main(){
    struct node *ptr;
    int choice;
    while(1){
        printf("1.Insert from beginning  2.Delete from beginning  3.Insert from End  4.Delete from end  5.Traverse from beginning  6.Traverse from end  6.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            ptr=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&ptr->data);
            ptr->next=NULL;
            ptr->prev=NULL;
            ins_beg(ptr);
            break;
        case 2: del_beg();
            break;
        case 3:
            ptr=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&ptr->data);
            ptr->next=NULL;
            ptr->prev=NULL;
            ins_end(ptr);
            break;
        case 4: del_end();
            break;
        case 5: trav_beg();
            break;
        case 6: trav_end();
            break;
        default:
            exit(1); 
        }
    }
}
void ins_beg(struct node *new1){
    if(head==NULL){
        head=new1;
    }
    else{
        new1->next=head;
        head->prev=new1;  
        head=new1;
    }
}
void del_beg(){
    struct node *t1=head;
    if(head==NULL){
        printf("Empty\n");
    }
    else if(head->next==NULL){
        head = NULL;
    }
    else{
        head=head->next;
        head->prev = NULL;
        free(t1);
        t1=NULL;
    }
}
void ins_end(struct node *new1){
    struct node *temp=head;
    if(head==NULL){
        head=new1;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new1;
        new1->prev=temp;  
    }
}
void del_end(){
    struct node *temp1,*temp2;
    temp1=head;
    temp2=head;
    if(head==NULL){
        printf("Empty\n");
    }
    else if(head->next==NULL){
        head=NULL;
    }
    else{
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        while(temp2->next!=temp1){
            temp2=temp2->next;
        }
        temp2->next=NULL;
        free(temp1);
        temp1=NULL;
    }
}
void trav_end(){
    struct node *t2=head;
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        while(t2->next!=NULL){    
            t2=t2->next;          
        }
        while(t2!=NULL){
            printf("%d ",t2->data);
            t2=t2->prev;          
        }
    }
}
void trav_beg(){
    struct node *temp=head;
    if(head==NULL){
        printf("No Elements to show\n");
    }
    else{
        
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}