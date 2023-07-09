class Solution {
public:
    int merge(vector<int>&nums,int temp[],int left,int mid,int right){
         int i = left;
    int j = mid;
    int k = left;
    int rev_count = 0;

    while (i < mid && j <= right) {
        if (nums[i] > 2LL * nums[j]) { // Use long long for multiplication to avoid overflow
            rev_count += mid - i; // Count all elements from i to mid-1 as reverse pairs
            j++;
        } else {
            i++;
        }
    }

    i = left;
    j = mid;
    k = left;

    while (i < mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i < mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy the merged elements back to the original array
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return rev_count;
    }
    int mergeSort(vector<int>&nums,int temp[],int left,int right){
        int rev_count=0;
        int mid;
        if(left<right){
            mid=(left+right)/2;
            rev_count+=mergeSort(nums,temp,left,mid);
            rev_count+=mergeSort(nums,temp,mid+1,right);
            rev_count+=merge(nums,temp,left,mid+1,right);
        }
        return rev_count;
    }
    int reversePairs(vector<int>& nums) {
         int  temp[nums.size()];
        return mergeSort(nums,temp,0,nums.size()-1);
    }
};
