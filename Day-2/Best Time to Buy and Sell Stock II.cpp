class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //    sort(nums.begin(),nums.end());
    for (int i = 0;i<nums.size();)
    {
        if(nums[i]>0)nums[i]=-nums[i];
        else return i;
        i = -(nums[i]);
        
    }
    return -1;
    }
};
