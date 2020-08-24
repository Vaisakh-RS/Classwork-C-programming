#include <stdio.h>

int * readpolynomial(int p[],int d)
{
  	int i;
  	for(i=d;i>=0;i--)
  	{
    	scanf("%d",&p[i]);
  	}
  	return p;
}

void printpolynomial(int p[],int d)
{
  	int i;
  	for(i=d;i>=0;i--)
  	{
    	if(p[i]!=0)
    	{
      		if(i==d)
        		printf("%dx^%d",p[i],i);
      		else if(i==0)
        		printf(" + %d = 0 ",p[i]);
      		else
      		printf(" + %dx^%d",p[i],i);
  		}
	}
}


int * addpolynomial(int p1[],int p2[],int p3[],int d3)
{
 	int i;
  	for(i=0;i<=d3;i++)
    	p3[i]=p1[i]+p2[i];

    return p3;
}


int main()
{
	int pol1[20],pol2[20],pol3[20];
	int * poly1,* poly2,* poly3;
  	int d1,d2,d3;
  	printf("\nEnter the degree of the first and second polynomials: ");
  	scanf("%d%d",&d1,&d2);
  	d3=d1>d2?d1:d2;
  	printf("\nEnter the coefficients of first polynomial for terms from x^%d to x^0 in order ",d1);
	poly1=readpolynomial( pol1, d1);
	printf("\nEnter the coefficients of second polynomial for terms from x^%d to x^0 in order ",d2);
	addpolynomial(pol1,pol2,pol3,d3);
	poly2=readpolynomial( pol2, d2);
	poly3=addpolynomial(pol1,pol2,pol3,d3);
	printf("\n\nFirst Polynomial: \n");
	printpolynomial(pol1,d1);
	printf("\n\nSecond Polynomial: \n");
	printpolynomial(pol2,d2);
	printf("\n\nSum of the polynomials : \n");
	printpolynomial(pol3,d3);
}
