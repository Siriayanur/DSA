#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> getCoordinates(int current,int n){
        vector<int> res;
        int row = n - (current - 1/ n) -1;
        int col = (current - 1) % n;
        if(r%2 == n %2){
            res.push_back(r);
            res.push_back(n - 1- c);
            
        }else{
            res.push_back(r);
            res.push_back(c);
            
        }
        return res;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<bool>> visited;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                visited[i].push_back(false);
            }
        }
        queue<int> pending;
        pending.push(1);
        int steps = 0;

        while(!pending.empty()){
            int size = pending.size();
            int current = pending.pop();
            if(current == n * n){
                return steps;
            }
            for (int i = 1; i <= 6; i++){
                if(i+current > n*n){
                    break;
                }
                vector<int> co = getCoordinates(current, n);
                int x = co[0];
                int y = co[1];
                if(visited[x][y])
                    continue;
                visited[x][y] = true;
                if (board[x][y] == -1)
                {
                    pending.push(current + i);
                }
                else{
                    pending.push(board[x][y]);
                }
            }
            steps++;
        }
        return -1;
    }
};