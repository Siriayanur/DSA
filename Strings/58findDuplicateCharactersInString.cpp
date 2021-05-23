#include <iostream>
#include <unordered_map>
using namespace std;

//o(nlogn)

void printDuplicateChars(char *input, int n)
{
    sort(input, input + n);
    for (int i = 0; i < n;)
    {
        if (input[i] == input[i + 1])
        {

            cout << input[i] << " ";
            i += 2;
        }
        else
        {
            i++;
        }
    }
}

// o(n) time space
void printDuplicateChar2(char *input, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[input[i]]++;
    }
    for (auto i : map)
    {
        if (i.second > 1)
        {
            cout << i.first << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    char input[n];
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        input[i] = c;
    }
    printDuplicateChars(input, n);
}