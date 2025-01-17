class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int end = numbers.size() - 1;
        for(int i = 0; i < numbers.size(); i++){
            while(numbers[end] > target - numbers[i]){
                end--;
            }
            if(numbers[end] == target - numbers[i]) return {i + 1, end + 1};
        }
        return {-1, -1};
    }
};