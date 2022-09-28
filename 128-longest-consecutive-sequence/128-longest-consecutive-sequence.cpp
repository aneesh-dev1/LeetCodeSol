class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int l = 0;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        for(int i=0;i<nums.size();i++){
            int temp = 0;
            if(s.find(nums[i]-1) == s.end()){
                int var = nums[i];
                while(s.find(var++) != s.end()){
                    temp++;
                }
                l = max(l,temp);
            }
        }
        return l;
    }
};