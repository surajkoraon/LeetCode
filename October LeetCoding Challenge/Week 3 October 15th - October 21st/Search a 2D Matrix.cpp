class Solution {
public:
    int binarySearchCol(vector<int>& v,int target)
    {
        int left=0,right=v.size()-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(v[mid]>target)
                right=mid-1;
            else if(v[mid]<target)
                left=mid+1;
            else
                return -2;
        }
        return right;
    }
    bool binarySearchRow(vector<int>& v,int target)
    {
        int left=0,right=v.size()-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(v[mid]>target)
                right=mid-1;
            else if(v[mid]<target)
                left=mid+1;
            else
                return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        vector<int> v;
        for(int i=0;i<matrix.size();i++)
        {
            v.push_back(matrix[i][0]);
        }
        int temp=binarySearchCol(v,target);
        if(temp==-2)
            return true;
        if(temp==-1)
            return false;
        v.clear();
        v=matrix[temp];
        return binarySearchRow(v,target);
    }
};