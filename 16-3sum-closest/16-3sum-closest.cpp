class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
       sort(nums.begin(),nums.end());
        int left,right,ans = 0,diff = INT_MAX;
        int i=1;
        for(int i=0;i<nums.size();i++){
            left = i+1,right = n-1;
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i];
            if(abs(sum-target) < diff){
                diff = abs(sum-target);
                ans = sum;
            }
            else if(sum == target)
                return sum;
            else if(sum > target)
                right--;
            else
                left++;
            }
        }
        return ans;
    }
};