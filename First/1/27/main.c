
#include<stdio.h> // printf и scanf


int Calculate(FILE *pfIN, double *Middle); // Возвращает код ошибки


int Calculate(FILE *pfIN, double *Middle)
{
	int N, PreviousN, Amount;
	unsigned int Count;
	N = PreviousN = Amount = 0;
	Count = 1;
	if (!(fscanf(pfIN, "%d", &PreviousN)==1))
	{
		return -1; // Не удалось считать первое число
	}
	Amount += PreviousN;
	for (;fscanf(pfIN, "%d", &N)==1;)
	{
		if(!(N==PreviousN))
		{
			Amount += N;
			Count ++;
			printf("Amount et Count: %d, %u",Amount,Count);
		}
		PreviousN = N;
	}
	*Middle = Amount*1.0/Count;
	return 0;
}


int main(void)
{
	/* 
	 * Считает среднее арифметическое представителей постоянных участков последовательности
	 * Ввод ограничен форматом, точность целых чисел
	 * Точность вывода 16 цифр после запятой
	 */
	double Middle;
	unsigned int Q; // Ответ на вопрос
	FILE *pfIN, *pfOUT;
	Middle = Q = 0;
	
	printf("-------------main.c-------------\n");
	printf("Определяет ср.арифм. представителей постоянных участков последовательности\n");
	printf("Пусть постоянный участок может быть длины 1\n");
	printf("Точность: 16 цифр после запятой\n");
	
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
			if (Calculate(pfIN,&Middle)<0) // Запуск функции
			{
				return -1; // Ошибка в функции
			}
			printf("Вывести ответ в файл (0) или на экран (1)? (0/1)\n");
			if(scanf("%ud", &Q)==1)
			{
				if(Q==0) // В файл
				{
					pfOUT 
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
	}= fopen("OUTPUT.txt","w");
					if (pfOUT != NULL)
					{
						fprintf(pfOUT, "%16lf\n", Middle);
						fclose(pfOUT);
					} else {
						return -1; // Файл вывода не открывается
					}
				} else if(Q==1) // На экран
					{
						printf("Такое среднее равно %.16lf\n", Middle);
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