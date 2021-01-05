/*
To just give one possible feasible solution
to the problem , One feasible path among (if) many
*/
#include <iostream>
#include <vector>
#define MAX 5
using namespace std;

// 1. Check if path safe
// 2. send an output matrix for solution
// 3. Main function to manipulate the solution matrix
// 4. Void main function
// 5.

bool isSafe(int i, int j, int **maze, int n)
{
    if (i >= 0 && j >= 0 && i <= n - 1 && j <= n - 1 && maze[i][j] == 1)
    {
        return true;
    }
    return false;
}

bool findMazeUtil(int **maze, int **solution, int n, int i, int j)
{
    if (i == n - 1 && j == n - 1 && maze[i][j] == 1)
    {
        solution[i][j] = 1;
        return true;
    }

    if (isSafe(i, j, maze, n))
    {
        solution[i][j] = 1;

        if (findMazeUtil(maze, solution, n, i, j + 1))
        {
            return true;
        }
        if (findMazeUtil(maze, solution, n, i + 1, j))
        {
            return true;
        }

        solution[i][j] = 0;
        return false;
    }
    return false;
}

bool findMaze(int **maze, int n)
{
    int **solution = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solution[i][j] = 0;
        }
    }
}

/*
Return all the possible paths
*/
bool isSafeNew(int maze[][MAX], int n, int i, int j)
{
    if (i >= 0 && j >= 0 && j <= n - 1 && i <= n - 1 && maze[i][j] == 1)
    {
        return true;
    }
    return false;
}

bool printPathUtil(int maze[][MAX], int n, int i, int j, vector<string> result)
{
    if (isSafeNew(maze, n, i, j))
    {
        string rightPath = "";
        string downPath = "";

        if (printPathUtil(maze, n, i + 1, j, result))
        {
            downPath += "D";
        }

        if (printPathUtil(maze, n, i, j + 1, result))
        {
            rightPath += "R";
        }
    }
}

vector<string> printPath(int maze[MAX][MAX], int n)
{
    // Your code goes here
    vector<string> result;
    int i = 0, j = 0;
    printPathUtil(maze, n, i, j, result);
}