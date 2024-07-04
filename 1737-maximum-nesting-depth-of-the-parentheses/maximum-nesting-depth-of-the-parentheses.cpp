class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        stack<char>stack; 
        for (char c : s) {
            if (c == '(') {
                stack.push(c); 
            }
            else if (c == ')') { 
                res = max(res, static_cast<int>(stack.size())); 
                stack.pop(); 
            }
        }
        return res;
    }
};