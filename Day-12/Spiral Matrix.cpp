class Solution {
public:
      vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int count =0;
        int total = row*col;
        vector<int> ans;

        int sRow = 0, sCol=0, eRow =row-1, eCol = col-1;

        while(count<total){

            for(int i=sCol; i<=eCol && count<total; i++){
                ans.push_back(matrix[sRow][i]);
                count++;
            }
            sRow++;

            for(int i=sRow; i<=eRow && count<total; i++){
                ans.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;

            for(int i=eCol; i>=sCol && count<total; i--){
                ans.push_back(matrix[eRow][i]);
                count++;
            }
            eRow--;

            for(int i=eRow; i>=sRow && count<total; i--){
                ans.push_back(matrix[i][sCol]);
                count++; 
            }
            sCol++;
        }
         return ans;
      }
};
