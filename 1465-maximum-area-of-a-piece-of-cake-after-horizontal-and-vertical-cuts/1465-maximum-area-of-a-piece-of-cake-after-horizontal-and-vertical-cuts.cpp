class Solution {
public:
    
    int mod=1e9+7;
    
    int maxArea(int h, int w, vector<int>& hor,vector<int>& ver) {

        sort(hor.begin(), hor.end()); 
        sort(ver.begin(), ver.end());

        int m=INT_MIN, n=INT_MIN;
    
        for(int i = 1;i<hor.size();i++){ 
            int a=hor[i]-hor[i-1];
            m=max(m,a);
        }
        
        m=max({m, hor[0], h-hor[hor.size()-1]});
        
        for(int i = 1 ;i<ver.size();i++) { 
            int b =ver[i]-ver[i-1];
            n=max(n,b);
        }
        
        n=max({n, ver[0], w-ver[ver.size()-1]});
        int ans=(1ll*n*m)%mod;
        
        return ans;
    }
};