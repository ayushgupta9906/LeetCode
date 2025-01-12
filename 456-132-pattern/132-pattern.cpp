class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        multiset<int>st;
        int n = nums.size();
        for(int i=1;i<n;i++){
            st.insert(nums[i]);
        }
        int mini=nums[0];
        for(int i=1;i+1<n;i++){
            st.erase(st.find(nums[i]));
            int x = mini;
            int y = nums[i];
            auto it = st.upper_bound(x);
            if(it==st.end() or mini>=y or *it>=y){
                mini=min(mini,nums[i]);
            }
            else{
                return true;
            }
        }
        return false;
    }
};