#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"

typedef enum { false, true } bool;

//int j,t;
int p,q;                              // Primzahlen
int pub, pKey;                        // Public & Privat Key
char input[100];                      // Eingabe String
int en[100], de[100];                 // Encrypted & Decrypted Array
int i;                                // Zählvariabel
int n,phi;
int len = 0;                          // Länge der Eingabe

void main()
{
      printf("\nPrimzahl 1:\n");
      scanf("%d",&p);
      if(primeTest(p)==false)
      {
          printf("\nThis is not a PRIME NUMBER!\n");
          exit(1);
      }
      printf("\nPrimzahl 2:\n");
      scanf("%d",&q);
      if(primeTest(p)==false||p==q)
      {
          printf("\nThis is not a PRIME NUMBER!\n");
          exit(1);
      }
      printf("\nENTER MESSAGE:\n");
      fflush(stdin);
      scanf("%s",input);
      len = i;

      i = 0;
      pub = 99;
      phi = (p-1)*(q-1);
      while(i != 1)
      {
              pub++;
              i = ggt(pub, phi);
      }

      n = p*q;
      pKey = phi + erwEuklid(pub, phi);

      printf("-----------------\nENCRYPTED MESSAGE:\n");
      for(i = 0;input[i]!='\0';i++)
      {
            en[i] = crypt(input[i], pub, n);
            printf("%c",(char) en[i]);
      }

      printf("\n-----------------\nDECRYPTED MESSAGE:\n");
      for(i = 0;en[i]!='\0';i++)
      {
            de[i] = crypt(en[i], pKey, n);
            printf("%c", (char)de[i]);
      }
      printf("\n-----------------\n");
}
