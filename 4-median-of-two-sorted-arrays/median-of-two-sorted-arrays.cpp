class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int c = v1.size() + v2.size();
        vector<int> merged(c);

        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), merged.begin());

        if (c % 2 == 0) {
            return (merged[c/2 - 1] + merged[c/2]) / 2.0;
        } else {
            return merged[c/2];
        }
    }
};