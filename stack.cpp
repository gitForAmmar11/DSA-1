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

int main()
{
    push(20);
    push(1);
    push(15);
    //pop();
    //pop();
    //pop();
    pop();

    for(int i=0; i<=top; i++){
        cout << stack[i] << endl;
    }
return 0;
}
