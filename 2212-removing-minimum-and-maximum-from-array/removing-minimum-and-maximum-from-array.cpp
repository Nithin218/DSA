class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        int mxi=0,mni=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxi=i+1;
            }
            if(nums[i]<mn){
                mn=nums[i];
                mni=i+1;
            }
        }
        int minb=n-mni+1;
        int maxb=n-mxi+1;
        int ans1=max(minb,maxb);
        int ans2=max(mni,mxi);
        int ans3=mxi+minb;
        int ans4=maxb+mni;
        int temp1=min(ans1,ans2);
        int temp2=min(ans3,ans4);
        int ans=min(temp1,temp2);

    return ans;
    }
};