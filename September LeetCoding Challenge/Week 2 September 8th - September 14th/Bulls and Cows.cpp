class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0,b=0;
        map<pair<char,int>,int> m1;
        map<int,int> m2;
        for(int i=0;i<secret.length();i++)
        {
            m1[{secret[i],i}]=0;
            m2[secret[i]]++;
        }
        for(int i=0;i<guess.length();i++)
        {
            if(m1.count({guess[i],i})>0)
                a++;
            if(m2.count(guess[i])>0 && m2[guess[i]]>0)
            {
                b++;
                m2[guess[i]]--;
            }
        }
        return to_string(a)+'A'+to_string(b-a)+'B';
    }
};
