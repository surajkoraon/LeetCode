class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int a = 0, b = 0;

        while (i >= 0 || j >= 0) 
        {
            while (i >= 0) 
            {
                if (S[i] == '#') 
                {
                    a++;
                    i--;
                }
                else if(a > 0) 
                {
                    a--;
                    i--;
                }
                else break;
            }
            while (j >= 0) 
            {
                if (T[j] == '#') 
                {
                    b++;
                    j--;
                }
                else if(b > 0) 
                {
                    b--;
                    j--;
                }
                else break;
            }
            if (i >= 0 && j >= 0 && S[i] != T[j])
                return false;
            if ((i >= 0) != (j >= 0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};