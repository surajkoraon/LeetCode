class LRUCache {
public:
int cap;
map<int, pair<int, list<int>::iterator>> m;
list<int> l;
LRUCache(int capacity) {
    cap=capacity;  
}

int get(int key) {
    if(m.find(key)==m.end()) 
        return -1;
    else
    {
        l.erase(m[key].second);
        l.push_front(key);
        m[key].second=l.begin();
        return m[key].first;
    }
}

void put(int key, int value) {
    if(m.find(key)!=m.end())
    {
        l.erase(m[key].second);
        l.push_front(key);
        m[key].second=l.begin();
        m[key].first=value;
    }
    else
    {
        if(m.size() < cap)
        {
            l.push_front(key);
            m[key]={value, l.begin()};
        }
        else
        {
            m.erase(l.back());
            l.pop_back();
            l.push_front(key);
            m[key]={value, l.begin()};
        }    
    }        
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */