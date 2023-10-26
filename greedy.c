

#include<stdio.h>
void knapsack(int n, float profit[], float weight[], int capacity, float object[])
//function definition (parameterized function)
{
       float xi[20], total_profit=0,temp;
//local variable declaration (xi-sequence array, temp-temporary variable ) 
        int i,j;
       for(i=0; i<n; i++) //initializing the xi array to 0
  {
    xi[i] = 0;
  }
     for(i=0; i<n; i++) //assigning values in xi array (0 or 1)
   {
     if(weight[i] > capacity)
    { 
    
      break;
    }
     else 
     
   {
     xi[i] = 1;
     total_profit = total_profit + profit[i];
     capacity = capacity - weight[i];
   }
   }
         if(i < n) //assigning values in xi array for fractional case
    { 
      xi[i] = capacity/weight[i];
    }
       total_profit = total_profit + (xi[i]*profit[i]); //calculating maximum profit
     for(i=0; i<n; i++) //sorting again on the basis of object array
    {
      for (j = i + 1; j < n; j++)
     {
    if(object[i] > object[j]) //sorting in ascending order
    {
    temp = object[j]; //swapping of object (numbering of elements) array elements
      object[j] = object[i];
      object[i] = temp;
      temp = xi[j]; //swapping of xi (sequence of selected elements) array elements
      xi[j] = xi[i];
      xi[i] = temp;
    }
      }
    }
     printf("\nThe knapsack sequence is:"); //printing the selected elements' sequence
      for(i=0; i<n; i++)
   {
     printf("%f\t", xi[i]);
   }
      printf("\nThe maximum profit of the given objects is:     %f\n",total_profit);
//printing maximum profit
}
     int main() //main function
{
float object[20]; // local variable declaration
float profit[20];
float weight[20];
float ratio[20], temp;
int capacity;
int n,i,j;
//accepting user input for no of elements their number, weight, profit and capacity of
//the container
printf("Please enter the number of elements/objects:");
scanf("%d", &n);
printf("Please enter the capacity of container:");
scanf("%d", &capacity);
printf("Please enter number, weight and profit of objects:");
for(i=0; i<n; i++)
{
scanf("%f %f %f", &object[i], &weight[i], &profit[i]);
}
for (i = 0; i < n; i++) //taking ratio of profit/weight for every element using for loop
{
ratio[i] = profit[i] / weight[i];
}
for(i=0; i<n; i++) //sorting the elements on the basis of ratio
{
for (j = i + 1; j < n; j++)
{
if(ratio[i] < ratio[j]) //sorting in descending order
{
temp = ratio[j]; //swapping of ratio (of elements entered) array elements
ratio[j] = ratio[i];
ratio[i] = temp;
temp = weight[j]; //swapping of weight (of elements entered) array elements
weight[j] = weight[i];
weight[i] = temp;
temp = profit[j]; //swapping of profit (of elements entered) array elements
profit[j] = profit[i];
profit[i] = temp;
temp = object[j]; //swapping of object (numbering of elements) array elements
object[j] = object[i];
object[i] = temp;
}
}
}
knapsack(n, profit, weight, capacity, object); //function call
return 0;
}
/*Please enter the number of elements/objects: 4
Please enter the capacity of the container: 10
Please enter number, weight, and profit of objects:
1 3 50
2 2 60
3 4 80
4 1 40
The knapsack sequence is:1.000000    0.000000    1.000000    0.250000    
The maximum profit of the given objects is: 210.000000
*/
