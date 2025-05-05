#include <iostream>

using namespace std;

int stack[100],top=-1;

void push(int x){
if(top>99)
cout<<"Stack overflow!";
else
top++;
stack[top] = x;
}

int pop()
{
int y;
if(top<=-1)
cout<<"Stack underflow!";
else
y = stack[top];
top--;
return y;
}

int peek() {
    if (top == -1) {
        cout << "Stack is empty. Cannot peek." << endl;
        return -1; // You can define a specific value to indicate underflow if needed.
    }
    return stack[top];
}
int isEmpty() {
    return top == -1;
}

int main() {

    push(10);
    push(20);
    push(30);

    cout << "Top element: " << peek() << endl;

    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;

    push(40);
    cout << "Top element: " << peek() << endl;

    cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
