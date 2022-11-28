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
        
        vector<vector<int>>ans;
        vector<int>res, res1;
       
        for(auto e:loser){
            
            if(winner.count(e.first)){
                winner[e.first]=0;
            }
        }
        
        for(auto e:winner){
            if(e.second==1)
                res.push_back(e.first);
        }
        
        for(auto e:loser){
            if(e.second==1)
                res1.push_back(e.first);
        }
        
        ans.push_back(res);
        ans.push_back(res1);
        
        return ans;
    }
};