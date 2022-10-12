class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int perimeter = 0;
        int n = nums.size()-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]+nums[i+1]>nums[i+2])
                perimeter = max(perimeter,nums[i]+nums[i+1]+nums[i+2]);
        }
        return perimeter;
    }
};