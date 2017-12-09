
#include<stdio.h> // printf и scanf


int Search(FILE *pfIN, int *Min, unsigned int *Count);


int Search(FILE *pfIN, int *Min, unsigned int *Count)
{
	int Z; // Считываемое число
	//Z = 0;
	if(fscanf(pfIN, "%d", &Z)==1) // Первое число станет минимальным
    {
		*Min = Z;
		printf("I минимум равен %d\n", Z);
		*Count = 1;
    } else {
		return -1; // Невозможно считать первое число
    }
	for (unsigned int n=1; fscanf(pfIN,"%d",&Z)==1; n++)
	{
		if (*Min==Z)
		{
			(*Count) ++;
		} else if (Z< *Min) {
			*Min = Z;
			printf("минимум равен %d\n", Z);
			*Count = 1;
			} // Если Z> *Min - игнорируем
	}
	return 0;
}


int main(void)
{
	/*
	 * Считает количество чисел, равных наименьшему в целой последовательности
	 * Ввод ограничен форматом, точность целых чисел
	 * Точность вывода целых чисел: Min [int], Count [uns. int]
	 */
	unsigned int Q, Count;
	int Min; // Наименьшее число
	FILE *pfIN, *pfOUT;
	Q = Min = Count = 0;
	
	printf("-------------main.c-------------\n");
	printf("Определяет количество чисел, равного наименьшему в целой последовательности\n");
	printf("Точность: Min [int], Count [uns. int]\n");
	
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
			if (Search(pfIN, &Min, &Count)<0) // Запуск функции
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
						fprintf(pfOUT, "%u", Count);
						fclose(pfOUT);
					} else {
						return -1; // Файл вывода не открывается
					}
				} else if(Q==1) // На экран
					{
						printf("Наименьшее число %d и таких чисел %u\n", Min, Count);
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