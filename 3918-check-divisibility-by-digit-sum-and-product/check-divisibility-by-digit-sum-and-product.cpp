class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int mul=1;
        int m=n;
        while(n>0){
            int x=n%10;
            sum=sum+x;
            mul=mul*x;
            n=n/10;
        }
        int temp=sum+mul;
        if(m%temp==0){
            return true;
        }
        return false;
    }
};