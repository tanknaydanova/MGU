
#include<stdio.h> // для scanf, printf, fgets
#include<string.h> // для операций со строками: str~
#include<stdlib.h> // для динамических массивов: malloc, free


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
	 *  Ввод рабочих данных без ошибок; проверки вида нет
	 *  Наибольшая длинна имени файла расчитана на
	 *  Windows API, файловую систему NTFS - 260 символов
	 */
	unsigned int Q, Len;
	FILE *pfIN, *pfOUT;
	char fName[260];
	int *Numbers;
	Q = Len = 0;
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
				// Пояснения см. в User_filename
				printf("Напишите его адрес-имя в текущей библиотеке\n");
				printf("Ограничение 259 символов\n");
				fgets(fName,2,stdin);
				fgets(fName, sizeof(fName), stdin);
				printf("Считана строка: %s\n",fName);
				if(strlen(fName)+1 == sizeof(fName))
				{
					fName[strlen(fName)] = 0;
				} else {
					fName[strlen(fName)-1] = 0;
				}
				printf("Считан путь: %s\n", fName);
				pfIN = fopen(fName,"r");
			} else {
				return -1; // Ответ на вопр-1ос не 1 и не 0
			}
	    if(pfIN != NULL) // Основной ход программы
	    {
			fscanf(pfIN,"%ud",&Len);
			Numbers = malloc(Len*sizeof(int));
			for(unsigned int N=0; N<sizeof(Numbers); N++)
			{
				fscanf(pfIN,"%d",&Numbers[N]);
			}
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
						//return 0;
					} else {
						return -1; // Ответ на II вопрос не 1 и не 0
					}
			} else {
				return -1; // Q не считано (2й вопрос)
			}
			free(Numbers);
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