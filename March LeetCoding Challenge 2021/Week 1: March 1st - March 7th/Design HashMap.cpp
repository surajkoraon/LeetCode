class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<pair<int,int>> v;
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==key)
            {
                v[i].second=value;
                return; 
            }
        }
        v.push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==key)
                return v[i].second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==key)
            {
                v.erase(v.begin()+i);
                return;
            }
        }
    }
};
