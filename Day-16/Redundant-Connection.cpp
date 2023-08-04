class Solution {
public:
    bool unionFunc(int a,int b,vector<int>&parent){
        int aRoot=find(a,parent);
        int bRoot=find(b,parent);
        if(aRoot==bRoot){
            return true;
        }
        parent[bRoot]=aRoot;
        return false;
    }
    int find(int x,vector<int>&parent){
        if(parent[x]==x)
            return x;
        return find(parent[x],parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        for(int it=1;it<=edges.size();it++){
            parent[it]=it;
        }
        vector<int>ans(2);
        for(auto it : edges){
            if(!unionFunc(it[0],it[1],parent))
                continue;
            ans[0]=it[0];
            ans[1]=it[1];
        }
        return ans;
    }
};
