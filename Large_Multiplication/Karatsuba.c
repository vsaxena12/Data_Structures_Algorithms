#include <stdio.h>
#include <math.h>

long noOfDigit(long m,long n)
{
 long max;
 int b=0;
 if(m>=n)
  max=m;
 else
  max=n;
 while(max>0)
 {
  max=max/10;
  b++;
  //printf("b=%d\n",b);
 }
 return b;
}

long prod(long u,long v)
{
 long x,y,w,z,final_answer;
 long n,m,p,q,r;
 
 n=noOfDigit(u,v);//What is this?
 //printf("n=%ld",n);
 
 if(u==0 || v==0)
 {
  printf("Multiplication of either u = 0 or v = 0 is \"0\" \n");
  return 0;
 }
 
 /*
 else if(u<10 && v<10)
 {
  /*
  *For single digit numbers, perform regular multiplication
  *Here, threshold is considered as less than 10
  */
  //printf("Multiplication of u and v are: %ld\n",(u*v));
  //return u*v;
 //}


 else if(u>10 && v>10)
 {
  m=floor(n/2);
 
  w=u/pow(10,m);
  x=u%(int)pow(10,m);
  y=v/pow(10,m);
  z=v%(int)pow(10,m);
 
  p=prod(w,y);
  q=prod(x,z);
  r=prod(w+x,y+z);
 
  return p * pow(10,2*m) + (r-p-q) * pow(10,m) + q;
  return 0;
 }
}
 


void main()
{
 long m,n;
 
 printf("\n Enter number1:");
 scanf("%ld",&m);
 printf("\n Enter number2:");
 scanf("%ld",&n);
 prod(m,n);
 printf("%ld\n",prod(m,n));
 
}