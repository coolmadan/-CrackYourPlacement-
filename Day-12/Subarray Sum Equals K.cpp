class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
       //Because of negative numbers constraint we won't be able to use sliding window problem
       int res=0;
       int currSum=0;
       unordered_map<int,int>map;
       map[0]=1;
       int diff=0;
       for(auto i : nums)
       {
           currSum+=i;
            diff=currSum-k;
            if(map.count(diff))
            {
                res+=map[diff];
            }
            map[currSum]++;
       }
       return res;
       //Space complexity : O(n)
       //Time complexity: O(n)
    }
};
