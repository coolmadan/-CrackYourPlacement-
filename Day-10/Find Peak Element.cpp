class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        int left=1;
        int right=nums.size()-2;
        while(left<=right){
            int mid= (left+right)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
                return mid;
            else if (nums[mid]>nums[mid-1])
                left=mid+1;
            else if(nums[mid]>nums[mid+1])
                right=mid-1;
            else
                right=mid-1;//for the edge case when the mid is at local maxima
        }
        return -1;
    }
};
