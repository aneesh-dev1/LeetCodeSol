class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i=0, j=0, bit=0;
        while(i<n && j<n){
            while((bit&nums[j])!=0){
                bit^=nums[i];
                i++;
            }
            bit|=nums[j];
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};