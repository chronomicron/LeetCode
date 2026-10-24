#include<iostream>
#include<map>
#include<list>

using namespace std;

int main()
{

    map<int, list<string>> myMap;

    list<string> fruits = {"apple", "banana", "strawberry", "pear", "grape"};
    list<string> vegetables = {"potato", "carrot", "beet", "onion", "peas"};
    list<string> meat = {"pork", "beef", "chicken", "salmon", "shrimp"};

    myMap[1] = fruits;
    myMap[2] = vegetables;
    myMap[3] = meat;

    for(auto it_pair : myMap)
    {
        cout << "key index: " << it_pair.first << " -- " << "value: ";
        for (const auto& item : it_pair.second)
        {
            cout << item << " ";
        }

        cout << endl;
    }
    





}