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

int searchitem(int ele)
{
    struct node* temp ;
    temp = head;
    while (temp != 0)
    {
        if (temp->value == ele)
            return 1 ;          //element is found
        temp = temp->next;
    }
    return 0 ;
}



void printReverse(struct node* head)  //print the linked list in reverse way using recursion
{
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d->", head->value);
}

void reverselist()    //reverse the linked list
{
    struct node* prev=NULL;
    struct node* cur=head;
    struct node* nxt;
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    head=prev;      //points the head pointer to prev as it the new head or beginning in reverse list
}

void sum()    //sum of elements of the linked list
{

}


int main()
{
    init();

    int ch,element;
    while(1)
    {
        printf("\n1. Insert new item. 3. Search item. 5. Print. 9.Print Linked List in Reverse way. 10.Sum 11.Make the linked list reverse 12.Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
        }

        else if(ch==3)
        {
            int se,reply;
            printf("enter element to search ");
            scanf("%d",&se);
            reply=searchitem(se);
            if(reply==1)
                printf("element found\n");
            else
                printf("element not found\n");
        }

        else if(ch==5)
        {
            print();
        }


        else if(ch==9)
        {
            printReverse(head);
        }
        else if(ch==10)
        {
            sum();
        }
        else if(ch==11)
        {
            reverselist();
        }
        else if(ch==12)
            return 0;
        else
            return 0;
    }
    return 0;
}
