class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
        {
            int c=s[i]-'a';
            arr[c]++;
            c=t[i]-'a';
            arr[c]--;
        }
        arr[t[t.length()-1]-'a']--;
        for(int i=0;i<26;i++)
            if(arr[i]==-1)
                return char('a'+i);
        return ' '; 
    }
};
