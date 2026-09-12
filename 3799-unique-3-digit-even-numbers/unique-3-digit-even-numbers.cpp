class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        vector<int> freq(10, 0);

        for (int x : digits) {
            freq[x]++;
        }

        int ans = 0;

        // Last digit must be even
        for (int last = 0; last <= 8; last += 2) {

            if (freq[last] == 0)
                continue;

            freq[last]--;

            // First digit cannot be zero
            for (int first = 1; first <= 9; first++) {

                if (freq[first] == 0)
                    continue;

                freq[first]--;

                // Count DISTINCT possible middle digits
                for (int middle = 0; middle <= 9; middle++) {

                    if (freq[middle] > 0) {
                        ans++;
                    }
                }

                freq[first]++;
            }

            freq[last]++;
        }

        return ans;
    }
};