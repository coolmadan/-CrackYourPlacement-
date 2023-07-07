class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     /*In order to solve this problem you have three approaches 
     APPROACH 1 :  Run 3 nested loops , TC: O(N^3)
     APPROACH 2 :  Use Map for c 
        Normally take values for a and b but for c = -(a+b) with the help of hashing 
        such that no duplicates are formed, TC: O(N^2 * log(M)), SC: O(m)*O(n)
     APPROACH 3 : Using two pointers approach , TC: O(N^2),SC: O(1)
     */
     //Using Approach 3 i.e. two pointers
     //Sort the given array
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    for(int i =0;i<nums.size()-2;i++)
    {
        if(i==0||(i>0&&nums[i]!=nums[i-1]))
        {
            int lo= i+1,hi=nums.size()-1,sum=0-nums[i];
            while(lo<hi)
            {
                if(nums[lo]+nums[hi]==sum)
                {
                    vector<int>res1;
                    res1.push_back(nums[i]);
                    res1.push_back(nums[lo]);
                    res1.push_back(nums[hi]);
                    res.push_back(res1);
                
                while(lo<hi && nums[lo]==nums[lo+1] )lo++;
                while(lo<hi && nums[hi]==nums[hi-1] )hi--;
                lo++;
                hi--;
                }
                else if(nums[lo]+nums[hi]<sum)
                    lo++;
                else
                    hi--;
            }
            
        }
    }
    return res;
    }
};
