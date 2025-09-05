class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int>result;
        for(int x:nums1){
            bool found=false;
            int ans=-1;
        for(int i=0;nums2.size();i++){
            if(nums2[i]==x){
                for(int j=i+1;j<nums2.size();j++){
                    if(nums2[j]>x){
                        ans=nums2[j];
                        found=true;
                        break;
                    }
                }
                break;

            }
        }
        result.push_back(ans);
        }
        return result;


        
    }
};