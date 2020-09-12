class Solution {
public:
    vector<vector<int>> v;
    void recurse(int k,int n,vector<bool> arr,int sum,vector<int> &vec)
    {
        if(sum>n)
            return;
        if(k==0)
        {
            if(sum==n)
                v.push_back(vec);
            return;
        }
        for(int i=1;i<10;i++)
        {
            if(!arr[i] && sum+i<=n)
            {
                vec.push_back(i);
                arr[i]=true;
                recurse(k-1,n,arr,sum+i,vec);
                vec.erase(vec.end()-1);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> arr(10,false);
        vector<int> vec;
        recurse(k,n,arr,0,vec);
        return v;
    }
};
