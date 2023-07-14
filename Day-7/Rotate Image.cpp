class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int row=matrix.size();
    int col=matrix[0].size();
    int array[row][col];
    memset(array,0,row*sizeof(array[0]));
    int it=col-1;
    for(int i=0;i<row;i++)
    for(int j=0;j<i;j++)
    swap(matrix[i][j],matrix[j][i]);
    for(int i=0;i<row;i++)
    reverse(matrix[i].begin(),matrix[i].end());
    }
};
