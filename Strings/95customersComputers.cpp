#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_CHAR 26

int main()
{
    // char *sq;
    string seq;
    cout << "String : ";
    cin >> seq;

    int computers;

    cout << "Computers : ";
    cin >> computers;

    unordered_map<char, int> map;

    // int seen[MAX_CHAR] = {0};
    int r = 0;
    for (int i = 0; i < seq.size(); i++)
    {

        if (map.find(seq[i]) != map.end())
        {
            if (map[seq[i]] == 1)
            {
                map[seq[i]] = 2;

                computers++;
            }
        }
        else
        {
            if (computers)
            {
                computers--;
                map[seq[i]] = 1;
            }
            else
            {
                r++;
                map[seq[i]] = 3;
            }
        }
    }
    cout << seq << " " << r << endl;
}
