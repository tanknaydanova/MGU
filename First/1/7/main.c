
#include<stdio.h> // printf и scanf


const double eps = 1e-16;

int Compare(const double A1, const double A2);


int Compare(const double A1, const double A2)
{
	double Max, Min;
	Max = A1>A2?A1:A2;
	Min = A1>A2?A2:A1;
	if(Max-Min<eps) //abs округляет
	{
		return 1;
	}
	return 0;
}


int main(void)
{
	/*
	 * Определяет номер последнего числа, равного данному
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	unsigned int n, N;
	double R, X;
	R = X = n = N = 0;
	printf("-------------main.c-------------\n");
	printf("Определяет номер последнего числа, равного данному\n");
	printf("Точность: 16 цифр после запятой\n");
	printf("Э Псилон [16] = %.16lf\n",eps);
	
	for(n = 1;scanf("%lf",&R)==1; n++)
	{
	  if(Compare(X, R)==1)
	  {
	    N = n;
	  }
	}
	if(N>0)
	{
	  printf("Номер последнего такого числа равен %d\n",N);
	} else {
	  printf("Искомого числа нет\n");
	  return -1;
	}
	return 0;
}

