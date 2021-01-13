class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end(),[&](int a,int b){
            return a>b;
        });
        int i=0,j=n-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
                j--;
            i++;
        }
        return i;
    }
};
