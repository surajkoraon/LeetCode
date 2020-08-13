class CombinationIterator {
public:
    set<string> itr;
    set<string>::iterator it;
    set<string> fun(string s, int n)
    {
        set<string> comb;
        int mask=1<<s.size();
        for(int i=1;i<mask;i++)
        {
            int num=i;
            string str;
            int j=0;
            while(num)
            {
                if(num&1)
                {
                    str+=s[j];
                }
                j++;
                num=num>>1;
            }
            if(str.size()==n)
            {
                comb.insert(str);
            }
        }
        return comb;
        
    }
    CombinationIterator(string characters, int combinationLength) {
        itr=fun(characters,combinationLength);
        it=itr.begin();
    }
    
    string next() {
        return *it++;
    }
    
    bool hasNext() {
        return !(itr.end()==it);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
