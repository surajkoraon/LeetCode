class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size()==1 || (asteroids.size()==2 && asteroids[0]<0))
            return asteroids;
        stack<int> st;
        for(int i:asteroids)
        {
            if(i<0)
            {
                while(!st.empty() && st.top()>0 && st.top()<abs(i))
                    st.pop();
                if(!st.empty() && st.top()==abs(i))
                    {
                        st.pop();
                        continue;
                    }
                if(st.empty() || st.top()<0)
                    st.push(i);
            }
            else
                st.push(i);
        }
        vector<int> v(st.size());
        for(int i=st.size()-1;i>=0;i--)
        {
            v[i]=st.top();
            st.pop();
        }
        return v;
    }
};
