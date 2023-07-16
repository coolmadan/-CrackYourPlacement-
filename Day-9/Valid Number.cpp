class Solution {
public:
    bool isNumber(string s) {
        bool eSeen=0,digitSeen=0,dotSeen=0;
        int plusMinusCount=0;
        for(int i =0;i<s.size();i++){
            char ch =s[i];
            if(ch>='0'&&ch<='9'){
                digitSeen=true;
            }else if(ch=='-'||ch=='+'){
                if(plusMinusCount==2){
                    return false;
                }
                if(i>0&&s[i-1]!='e'&&s[i-1]!='E'){
                    return false;
                }
                if(i==s.size()-1)
                    return false;
                plusMinusCount++;
            }else if(ch=='.'){
                if(dotSeen||eSeen){
                    return false;
                }
                if(i==s.size()-1&&!digitSeen)
                    return false;
                dotSeen=true;
            }else if(ch=='e'||ch=='E'){
                if(eSeen||!digitSeen||i==s.size()-1)
                    return false;
                eSeen=true;
                
            }else
            return false;
        }
        return true;
    }
};
