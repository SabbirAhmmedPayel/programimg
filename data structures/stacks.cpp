#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

#define Size 100

class Stack
{
    int top;
    int arr[Size];

public:
    Stack()
    {
        top = -1;
    }

    void push(int n)
    {
        arr[++top] = n;
    }
    int pop()
    {

        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            exit(-1);
        }
        return arr[top--];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack st1, st2;

    st1.push(67);
    st1.push(7);
    st1.push(44);

    cout << st1.pop() << endl;
    cout << st1.pop() << endl;
    cout << st1.pop() << endl;

    return 0;
}