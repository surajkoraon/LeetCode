class Solution {
public:
    unordered_map<string,bool> words;
    unordered_map<string,string> lowercase;
    unordered_map<string,string> vowels;
    vector<string> answer;
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for(string word:wordlist)
        {
            if(words.count(word)==0)
                words[word]=true;
            string str1,str2;
            for(char ch:word)
            {
                if(tolower(ch)=='a'|| tolower(ch)=='e' || tolower(ch)=='i' || tolower(ch)=='o' || tolower(ch)=='u')
                    str1+='*';
                else
                    str1+=tolower(ch);
                str2+=tolower(ch);
            }
            if(lowercase.count(str2)==0)
                lowercase[str2]=word;
            if(vowels.count(str1)==0)
                vowels[str1]=word;
        }
        for(string query:queries)
        {
            string str1,str2;
            for(char ch:query)
            {
                if(tolower(ch)=='a'|| tolower(ch)=='e' || tolower(ch)=='i' || tolower(ch)=='o' || tolower(ch)=='u')
                    str1+='*';
                else
                    str1+=tolower(ch);
                str2+=tolower(ch);
            }
            if(words.count(query)>0)
            {
                answer.push_back(query);
            }
            else if(lowercase.count(str2)>0)
            {
                answer.push_back(lowercase.find(str2)->second);
            }
            else
            {
                if(vowels.count(str1)>0)
                {
                    answer.push_back(vowels.find(str1)->second);
                }
                else
                {
                    answer.push_back("");
                }
            }
        }
        return answer;
    }
};
