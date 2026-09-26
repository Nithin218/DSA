class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
           string ans;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                // Find closing bracket
                int j = i + 1;

                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check hashmap
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

                // Move i after ')'
                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};