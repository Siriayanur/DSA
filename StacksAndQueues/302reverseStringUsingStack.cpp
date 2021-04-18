#include <iostream>
using namespace std;

int main()
{
    char *name = "abced";
    for (int i = 0; i <= 6; i++)
    {
        cout << name[i] << " " << (int)name[i];
    }
    return 0;
}