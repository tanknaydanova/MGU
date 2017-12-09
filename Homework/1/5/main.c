
#include<stdio.h> // printf и scanf
// #include<stdlib.h> // malloc


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
	 * Определяет, есть ли в последовательности данное число
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	//unsigned int Count = 0;
	double X, N;
	//double *Numbers;
	X = N = 0;
	printf("-------------main.c-------------\n");
	printf("Определение, есть ли в последовательности данное число\n");
	printf("Точность: 16 цифр после запятой\n");
	printf("Э Псилон = %.16lf\n",eps);
	
	printf("Введите искомое число X\n");
	scanf("%lf", &X);
	printf("Считано число %.16lf\n",X);
	//printf("Введите длину последовательности\n");
	//scanf("%ud", &Count);
	//Numbers = malloc(Count*sizeof(double));
	///for(;scanf("%lf",&N)==1;)
	//for(int n=1; (n<(int)(Count+1))&&(scanf("%lf",&N)); n++)
	for(;scanf("%lf",&N)==1;)
	{
		if(Compare(X,N)==1)
		{
			printf("Искомое число есть!\n");
			return 0;
		}
	}
	printf("Искомого числа нет\n");
	//free(Numbers);
	return -1;
}
