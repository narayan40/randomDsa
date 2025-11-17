class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int n = maze.size();
        int m = maze[0].size();
        pair<int, int> start = make_pair(entrance[0], entrance[1]);
        vector<vector<int>> vis(n, vector<int>(m, 0));
       queue<pair<pair<int,int>,int>> q;
        q.push(make_pair(start, 0));
        vis[entrance[0]][entrance[1]]=1;
        while (!q.empty()) {
            pair<pair<int, int>, int> node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int step = node.second;
            if ((r == 0 || c == 0 || r == n - 1 || c == m - 1)&&!(r==entrance[0]&&c==entrance[1])) {
                return step;
            }
                for (int i = 0; i < 4; i++) {
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]!=1 && maze[nrow][ncol]!='+'){
                        q.push(make_pair(make_pair(nrow,ncol),step+1));
                        vis[nrow][ncol]=1;
                    }
                }
            
        }
        return -1;
    }
};
