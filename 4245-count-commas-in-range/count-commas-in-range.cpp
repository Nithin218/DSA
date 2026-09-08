class Solution {
public:
    int countCommas(int n) {
        int ans=n;
        int cnt=0;
        if(ans>=100000){
            ans=ans-100000;
            cnt+=ans;
            ans=100000;

        }
        if(ans>=10000){
            ans=ans-10000;
            cnt+=ans;
            ans=10000;
        }
        if(ans>=1000){
            ans=ans-1000;
            cnt+=ans+1;

        }
    
        if(n<1000){
            return 0;
        }
        return cnt;
        
    }
};