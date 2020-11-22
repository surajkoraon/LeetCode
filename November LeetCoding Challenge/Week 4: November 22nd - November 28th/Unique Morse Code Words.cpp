class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string mp[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for(string s:words)
        {
            string tmp;
            for(char ch:s)
            {
                tmp+=mp[ch-'a'];
            }
            st.insert(tmp);
        }
        return st.size();
    }
};
