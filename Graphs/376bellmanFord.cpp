#include<iostream>
using namespace std;


class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> distance(n,INT_MAX);
	    
	    
	    distance[0] = 0;
	    
	    for(int i = 0; i < n - 1; i++){
	        for(int j = 0 ; j < edges.size(); j++){
	            int s = edges[j][0];
	            int e = edges[j][1];
	            int w = edges[j][2];
	            if(distance[s] != INT_MAX && distance[s] + w < distance[e]){
	                distance[e] = distance[s] + w;
	            }
	        }
	        
	    }
	    
	       for(int j = 0 ; j < edges.size(); j++){
	            int s = edges[j][0];
	            int e = edges[j][1];
	            int w = edges[j][2];
	            if(distance[s] != INT_MAX && distance[s] + w < distance[e]){
	                return 1;
	            }
	        }
	    return 0;
	}
	
};