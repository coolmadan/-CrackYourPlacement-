class Solution {
public:
    int maxArea(vector<int>& height) {
      int lp=0;
      int rp=height.size()-1;
      int ans=INT_MIN;
      while(lp<rp)
      {
          int lh=height[lp];
          int rh=height[rp];
          int min_h=min(lh,rh);
          ans = max(ans,min_h*(rp-lp));
          if(lh<rh)
            lp++;
        else
            rp--;
      }
      return ans;
    }
    
};
