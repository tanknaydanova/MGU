#include<stdio.h>


int main(void)
{
	double N, Sum, Mid;
	unsigned int Count;
	FILE *F;
	N = Sum = Mid = Count = 0;
	F = fopen("main_file.dat","r");
	if(F != NULL)
	{
		for (Count = 0; scanf("%lf",&N)==1; Count+=1)
		{
			printf("Считано число %lf\n",N);
			Sum+=N;
		}
		if(Count != 0)
		{
			Mid = Sum / Count;
		} else {
			printf("Чисел не ввели\n");
			fclose(F);
			return -1;
		}
		printf("Среднее равно %lf\n",Mid);
		fclose(F);
	} else
	{
		printf("Ошибка при прочтении файла\n");
		return -1;
	}
	return 0;
}
