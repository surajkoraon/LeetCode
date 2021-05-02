class Solution {
public:
    int a=0,b=0,n;
    void isVowel(char ch,int index)
    {
        if(tolower(ch)=='a' || tolower(ch)=='e' || tolower(ch)=='i' || tolower(ch)=='o' || tolower(ch)=='u')
        {
            if(index<n/2)
                a++;
            else
                b++;
        }
    }
    bool halvesAreAlike(string s) {
        n=s.length();
        for(int i=0;i<n;i++)
        {
            isVowel(s[i],i);
        }
        return a==b;
    }
};
