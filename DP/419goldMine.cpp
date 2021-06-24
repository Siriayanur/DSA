#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> t)
    {
        // code here
        for (int col = m-2; col >= 0;col--){
            for (int row = 0; row < n; row++){
                
                //current value in the gold mine
                int x = t[row][col+1];
                
                //diagonally right up
                int y = (row == 0 ? 0 : t[row-1][col+1]);
    
                //diagonally right down
                int z = (row == n - 1 ? 0 : t[row + 1][col + 1]);
    
                //take the maximum of the values
                t[row][col] = t[row][col] + max(x, max(y, z));
            }
        }
        int result = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            
            if(t[i][0] > result)
                result = t[i][0];
        }
        return result;
    }
};

int main(){
    int m;
    int n;
    //Take the number of rows and columns
    cin >> m >> n;

    //gold mine
    int t[m][n];
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j++){
            cin >> t[i][j];
        }
    }
}
