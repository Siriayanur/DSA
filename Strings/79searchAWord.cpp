#include <bits/stdc++.h>
using namespace std;

/*
helper2() - right output for all test cases
*/
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool helper2(int i, int j, int m, int n, vector<vector<char>> &grid, string word)
{
    if (grid[i][j] != word[0])
    {
        return false;
    }
    int len = word.length();
    for (int direction = 0; direction < 8; direction++)
    {

        int k;
        int row = i + x[direction];
        int col = j + y[direction];

        for (k = 1; k < len; k++)
        {
            if (row >= m || col >= n || row < 0 || col < 0)
                break;

            if (grid[row][col] != word[k])
                break;

            //update
            row += x[direction];
            col += y[direction];
        }

        if (k == len)
            return true;
    }
    return false;
}

/*

helper() - Gives wrong output for zig zag pattern
*/
bool helper(int i, int j, int m, int n, vector<vector<char>> &grid, string word, int size, int idx)
{
    // int found = 0;
    bool found = false;
    if (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == word[idx])
    {
        // cout << "Enter " << i << " " << j << endl;
        char temp = grid[i][j];
        grid[i][j] = '0';

        idx++;
        if (idx >= size)
            found = true;
        else
        {
            found = found ||
                    helper(i, j + 1, m, n, grid, word, size, idx) ||
                    helper(i + 1, j + 1, m, n, grid, word, size, idx) ||
                    helper(i + 1, j, m, n, grid, word, size, idx) ||
                    helper(i + 1, j - 1, m, n, grid, word, size, idx) ||
                    helper(i, j - 1, m, n, grid, word, size, idx) ||
                    helper(i - 1, j - 1, m, n, grid, word, size, idx) ||
                    helper(i - 1, j + 1, m, n, grid, word, size, idx) ||
                    helper(i - 1, j, m, n, grid, word, size, idx);
        }
        grid[i][j] = temp;
        // cout << "Rewritten" << endl;
    }
    return found;
}

int main()
{

    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m);

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            grid[i].push_back(c);
        }
    }
    string word;
    cin >> word;

    vector<vector<int>> ans;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (helper(i, j, m, n, grid, word, word.length(), 0))
            {
                vector<int> small;
                small.push_back(i);
                small.push_back(j);
                ans.push_back(small);
                // cout << "Pushed" << endl;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}