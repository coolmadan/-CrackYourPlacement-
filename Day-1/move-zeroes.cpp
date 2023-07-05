class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int slow=0;
    for(int fast=0;fast<nums.size();fast++)
    {
        if(nums[fast]!=0&&nums[slow]==0)
            swap(nums[fast],nums[slow]);
        if(nums[slow]!=0)
            slow++;
    }
    }
    
};
