class Solution {
public:

    int minimumAverageDifference(vector<int>& nums) {
        
        vector<long long int>p_sum(nums.size(),0);       
        p_sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            p_sum[i]=nums[i]+p_sum[i-1];
        }
        
        long long int n=nums.size();
        int ans=INT_MAX;
  
        int mx;
        
        for(int i=0;i<nums.size();i++){
            long long int ith=p_sum[i]/(i+1);
            long long int rem=0;
            if((n-i-1)!=0)
                rem=(p_sum[n-1]-p_sum[i])/(n-i-1);
            
            int res=abs(ith-rem);
            if(ans > res){
                ans=res;
                mx=i;
            }
            
        }
        
        return mx;
    }
};