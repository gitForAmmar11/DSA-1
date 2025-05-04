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

void insertlast(int ele)    //insert at the last of linked list
{
    struct node *newItem;
    newItem = (struct node*)malloc (sizeof(struct node));

    if(head == NULL)
    {
        insertfirst(ele);
        printf("Data Inserted Successfully!\n");
    }
    else
    {
        newItem->value = ele;
        newItem->next = NULL;

        struct node *last = head;

        while(last->next != NULL)
            last = last->next;
        last->next = newItem;
        printf("Data Inserted Successfully!\n");
    }

}

void insertafter(int elem, int num)   //inserts element for any given element present in linked list
{
    struct node *newItem;
    newItem = (struct node*)malloc (sizeof(struct node));
    newItem->value = elem;
    newItem->next = NULL;

    struct node *prev = head;
    while((prev->value != num) && (prev->next != NULL)){
        prev = prev->next;
    }

    if(prev->next==NULL){
        printf("The element not found!\n");
    }
    else{
    newItem->next = prev->next;
    prev->next = newItem;
    }


}

int main()
{
    init();

    int ch,element;
    while(1)
    {
        printf("\n1. Insert new item. 4. Insert Last. 5. Print. 8.Insert After 12.Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
        }

        else if(ch==4)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d",&le);
            insertlast(le);
        }
        else if(ch==5)
        {
            print();
        }

        else if(ch==8)
        {
            int ie,p;
            printf("enter element to insert: ");
            scanf("%d",&ie);
            printf("enter after which element to insert: ");
            scanf("%d",&p);
            insertafter(ie,p);
        }

        else if(ch==12)
            return 0;
        else
            return 0;
    }
    return 0;
}

