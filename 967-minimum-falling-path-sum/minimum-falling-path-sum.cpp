class Solution {
public:

    int dpWithMemoization(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i < 0 or i >= n or j < 0 or j >= n) {
            return INT_MAX;
        }

        if(i == n-1) {
            return matrix[i][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = dpWithMemoization(i+1, j, n, matrix, dp);
        int diagLeft = dpWithMemoization(i+1, j-1, n, matrix, dp);
        int diagRight = dpWithMemoization(i+1, j+1, n, matrix, dp);
        return dp[i][j] = matrix[i][j] + min(down, min(diagLeft, diagRight));
    }

    int dpWithTabulation(vector<vector<int>>& matrix, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+2, INT_MAX));

        for(int j=1; j<=n; j++) {
            dp[1][j] = matrix[0][j-1];
        }

        for(int i=2; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int up = dp[i-1][j];
                int diagLeft = dp[i-1][j-1];
                int diagRight = dp[i-1][j+1];
                dp[i][j] = matrix[i-1][j-1] + min(up, min(diagLeft, diagRight));
            }
        }

        int ans = INT_MAX;
        for(int j=1; j<=n; j++) {
            ans = min(ans, dp[n][j]);
        }
        return ans;
    }

    int dpWithSpaceOptimisation(vector<vector<int>>& matrix, int n) {
        vector<int> prev(n+2, INT_MAX);

        for(int i=1; i<=n; i++) {
            prev[i] = matrix[0][i-1];
        }

        for(int i=1; i<n; i++) {
            vector<int> curr(n+2, INT_MAX);
            for(int j=1; j<=n; j++) {
                curr[j] = matrix[i][j-1] + min(prev[j], min(prev[j-1], prev[j+1]));
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for(int j=1; j<=n; j++) {
            ans = min(ans, prev[j]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();


        return dpWithSpaceOptimisation(matrix, n);
    }
};