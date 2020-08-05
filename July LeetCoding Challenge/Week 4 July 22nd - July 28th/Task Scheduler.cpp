class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        int time=0;
        int sol=0;
        //int count=0;
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;
        for(char ch:tasks)
        {
            m[ch]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push({it->second,it->first});
        }
        vector<pair<int,char>> v;
        while(!pq.empty())
        {
            time++;
            v.push_back(pq.top());
            pq.pop();
            if(pq.empty() || time==n+1)
            {
                sol+=time;
                for(auto it:v)
                {
                    if(it.first-1>0)
                    {   
                        pair<int,char> p;
                        p=make_pair(it.first-1,it.second);
                        pq.push(p);
                    }
                }
                v.clear();
                if(!pq.empty())
                    sol+=n+1-time;
                time=0;
            }
        }
        return sol;
    }
};
