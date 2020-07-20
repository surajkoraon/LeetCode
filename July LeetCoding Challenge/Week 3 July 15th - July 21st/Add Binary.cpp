class Solution {
public:
    string carry="0";
    string ans;
    string addBinary(string a, string b) {
        int i,j;
        for(i=a.size()-1,j=b.size()-1;i>=0&&j>=0;i--,j--)
        {
            string sum;
            if(a[i]=='1')
                sum+="1";
            if(b[j]=='1')
                sum+="1";
            if(carry=="1")
                sum+="1";
            if(sum.size()==3)
            {
                ans="1"+ans;
                carry="1";
            }
            else if(sum.size()==2)
            {
                ans="0"+ans;
                carry="1";
            }
            else if(sum.size()==1)
            {
                ans="1"+ans;
                carry="0";
            }
            else if(sum.size()==0)
            {
                ans="0"+ans;
                carry="0";
            }
        }
        int index;
        if(i>=0)
        {
            while(i>=0)
            {
                string sum;
                if(a[i]=='1')
                    sum+="1";
                if(carry=="1")
                    sum+="1";
                if(sum.size()==2)
                {
                    ans="0"+ans;
                    carry="1";
                }
                else if(sum.size()==1)
                {
                    ans="1"+ans;
                    carry="0";
                }
                else if(sum.size()==0)
                {
                    ans="0"+ans;
                    carry="0";
                }
                i--;
            }
        }
        else
        {
            while(j>=0)
            {
                string sum;
                if(b[j]=='1')
                    sum+="1";
                if(carry=="1")
                    sum+="1";
                if(sum.size()==2)
                {
                    ans="0"+ans;
                    carry="1";
                }
                else if(sum.size()==1)
                {
                    ans="1"+ans;
                    carry="0";
                }
                else if(sum.size()==0)
                {
                    ans="0"+ans;
                    carry="0";
                }
                j--;
            }
        }
        if(carry=="1")
            ans="1"+ans;
        if(ans=="")
            return "0";
        return ans;
    }
};