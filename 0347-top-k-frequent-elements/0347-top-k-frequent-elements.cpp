class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        vector<int>ans;
        vector<pair<int, int>>v;
        
        for(auto e:mp)
            v.push_back(make_pair(e.second, e.first));
        
        sort(v.rbegin(), v.rend());
        
        for(auto e:v){
            if(k==0)
                break;
            ans.push_back(e.second);
            k--;
        }    
        
        return ans;
    }
};