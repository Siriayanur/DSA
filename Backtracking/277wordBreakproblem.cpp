class Solution{
public:

    void solve(string s,string ans,unordered_map<string,int>& dict,vector<string>& result){
        
        if(s.length() == 0){
            ans = ans.substr(0,ans.length()-1);
            result.push_back(ans);
            return ;
        }
        
        for(int i = 0; i < s.length(); i++){
            string left = s.substr(0,i+1);
            if(dict.find(left) != dict.end()){
                string right = s.substr(i+1);
                
                solve(right,ans + left + " ",dict,result);
            }
        }
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_map<string,int> dictionary;
        for(int i = 0; i < n; i++){
            dictionary[dict[i]]++;
        }
        vector<string>  result;
        solve(s,"",dictionary,result);
        return result;
    }
};