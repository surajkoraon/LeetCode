/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        int size=coins.size();
        if(size==0)
            return 0;
        int dp[amount+1][size];
        for(int i=0;i<size;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<size;j++)
            {
                int a=j>0?dp[i][j-1]:0;
                int b=(i-coins[j])>=0?dp[i-coins[j]][j]:0;
                dp[i][j]=a+b;
            }
        }
        return dp[amount][size-1];
    }
};
