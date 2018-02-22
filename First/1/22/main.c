
#include<stdio.h> // printf и scanf


const double eps = 1e-16;

int Compare(const double A1, const double A2); // Возвращает код ошибки
int Counting(FILE *pfIN, unsigned int *Length); // Воззвращает код ошибки


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

int Counting(FILE *pfIN, unsigned int *Length)
{
	double PreviousN, N;
	unsigned int LengthAlt;
	PreviousN = N = 0;
	LengthAlt = 1;
	// Здесь Length = 1
	if (!(fscanf(pfIN, "%lf", &PreviousN)==1))
	{
		return -1; // Не удалось считать первое число
	}
	for (;fscanf(pfIN,"%lf",&N)==1;)
	{
		if (Compare(PreviousN,N)||(N>PreviousN)) // Здесь можно менять тип возрастания
		{
			LengthAlt ++;
		} else if (LengthAlt > (*Length))
			{
				*Length = LengthAlt;
				LengthAlt = 1;
			}
		PreviousN = N;
	}
	if (LengthAlt > (*Length))
	{
		*Length = LengthAlt;
	}
	return 0;
}


int main(void)
{
	/*
	 * Определяет наибольшую длину возрастающего участка
	 * Ввод ограничен форматом, точность не ограничена
	 * Точность вывода 16 цифр после запятой
	 */
	unsigned int Length, Q;
	FILE *pfIN, *pfOUT;
	Length = Q = 1;
	
	printf("-------------main.c-------------\n");
	printf("Определяет наибольшую длину возрастающего участка\n");
	printf("Пусть возрастание нестрогое\n");
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
			if (Counting(pfIN,&Length)<0) // Запуск функции
			{
				return -1; // Ошибка в функции
			}
			printf("Вывести ответ в файл (0) или на экран (1)? (0/1)\n");
			if(scanf("%ud", &Q)==1)
			{
				if(Q==0) // В файл
				{
					pfOUT = fopen("OUTPUT.txt","w");
					if (pfOUT != NULL)
					{
						fprintf(pfOUT, "%u\n", Length);
						fclose(pfOUT);
					} else {
						return -1; // Файл вывода не открывается
					}
				} else if(Q==1) // На экран
					{
						printf("Длина такого участка %u\n", Length);
						return 0;
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
