#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue()
    {
        if (s1.empty()) {
            return -1;
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
};


int main()
{
    Queue q;
    q.enQueue(5);
    q.enQueue(10);
    q.enQueue(13);
    q.enQueue(25);
    //q.deQueue();

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}
