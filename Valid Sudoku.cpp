int squareNumber(int i, int j)
{
    if(i<=2)
    {
        if(j<=2) return 0;
        else if(j<=5) return 1;
        else if(j<=8) return 2;
    }
    else if(i<=5)
    {
        if(j<=2) return 3;
        else if(j<=5) return 4;
        else if(j<=8) return 5;
    }
    else if(i<=8)
    {
        if(j<=2) return 6;
        else if(j<=5) return 7;
        else if(j<=8) return 8;
    }
}

int Solution::isValidSudoku(const vector<string> &A) {
    vector<vector<bool >> inRow(9, vector<bool>(9, false));
    vector<vector<bool >> inCol(9, vector<bool> (9, false));
    vector<vector<bool >> inSquare(9, vector<bool>(9, false));
    int element, sq;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            if(A[i][j]!='.')
            {
                element=(A[i][j]-'0');
                //repeat in row
                if(inRow[i][element-1]) return false;
                else inRow[i][element-1]=true;
                //repeat in column
                if(inCol[j][element-1]) return false;
                else inCol[j][element-1]=true;
                //check square
                sq=squareNumber(i,j);
                if(inSquare[sq][element-1]) return false;
                else inSquare[sq][element-1]=true;
            }
        }
    }
    
    return true;
}
