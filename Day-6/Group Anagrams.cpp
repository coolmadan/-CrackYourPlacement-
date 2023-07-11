class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>>map;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
           // cout<<s<<" "<<strs[i]<<endl;
            map[strs[i]].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto i:map)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
