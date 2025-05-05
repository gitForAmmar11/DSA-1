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

int peek() {
        if (top == NULL) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // You can define a specific value to indicate underflow if needed.
        }
        return top->value;
}


    int isEmpty() {
        return top == NULL;
    }

int main() {

    push(10);
    push(20);
    push(30);

    cout << "Top element: " << peek() << endl;

    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;

    push(40);
    cout << "Top element: " << peek() << endl;

    cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
