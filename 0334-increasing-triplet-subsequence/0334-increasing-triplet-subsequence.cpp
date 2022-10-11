class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int prev = INT_MAX,mid = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid)
                return true;
            if(nums[i]<prev)
                prev = nums[i];
            else if(nums[i]>prev && nums[i]<mid)
                mid = nums[i];
        }
        return false;
    }
};