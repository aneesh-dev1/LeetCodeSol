class Solution {
public:
    int maxArea(vector<int>& height) {
       int currArea= INT_MIN;
        int si = 0;
        int ei = height.size()-1;
        int maxArea = INT_MIN;
        while(si<ei){
           if(height[si]>height[ei])
               currArea = height[ei]*(ei-si);
           else{
               currArea = height[si]*(ei-si);
           }    
            maxArea = max(maxArea,currArea);
        if(height[si] > height[ei]) ei--;
         else si ++;
        }
        return maxArea;
    }
};