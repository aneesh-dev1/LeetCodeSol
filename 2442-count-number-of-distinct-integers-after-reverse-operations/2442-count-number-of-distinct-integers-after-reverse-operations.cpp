class Solution {
public:
    int reverser(int num){
        int ans = 0;
        while(num != 0 ){
            int temp = num%10;
            ans = ans*10 + temp;
            num/=10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums)
            s.insert(it);
        for(int i=0;i<nums.size();i++){
            s.insert(reverser(nums[i]));
        }
        return s.size();
    }
};