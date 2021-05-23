#include <iostream>
using namespace std;
/**
 * 2 22 222
 * 3 33 333 
 * 4 44 444
 * 5 55 555
 * 6 66 666
 * 7 77 777 7777
 * 8 88 888
 * 9 99 999 9999
*/
string keypadSequence(string str[], string input)
{
    string output = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '')
        {
            output += '0';
        }
        else
        {
            char current = input[i];
            output += str[input[i] - 'a'];
        }
    }
    return output;
}

int main()
{
    string store[26] = {
        "2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555",
        "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};

    string input;
    cin >> input;
    cout << keypadSequence(store, input);
}