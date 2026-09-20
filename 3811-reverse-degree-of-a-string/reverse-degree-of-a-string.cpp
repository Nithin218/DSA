class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int temp=(27-((s[i]-'a')+1));
            int temp2=temp*(i+1);
            sum+=temp2;
        }
        return sum;
        
    }
};