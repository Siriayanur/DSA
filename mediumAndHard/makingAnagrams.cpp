#include<iostream>
#include<unordered_map>
using namespace std;



*/
int makeAnagram(string a, string b) {
    int store[27] = {0};
    int count = 0;
    
    for(int i = 0; i < a.length(); i++){
        store[a[i] - 'a'] ++; 
    }
    for(int i = 0; i < b.length(); i++){
        store[b[i] - 'a'] --;
    }
    for(int i = 0; i < 26; i++){
        if(store[i] != 0){
            
            count = count+ abs(store[i]);
        }
    }
    
    return count;
    
}
int main(){
    cout << makeAnagram("cde", "dcf") << endl;
    return 0;
}