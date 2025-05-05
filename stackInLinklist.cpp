#include<iostream>
using namespace std;

struct Node {
int value;
struct Node* next;
};

struct Node* top;
void push(int data){
	struct Node* temp;
temp = (struct Node *)malloc(sizeof(struct Node));

// Check if memory(heap) is full.
 if (!temp){
cout << "\n Heap Overflow";
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
cout << "\n Stack Underflow" << endl;
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
    push(20);
    push(1);
    push(15);
    push(25);
    //pop();

    struct Node* temp = top;

    while(temp!=NULL){
        cout << temp->value <<  endl;
        temp = temp->next;
    }

return 0;
}

