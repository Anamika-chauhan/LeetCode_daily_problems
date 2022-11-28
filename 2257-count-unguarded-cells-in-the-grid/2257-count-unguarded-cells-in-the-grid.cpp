class Solution {
public:
    
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, -1, 1};
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<char>>grid(m, vector<char>(n, '.'));
        queue<pair<int, int>>q;
        int occupied=guards.size()+walls.size();
                                 
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
            q.push({x, y});
            grid[x][y]='g';
        }   
                                 
        for(int i=0;i<walls.size();i++){
            int x=walls[i][0];
            int y=walls[i][1];
            grid[x][y]='w';
        }   
                                
        for(int k=0;k<guards.size();k++){
            int x=guards[k][0];
            int y=guards[k][1];
            
           for(int i=0;i<4;i++){
               int nx=x;
               int ny=y;
               while(true){                
                 nx+=dx[i];
                 ny+=dy[i];
                   
    // break if you see a wall, or if another guard is standing infront of you. ("no vision")
                if(nx<0 || ny<0 || nx==m || ny==n || grid[nx][ny]=='w' || grid[nx][ny]=='g')
                    break;
                
     // if two guards can vision the same cell (1,0) or (1, 3) in example, dont occupy++
                 if(grid[nx][ny]!='o'){
                     grid[nx][ny]='o';
                     occupied++;
                 }
               }
           }
            
        }
                                 
        return m*n - occupied;                
    }
};