class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m=version1.length();
        int n=version2.length();
        int sum1=0,sum2=0;
        int i=0,j=0;
        while(i<m || j<n)
        {
            while(i<m && version1[i]!='.')
            {
                sum1=sum1*10+(version1[i]-'0');
                i++;
            }
            while(j<n && version2[j]!='.')
            {
                sum2=sum2*10+(version2[j]-'0');
                j++;
            }
            if(sum1>sum2)
                return 1;
            if(sum1<sum2)
                return -1;
            sum1=0;
            sum2=0;
            i++;
            j++;
        }
        return 0;
    }
};
