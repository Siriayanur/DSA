#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

string
printDuplicates(Node *root, unordered_map<string, int> &map, vector<int> &result)
{

    if (root == NULL)
        return "";

    string str = "(";
    str += printDuplicates(root->left, map, result);
    str += to_string(root->data);
    str += printDuplicates(root->right, map, result);
    str += ")";

    if (map[str] == 1)
    {
        result.push_back(root->data);
    }

    map[str]++;
    return str;
}

void printAllDups(Node *root)
{
    // Code here

    vector<int> result;
    unordered_map<string, int> map;
    printDuplicates(root, map, result);

    if (result.size() > 0)
    {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
    else
    {
        cout << "-1";
    }
}