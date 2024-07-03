class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(v.begin(),v.end());
        int i = 0;
        int j = 1;
        int ans = 0;
        while(j < v.size())
        {
            if(v[i][1] <= v[j][0])
            {
                i = j;
                j++;
            }
            else if(v[i][1]<=v[j][1])    // [1,3] [2,4]
            {
                ans++;
                j++;
            }
            else if(v[i][1] > v[j][1]) // [1,3] [1,2] we will remove larger interval
            {
                ans++;
                i = j;
                j++;
            }
        }
        return ans;
    }
};