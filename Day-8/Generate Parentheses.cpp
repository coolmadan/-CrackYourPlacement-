class Solution {
public:
    void helper(int n ,string &str, vector<string>&res,int openCount,int closeCount){
        if(openCount==n&&closeCount==n){
            res.push_back(str);
            return;
        }
        if(openCount<n){
            str+='(';
            helper(n,str,res,openCount+1,closeCount);
            str.pop_back();
        }
        if (closeCount<openCount){
            str+=')';
            helper(n,str,res,openCount,closeCount+1);
            str.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string str="";
        helper(n,str,res,0,0);
        return res;
    }
};
