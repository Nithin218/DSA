class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      
        int i = 0;
        int max1 = -1;
        int sum = 0;
        int sum1 = 0;
        
        for (int k = 0; k < nums.size(); k++) {
            sum1 += nums[k];
        }

        int y = sum1 - x;

        if (y < 0)
            return -1;

        if (y == 0)
            return nums.size();

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            
            while (sum > y) {
                sum = sum - nums[i];
                i++;
            }

            if (sum == y) {
                max1 = max(j - i + 1, max1);
            }
        }

        if (max1 == -1) {
            return -1;
        }

        return nums.size() - max1;
    }
};