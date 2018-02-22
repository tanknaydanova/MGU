
#include<stdio.h> // printf и scanf


const double eps = 1e-16;

int Compare(const double A1, const double A2);
int FirstSought(FILE *pfIN, double *X);
int Check(FILE *pfIN, const double X, unsigned int *N);


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

int FirstSought(FILE *pfIN, double *X)
{
    if(fscanf(pfIN, "%lf", X)==1) // Получение данного числа Х
    {
		printf("Искомое число X [16] = %.16lf\n",*X);
    } else {
		return -1; // Невозможно считать искомое число
    }
    return 0;
}

int Check(FILE *pfIN, const double X, unsigned int *N)
{
    unsigned int n;
	double R;
    n = R = 0;
	for(n=1;fscanf(pfIN,"%lf",&R)==1;n++) // Цикл сравнений
	{
		if(Compare(X, R)==1)
		{
			*N = n;
		}
	}
	if(*N>0)
	{
		//printf("Номер последнего такого числа равен %u\n", *N);
		return 0;
	} else { // Если нового значения N не присвоили
		//printf("Искомого числа нет\n");
		return -1; // Искомого числа нет в последовательности
	}
} 
/* int Check(FILE *pfIN, const X; unsigned int *N)
{
    unsigned int n;
	double R;
    n = R = 0;
    if(fscanf(pfIN, "%lf", &X)==1) // Получение данного числа Х
    {
		printf("Искомое число X [16] = %.16lf\n",X);
		for(n=1;fscanf(pfIN,"%lf",&R)==1;n++) // Цикл сравнений
		{
			if(Compare(X, R)==1)
			{
				*N = n;
			}
		}
		if(*N>0)
		{
			//printf("Номер последнего такого числа равен %u\n", *N);
			return 0;
		} else { // Если нового значения N не присвоили
			//printf("Искомого числа нет\n");
			return -1; // Искомого числа нет в последовательности
		}
    } else {
		return -1; // Невозможно считать искомое число
    }
} */

int main(void)
{
	/*
	 * Определяет номер последнего числа, равного данному
	 * Ввод ограничен форматом, точность неограничена
	 * Точность вывода 16 цифр после запятой
	 */
	int Result; // return функции Check
	unsigned int Q, N; 
	double X; // Искомое число
	FILE *pfIN, *pfOUT;
	Result = N = Q = X = 0;
	
	printf("-------------main.c-------------\n");
	printf("Определяет номер последнего числа, равного данному\n");
	printf("Точность: 16 цифр после запятой\n");
	printf("Э Псилон [16] = %.16lf\n",eps);
	
	printf("Хотите ввести имя файла самостоятельно? (1/0)\n");
	if(scanf("%ud", &Q)==1)
	{
	    if(Q==0)
	    {
			pfIN = fopen("INPUT.txt","r");
	    } else if(Q==1) // Альтер. имя файла
			{
				return -1; // Пока не работает. Нужно считать строку
				// scanf(...)
				//pfIN = fopen("...","r");
			} else {
				return -1; // Ответ на вопр-1ос не 1 и не 0
			}
	    if(pfIN != NULL) // Основной ход программы
	    {
			FirstSought(pfIN, &X);
			Result = Check(pfIN, X, &N);
			printf("Вывести ответ в файл (0) или на экран (1)? (0/1)\n");
			if(scanf("%ud", &Q)==1)
			{
				if(Q==0) // В файл
				{
					pfOUT = fopen("OUTPUT.txt","w");
					if (pfOUT != NULL)
					{
						fprintf(pfOUT, "%u", N);
						fclose(pfOUT);
					} else {
						return -1; // Файл вывода не открывается
					}
				} else if(Q==1) // На экран
					{
						if(Result==0)
						{
							printf("Номер последнего такого числа равен %u\n", N);
							return 0;
						} else {
							printf("Искомого числа нет в последовательности\n");
							return -1;
						}
					} else {
						return -1; // Ответ на II вопрос не 1 и не 0
					}
			} else {
				return -1; // Q не считано (2й вопрос)
			}
	    } else {
			printf("Файл не удаётся открыть\n");
			return -1; // Файл не открывается
	    }
	    fclose(pfIN);
	} else {
		return -1; // Q не считано (1й вопрос)
	}
	
	
	return 1; // ? конец программы
}
