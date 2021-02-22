class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n=s.length();
        int maxLen=0;
        string str;
        for(string word:d)
        {
            int i=0,j=0,m=word.length();
            while(i<n && j<m)
            {
                if(s[i]==word[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            if((j==m) && ((m>maxLen) || (m==maxLen && word<str)))
            {
                maxLen=m;
                str=word;
            }
        }
        return str;
    }
};