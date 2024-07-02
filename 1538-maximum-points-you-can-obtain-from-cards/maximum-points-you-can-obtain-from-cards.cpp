class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        int maxsum = sum;
        int lindex = k-1;
        int rindex = cardPoints.size()-1;
        while(lindex >= 0 ){
            sum -= cardPoints[lindex];
            sum += cardPoints[rindex];
            rindex--;
            lindex--;
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};