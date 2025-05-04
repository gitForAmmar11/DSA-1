#include<iostream>
using namespace std;

struct Node {
int value;
struct Node* next;
};

struct Node* top;

void push(int data) {
	struct Node* temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory(heap) is full.
     if (!temp){
    printf("\n Heap Overflow");
    exit(1);
    }
    temp->value = data;
    temp->next = top;
    top = temp;
}

int pop(){
    struct Node* temp;
    int data;
    if (top == NULL) {
    printf("\n Stack Underflow" );
    exit(1);
    }
    else {
    data = top->value;
    temp = top;
    top = top->next;
    free(temp);
    return data;
    }
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin>>s;

    bool flag=true;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='x')
        {
            flag=false;
        }
        else if(flag==true)
        {
            push(s[i]);
        }
        else{

            if(s[i]!=pop())
            {
                cout<<"Not a Palindrome"<<endl;
                return 0;
            }
        }

    }

    cout<<"Palindrome"<<endl;

    return 0;
}
