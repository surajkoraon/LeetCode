class Solution {
public:
    int maxPower(string s) {
        if(s.size()==0)
            return 0;
        int arr[26];
        memset(arr,0,sizeof(arr));
        int sol=1;
        for(int i=0;i<s.size();i++)
        {
            int ch=s[i]-'a';
            if(i>0 && s[i-1]-'a'==ch)
            {
                arr[ch]++;
            }
            else
            {
                arr[ch]=1;
            }
            sol=max(sol,arr[ch]);
        }
        return sol;
    }
};
