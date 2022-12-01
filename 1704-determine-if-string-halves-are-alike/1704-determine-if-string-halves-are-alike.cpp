class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int i=0, sz=s.size()/2;
        string p=s.substr(0, sz);
        string q=s.substr(sz);
        
        int cnt=0, cnt1=0;
        for(auto ch:p){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I'
              || ch=='O' || ch=='U')
                cnt++;
        }
        
        for(auto ch:q){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I'
              || ch=='O' || ch=='U')
                cnt1++;
        }
        
        return cnt==cnt1;
        
    }
};