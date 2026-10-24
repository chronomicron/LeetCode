#include<iostream>
#include<map>
#include<string>
#include<list>


using namespace std;

int main()
{

    map<string, list<string> > pokedex;

    list<string> pikachu_moves = {"Thunder Shock", "Growl", "Quick Attack", "Thunderbolt"}; 
    list<string> bulbasaur_moves = {"Tackle", "Growl", "Vine Whip", "Razor Leaf"};
    list<string> charmander_moves = {"Scratch", "Growl", "Ember", "Flamethrower"};
    list<string> squirtle_moves = {"Tackle", "Tail Whip", "Water Gun", "Bubble"};

    pokedex.insert(pair<string, list<string> >("Pikachu", pikachu_moves));
    pokedex.insert(pair<string, list<string> >("Bulbasaur", bulbasaur_moves));
    pokedex.insert(pair<string, list<string> >("Charmander", charmander_moves));
    pokedex.insert(pair<string, list<string> >("Squirtle", squirtle_moves));


    for (auto pair : pokedex) 
    {

        cout << pair.first << " moves: ";

        bool firstMove = true;
        for (const auto& move : pair.second)
        {
            if (!firstMove) {
                cout << ", ";
            }
            cout << move;
            firstMove = false;
        }
        cout << "." << endl;
    }




    return 0;



}


