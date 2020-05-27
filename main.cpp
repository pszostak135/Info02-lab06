#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "winbgi2.h"
#include "gauss.h"

void HilbertMatrix(int N, double **H)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			H[i][j]=1.0/(1+i+j);
		}
	}
}

void displayMatrix(int N, double **H)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("H[%d][%d]=%lf\t",i,j,H[i][j]);
		}
		printf("\n");
	}
}

void computeVec(int N, double **H, double *b)
{

	for(int i=0;i<N;i++)
	{
		b[i]=0;
		for(int j=0;j<N;j++)
		{
			b[i]+=H[i][j];
		}
	}
}

void plotVec(int N, double *b)
{
	for(int i=0;i<N;i++)
		{
			printf("b[%d]=%lf\n",i,b[i]);
		}
}


void main()
{
	int N=15;
	double **H,*b,*x;

	b = (double*)malloc(N*sizeof(double));
	x = (double*)malloc(N*sizeof(double));
	
	H = (double**)malloc(N*sizeof(double*)); 
	for(int i = 0; i<N; ++i) 
		H[i] = (double*)malloc(N*sizeof(double));

	HilbertMatrix(N,H);
	//displayMatrix(N,H);
	computeVec(N,H,b);
	//plotVec(N,b);
	gauss(N, H, x, b);

	for(int i=0;i<N;i++)
	{
		printf("x[%d]=%lf\n",i,x[i]);
	}

	/*for(int i = 0; i<N; ++i)
		free(H[i]);
	free(H);
	*/

	
	wait();
}