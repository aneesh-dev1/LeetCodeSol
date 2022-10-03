class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        int ans = 0;
        if(n1%2 == 0 && n2%2 ==0)
            return 0;
        else if(n1%2 == 0 && n2%2 != 0){
            for(auto it:nums1){
                ans^=it;
            }   
        }
        else if(n1%2!=0 && n2%2 ==0)
            for(int i=0;i<nums2.size();i++)
                ans^=nums2[i];
        else{
            int temp1=0,temp2 = 0;
            for(auto it:nums1)
                temp1^=it;
            for(auto it:nums2)
                temp2^=it;
            ans = temp1^temp2;
        }
        return ans;
    }
};