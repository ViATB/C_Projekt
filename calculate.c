#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "util.h"

#define MSGLVL INFO

int i,j; // Zählvariabeln

int primeTest(int value)          // Primzahlentest
{
      i = 0;
      j = sqrt(value);
      for(i=2;i<=j;i++)
      {
          if(value%i==0)
          return 0;
      }
      return 1;
}

int ggt(int x, int y)             // Groesster Gemeinsamer Teiler
{
     if (x < y) return ggt(y, x);
     else{
           if (x%y != 0)  return ggt(y, x%y);
           else return y;
         }
}

int erwEuklid(int a, int b){      //  Erweiterer Euklidischer Algorithmus


  int x = 0;
  int y = 1;
  int u = 1;
  int v = 0;
  int q,r,m,n;

  if(b>a) return erwEuklid ( b,a);
  while(b!=0){
  q = a/b;
  r = a%b;
  m = x - u * q;
  n = y - v * q;
  a = b;
  b = r;
  x = u;
  y = v;
  u = m;
  v = n;
  }
  return x;

}

int crypt(int p, int c, int n)    // Ver-/Entschlüsslungsfunktion
{
        j = 1;
        int result = 1;

      for (int i=2; i<=p; i++){
                while (p%i == 0 )
                {
                  p/=i;
                  int j = c;
                  while (j > 0)
                  {
                      if ((j%2)==0)
                      {
                            result = (result * i*i)%n;
                            j = j - 2 ;
                      }
                      else{
                            result = (result *i)%n;
                            j = j - 1;
                      }
                   }
                }
      }
      return result;
}
