#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
 
     int board[20],count;
 
    int main()
    {
        int n,i,j;
             
       void queen(int row,int n);
 
      printf("\n\nEnter number of Queens:");
      scanf("%d",&n);
      queen(1,n); //row as 1 and n is no of queen input by user
      
      return 0;//program executed &terminated 
}
 
 
 
//function for printing the solution
void print(int n)
{
int i,j;
printf("\n\nSolution %d:\n\n",++count);
 
 for(i=1;i<=n;++i)
  printf("\t%d",i); //representing the column no to top
 
for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
}
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/

int place(int row,int column) //check if it is possible to place the queen

{
int i;
for(i=1;i<=row-1;++i)//loopchecks from
{
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
 
return 1; //no conflicts
}


 
//function to check for proper positioning of queen
     void queen(int row,int n)
     {
       int column; // check in all column if it is possible to place the queen by current low
       
      for(column=1;column<=n;++column)
   {
        if(place(row,column)) //using place fun check if is it possible to place queen 
     {
       board[row]=column;     //no conflicts so place queen
     if(row==n)      //if it is last then it will use print function to print  
      print(n); //printing the board configuration
       else 
       
    queen(row+1,n);
  }   ////try queen with next position
       
}
}
