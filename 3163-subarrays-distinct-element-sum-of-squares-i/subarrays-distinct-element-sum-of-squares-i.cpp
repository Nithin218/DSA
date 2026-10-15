class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = i; j < n; j++) {
                auto it = s.find(nums[j]);

                
                    s.insert(nums[j]);
                    int siz=s.size();
                    ans +=siz*siz ;
                
            }
        }
        return ans;
    }
};