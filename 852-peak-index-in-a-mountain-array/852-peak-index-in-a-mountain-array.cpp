class Solution {
private:
    int solve(vector<int> arr,int low,int high){
        while(low<high-1){
            int mid = (low+high)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid] > arr[mid+1])
                high = mid-1;
            else
                low = mid+1;
        }
        return arr[low] > arr[high] ? low:high;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ans = solve(arr,0,n-1);
        return ans;
    }
};