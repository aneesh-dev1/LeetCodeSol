class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        
        int i=0,j=0;
        
        while(j<nums.size())
        {
            if(j-i+1<k)
            {
                j++;
            }
            if(j-i+1==k)
            {
                ans=min(ans,nums[j]-nums[i]);
                    i++;
                j++;
            }
        }
            
            
         return ans;
    }
};