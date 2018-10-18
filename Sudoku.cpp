#include<bits/stdc++.h>
using namespace std;
# define UNASSIGNED 0

class sudoku
{
public:
    int mat[9][9];
public:
    sudoku(){
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                mat[i][j]=UNASSIGNED;
            }
        }
    }
    bool unAssignedPlace(int mat[9][9],int &row,int &col)
    {
        for(row=0;row<9;row++)
            {
                for(col=0;col<9;col++)
                {
                    if(mat[row][col]==UNASSIGNED)
                    {
                        return true;
                    }
                }
            }
        return false;
    }

    bool usedRow(int mat[9][9],int row,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(mat[row][i]==num)
            {
                return true;
            }
        }
        return false;
    }
    bool usedCol(int mat[9][9],int col,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(mat[i][col]==num)
            {
                return true;
            }
        }
        return false;
    }
    bool usedBlock(int mat[9][9],int rowStart,int colStart,int num)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(mat[rowStart+i][colStart+j]==num)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isSafe(int mat[9][9],int row,int col,int num)
    {
        return (!usedBlock(mat,row-row%3,col-col%3,num) && !usedRow(mat,row,num) && !usedCol(mat,col,num));
    }

    bool solveSudoku(int mat[9][9])
    {
        int row, col;
        if(!unAssignedPlace(mat,row,col))
        {
            return true;
        }
        for(int i=1;i<=9;i++)
        {
            if(isSafe(mat,row,col,i))
            {
                mat[row][col]=i;
                if(solveSudoku(mat))
                {
                    return true;
                }
                mat[row][col]=UNASSIGNED;
            }
        }
        return false;
    }
    void printSudoku(int mat[9][9])
    {
        for(int i=0;i<9;i++)
        {
            if(i%3==0)
            cout<<"------------------------------------------------------\n";
            for(int j=0;j<9;j++)
            {
                if(j%3==0 && j!=0)
                    cout<<" * ";
                if(mat[i][j]==UNASSIGNED)
                {
                    cout<<"| . |";
                }
                else
                {
                    cout<<"| "<<mat[i][j]<<" |";
                }
                if(j==8)
                    cout<<" * ";
            }
            cout<<endl;
        if(i==8)
            cout<<"------------------------------------------------------\n";
        }
        cout<<endl;
    }

};
int main()
{
    sudoku s;
    int flag=1;
    char ch,c;
    int a[9];
    do{
    cout<<"\n\n\n\n\n\n\n\n\nStarting the game Sudoku........"<<endl;
    cout<<"\nEnter the elements of the Sudoku whose solution you want to find.\n\t(**NOTE : Enter '0' for blank space**)\n";
        for(int i=0;i<9;i++)
        {
            a[9]={0};
            for(int j=0;j<9;j++)
            {
                cin>>s.mat[i][j];
                if(s.mat[i][j]<0 || s.mat[i][j]>9)
                    flag=0;

                    a[j]=s.mat[i][j];
                    for(int k=0;k<9;k++)
                    {
                        if(s.mat[i][j]==a[k] && s.mat[i][j]!=0)
                            flag=0;

                    }
            }
        }

        cout<<"\nYour entered sudoku"<<endl;
        s.printSudoku(s.mat);
        cout<<"\n------------------------------------------------------------------------\n";
        if (s.solveSudoku(s.mat) == true)
            {
                cout<<"\nSolution of your Sudoku\n";
                s.printSudoku(s.mat);
        cout<<"Thank you!!!!\nExiting the game.\n";            }
        else
        {
         cout<<"Error!!.\nNo solution exists.Check the entered values."<<endl;
        }
    cout<<"\nDo you want to try again?(y for yes, n for no)\n";
    cin>>c;
    }while(c=='y' || c=='Y');
    if(c='n')
        cout<<"Thank you!!!!\nExiting the game.\n";
    return 0;
}
