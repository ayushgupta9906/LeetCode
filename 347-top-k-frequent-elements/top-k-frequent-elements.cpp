class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        int n=v.size();
        vector<int>ans;
        multiset<pair<int,int>,greater<>>ms;
        map<int,int>m;
        for(auto it:v) m[it]++;
        for(auto it:m){
            int a=it.second;
            int b=it.first;
            ms.insert({a,b});
        }
        while(k--){
            auto p=*ms.begin();
            ms.erase(ms.begin());
            ans.push_back(p.second);
        }
        return ans;
    }
};