class Solution {
public:
    string sol;
    void processing(string s, int numRows)
    {
        vector<vector<char>> v(numRows);
        int row=numRows-1;
        bool flag=false;
        for(int i=0;i<s.length();i++)
        {
            
            int index=i%row;
            if(index==0)
                flag=!flag;
            if(!flag)
                index=row-index;
            v[index].push_back(s[i]);
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                sol+=v[i][j];
            }
        }
    }
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        processing(s,numRows);
        return sol;
    }
};
