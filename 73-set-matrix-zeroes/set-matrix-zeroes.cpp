class Solution {
    private:

    void setzerorow(vector<vector<int>>& matrix,int i,int n){
        for(int k=0;k<n;k++){
            matrix[i][k]=0;
        }
    }
    void setzerocol(vector<vector<int>>& matrix,int j,int m){
          for(int k=0;k<m;k++){
            matrix[k][j]=0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<pair<int,int>>mn;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   pair temp = make_pair(i,j);
                   mn.push_back(temp);
                }
            }
        }

        for(auto i:mn){
            int temp1=i.first;
            int temp2=i.second;

            setzerorow(matrix,temp1,n);
            setzerocol(matrix,temp2,m);
            
        }

        
    }
};