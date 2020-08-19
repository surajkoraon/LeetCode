class Solution {
public:
    string toGoatLatin(string S) {
        stringstream s(S);
        string word,str;
        string suffix="a";
        while(s>>word)
        {
            string temp;
            if(tolower(word[0])=='a' || tolower(word[0])=='e' || tolower(word[0])=='i' || tolower(word[0])=='o'                 || tolower(word[0])=='u')
            {
                temp=word+"ma";  
            }
            else
            {
                temp=word.substr(1,word.size()-1)+word[0]+"ma";   
            }
            temp+=suffix;
            suffix+='a';
            str+=temp+" ";
        }
        return str.substr(0,str.size()-1);
    }
};
