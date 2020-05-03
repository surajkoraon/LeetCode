class FirstUnique {
    unordered_map<int,list<int>::iterator> m;
    list<int> l;
public:
    FirstUnique(vector<int>& nums) {
        for(int i:nums)
        {
            if(m.find(i)!=m.end())
            {
                auto it=m[i];
                if(it!=l.end())
                {
                    l.erase(it);
                    m[i]=l.end();
                }
            }
            else
            {
                l.push_back(i);
                auto it=l.end();
                m[i]=--it;
            }
        }
    }
    
    int showFirstUnique() {
        if(l.size()==0)
            return -1;
        return *(l.begin());
    }
    
    void add(int value) {
         if(m.find(value)!=m.end())
            {
                auto it=m[value];
                if(it!=l.end())
                {
                    l.erase(it);
                    m[value]=l.end();
                }
            }
            else
            {
                l.push_back(value);
                auto it=l.end();
                m[value]=--it;
            }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */