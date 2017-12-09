#include<stdio.h>


int main(void)
{
	/*
	 * Вычисление среднего арифметического циклом for.
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	double N, Sum, Mid;
	unsigned int Count;
	N = Sum = Mid = Count = 0;
	printf("-------------main_alt.c-------------\n");
	printf("Вычисление среднего арифметического\n");
	printf("Точность: 16 цифр после запятой\n");
	for (Count = 0; scanf("%lf",&N)==1; Count+=1)
	{
		printf("Считано число %.16lf\n",N);
		Sum+=N;
	}
	if(Count != 0)
	{
		Mid = Sum / Count;
	} else {
		printf("Чисел не ввели\n");
		return -1;
	}
	printf("Среднее равно %.16lf\n",Mid);
	return 0;
}
