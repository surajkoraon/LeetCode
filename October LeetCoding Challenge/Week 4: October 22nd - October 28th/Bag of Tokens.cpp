class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.size()==0)
            return 0;
        sort(tokens.begin(),tokens.end());
        if(P<tokens[0])
            return 0;
        int l=0;
        int r=tokens.size()-1;
        int score=0;
        int maxScore=0;
        while(l<=r)
        {
            while(l<=r && P>=tokens[l])
            {
                score++;
                P-=tokens[l++];
                maxScore=max(maxScore,score);
            }
            if(score>=1)
            {
                P+=tokens[r--];
                score--;
            }
        }
        return maxScore;
    }
};
