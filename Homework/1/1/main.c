#include<stdio.h>


int main(void)
{
	double N, Sum, Mid;
	unsigned int Count;
	N = Sum = Mid = Count = 0;
	while (scanf("%lf", &N)==1)
	{
		printf("Считано число %lf\n",N);
		Sum+=N;
		Count+=1;
	}
	if(Count != 0)
	{
		Mid = Sum / Count;
	} else {
		printf("Чисел не ввели\n");
		return -1;
	}
	printf("Среднее равно %lf\n",Mid);
	return 0;
}
