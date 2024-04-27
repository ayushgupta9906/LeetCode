class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (c >= 1) {
                    ans += s[i];
                }
                c++;
            } else { // s[i] == ')'
                if (c >= 2) {
                    ans += s[i];
                }
                c--;
            }
        }
        
        return ans;
    }
};