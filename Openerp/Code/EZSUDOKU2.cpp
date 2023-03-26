#include <iostream>
#include <stdio.h>

using namespace std;
int matrix[10][10];
int flag;

int check_blocks(int x, int y)
{
    int startx = x/4;
    int starty = y/4; int end_x = startx*4 + 4; int end_y = starty*4 + 4;
    int F[9];
    for(int ii=0; ii<9; ii++)F[ii] = 0;
    for(int i=startx*4; i<end_x; i++)
        for(int j=starty*4; j<end_y; j++)
        {
            if(matrix[i][j] == 0)continue;
            F[matrix[i][j]]++;
            if(F[matrix[i][j]]>2)
                return 1;
        }
        return 0;
}
int check_row_col(int index_x, int index_y)
{
    int F_row[10];
    int F_col[10];
    for(int i=0; i<9; i++)F_row[i] = F_col[i] =0;
    // hang
    for(int i=0; i<8; i++){
        if(matrix[index_x][i]==0)continue;
        F_row[matrix[index_x][i]]++;
        if(F_row[matrix[index_x][i]]>1)
            return 1;
    }
    // cot
    for(int i=0; i<8; i++){
        if(matrix[i][index_y]==0)continue;
        F_col[matrix[i][index_y]]++;
        if(F_col[matrix[i][index_y]]>1)
            return 1;
    }
    return 0;
}
int check_full_row_col()
{
    for(int i=0; i<8; i++)
        if(check_row_col(i,i)==1)return 1;
    return 0;
}
void sodoku(int x, int y)
{
    if(x>=8)
    {
        flag = 1;
        return;
    }
    if(matrix[x][y]!=0)
    {
        if(y<7)sodoku(x, y+1);
        else sodoku(x+1, 0);
    }
    else
    {
        for(int i=1; i<=8; i++)
        {
            matrix[x][y] = i;// dat thu? gia tri i vao o toa do x, y
            if(!check_row_col(x, y)&&!check_blocks(x, y))
            {
                if(y<7)sodoku(x, y+1);
                else sodoku(x+1, 0);                
            }
            if(flag==1)return;
            matrix[x][y] = 0;
        }
    }
}

int main()
{
    int nTestCase;
    scanf("%d", &nTestCase);
    for(int test=1; test<=nTestCase; test++)
    {
        int startx = -1, starty = -1;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
            {
                scanf("%d", &matrix[i][j]);
                if(matrix[i][j]==0&&startx==-1)
                {
                    startx = i;
                    starty = j;
                }
            }
            flag = 0;
            if(!check_blocks(0,0)&&!check_blocks(0,4)&&!check_blocks(4,0)&&!check_blocks(4,4)&&!check_full_row_col())
            {
                sodoku(startx, starty);
                if(flag)
                {
                    printf("Test case #%d: YES\n", test);
                    for(int i=0; i<8; i++)
                    {
                        for(int j=0; j<8; j++)
                            printf("%d ", matrix[i][j]);
                        printf("\n");
                    }
                }
                else printf("Test case #%d: NO\n", test);
            }
            else printf("Test case #%d: NO\n", test);
    }
    return 0;
}
