class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> v(5,1);
        int count=5;
        for(int i=1;i<n;i++)
        {
            int temp2;                  
            int temp=v[0];          //storing value before updation
            v[0]=count;
            int sum=v[0];
            for(int j=1;j<5;j++)
            {
                temp2=v[j];         //storing value before updaion for current index
                v[j]=count-temp;
                sum+=v[j];
                count-=temp;
                temp=temp2;
            }
            count=sum;
        }
        return count;
    }
};
