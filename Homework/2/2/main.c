
#include<stdio.h> // printf и scanf


/*int Rearrange(..., L);


int Rearrange(..., L)
{
	
}*/


int main(void)
{
	/*
	 *  Переставляет элементы массива в обратном порядке
	 *  Ввод ограничен форматом, точнсть не ограничена
	 *  Точность вывода 16 цифр после запятой
	 *  Наибольшая длинна имени файла расчитана на
	 *  Windows API, файловую систему NTFS - 260 символов
	 */
	unsigned int Q;
	FILE *pfIN, *pfOUT;
	char FName[260] = {0};
	Q = 0;
	
	printf("-------------main.c-------------\n");
	printf("- - - - - Задача 2.2 - - - - -\n");
	printf("Переставляет элементы массива в обратном порядке\n");
	printf("Пусть в массиве вещественные числа\n");
	printf("Точность: 16 цифр после запятой\n");
	
	printf("Хотите ввести имя файла входных данных самостоятельно? (1/0)\n");
	if(scanf("%ud", &Q)==1)
	{
	    if(Q==0)
	    {
			pfIN = fopen("INPUT.txt","r");
	    } else if(Q==1) // Альтер. имя файла
			{
				printf("Напишите его адрес-имя в текущей библиотеке\n");
				printf("Ограничение 259 символов\n");
				fgets(FName, sizeof(FName)-1, stdin);
				for(unsigned int n = 0; n < sizeof(FName); n++)
				{
					printf("%d", FName[n]);
				}
				printf("END\n");
				// scanf(...)
				//pfIN = fopen("...","r");
			} else {
				return -1; // Ответ на вопр-1ос не 1 и не 0
			}
	    if(pfIN != NULL) // Основной ход программы
	    {
			/*if (Calculate(pfIN,&Middle)<0) // Запуск функции
			{
				return -1; // Ошибка в функции
			}*/
			printf("Вывести ответ в файл (0) или на экран (1)? (0/1)\n");
			if(scanf("%ud", &Q)==1)
			{
				if(Q==0) // В файл
				{
					pfOUT = fopen("OUTPUT.txt","w");
					if (pfOUT != NULL)
					{
						//fprintf(pfOUT, "%16lf\n", Middle);
						fclose(pfOUT);
					} else {
						return -1; // Файл вывода не открывается
					}
				} else if(Q==1) // На экран
					{
						//printf("Такое среднее равно %.16lf\n", Middle);
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