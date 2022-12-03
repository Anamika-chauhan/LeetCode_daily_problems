class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x=0, y=0;
 
        for(auto e:moves){
            if(e=='U') y+=1;
            if(e=='D') y-=1;
            if(e=='L') x-=1;
            if(e=='R') x+=1;
        }
        
        return x==0 && y==0;
    }
};