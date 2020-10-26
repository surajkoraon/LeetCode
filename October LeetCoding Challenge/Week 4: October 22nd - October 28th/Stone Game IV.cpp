class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n==1)
            return true;
        if(n==2)
            return false;
        bool arr[n+1];
        arr[1]=true;
        arr[2]=false;
        for(int i=3;i<=n;i++)
        {
            if((int)sqrt(i)*(int)sqrt(i)==i)
            {
                arr[i]=true;
                continue;
            }
            int j=1;
            while(j*j<=i)
            {
                if(arr[i]=!arr[i-(j*j)])
                    break;
                j++;
            }
        }
        return arr[n];
    }
};
