class Solution {
public:
    int reachNumber(int target) {
        int current=0,steps=0;
        target=abs(target);
        while(current<target || (current+target)&1)
            current+=++steps;
        return steps;
    }
};
