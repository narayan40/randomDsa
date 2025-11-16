class Solution {
public:
   int cnt=0;
   void dfs(int st,vector<int>& vis, vector<vector<pair<int,int>>>& adj){
    vis[st]=1;

    for(auto i:adj[st]){
        if(!vis[i.first]){
        if(i.second==1)
        cnt++;
        dfs(i.first,vis,adj);
        }
    }
   }
    int minReorder(int n, vector<vector<int>>& connections) {
       vector<vector<pair<int,int>>> adj(n);
       vector<int> vis(n,0);
       for(auto i:connections){
        int a=i[0];
        int b=i[1];
        adj[a].push_back({b,1});
        adj[b].push_back({a,0});

       }
       dfs(0,vis,adj);
       return cnt; 
    }
};
