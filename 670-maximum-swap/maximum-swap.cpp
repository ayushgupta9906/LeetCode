
class Solution {
public:
    int maximumSwap(int num) {
        std::string num_str = std::to_string(num);
        int n = num_str.size();
        std::vector<int> max_right(n);
        max_right[n - 1] = n - 1;
        
        for (int i = n - 2; i >= 0; --i) {
            if (num_str[i] > num_str[max_right[i + 1]]) {
                max_right[i] = i;
            } else {
                max_right[i] = max_right[i + 1];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (num_str[i] < num_str[max_right[i]]) {
                std::swap(num_str[i], num_str[max_right[i]]);
                break;
            }
        }
        
        return std::stoi(num_str);
    }
};
