class Solution {
public:
    vector<int>dp;

    int fun(vector<vector<int>>& nums, int idx, int eidx){
        
        if(idx==nums.size())
            return 0;
        
        if(nums[idx][0] < eidx)
            return fun(nums, idx+1, eidx);

        if(dp[idx]!=-1)
            return dp[idx];
           
        int not_take=fun(nums, idx+1, eidx);
        int take=nums[idx][2] + fun(nums, idx+1, nums[idx][1]);
      
        int ans=max(take, not_take);
        return dp[idx]=ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>events(startTime.size(),vector<int>(3,0));
        for(int i=0;i<startTime.size();i++)
        {
            events[i][0]=startTime[i];
            events[i][1]=endTime[i];
            events[i][2]=profit[i];
        }
        sort(events.begin() , events.end());
        dp.resize(profit.size(),-1);
        return fun(events, 0, 0);
    }
};