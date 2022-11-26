class Solution {
public:
    // linear search 
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n=startTime.size();
        vector<vector<int>>values(n, vector<int>(3));
        
        for(int i=0;i<n;i++){
            values[i][0]=endTime[i];
            values[i][1]=startTime[i];
            values[i][2]=profit[i];
        }
        
        sort(values.begin(), values.end());
        vector<int>dp(n, 0);
        int ans=values[0][2];
        dp[0]=ans;
        
        for(int i=1;i<n;i++){
            
            dp[i]=values[i][2];
            dp[i]=max(dp[i], dp[i-1]);
            int temp=-1;
            for(int j=i-1;j>=0;j--){
                if(values[j][0] <= values[i][1]){    // endTime of j <= startTime of i
                    dp[i]=max(dp[i], values[i][2]+dp[j]);
                    break;
                }
            }
            
            ans=max(ans, dp[i]);
        }
        
        return ans;
    }
};