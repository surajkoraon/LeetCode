class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int current=-1;
        unordered_map<int,bool> m;
        stack<int> st;
        int i=0,j=0;
        int n=popped.size();
        while(i<n || j<n)
        {
            if(!st.empty() && popped[j]==current)
            {
                j++;
                st.pop();
                if(!st.empty())
                    current=st.top();
                else
                    current=-1;
            }
            else if(m.count(popped[j])==0)
            {
                current=pushed[i];
                m[current]=1;
                st.push(current);
                i++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};