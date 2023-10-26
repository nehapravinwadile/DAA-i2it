#include<stdio.h> //correct
#include<math.h>
int max(int a, int b) 

     {      
     return (a > b)? a : b ;    
     }

void D_knapsack(int n, int m, int p[10], int w[10]) 

  {
    int v[n+1][m+1]; //multi-dimensional array initialized to 0
    int xi[10]={0}; //sequence array initialized to 0
    int i,j,k; 
    
      for( i=0;i<=n;i++)
    {
       for(j=0;j<=m;j++)
          {
               if(i==0 ||  j==0) //initializing to 0
              {
                 v[i][j] = 0;  
              }
                   else if(w[i]<=j)
               {
          v[i][j] = max(v[i-1][j],v[i-1][j-w[i]]+p[i]); 
                }
                 else
               {
                 v[i][j] = v[i-1][j];
              } 
            }
        }
        
        
           printf("\nThe vector table is:\n"); //printing 2D array
           
           
                 for(i=0;i<=n;i++)
             {
                for(j=0;j<=m;j++)
            {
              printf("%d\t", v[i][j]);
            }
               printf("\n");
            }
            
         i=n; 
         k=m;
         
         
   while(i>0 && k>0) 
      {
            if(v[i][k]!=v[i-1][k])
             {
             
              xi[i]=1;
              k=k-w[i];
              i=i-1;
              
             }
         else
         {
           i--;
         }
         
     }
             
             
           printf("\nThe resultant vector is ");
     
              printf("( ");
               
            for(i=1;i<=n;i++)
         {
            printf("%d ",xi[i]);
         }
         
        printf(")\n");
         
        printf("\nThe maximum profit of the given objects is: %d\n", v[n][m]);

     } 
         
         
                
         int main()
          {
       int p[10]={0}; //profit of elements
       int w[10]={0}; //weight of elements

              int n,m ; 
              
          printf("Please enter number of elements:"); 
          scanf("%d",&n);
          
          
           printf("Please enter capacity:"); 
           scanf("%d",&m);
           
           printf("Please enter profit and weight of the elements:");

            for(int i=0;i<n;i++)
            {  
               scanf("%d %d", &p[i], &w[i]);
            }
            
            
          D_knapsack(n,m,p,w); 
          
          
           return 0;
            
 }
 
 /*Please enter number of elements: 4
Please enter capacity: 5
Please enter profit and weight of the elements:
2 1
3 2
5 2
4 3
ouput
The vector table is:
0       0       0       0       0       0
0       2       2       2       2       2
0       2       3       5       5       5
0       2       3       7       8       8
0       2       3       7       9       10

The resultant vector is ( 0 0 1 1 )
The maximum profit of the given objects is: 10*/
