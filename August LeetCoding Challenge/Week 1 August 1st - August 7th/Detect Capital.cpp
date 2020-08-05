class Solution {
public:
    bool detectCapitalUse(string word) {
        bool caps=false,small=false;
        if(word[0]>'Z')
        {
            small=true;
        }
        for(int i=1;i<word.size();i++)
        {
            char ch=word[i];
            if(ch>'Z')
            {
                small=true;
            }
            if(ch<='Z')
            {
                caps=true;
            }
            if(ch<='Z' && small)
            {
                return 0;
            }
            if(ch>'Z' && caps)
            {
                return 0;
            }
        }
        return 1;
    }
};