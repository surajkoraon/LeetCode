class Solution {
public:
    int nextGreaterElement(int n) {
        string t=to_string(INT_MAX);
        string s=to_string(n);
        string str=s;
        while(next_permutation(s.begin(),s.end()))
        {
            if(s>t && s.size()>=t.size())
                return -1;
            if(s>str)
                return stoi(s);
        }
        return -1;
    }
};
