#include<bits/stdc++.h>
using namespace std;


class Solution{
public:

    bool isSafeToKeepQueen(int row,int col,int n,vector<vector<int>> &board){
        int row_temp = row, col_temp = col;
        
        //Check the row
        
        //Check the upper left diagonal
        while(row >= 0 && col >= 0){
            if(board[row][col])
                return false;
            row--;col--;
        }
        
        //Check adjacent left side
        row = row_temp;
        col = col_temp;
        while(col >= 0){
            if(board[row][col])
                return false;
            col--;
        }
        
        //Check the bottom right diagonal
        row = row_temp;
        col = col_temp;
        while(row < n && col >= 0){
            if(board[row][col])
                return false;
            row++; col--;
        }
        
        return true;
    }
    
    void solve(int n,int col,vector<vector<int>> &board, vector<vector<int>>& result){
        
        //Base condition
        if(col == n){
            vector<int> current;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(board[i][j]){
                        current.push_back(j+1);
                    }
                }
            }
            result.push_back(current);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isSafeToKeepQueen(i,col,n,board)){
                board[i][col] = 1;
                solve(n,col+1,board,result);
                board[i][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> result;
        vector<int> current;
        vector<vector<int>> board(n,vector<int> (n, 0));
        solve(n,0,board,result);
        sort(result.begin(),result.end());
        return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
} 