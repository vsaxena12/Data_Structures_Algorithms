#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct backtrack
{
    int profitBacktrack;
    int weightBacktrack;
    double fractionBacktrack;   
}BACKTRACK;
int profit[1000]; //profit of item (i)
int weight[1000]; //weight of item (i)
unsigned int n; //number of items
int val;
int p = 0; //temp values
unsigned int w = 0; //temp values
int k = 0; //temp values
int A[1000][1000];
int W = 0; //Capacity of the knapsack
int x[10];
int y[10];
float unit[100];
int count = 0;
int temp;
int i,j;
int matrix_flag[1000][1000];
int max_Profit;
int include[1000];
int bestset[1000];
int num;
int power_value = 0;
int total_Weight = 0;
int total_Profit = 0;
BACKTRACK elements[10];

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int randomFunc()
{
    srand(time(NULL));
    n = (4 + rand() % 5); 
    printf("Number of Items: %d\n\n",n);
    int i = 0;
    while(i<n) 
    {   
        profit[i] = (9 + rand() % 20) + 1;
        weight[i] = (4 + rand() % 10) + 6;
        total_Weight = total_Weight + weight[i];
        total_Profit = total_Profit + profit[i];
        printf("Item[%d] \t Weight[%d]: %d \t\t Profit[%d]: %d\n",i+1,i+1,weight[i],i+1,profit[i]);
        i=i+1;
    }
    printf("\n");
    W = 0.6 * floor(total_Weight); //Capacity of Knapsack
    printf("Total Weight of %d Items:%d\nTotal Profit of %d Items:%d\nCapacity of Knapsack:%d\n\n", n, total_Weight, n, total_Profit, W);
}

int randomFuncBacktrack()
{
  total_Weight = 0;
  total_Profit= 0;
  int i=0;
  
  while(i<n) 
  {
    int elemtW = elements[i].weightBacktrack;
    int elemtP = elements[i].profitBacktrack;
    elements[i].profitBacktrack = profit[i];
    elements[i].weightBacktrack = weight[i];
    elements[i].fractionBacktrack = (double)elements[i].profitBacktrack/elements[i].weightBacktrack;
    total_Weight = total_Weight + elemtW;
    total_Profit = total_Profit + elemtP;
    i=i+1;
  }
}

/*------------------------------------------------------------------------------------------------------------------------------------------
                                                Brute Force Algorithm
--------------------------------------------------------------------------------------------------------------------------------------------*/

int funCallBrute(int n,int W)
{
    int temp;
    int nsol = 0;
    int profit_max = 0;
    int w_max = 0;
    power_value = (2 << (n - 1));

    while(nsol<power_value) //brute force algo runs 2^n times.
    {
        temp = nsol;
        w = 0;
        p = 0;
        int i = 0;
        while(i<n) 
        {
            if(temp%2 != 0)
            {
                w = w + weight[i];
                p = p + profit[i];
            }
            temp = temp/2; 
            i++;
        }  
        if(w <= W)
        {
            if(p > profit_max)
            {
                profit_max = p;
                val = nsol;
            }
        }
        nsol = nsol + 1;
    }
    return profit_max; //returns maximum profit value
}

int bruteForce()
{
    printf("Brute Force algorithm:\n\n");
    int w_max = 0;
    int profit_max = funCallBrute(n, W);
    printf("Selected Items-> \n");
    int i = 0;
    while(i<n) 
      {
        if((val%2) != 0) //Selection of the Item
        {
          w_max = w_max + weight[i];
          printf("Item[%d] \t Weight[%d]: %d \t\t Profit[%d]: %d\n", i+1, i+1, weight[i], i+1, profit[i]);
        }
        val = val/2; 
        i=i+1;       
      }
      printf("\nTotal Profit: %d\n", profit_max);
      printf("Total Weight: %d\n\n", w_max);
    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
                                                Dynamic Code
--------------------------------------------------------------------------------------------------------------------------------------------*/
int Dynamic_test(int n, int w)
{
  if (n == 0 || w==0) 
  {
    return 0;
  }
  else
  {
    int i = n-1;
    while(i>=0) 
    {
      if (weight[i] > w) 
      {
        matrix_flag[n][w] = 0;
        return Dynamic_test(n-1, w);  
      }
      else
      {
        int store1 = Dynamic_test(n-1, w);
        int store2 = profit[i] + Dynamic_test(n-1, w-weight[i]);  
        
        if (store1 > store2) 
        {
          matrix_flag[n][w] = 0;
          A[n][w] = store1;
          return store1;
        }
        else
        {
          matrix_flag[n][w] = 1;
          A[n][w] = store2;
          return store2;
        }
      }
      i = i - 1;
    }
  }
  return 0;
}

int Dynamic_KP()
{
  int final_value = Dynamic_test(n, W);
 
  printf("Selected Items \n");
    int number, Capacity;
    number = n; Capacity = W;
    int i,j;
    i=1;
    while(i<=n) 
    {
      if (matrix_flag[number][Capacity]==1) 
      {
        count = count + weight[number-1];
        printf("Item[%d] \t Weight: %d \t Profit: %d\n", number, weight[number-1], profit[number-1]);
        Capacity = Capacity - weight[number-1];
      }
      number--;
      i=i+1;
    }
    
    printf("\n");
    printf("Entries\n");
    int a=n;
    while(a >=1)
    {
      printf("%d th row entries->", a);
      int b=0;
      while(b <=W)
      {
        if(A[a][b]!=0)
        printf("[%d, %d]-",a, b);
        b++;
      }
     printf("\n");
     a--;
    }
    printf("\nTotal Profit: %d\n", final_value);
    printf("Total Weight: %d\n", count);
  printf("\n");
}


/*------------------------------------------------------------------------------------------------------------------------------------------
                                                BACKTRACKING ALGORITHM
--------------------------------------------------------------------------------------------------------------------------------------------*/
int sort()
{
  int i=0;
    while(i<n-1)
    {
      int j=i+1;
        while(j<n)
        {
            if(elements[j].fractionBacktrack>elements[i].fractionBacktrack)
            {
                int t1;
                t1=elements[i].weightBacktrack;
                elements[i].weightBacktrack=elements[j].weightBacktrack;
                elements[j].weightBacktrack=t1;

                int t2;
                t2=elements[i].profitBacktrack;
                elements[i].profitBacktrack=elements[j].profitBacktrack;
                elements[j].profitBacktrack=t2;
            }
            j=j+1;
        }
        i=i+1;
    }
    //printf("Items->\n");
    int c=0;
    while(c<n) 
    {
      //printf("Item[%d] \tWeight[%d] \tProfit[%d] \n",i+1,elements[i].weightBacktrack, elements[i].profitBacktrack);
      c++;
    }
    printf("Print Weight, Profit, Bound->");
}

//Lecture Slides
int KWF2(int i, int weight, int profit, int n, int W)
{
    int bound = profit;
    int j = i;
    while(j<=n) 
    {
        x[j] = 0; //initialize variable to zero
        j=j+1;
    }

    while (weight < W && i<=n) //Not full or new items
    {
        if (weight + elements[i-1].weightBacktrack <= W)//room for new item 
        {
          ///item i is added to knapsack
            x[i]=1;
            weight = weight + elements[i-1].weightBacktrack;
            bound = bound + elements[i-1].profitBacktrack;
        }
        else
        {
          //fraction of i added to knapsack
            float X = (float)(W-weight)/(float)elements[i-1].weightBacktrack;
            weight = W;
            bound = bound + elements[i-1].profitBacktrack * X;
        }
        i = i + 1; //Next Item
    }
    return bound;
}

//Lecture Slides
int promising_node(int i, int profit, int W, int weight, int n)
{

    if (weight >= W) 
    {
    //Cannot get a solution by expanding node
      return 0;
    }

    else
    {
    //Compute upper bound
      int bound = KWF2(i+1, weight, profit, n, W);

      printf("Weight: %d\t Profit: %d\t Bound: %d\n",weight,profit,bound);
      return (bound > max_Profit);
    }
}

//Lecture Slides
void knapsack(int i, int profit, int weight, int W,int n)
{
  if (weight <= W && profit > max_Profit) 
  {
  //Save better solution  
  max_Profit = profit; //Save new profit
  num = i;
  int j = 1;
    while(j<=n) 
    {
      bestset[j] = include[j]; //save solution
      j++;
    }
  }
  
  if (promising_node(i, profit, W, weight, n)) 
  {
    include[i+1] = 1; //Yes, not promising
    knapsack(i+1, profit + elements[i].profitBacktrack, weight + elements[i].weightBacktrack, W, n);
    include[i+1] = 0; //No, not promising
    knapsack(i+1, profit, weight, W, n);
  }  
}

//Refer Lecture Slides
void Knapsack(int n, int W)
{
  num = 0; //Number of items considered
  max_Profit = 0;
  int tempwt = 0;
  int i=1;
  knapsack(0, 0, 0, W, n);
  printf("\nSelected Items->\n");
  while(i<=num) 
  {
    if (bestset[i]==1) 
    {
      tempwt = tempwt + elements[i-1].weightBacktrack;
      printf("Item[%d] \t Weight: %d \t Profit: %d\n",i+1,elements[i-1].weightBacktrack, elements[i-1].profitBacktrack);
    }
    i++;
  }
  printf("\nTotal Profit: %d\n", max_Profit);
  printf("Total Weight: %d\n\n", tempwt);
}

int main() 
{ 
  printf("----------------------------------------------------------------------------------------------------------------\n");
  printf("Basic Details\n");
  printf("----------------------------------------------------------------------------------------------------------------\n");
  randomFunc();
  randomFuncBacktrack();
  
  printf("----------------------------------------------------------------------------------------------------------------\n");
  printf("Brute Force Algorithm on Knapsack\n");
  printf("----------------------------------------------------------------------------------------------------------------\n");
  bruteForce();
 
  printf("----------------------------------------------------------------------------------------------------------------\n");
  printf("Dynamic Programming Algorithm on Knapsack\n");
  printf("----------------------------------------------------------------------------------------------------------------\n");
  Dynamic_KP();
    
  printf("----------------------------------------------------------------------------------------------------------------\n");
  printf("Backtrack Algorithm on Knapsack\n");
  printf("----------------------------------------------------------------------------------------------------------------\n");
  sort();
  printf("\n");
  Knapsack(n, W);
  
  return 0;
}