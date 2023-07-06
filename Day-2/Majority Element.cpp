class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int half_size=nums.size()/2;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]==nums[(half_size)+i])
                return nums[i];
        }
        return -1;
    }
};
