#include<stdio.h>   
#include<stdlib.h>
#include<limits.h>

void Negative_cycle(int graph[10][3] , int V, int E, int distance[])
{
            for(int j=0;j<E;j++) //Edges j considered
            {
               
if(distance[graph[j][0]]!= INT_MAX &&
 distance[graph[j][0]] +graph[j][2] < distance[graph[j][1]])  
 
 {
       printf("Negative cycle so not implemented") ;
       
        exit(0);
        }
      }
       
        
     }
                 
 void Bellmanford(int graph[10][3], int V, int E, int scr)
 {
           int distance[V];
           
           for(int i=0;i<V;i++) 
         {
            distance[i] = INT_MAX;
         }         
          
         distance[scr]  = 0;
         
         for(int i=0; i<V-1; i++)
         { 
              for(int j=0; j<E; j++)
              {
   if(distance[scr]!= INT_MAX &&
 distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]] )      
 {
 
 
 distance[graph[j][1]] = distance[graph[j][0]] +graph[j][2] ;            
    
    printf("\n Relaxation Step %d: \n", i+1);
    printf("Updated distance to the vertex %d %d \n",graph[j][1] , distance [graph[j][1]]);
    }
    }
    }
    
         Negative_cycle( graph, V, E, distance); 
       
        
        printf("\n Vertex Distance from source\n"); 
        for(int i=1; i<V+1; i++)  
        {
        
        printf("%d\t%d\n ", i, distance[i]);
        }
      }  
        
        
        
        
        
int main()
{
   int V, E, source;
   int graph[10][3];
   
   printf("please Enter the no of Vertices");
   scanf("%d",&V);
   
   printf("please Enter the no of Edges");
   scanf("%d",&E);
   
   printf("please Enter the source vertex ,destination Vertex,  weight");
    
    for(int i=0;i<E;i++)
    {
     scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }
    printf("Please enter the source");
    scanf("%d",&source);
    
    Bellmanford(graph,V,E,source);
    
    return 0;
    }
    
    
    /*please Enter the no of Vertices3
please Enter the no of Edges3
please Enter the source vertex destination Vertex weight0 1 10
0 2 5
1 2 -8
Please enter the source0

 Relaxation Step 1: 
Updated distance to the vertex 1 10 

 Relaxation Step 1: 
Updated distance to the vertex 2 5 

 Relaxation Step 1: 
Updated distance to the vertex 2 2 

 Vertex Distance from source
1	10
 2	2
 3	0
--------------------------------
negative cycle
   please Enter the no of Vertices4 
please Enter the no of Edges4
please Enter the source vertex ,destination Vertex,  weight0 1 1
1 2 -1
2 3 -1
3 0 -1
Please enter the source0

 Relaxation Step 1: 
Updated distance to the vertex 1 1 

 Relaxation Step 1: 
Updated distance to the vertex 2 0 

 Relaxation Step 1: 
Updated distance to the vertex 3 -1 

 Relaxation Step 1: 
Updated distance to the vertex 0 -2 

 Relaxation Step 2: 
Updated distance to the vertex 1 -1 

 Relaxation Step 2: 
Updated distance to the vertex 2 -2 

 Relaxation Step 2: 
Updated distance to the vertex 3 -3 

 Relaxation Step 2: 
Updated distance to the vertex 0 -4 

 Relaxation Step 3: 
Updated distance to the vertex 1 -3 

 Relaxation Step 3: 
Updated distance to the vertex 2 -4 

 Relaxation Step 3: 
Updated distance to the vertex 3 -5 

 Relaxation Step 3: 
Updated distance to the vertex 0 -6 
Negative cycle so not implemented*/
