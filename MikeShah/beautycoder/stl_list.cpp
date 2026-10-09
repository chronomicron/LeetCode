#include <iostream>
#include <list>

using namespace std;

void displayRatings(const list<int>& playerRatings)
{
    for (list<int>::const_iterator it = playerRatings.begin(); it!= playerRatings.end(); it++){
        cout << "Player rating " << *it << endl;
    }
}

void instertPlayerIntoOrderedList(list<int>& playerRatings, int rating)
{
    for(list<int>::iterator it = playerRatings.begin(); it!= playerRatings.end(); it++)
    {
        if(rating < *it)
        {
            playerRatings.insert(it, rating);
            return;
        }
    }
    playerRatings.push_back(rating);
}

int main() 
{
/*
    list<int> myList;

    myList.push_back(10);
    myList.push_back(20);

    myList.push_front(30);

    for (list<int>::iterator it = myList.begin(); it!= myList.end(); it++ ) 
    {
        cout << *it << endl;
    }

    myList.erase(myList.begin());

        for (list<int>::iterator it = myList.begin(); it!= myList.end(); it++ ) 
    {
        cout << *it << endl;
    }
*/

    list<int> allPlayers = {2, 9, 6, 7, 3, 1, 4, 8, 3, 2, 9,};
    list<int> beginners = {}; //ratings 1 to 5
    list<int> pros = {}; //ratings 6 to 10

    for(list<int>::iterator it = allPlayers.begin(); it!= allPlayers.end(); it++)
    {
        int rating = *it;

        if (rating >= 1 && rating <= 5) 
        {
            instertPlayerIntoOrderedList(beginners, rating);
        }
        else
        {
            if(rating >= 6 && rating <= 9)
            {
                instertPlayerIntoOrderedList(pros, rating);
            }
        }
    }

    cout << "Beginner players" << endl;
    displayRatings(beginners);
    cout << "Pro players" << endl;
    displayRatings(pros);
    

    return 0;

}
