class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i<=n;i++){
            if((n%(i))==0){
                int ans1=nums[i-1];
                ans+=(ans1*ans1);
            }
        }
        return ans;
    }
};