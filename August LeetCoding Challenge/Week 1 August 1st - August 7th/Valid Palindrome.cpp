class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length();
        while(l < r) {
            while(l < r && !isalnum(s[l])) l++;
            while(l < r && !isalnum(s[r])) r--;
            char c1 = tolower(s[l]);
            char c2 = tolower(s[r]);
            if(c1 != c2) return false;
            l++;
            r--;
        }
        return true;
    }
};