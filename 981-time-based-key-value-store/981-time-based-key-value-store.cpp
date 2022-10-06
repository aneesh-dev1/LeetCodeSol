class TimeMap {
private:
    unordered_map<string,vector<pair<string,int>>> mapper; // key ,{value,timestamp}
    string searcher(vector<pair<string,int>> &vector,int timeStamp){
        int start = 0,end = vector.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(vector[mid].second > timeStamp)
                end = mid-1;
            else if(vector[mid].second < timeStamp)
                start = mid+1;
            else
                return vector[mid].first;
        }
        return end >=0 ?vector[end].first : "";
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapper[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mapper.find(key) == mapper.end())
            return "";
        return searcher(mapper[key],timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */