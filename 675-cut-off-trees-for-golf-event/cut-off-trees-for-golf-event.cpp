class Solution {
public:
    
    int cutOffTree(vector<vector<int>>& forest) {
        map<int, vector<int>> trees;

        // find location of all trees to cut
        for(int i = 0; i < forest.size(); i++){
            for(int j = 0; j<forest[0].size(); j++){
                if(forest[i][j] > 1) trees[forest[i][j]] = {i,j};
            }
        }
        
        int total_distance = 0;
        
        vector<int> current_location{0,0};
        //find path to smallest tree.
        while(!trees.empty()){
            // ordered map begins with smallest key
            vector<int> smallest_tree_location = trees.begin()->second; //get location of smallest tree
            trees.erase(trees.begin());
            int distance = bfs(forest, current_location, smallest_tree_location);
            if(distance < 0) return -1;
            total_distance += distance;
            current_location = smallest_tree_location;
        }
        
        return total_distance;
    }
    
    
    int bfs(vector<vector<int>>& grid, vector<int> start, vector<int>end){
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols, 0));        
        
        int distance = 0;
        
        queue<pair<int,int>> q;
        
        q.push(make_pair(start[0],start[1]));
        
        while(!q.empty()){
            int size = q.size();
            
            // Distance increments after each level
            while(size--){
                auto loc = q.front();
                q.pop();
                
                // Access pair contents using inbuilt methods first and second
                if(loc.first == end[0] && loc.second == end[1]) return distance;
                
                // move up
                if(loc.first != 0){
                    if(grid[loc.first-1][loc.second] != 0 && visited[loc.first-1][loc.second] == 0){
                        visited[loc.first-1][loc.second] = 1;
                        q.push(make_pair(loc.first-1,loc.second));
                    }
                }

                // move down
                if(loc.first != rows-1){
                    if(grid[loc.first+1][loc.second] != 0 && visited[loc.first+1][loc.second] == 0){
                        visited[loc.first+1][loc.second] = 1;
                        q.push(make_pair(loc.first+1,loc.second));
                    }
                }

                // move left
                if(loc.second != 0){
                    if(grid[loc.first][loc.second-1] != 0 && visited[loc.first][loc.second-1] == 0){
                        visited[loc.first][loc.second-1] = 1;
                        q.push(make_pair(loc.first,loc.second-1));
                    }
                }

                // move right
                if(loc.second != cols-1){
                    if(grid[loc.first][loc.second+1] != 0 && visited[loc.first][loc.second+1] == 0){
                        visited[loc.first][loc.second+1] = 1;
                        q.push(make_pair(loc.first,loc.second+1));
                    }
                }
            }
            distance++;
        }
        
        return -1;
    }
};