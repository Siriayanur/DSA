class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        int t[nums.size()];
        
        t[0] = nums[0];
        t[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++){
            
            t[i] = max(t[i-1],nums[i]+t[i-2]);
        }
        return t[nums.size()-1];
        
        int one = nums[0];
        int two = nums[1];
        int result = max(one,two);
        for(int i = 2; i < nums.size(); i++){
            
        }
    }
};