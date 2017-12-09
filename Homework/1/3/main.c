
#include<stdio.h>


int main(void)
{
	/*
	 * Вычисление среднего гармонического.
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	double N, Sum, Mid;
	unsigned int Count;
	N = Mid = Count = Sum = 0;
	printf("-------------main.c-------------\n");
	printf("Вычисление среднего гармонического\n");
	printf("Точность: 16 цифр после запятой\n");
	for (Count = 0; scanf("%lf",&N)==1; Count+=1)
	{
		printf("Считано число %.16lf\n",N);
		if(!(N>0))
		{
		  printf("Числа должны быть положительными\n");
		  return -1;
		}
		Sum += (1.0/N);
	}
	if (Count != 0)
	{
		Mid = Count/Sum;
	} else {
		printf("Чисел не указано\n");
		return -1;
	}
	printf("Среднее равно %.16lf\n",Mid);
	return 0;
}
