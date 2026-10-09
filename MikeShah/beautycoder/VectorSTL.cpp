#include<iostream>
#include<vector>

using namespace std;

int initVect(vector<int> &numbers)
{
    for(int i = 1; i <= 10; i++)
    {
        numbers.push_back(i);
    }
    return 0;
}

int printVect(vector<int> &numbers)
{
    for(int number : numbers)
    {
        cout << "numbers are: " << number << endl;
    }
    return 0;
}


int main()
{

    vector<int> numbers;

    //numbers.push_back(0);

    for(int i = 1; i <= 10; i++)
    {
        numbers.push_back(i);
    }

    // can use initVect function to initialize vector
    //initVect(numbers);

    for(int number : numbers)
    {
        cout << "numbers are: " << number << endl;
    }

    for(auto it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << "*it = " << *it << endl;
        cout << "&it = " << &it << endl;
        cout << "&(*it) = " << &(*it) << endl;
    }

    auto it = numbers.begin();
    cout << "*(it + 5) = " << *(it + 5) << endl;

    for(auto it = numbers.cbegin(); it != numbers.cend(); it++)
    {
        //*it = 20;

        cout << "*it = " << *it << endl;
        cout << "&it = " << &it << endl;
        cout << "&(*it) = " << &(*it) << endl;
        
    }

    cout << "Size = " << numbers.size() << endl;
    cout << "Capacity = " << numbers.capacity() << endl;
    cout << "Max Size = " << numbers.max_size() << endl;
    numbers.resize(5);
    cout << "Size = " << numbers.size() << endl;

    if(numbers.empty())
    {
        cout << "vector is empty." << endl;        
    }
    else
    {
        cout << "vector is not empty." << endl;
    }

    cout << "element at 0th position " << numbers.at(0) << endl;

    cout << "element at 5th position " << numbers[5] << endl;

    size_t index = 3;

    if(index < numbers.size())
    {
        cout << "element at " << index << "th position " << numbers.at(index) << endl;
    }
    else
    {
        cout << "number out of range boi" << endl;
        // throw out_of_range exception or warning;
    }

    cout << "front element = " << numbers.front() << endl;
    cout << "back element = " << numbers.back() << endl;

    numbers.clear();
    cout << "Size = " << numbers.size() << endl;
    cout << "Capacity = " << numbers.capacity() << endl;

    cout << "insert element at... " << endl;

    initVect(numbers);
    printVect(numbers);

    cout << " new line " << endl;
    
    int pos = 5; // position where we want to insert the element
    int value = 20; // value to be inserted

    auto it1 = numbers.begin();
    numbers.insert(it1 + pos, value);
    printVect(numbers);
    
    //cin.get();
    return 0;

}