class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        vector<int>ans;
        priority_queue<pair<int, int>>v;
        
        for(auto e:mp){
            v.push(make_pair(-1*e.second, e.first));
            if(v.size()>k){
                v.pop();
            }
        }
            
        while(!v.empty()){
            ans.push_back(v.top().second);
            v.pop();
        }
        
        return ans;
    }
};