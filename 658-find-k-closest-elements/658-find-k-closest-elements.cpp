class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {\
        int n = arr.size();
        sort(arr.begin(),arr.end(),[x](int a,int b){
            if(abs(a-x)==abs(b-x))
                return a<b;
            return abs(a-x)<abs(b-x);
        });
        auto ans = vector<int>(arr.begin(),arr.begin()+k);
        sort(ans.begin(),ans.end());                                                           
        return ans;
        
    }
};