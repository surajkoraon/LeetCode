class Solution {
public:
    vector<int> sol;
    void partition(vector<pair<int,int>> v,string s)
    {
        unordered_map<int,int> m;
        int n=v.size();
        int i=0;
        int start=0;
        while(i<n)
        {
            int c=v[i].first;
            int index=v[i].second;
            if(m.count(c)==0)
            {
                m[c]=index;
            }
            else
            {
                m.erase(c);
                if(m.size()==0)
                {
                    sol.push_back(index-start+1);
                    start=index+1;
                }
            }
            i++;
        }
    }
    vector<int> partitionLabels(string S) {
        int first[26]={[0 ... 25]=-1};
        int last[26]={[0 ... 25]=-1};
        for(int i=0;i<S.length();i++)
        {
            int c=S[i]-'a';
            if(first[c]==-1)
            {
                first[c]=i;
            }
            last[c]=i;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<26;i++)
        {
            if(first[i]>=0)
            {
                pair<int,int> p={i,first[i]};
                pair<int,int> q={i,last[i]};
                v.push_back(p);
                v.push_back(q);
            } 
        }
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b)
             {
                 return a.second<b.second;
             });
        partition(v,S);
        return sol;
    }
};