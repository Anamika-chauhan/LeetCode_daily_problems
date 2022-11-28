class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int ans=0;
        unordered_map<int, int>mp;
        vector<int>v;
        
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        
        for(auto e:mp)
            v.push_back(e.second);
        
        sort(v.begin(), v.end());
        int sum=0;
      
        for(int i=v.size()-1;i>=0;i--){
            ans++;
            sum+=v[i];
            if(sum >= (arr.size()/2))
                break;
            
        }
        
        return ans;
    }
};