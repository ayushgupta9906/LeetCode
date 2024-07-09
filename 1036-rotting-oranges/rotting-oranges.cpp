class Solution {
public:
    void bfs(int &tm, vector<vector<int>>& grid,vector<vector<int>>&vis)
    {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;

         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }


        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            tm=max(tm,t);
            cout<<"tm"<<tm<<endl;
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }

            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int tm=0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        bfs(tm,grid,vis);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return tm;
    }
};