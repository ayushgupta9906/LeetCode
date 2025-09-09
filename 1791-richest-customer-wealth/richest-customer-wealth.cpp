class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int>wealths;
        for(int i=0;i<accounts.size();i++){
            int sum=0;
            for(int j=0;j<accounts[i].size();j++){
                sum+=accounts[i][j];
            }
            wealths.push_back(sum);

        }
        int richest=0;
        for(int w: wealths)richest=max(richest,w);
        return richest;
        
    }
};