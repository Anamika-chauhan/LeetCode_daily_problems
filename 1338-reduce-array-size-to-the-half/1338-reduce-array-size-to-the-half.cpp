class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        
        int ans=0;
        unordered_map<int, int>mp;
        
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        
        priority_queue<int>pq;
        for(auto e:mp) pq.push(e.second);
        
        int sum=0;
        int sz=arr.size()/2;
        
        while(sum<sz){
            sum+=pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};