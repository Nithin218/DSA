class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        // first & last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int,int>> intervals;

        // build valid intervals
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (i != first[c]) continue;

            int end = last[c];
            bool valid = true;

            for (int j = i; j <= end; j++) {
                int x = s[j] - 'a';

                if (first[x] < i) {
                    valid = false;
                    break;
                }

                end = max(end, last[x]);
            }

            if (valid) intervals.push_back({i, end});
        }

        // greedy by end
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prev_end = -1;

        for (auto &it : intervals) {
            if (it.first > prev_end) {
                ans.push_back(s.substr(it.first, it.second - it.first + 1));
                prev_end = it.second;
            }
        }

        return ans;
    }
};