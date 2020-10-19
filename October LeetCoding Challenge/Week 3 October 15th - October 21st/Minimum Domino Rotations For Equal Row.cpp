class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int target=-1;
        int arr[6];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
        {
            if(A[i]==B[i])
            {
                if(++arr[A[i]-1]==n)
                {
                    target=A[i];
                    break;
                }
                continue;
            }
            if(++arr[A[i]-1]==n)
            {
                target=A[i];
                break;
            }
            if(++arr[B[i]-1]==n)
            {
                target=B[i];
                break;
            }
        }
        if(target==-1)
            return -1;
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]!=target)
                a++;
            if(B[i]!=target)
                b++;
        }
        return min(a,b);
    }
};
