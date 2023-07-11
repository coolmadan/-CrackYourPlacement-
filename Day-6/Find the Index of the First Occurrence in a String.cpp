class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())
            return -1;
        queue<char>q1;
        queue<char>q2;
        int sp=0;
        int ep=0;
        int j =0;
        while(j<needle.size())
        {
            q1.push(needle[j]);
            j++;
        }
        int k =needle.size();
        while(ep<haystack.size())
        {
            q2.push(haystack[ep]);
            if(ep-sp+1<k)
                ep++;
            else if(ep-sp+1==k)
            {
                if(q1==q2)
                    return sp;
                q2.pop();
                ep++;
                sp++;
            }
        }
        return -1;
    }
};
