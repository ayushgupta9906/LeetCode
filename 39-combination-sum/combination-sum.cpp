class Solution {
public:
    void combSum(int i,int target,vector<int>& arr,vector<int>& comb,vector<vector<int>>& ans,int n)
    {
        if(i==n)
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(comb);
            return;
        }
        if(arr[i]<=target)
        {
            comb.push_back(arr[i]);
            combSum(i,target-arr[i],arr,comb,ans,n);
            comb.pop_back();
        }
        combSum(i+1,target,arr,comb,ans,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        int n=candidates.size();
        combSum(0,target,candidates,comb,ans,n);
        return ans;
    }
};