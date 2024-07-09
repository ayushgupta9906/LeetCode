class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char ch : s)
        {
            if(st.empty())
            {
                st.push(ch);
            }
            else
            {
                int temp = st.top();
                if(ch == ')' && temp == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }
        int n = st.size();
        return n;
    }
};