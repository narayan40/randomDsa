class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(make_pair(i,j),0));
                    vis[i][j]=2;
                }
            }
        }
        int time=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
       
        while(!q.empty()){
            pair<pair<int,int>,int> node=q.front();
            q.pop();
            int i=node.first.first;
            int j=node.first.second;
            int t=node.second;
            time=max(time,t);
            for(int x=0;x<4;x++){
                int nrow=i+drow[x];
                int ncol=j+dcol[x];
                if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    vis[nrow][ncol]=2;
                    q.push(make_pair(make_pair(nrow,ncol),t+1));
                }
            }
        }
        
        //checking if any fresh orange left if any then return -1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};
