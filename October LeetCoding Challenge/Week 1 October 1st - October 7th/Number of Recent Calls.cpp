
class RecentCounter {
    map<int,bool> m;
public:
    int ping(int t) 
    {
        m[t]=true;
        auto it=m.begin();
        while(t-3000>it->first)
        {
            m.erase(it);
            it=m.begin();  
        }
        return m.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */