#include <iostream>

using namespace std;

class Stack
{
public:
    int capacity;
    int top = -1;
    int *arr;
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[cap];
    }
    void push(int value);
    int pop();
    int peek();
};

void Stack::push(int value)
{
    if (top == capacity)
        return;
    else
        arr[++top] = value;
}

int Stack::pop()
{
    if (top == -1)
        return -1;
    else
        return arr[top--];
}

int Stack::peek()
{
    return arr[top];
}

int prec(char c)
{
}

bool isOperand(char c)
{
    return ((c >= 'a' || c >= 'A') && (c <= 'z' || c <= 'Z'));
}

bool isOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}

// BODMAS
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostFix(string exp, Stack *st)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperand(exp[i]))
        {
            cout << exp[i];
        }
        else if (isOperator(exp[i]))
        {
            if (prec(exp[i]) > prec(st->peek()) || st->top == -1)
            {
                st->push(exp[i]);
            }
            else
            {
                while ((st->peek() == '(' || prec(exp[i]) <= prec(st->peek())) && st->top != -1)
                {
                    st->pop();
                }
            }
        }
        else if (exp[i] == '(')
        {
        }
    }
}

int main()
{
    Stack *st = new Stack(5);
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    cout << st->peek() << endl;
    st->pop();
    cout << st->peek() << endl;
    st->pop();
    cout << st->peek() << endl;
    return 0;
}