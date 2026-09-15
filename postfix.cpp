// C++ Program to illustrate how we can use the stack data
// structure to evaluate the value of a postfix expression
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to perform an operation based on the operator
// and return the result
int performOperation(int operand1, int operand2,
                     char operation)
{
    switch (operation)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}

// Function to evaluate the postfix expression
int evaluatePostfixExpression(const string &expression)
{
    stack<int> stack;
    for (char c : expression)
    {
        if (isdigit(c))
        {
            // Convert char digit to int and push onto the
            // stack
            stack.push(c - '0');
        }
        else
        {
            // Pop the top two elements for the operation
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            // Perform operation and push the result back
            // onto the stack
            int result = performOperation(operand1, operand2, c);
            stack.push(result);
        }
    }
    // The final result should be the only item left in the
    // stack
    return stack.top();
}

int main()
{
    string expression2 = "73*4+";
    int result = evaluatePostfixExpression(expression2);
    cout << "Result of Postfix Expression \"" << expression2
         << "\" is: " << result << endl;

    return 0;
}