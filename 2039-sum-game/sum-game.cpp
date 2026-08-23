class Solution {
public:
    bool sumGame(string num) {
        int first = 0;
        int sec = 0;
        int l = 0;
        int r = 0;

        for (int i = 0; i < num.size(); i++) {
            if (i < num.size() / 2) {
                if (num[i] == '?') {
                    l++;
                } else {
                    first += num[i] - '0';
                }
            }
            else {
                if (num[i] == '?') {
                    r++;
                } else {
                    sec += num[i] - '0';
                }
            }
        }

        int cur = first - sec;
        int temp = l - r;

        if (temp % 2 != 0) {
            return true;
        }

        if (cur == -9 * temp / 2) {
            return false;
        }

        return true;
    }
};