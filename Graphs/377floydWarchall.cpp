#include<iostream>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int v = matrix[0].size();
	   for(int src = 0; src < v; src++){
	        for(int i = 0; i < v; i++){
	            for(int j = 0; j < v; j++){
	                if(matrix[i][src] == -1 || matrix[src][j] == -1)
	                    continue;
	                else if(matrix[i][j] == -1){
	                    matrix[i][j] = matrix[i][src] + matrix[src][j];
	                }else{
	                    matrix[i][j] = min(matrix[i][j], matrix[i][src] + matrix[src][j]);
	                }
	            }
	        }
	    }
	   
	}
};