class Solution {
public:        
      static bool cmp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        int cnt=1;
        int et=pairs[0][1];
        
        for(int i=1;i<n;i++){
            if(pairs[i][0] > et){
                cnt++;
                et=pairs[i][1];
            }
        }
        
        return cnt;
    }
    
};