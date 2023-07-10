class Solution {
public:
    void helper(vector<vector<int>>&board,int row,int col){
        int m=board.size();
        int n=board[0].size();
        int upLeftDiagonal=0;
        int upRightDiagonal=0;
        int up=0;
        int bottom=0;
        int left=0;
        int right=0;
        int bottomLeftDiagonal=0;
        int bottomRightDiagonal=0;
        if(row>0&&col>0)
            upLeftDiagonal=board[row-1][col-1];
        if(row>0)
            up=board[row-1][col];
        if(col>0)
            left=board[row][col-1];
        if(row<m-1)
            bottom=board[row+1][col];
        if(col<n-1)
            right=board[row][col+1];
        if(row<m-1&&col<n-1)
            bottomRightDiagonal=board[row+1][col+1];
        if(row<m-1&&col>0)
            bottomLeftDiagonal=board[row+1][col-1];
        if(row>0&&col<n-1)
            upRightDiagonal=board[row-1][col+1];
        int oneCount=upLeftDiagonal+upRightDiagonal+bottomLeftDiagonal+bottomRightDiagonal+up+left+right+bottom;
        //2->0
        if(board[row][col]==1||board[row][col]==3){
            if(oneCount<2||oneCount>3)
                board[row][col]=2;
        }else if (board[row][col]==0||board[row][col]==2){//3->1
            if(oneCount==3)
                board[row][col]=3;
    }
    }
    void gameOfLife(vector<vector<int>>& board) {
         int m=board.size();
        int n=board[0].size();
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                 int upLeftDiagonal=0;
        int upRightDiagonal=0;
        int up=0;
        int bottom=0;
        int left=0;
        int right=0;
        int bottomLeftDiagonal=0;
        int bottomRightDiagonal=0;
        if(row>0&&col>0)
            upLeftDiagonal=board[row-1][col-1];
        if(row>0)
            up=board[row-1][col];
        if(col>0)
            left=board[row][col-1];
        if(row<m-1)
            bottom=board[row+1][col];
        if(col<n-1)
            right=board[row][col+1];
        if(row<m-1&&col<n-1)
            bottomRightDiagonal=board[row+1][col+1];
        if(row<m-1&&col>0)
            bottomLeftDiagonal=board[row+1][col-1];
        if(row>0&&col<n-1)
            upRightDiagonal=board[row-1][col+1];
        int oneCount=upLeftDiagonal+upRightDiagonal+bottomLeftDiagonal+bottomRightDiagonal+up+left+right+bottom;
        //2->0
        if(board[row][col]==1){
            if(oneCount<2||oneCount>3)
                board[row][col]=2;
        }else if (board[row][col]==0){//3->1
            if(oneCount==3)
                board[row][col]=3;
    }
            }
        }
                
        // for(int i=0;i<board.size();i++)
        //     for(int j=0;j<board[0].size();j++)
        //         {if(board[i][j]==2)
        //             board[i][j]=0;
        //         else if(board[i][j]==3)
        //             board[i][j]=1;}
                
    }
};
