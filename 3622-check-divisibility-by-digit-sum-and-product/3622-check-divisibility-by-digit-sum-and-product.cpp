class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int num=n;
        while(num>0){
            int digit=num%10;
            sum+=digit;
            prod*=digit;
            num=num/10;
        }
        if(n%(sum+prod)==0)return true;
        return false;
    }
};