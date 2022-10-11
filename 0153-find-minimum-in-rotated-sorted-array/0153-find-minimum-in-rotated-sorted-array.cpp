class Solution {
public:
    int findMin(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
         int left=0,right=nums.size()-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right]) left=mid+1;
        else if(nums[mid]<nums[right]) right=mid;
        else return nums[right];
    }
    return nums[left];
    }
};