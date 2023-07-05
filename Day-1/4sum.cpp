class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (j == i + 1 || nums[j] != nums[j - 1]) {
                    long long sum = nums[i] + nums[j];
                    int low = j + 1;
                    int high = nums.size() - 1;
                    
                    while (low < high) {
                        if (nums[low] + nums[high] == target - sum) {
                            vector<int> quadruplet = {nums[i], nums[j], nums[low], nums[high]};
                            res.push_back(quadruplet);
                            
                            while (low < high && nums[low] == nums[low + 1])
                                low++;
                            while (low < high && nums[high] == nums[high - 1])
                                high--;
                            
                            low++;
                            high--;
                        }
                        else if (nums[low] + nums[high] < target - sum)
                            low++;
                        else
                            high--;
                    }
                }
            }
        }
        
        return res;
    }
};
