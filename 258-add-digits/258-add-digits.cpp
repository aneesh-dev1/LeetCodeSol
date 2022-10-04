class Solution {
private:
    int digitCounter(int n){
        int ctr = 0;
        while(n!=0){
            ctr++;
            n /=10;
        }
        return ctr;
    }
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        while(digitCounter(num)!=1){
            int sum = 0;
            while(num!=0){
                sum += num%10;
                num/=10;
            }
            num = sum;
        }
        return num;
    }
};