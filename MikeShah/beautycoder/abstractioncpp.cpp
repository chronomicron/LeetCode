#include<iostream>
#include<queue>

using namespace std;

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    cout << "Size of queue: " << myQueue.size() << endl;
    cout << "Front element: " << myQueue.front() << endl;
    cout << "Back element: " << myQueue.back() << endl;

    cout << "MyQueue elements: " << endl;
    printQueue(myQueue);


    return 0;

}