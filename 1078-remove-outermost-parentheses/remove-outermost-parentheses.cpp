class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                // If stack is not empty, this is not outermost '('
                if (!st.empty()) {
                    ans.push_back('(');
                }

                st.push('(');
            }

            else {
                st.pop();

                // If stack is not empty, this is not outermost ')'
                if (!st.empty()) {
                    ans.push_back(')');
                }
            }
        }

        return ans;
    }
};