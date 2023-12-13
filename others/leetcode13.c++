class Solution {
public:
    int convert(char in)
    {
        if(in == 'I')
            return 1;
        else if(in == 'V')
            return 5;
        else if(in == 'X')
            return 10;
        else if(in == 'L')
            return 50;
        else if(in == 'C')
            return 100;
        else if(in == 'D')
            return 500;
        else if(in == 'M')
            return 1000;
        else
            return -1;
    }
    int romanToInt(string s) {
        int i=0;
        int res = 0;
        int size = s.size();
        
        while(i<size-1)
        {
            int tmp = convert(s[i]);
            if(tmp < convert(s[i+1]))
            {
                res -= tmp;
            }
            else
            {
                res += tmp;
            }
            i++;
        }
        res += convert(s[size-1]);

        return res;
    }
};
