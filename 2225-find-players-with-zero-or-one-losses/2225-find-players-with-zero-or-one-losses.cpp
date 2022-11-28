class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, int>loser, winner;
        for(int i=0;i<matches.size();i++){
            int x=matches[i][0];
            int y=matches[i][1];
            
            winner[x]=1;
            loser[y]++;
        }
        
        vector<vector<int>>ans(2);
        vector<int>res, res1;
       
        for(auto e:loser){
            if(winner.count(e.first)){
                winner[e.first]=0;
            }
            if(e.second==1)
                    ans[1].push_back(e.first);
        }
        
        for(auto e:winner){
            if(e.second==1)
                ans[0].push_back(e.first);
        }
 
        return ans;
    }
};