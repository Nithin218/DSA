class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        for (int i = 31; i >= 0; i--) {
            uint32_t power = (1U << i);

            if (n >= power) {
                n -= power;
                count++;
            }
        }

        return count;
    }
};