class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long x = (num/3) - 1;
        vector<long long> res;
        if((3*x + 3)==num){
            res.push_back(x);
            res.push_back(x+1);
            res.push_back(x+2);
        }
        return res;
    }
};