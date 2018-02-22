
#include<stdio.h> // для scanf, printf, fgets
#include<string.h> // для операций со строками: str~
#include<stdlib.h> // для динамических массивов: malloc, free


int Rearrange(int Numbers[], const unsigned int Len);


int Rearrange(int Numbers[], const unsigned int Len)
{
  int F, L;
  F=L=0;
  //printf("Len %u\n", Len);
  for(unsigned int n = 0; n<Len/2; n++)
  {
    // Можно альт. алгоритм по замене переменных
    F = Numbers[n];
    L = Numbers[Len-1-n];
    //printf("Меняется пара №%u: %d, %d;\n",n,F,L); 
    Numbers[Len-1-n] = F;
    Numbers[n] = L;
  }
  return 0;
}


int main(void)
{
	/*
	 *  Переставляет элементы массива в обратном порядке
	 *  Ввод ограничен форматом, точность не ограничена
	 *  Точность вывода целых чисел
	 *  Ввод рабочих данных без ошибок; проверки вида нет
	 *  Наибольшая длинна имени файла расчитана на
	 *  Windows API, файловую систему NTFS - 260 символов
	 */
	unsigned int Q, Len;
	FILE *pfIN, *pfOUT;
	char fName[260];
	int *Numbers = malloc(1);
	Q = Len = 0;
	printf("-------------main.c-------------\n");
	printf("- - - - - Задача 2.2 - - - - -\n");
	printf("Переставляет элементы массива в обратном порядке\n");
	printf("Пусть в массиве целые числа\n");
	printf("Точность: 16 цифр после запятой\n");
	
	printf("Хотите ввести имя файла входных данных самостоятельно (1)? (0/1)\n");
	if(scanf("%u", &Q)==1)
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
			fscanf(pfIN,"%u",&Len);
			free(Numbers); // Незачем, см наверх
			Numbers = /* (int*) */malloc(Len*sizeof(int));
			for(unsigned int N=0; N<Len; N++)
			// sizeof(Numbers) = длина указателя
			// sizeof(int) = 4
			{
				fscanf(pfIN,"%d",&Numbers[N]);
			}
			Rearrange(Numbers, Len);
			printf("Вывести ответ в файл (0) или на экран (1)? (0/1)\n");
			if(scanf("%u", &Q)==1)
			{
				if(Q==0) // В файл
				{
					pfOUT = fopen("OUTPUT.txt","w");
					if (pfOUT != NULL)
					{
						for(unsigned int N = 0; N<Len; N++)
						{
						  fprintf(pfOUT, "%d ", Numbers[N]);
						}
						fprintf(pfOUT,"\n");
						fclose(pfOUT);
					} else {
						return -1; // Файл вывода не открывается
					}
				} else if(Q==1) // На экран
					{
						for(unsigned int N = 0; N<Len; N++)
						{
						  printf("%d ", Numbers[N]);
						}
						printf("\n");
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