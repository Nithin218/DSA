class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int x=nums[0];
        int maxi=INT_MIN;
        int maxi1=INT_MIN;
    map<int,int> mp;
        int y=nums[n-1];
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,nums[i]);
          
        }
        if(k==1){
            for(auto &it:mp){
                if(it.second==1){
                    maxi1=max(maxi1,it.first);
                   
                }
            }
            if(maxi1!=INT_MIN)
             return maxi1;
         

        }
        else if(k==n){
          return maxi;
        }
        else{
        if(mp[x]==1&&mp[y]==1){
            if(x>y){
                return x;
            }
            else{
                return y;
            }
        }
        if(mp[y]==1){
            
                return y;
            
        }
        if(mp[x]==1){
            
                return x;
            
        }
        }
        return -1;
    }
};