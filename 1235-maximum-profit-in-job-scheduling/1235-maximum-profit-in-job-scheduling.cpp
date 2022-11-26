class Solution {
public:
    // binary search 

    int floor(vector<vector<int>>& et, int val){
        
        int l=0, h=et.size()-1, ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(et[mid][0] <= val){
                ans=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        
        return ans;
    }

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
            
            int temp=floor(values, values[i][1]);
            if(temp!=-1){
                dp[i]=max(dp[i], values[i][2]+dp[temp]);
            }
            
            ans=max(ans, dp[i]);
        }
        
        return ans;
    }
};