class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
      nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        //for finding mid elemnt
         int i=nums1.size()/2;
        if(nums1.size()%2==0){
            double d=(nums1[i]+nums1[i-1]);
            return(d/2);
        }else{
            return(nums1[i]);
        }
                   return 0;
    }
};