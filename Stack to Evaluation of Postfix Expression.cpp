#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0; // Invalid operation
    }
}

int evaluatePostfix(const string& expression) {
    stack<int> operands;

    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            operands.push(stoi(token));
        } else if (isOperator(token[0])) {
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            int result = performOperation(token[0], operand1, operand2);
            operands.push(result);
        } else {
            cerr << "Invalid input: " << token << endl;
            return 0;
        }
    }

    if (operands.size() == 1) {
        return operands.top();
    } else {
        cerr << "Invalid expression: " << expression << endl;
        return 0;
    }
}

int main() {
    string postfixExpression;
    cout << "Enter the space-separated postfix expression: ";
    getline(cin, postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
