class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1;
        long long num = n;
        if(num<0){
            num *= -1;
        }
        while(num){
            if(num%2==1){
                answer *= x;
            }
            num /= 2;
            x *= x;
        }
        if(n<0)answer = 1/answer;
        return answer;
    }
};

