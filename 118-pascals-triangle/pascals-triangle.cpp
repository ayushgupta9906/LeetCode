class Solution {
public:
    // Function to generate a single row of Pascal's Triangle
    vector<int> generateRow(int rowNum) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < rowNum; col++) {
            ans = ans * (rowNum - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    // Function to generate the entire Pascal's Triangle
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
