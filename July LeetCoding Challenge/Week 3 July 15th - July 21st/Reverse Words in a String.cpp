class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        stack<string> st;
        string word;
        string sol;
        while(str>>word)
        {
            sol=word+" "+sol;
        }
        return sol.substr(0,sol.length()-1);
    }
};