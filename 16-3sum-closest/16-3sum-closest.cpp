class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left,right,ans = 0,diff = INT_MAX;
        for(int i=0;i<nums.size();i++){
            left = i+1,right = nums.size()-1;
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i];
                if(abs(target-sum)<diff){
                    ans = sum;
                    diff = abs(target-sum);
                }
                else if(target == sum)
                    return sum;
                else if(target<sum)
                    right--;
                else
                    left++;
            }
        }
        return ans;
    }
};