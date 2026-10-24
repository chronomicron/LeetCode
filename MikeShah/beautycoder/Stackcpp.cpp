#include<iostream>
#include<stack>

using namespace std;

void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}


int main()
{
    stack<int> numbers;

    //empty, size, push, pop, top
    numbers.push(2);
    numbers.push(4);
    numbers.push(6);
    
    if(numbers.empty())
    {
        cout << "stack is empty." << endl;        
    }
    else
    {
        cout << "stack is not empty." << endl;
    }

    cout << "size of stack is: " << numbers.size() << endl;

    printStack(numbers);

    cout << "after pop, size of stack is: " << numbers.size() << endl;

    return 0;

}
