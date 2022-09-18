class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax[n],rightMax[n];
        int temp = INT_MIN;
        for(int i=0;i<n;i++){
            temp = max(temp,height[i]);
            leftMax[i]=temp;
        }
        temp = INT_MIN;
        for(int i=n-1;i>=0;i--){
            temp = max(temp,height[i]);
            rightMax[i] = temp;
        }
        int res = 0;
        for(int i =0;i<n;i++){
            res+=min(leftMax[i],rightMax[i])-height[i];
        }
        return res;
    }
};