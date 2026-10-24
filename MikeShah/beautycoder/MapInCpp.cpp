#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;

int main()
{

    unordered_map<string, string> myDictionary;
    unordered_map<string, int> myMap;

    myDictionary.insert(pair<string, string>("banana", "die Banane"));
    myDictionary.insert(pair<string, string>("apple", "der Apfel"));
    myDictionary.insert(pair<string, string>("strawberry", "die Erdbeere"));
    myDictionary.insert(pair<string, string>("orange", "die Orange, die Apfelsine"));


    myDictionary["strawberry"] = "Die Erdbeere";


    for(auto pair :myDictionary)
    {
        cout << "key: " << pair.first << " value: " << pair.second << endl;
    }

    cout << "size of dict is: " <<  myDictionary.size() << endl;

    cout << "value for 'strawberry': " << myDictionary.find("strawberry")->second << endl;


    myDictionary.erase("strawberry");

//    cout << "value for 'strawberry': " << myDictionary.find("strawberry")->second << endl;

    cout << "size of dict is: " <<  myDictionary.size() << endl;


    return 0;

}



