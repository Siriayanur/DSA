#include <iostream>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.size() == 1 || s.size() == 0)
        {
            return;
        }
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

///Equivalent way
#include <iostream>
using namespace std;

void reverse(char str[], int n)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        char temp = str[i];
        str[i++] = str[j];
        str[j--] = temp;
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

    reverse(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
}