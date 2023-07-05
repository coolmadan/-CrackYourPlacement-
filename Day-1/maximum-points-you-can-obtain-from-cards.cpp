class Solution {
public:
   
    int leftSum(vector<int>&nums,int k){
        int sum=0;
        for(int i =0;i<k;i++)
            sum+=nums[i];
        return sum;
    }
    int maxScore(vector<int>& nums, int k) {
        
        int sum=leftSum(nums,k);
        int maxSum=sum;
        int first=k-1;
        int last=nums.size()-1;
        for(int i =0;i<k;i++){
            
            sum=sum-nums[first];
            first--;
            sum=sum+nums[last];
            last--;
            maxSum=max(sum,maxSum);
            cout<<maxSum<<" "<<sum<<" ";
        }
        return maxSum;
    }
};
