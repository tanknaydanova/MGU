
#include<stdio.h>


int main(void)
{
	/*
	 * Считает кол-во чисел, больше предыдущего
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	const double eps = 1e-16;
	double PN, N;
	unsigned int Count = 0;
	printf("-------------main.c-------------\n");
	printf("Вычисление кол-ва чисел, больше предыдущего\n");
	printf("Точность: 16 цифр после запятой\n");
	printf("Э Псилон = %.16lf\n",eps);
	for (unsigned int n = 1; scanf("%lf",&N)==1; n++)
	{
		printf("Считано число %.16lf\n",N);
		if(n>1)
		{
			if((N>PN)&&((N-PN)>eps))
			{
				Count ++; 
			}
		}
		printf("Чисел пока насчитано %d\n",Count);
		PN = N;
	}
	printf("Всего таких чисел %d\n",Count);
	return 0;
}
