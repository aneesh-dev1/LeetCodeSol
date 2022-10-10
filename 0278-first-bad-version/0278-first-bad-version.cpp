// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(n) and !isBadVersion(n-1))
            return n;
          int l=1,h=n;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isBadVersion(mid) and isBadVersion(mid-1))
                h = mid-1;
            else l=mid+1;
        }
        return h;
    }
};