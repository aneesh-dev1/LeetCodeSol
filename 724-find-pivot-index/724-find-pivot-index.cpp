class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>preSum(n);
        preSum[0]=nums[0];
        int sum=nums[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            if((preSum[i]-nums[i])== (sum-preSum[i])){
                return i;
            }
        }
        return -1;
    }
};