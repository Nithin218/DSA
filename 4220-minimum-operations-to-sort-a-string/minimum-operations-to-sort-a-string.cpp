
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;

        // Check if the string is already sorted
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        // Cannot sort an unsorted string of length 2
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // One operation is sufficient
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Check whether min or max occurs in the middle
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // Neither extreme character is at an end or in the middle
        return 3;
    }
};
