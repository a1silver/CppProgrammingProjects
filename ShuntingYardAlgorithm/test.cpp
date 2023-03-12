#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

queue<string> shuntingYard(string expr) {
    queue<string> output;
    stack<char> operatorStack;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (isDigit(c)) {
            // Add digits to the output queue
            string num;
            num += c;
            while (i+1 < expr.length() && isDigit(expr[i+1])) {
                num += expr[++i];
            }
            output.push(num);
        }
        else if (isOperator(c)) {
            // Handle operators
            while (!operatorStack.empty() && isOperator(operatorStack.top()) && 
                   precedence(c) <= precedence(operatorStack.top())) {
                output.push(string(1, operatorStack.top()));
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
        else if (c == '(') {
            // Push left parenthesis to the stack
            operatorStack.push(c);
        }
        else if (c == ')') {
            // Handle right parenthesis
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                output.push(string(1, operatorStack.top()));
                operatorStack.pop();
            }
            operatorStack.pop();
        }
    }

    // Pop any remaining operators from the stack to the output queue
    while (!operatorStack.empty()) {
        output.push(string(1, operatorStack.top()));
        operatorStack.pop();
    }

    return output;
}

int evaluate(queue<string> expr) {
    stack<int> evalStack;

    while (!expr.empty()) {
        string token = expr.front();
        expr.pop();

        if (isDigit(token[0])) {
            // Push numbers to the evaluation stack
            stringstream ss(token);
            int num;
            ss >> num;
            evalStack.push(num);
        }
        else if (isOperator(token[0])) {
            // Apply operators to the top two numbers on the stack
            int b = evalStack.top();
            evalStack.pop();
            int a = evalStack.top();
            evalStack.pop();

            int result;
            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '^':
                    result = pow(a, b);
                    break;
            }

            evalStack.push(result);
        }
    }

    // The final result is the top value on the evaluation stack
    return evalStack.top();
}

int main() {
    string expr;
    cout << "Enter an infix expression: ";
    getline(cin, expr);

    queue<string> postfix = shuntingYard(expr);
    cout << "The postfix expression is: ";
    while (!postfix.empty()) {
        cout << postfix.front() << " ";
        postfix.pop();
    }

    int result = evaluate(postfix);
    cout << "\nThe result is: " << result << endl;

    return 0;
}
