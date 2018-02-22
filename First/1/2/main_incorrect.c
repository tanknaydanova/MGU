#include<stdio.h>


int main(void)
{
	/*
	 * Вычисление a1*a2*..*an/n - чего-то непонятного.
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	double N, Comp, Mid;
	unsigned int Count;
	N = Mid = Count = 0;
	Comp = 1;
	printf("-------------main_incorrect.c-------------\n");
	printf("Вычисление a1*a2*..*an/n\n");
	printf("Точность: 16 цифр после запятой\n");
	for (Count = 0; scanf("%lf",&N)==1; Count+=1)
	{
		printf("Считано число %.16lf\n",N);
		Comp*=N;
	}
	if (Count != 0)
	{
		Mid = Comp / Count;
	} else {
		printf("Чисел не указано\n");
		return -1;
	}
	printf("Среднее равно %.16lf\n",Mid);
	return 0;
}
