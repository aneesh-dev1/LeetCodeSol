class Solution {
public:
    bool static compare(vector<int> &a,vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),compare);
        int n = v.size();
        int count = 0;
        int maxi = v[n-1][1];
        for(int i=n-2;i>=0;i--){
            if(v[i][1]<maxi){
                count++;
            }
            maxi = max(maxi,v[i][1]);
        }
        return count;
    }
};