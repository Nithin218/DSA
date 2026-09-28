class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int maxi=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                st.pop();
            }
            int size=st.size();
            maxi=max(size,maxi);


        }
        return maxi;
    }
};