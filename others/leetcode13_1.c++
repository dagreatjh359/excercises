class Solution {
public:
    int romanToInt(string s) {
        int i=0;
        int res = 0;
        int size = s.size();
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        while(i<size-1)
        {
            if(mp[s[i]]<mp[s[i+1]])
            {
                res -= mp[s[i]];
            }
            else
            {
                res += mp[s[i]];
            }
            i++;
        }
        res += mp[s[size-1]];

        return res;
    }
};
