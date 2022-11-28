class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        
        int ans=0;
        int mx=*max_element(arr.begin(), arr.end());
        
        vector<int>mp(mx+1, 0);
        
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        
        sort(mp.begin(), mp.end());
        int sum=0;
        int sz=arr.size()/2;
        
        for(int i=mp.size()-1;i>=0;i--){
            if(mp[i]>=1){
                ans++;
                sum+=mp[i];   
            }
            if(sum >= sz)
                break;
        }      

        return ans;
    }
};