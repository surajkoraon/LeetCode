class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> v(num_people,0);
        int i=0;
        int j=1;
        while(candies)
        {
            i=i%num_people;
            v[i]+=min(j,candies);
            candies-=min(j,candies);
            i++;
            j++;
        }
        return v;
    }
};
