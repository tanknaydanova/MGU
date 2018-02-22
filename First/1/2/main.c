#include<stdio.h>
#include<math.h>


int main(void)
{
	/*
	 * Вычисление среднего геометрического.
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	double N, Comp, Mid;
	unsigned int Count;
	N = Mid = Count = 0;
	Comp = 1;
	printf("-------------main.c-------------\n");
	printf("Вычисление среднего геометрического\n");
	printf("Точность: 16 цифр после запятой\n");
	for (Count = 0; scanf("%lf",&N)==1; Count+=1)
	{
		printf("Считано число %.16lf\n",N);
		if( !((N>0)||(N<0)) )
		{
		  printf("Надеюсь, вы знаете, что в С.Г. могут быть только\nположительные числа. Среднее будет = 0\n");
		}
		if(N<0)
		{
		  printf("Числа должны быть положительными\n");
		  return -1;
		}
		Comp*=N;
	}
	if (Count != 0)
	{
		Mid = pow(Comp,1.0/Count);
	} else {
		printf("Чисел не указано\n");
		return -1;
	}
	printf("Среднее равно %.16lf\n",Mid);
	return 0;
}
