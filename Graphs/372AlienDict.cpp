#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void topo(int curr, int k, int **mat, bool *visited, stack<char> &st)
    {
        visited[curr] = true;

        for (int i = 0; i < k; i++)
        {
            if (i != curr && !visited[i] && mat[curr][i])
            {
                topo(i, k, mat, visited, st);
            }
        }
        st.push('a' + (char)curr);
    }

    string findOrder(string dict[], int n, int k)
    {
        //code here
        int **mat = new int *[k];
        for (int i = 0; i < k; i++)
        {
            mat[i] = new int[k];
            for (int j = 0; j < k; j++)
            {
                mat[i][j] = 0;
            }
        }
        bool visited[k] = {false};

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < min(dict[i].length(), dict[i + 1].length()); j++)
            {
                if (dict[i][j] != dict[i + 1][j])
                {
                    mat[dict[i][j] - 'a'][dict[i + 1][j] - 'a'] = 1;
                    break;
                }
            }
        }
        string result;
        stack<char> st;
        for (int i = 0; i < k; i++)
        {
            if (!visited[i])
            {
                topo(i, k, mat, visited, st);
            }
        }
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};