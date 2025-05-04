#include<stdio.h>
#include<stdlib.h>

struct node     //make node for linked list using structure
{
    int value;             //value part of node contains the element
    struct node *next;    //the next part of node contains the address of next element of list
};

struct node *head;    //contains the address of first element of linked list

void init()
{
    head=NULL;    //initialize the beginning(head) of list to NULL
}

void insertfirst(int element)    //inserts element in linked list
{
    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));    //New named node declared with size of node declared before
    New->value=element;       //inserts the new element to the value part of node New
    New->next=NULL;          //makes the next part of node New NULL so that no garbage value remains
    New->next=head;         //the address of previously first node, which was stored in head is now assigned to next part of node New
    head=New;              //the address of new first element which is present in node New is assigned to head node
}

void print()
{
    if(head==NULL)    //condition to check whether list is empty
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur=head;
    int count;
    count=0;
    while(cur!=NULL)                  //the loop traverse until it gets any NULL node
    {
        printf("%d->",cur->value);
        count++;                       //counts the number of nodes or elements present in list
        cur=cur->next;                //moves cur pointer to next node to check and get value
    }
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}

void deleteitem(int ele)
{
    if (head == NULL) //list empty
        return;
    struct node *cur = head;
    struct node *prev = NULL;

    while (cur->value != ele)
    {
        prev = cur;
        cur=cur->next;
    }
    if (prev != NULL)
        prev->next = cur->next;
    else head = NULL;

    free(cur);
}

void deletelast()   //delete the last element
{
    if(head==NULL)
    {
        printf("list is empty and nothing to delete\n");
    }
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev->next!=NULL)
        prev->next=NULL;
    free(cur);
}

void deletefirst()    //delete the first element
{
    struct node* cur;
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    cur=head;
    head=head->next;
    free(cur);
}

int main()
{
    init();

    int ch,element;
    while(1)
    {
        printf("\n1. Insert new item. 2. Delete item. 3. Print. 4.Delete Last 5.Delete First 6.Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
        }
        else if(ch==2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d",&de);
            deleteitem(de);
        }

        else if(ch==3)
        {
            print();
        }
        else if(ch==4)
        {
            deletelast();
        }
        else if(ch==5)
        {
            deletefirst();
        }

        else if(ch==6)
            return 0;
        else
            return 0;
    }
    return 0;
}

