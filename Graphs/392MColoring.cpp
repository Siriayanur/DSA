#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int currentNode,int currentColor,int color[],int n,bool graph[101][101]){
    for (int i = 0; i < n; i++){
        if(i != currentNode && graph[currentNode][i] && color[i] != currentColor)
            return false;

    }
    return true;
}

bool solve(int currentNode,int color[],int m,int n,bool graph[101][101]){
    if(currentNode == n){
        return true;
    }
    //Try assigning color to the currentNode
    for (int i = 1; i <= m; i++){
        if(isSafe(currentNode,i,n,color,graph)){
            color[currentNode] = i;
            if(solve(currentNode+1,color,m,n,graph)){
                return true;
            }
            color[current] = 0;//backtrack try some other color
        }
    }
}

bool graphColoring(bool graph[101][101],int m,int n){
    int color[n] = {0};
    return solve(0, color, m, n, graph);
}
