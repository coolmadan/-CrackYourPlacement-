class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        unordered_map<int,int>mp;
        int runningSum=0;
        int count=0;
        mp[0]=1;
        for(int i=0;i<A.size();i++){
            runningSum+=A[i];
            int remainder=runningSum%k;
            if(remainder<0)remainder+=k;
            if(mp.count(remainder))
                count+=mp[remainder];
            mp[remainder]++;
        }
        return count;
    }
};
