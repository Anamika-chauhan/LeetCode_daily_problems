class Solution {
public:
    int waysToSplitArray(vector<int>& nums){
        
        long long prefix=0, suffix=0;
        for(int i=0;i<nums.size();i++){
            suffix+=nums[i];
        }
        
        long long int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            prefix+=nums[i];
            long long int s=suffix-prefix;

            if(prefix >= s)
                cnt++;            
        }
        
        return cnt;
    }
};