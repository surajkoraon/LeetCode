class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3 || arr[0]>arr[1])
            return false;
        bool flag=false;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(flag && arr[i+1]>=arr[i])
                return false;
            else if(arr[i+1]<arr[i])
                flag=true;
            else if(arr[i]==arr[i+1])
                return false;
        }
        return flag;
    }
};
