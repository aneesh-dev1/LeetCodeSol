class Solution {
private:
    int solution(vector<int> arr,int low,int high){
            if(low == high)
                return low;
            while(low < high-1){
                int mid = low + (high - low) / 2;
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] )
                    return mid;
                else if(arr[mid] < arr[mid+1])
                    low = mid+1;
                else
                    high = mid-1;
            }
        return arr[low] > arr[high]?low:high;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = solution(nums,0,n-1);
        return ans;
    }
};