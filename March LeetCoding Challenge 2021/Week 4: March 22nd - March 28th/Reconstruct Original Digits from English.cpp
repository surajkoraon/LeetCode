class Solution {
public:
    string originalDigits(string s) {
        vector<int> v(26,0);
        string output;
        for(char ch:s)
        {
            v[ch-'a']++;
        }
        if(v['z'-'a']>0)
        {
            int count=v['z'-'a'];
            v['z'-'a']-=count;
            v['e'-'a']-=count;
            v['r'-'a']-=count;
            v['o'-'a']-=count;
            for(int i=0;i<count;i++)
                output+='0';
        }
        if(v['w'-'a']>0)
        {
            int count=v['w'-'a'];
            v['t'-'a']-=count;
            v['w'-'a']-=count;
            v['o'-'a']-=count;
            for(int i=0;i<count;i++)
                output+='2';
        }
        if(v['u'-'a']>0)
        {
            int count=v['u'-'a'];
            v['f'-'a']-=count;
            v['o'-'a']-=count;
            v['u'-'a']-=count;
            v['r'-'a']-=count;
            for(int i=0;i<count;i++)
                output+='4';
        }
        if(v['x'-'a']>0)
        {
            int count=v['x'-'a'];
            v['s'-'a']-=count;
            v['i'-'a']-=count;
            v['x'-'a']-=count;
            for(int i=0;i<count;i++)
                output+='6';
        }
        if(v['g'-'a']>0)
        {
            int count=v['g'-'a'];
            v['e'-'a']-=count;
            v['i'-'a']-=count;
            v['g'-'a']-=count;
            v['h'-'a']-=count;
            v['t'-'a']-=count;
            for(int i=0;i<count;i++)
                output+='8';
        }
        if(v['o'-'a']>0)
        {
            for(int i=0;i<v['o'-'a'];i++)
                output+='1';
        }
        if(v['t'-'a']>0)
        {
            for(int i=0;i<v['t'-'a'];i++)
                output+='3';
        }
        if(v['f'-'a']>0)
        {
            for(int i=0;i<v['f'-'a'];i++)
                output+='5';
        }
        if(v['s'-'a']>0)
        {
            for(int i=0;i<v['s'-'a'];i++)
                output+='7';
        }
        if(v['i'-'a']-v['f'-'a']>0)
        {
            for(int i=0;i<v['i'-'a']-v['f'-'a'];i++)
                output+='9';
        }
        sort(output.begin(),output.end());
        return output;
    }
};
