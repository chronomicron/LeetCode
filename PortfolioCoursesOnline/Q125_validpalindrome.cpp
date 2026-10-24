#include<iostream>
#include<string>
#include <algorithm>
#include <cctype>


using namespace std;


class Solution 
{

private:
    string sanitize_data(string s)
    {
        string clean_s = s;

        //to lower
        std::transform(clean_s.begin(), clean_s.end(), clean_s.begin(), [](char c) { return std::tolower(c); });

        //remove non-alpha characters
        clean_s.erase(remove_if(clean_s.begin(), clean_s.end(), [](char c) { return !isalpha(c); }), clean_s.end());

        return clean_s;

    }

public:

    bool isPalindrome(string s) 
    {
        bool is_Pal = true;

        //cleanup string, remove non-alpha, convert to lower
        string clean_s = sanitize_data(s); //  sanitize data, convert all to lower, remove non alpha

        // do once instead of repeatedly calling clean_s.length() in the loop
        int stringlen = clean_s.length();

        cout << "cleaned string = " << clean_s << endl;


        for(int i = 0; i < stringlen / 2 ; i++)
        {
            if(clean_s.at(i) != clean_s.at((stringlen - 1) - i))
            {
//                cout << "clean_s[" << i << "] = " << clean_s.at(i) << endl;
//                cout << "clean_s[" << (stringlen - 1) - i << "] = " << clean_s.at((stringlen - 1) - i) << endl;
//                cout << "Characters at positions " << i << " and " << (stringlen - 1) - i << " don't match." << endl;
                is_Pal = false;
                return is_Pal;
            }
            else
                continue;
        }
        return is_Pal;
    }
};


int main()
{

    Solution mySolution;

    string test1 = "abccba"; // true
    string test2 = "race star"; //false
    string test3 = "A man, a plan, a canal: Panama"; // true

    mySolution.isPalindrome(test1) ? cout << "true" << endl : cout << "false" << endl;
    mySolution.isPalindrome(test2) ? cout << "true" << endl : cout << "false" << endl;
    mySolution.isPalindrome(test3) ? cout << "true" << endl : cout << "false" << endl;


    return 0;
}