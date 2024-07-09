class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] or grid[grid.size()-1][grid[0].size()-1]==1) return -1;
        if(grid.size()==1) return 1;
        
        int dist=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i , j] = q.front();
                q.pop();
                if(i==grid.size()-1 and j==grid[0].size()-1){
                    return dist;
                }
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        int x = i+k;
                        int y=  j+l;
                        if(x<0 or x>=grid.size() or y<0 or y>= grid[0].size() or grid[x][y]==1)continue;
                        q.push({x,y});
                        grid[x][y] = 1;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};