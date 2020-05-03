/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int sol=INT_MAX;
        int flag=0;
        vector<int> v=binaryMatrix.dimensions();
        for(int i=0;i<v[0];i++)
        {
            int temp=binarySearch(binaryMatrix,i,v[1]-1);
            if(binaryMatrix.get(i,temp)==1)
            {
                sol=min(sol,temp);
                flag=1;
            }
        }
        if(flag==1)
            return sol;
        return -1;
    }
    
    int binarySearch(BinaryMatrix &binaryMatrix, int currentRow, int columns){
        int l = 0, r = columns;
        int pivot=r;
        while(r>l)
        {
            pivot=(l+r)/2;
            if(binaryMatrix.get(currentRow,pivot)==1)
            {
                r=pivot;
            }
            else
            {
                l=pivot+1;
            }
        }
        return r;
    }
};