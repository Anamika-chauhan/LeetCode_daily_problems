class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<unordered_map<long long int, long long int>>dp(nums.size());
        long long int ans=0;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                
                long long int diff=(long long)nums[j]-nums[i];
                long long int cnt=0;
                if(dp[j].count(diff)){
                    cnt=dp[j][diff];
                }
                
                dp[i][diff]+=cnt+1;
                ans+=cnt;
            }
        }
        
        return ans;
    }
};