#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    MyStack() {}

    void push(int x) {
        // Add the new element to queue1.
        queue1.push(x);
    }

    int pop() {
        if (empty()) {
            cerr << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return -1; // You can define a specific value to indicate underflow if needed.
        }

        // Move all elements from queue1 to queue2 except the last one.
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        // The front element in queue1 is the top of the stack, remove it.
        int topElement = queue1.front();
        queue1.pop();

        // Swap the queues so that queue2 becomes empty for the next operation.
        swap(queue1, queue2);

        return topElement;
    }

    int top() {
        if (empty()) {
            cerr << "Stack is empty. Cannot get the top element." << endl;
            return -1; // You can define a specific value to indicate underflow if needed.
        }

        // Move all elements from queue1 to queue2 except the last one.
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        // The front element in queue1 is the top of the stack.
        int topElement = queue1.front();

        // Move the top element back to queue1 for future operations.
        queue2.push(topElement);
        queue1.pop();

        // Swap the queues so that queue2 becomes empty for the next operation.
        swap(queue1, queue2);

        return topElement;
    }

    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};

int main() {
    MyStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

    stack.push(40);
    cout << "Top element: " << stack.top() << endl;

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

    return 0;
}
