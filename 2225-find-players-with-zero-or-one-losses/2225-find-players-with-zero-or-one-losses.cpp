class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int, int>loser;
        set<int>player;
        
        for(int i=0;i<matches.size();i++){
            int x=matches[i][0];
            int y=matches[i][1];
            
            player.insert(x);
            player.insert(y);
            loser[y]++;
        }
        
        vector<vector<int>>ans(2);
        for(auto e:player){
            if(!loser.count(e))
                ans[0].push_back(e);
            else if(loser[e]==1)
                ans[1].push_back(e);
        }
 
        return ans;
    }
};