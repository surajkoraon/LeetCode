class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,long> m;
        long count=0;
        for(int x:arr)
            m[x]++;
        for(auto itr1:m)
        {
            for(auto itr2:m)
            {
                int a=target-(itr1.first)-(itr2.first);
                if(m.count(a)==0)
                    continue;
                if(itr1.first==itr2.first && itr1.first==a)
                {
                    count+=(m[a]*(m[a]-1)*(m[a]-2))/6;
                }
                else if(itr1.first==itr2.first)
                {
                    count+=(itr1.second*(itr1.second-1)*m[a])/2;
                }
                else if(itr1.first<itr2.first&&itr2.first<a)
                {
                    count+=m[a]*itr1.second*itr2.second;
                }
            }
        }
        count=count%1000000007;
        return count;
    }
};
