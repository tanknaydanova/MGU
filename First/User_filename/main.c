
#include<stdio.h> // для scanf, printf, fgets
#include<string.h> // для операций со строками: str~

char fname[10]; // = {54}; - инициализирует только 1ый символ

int main(void)
{
	printf("Начало\n");
	
	for(int n = 0; n<=9; n++)
	{
		printf("%d (%c) ",fname[n],fname[n]);
	}
	printf("\n**********\n");
	
	//fgets(fname,2,stdin); - если перед fgets стоит scanf
	//scanf оставляет после себя в буффере перенос строки
	fgets(fname,sizeof(fname),stdin); // strlen или sizeof. -1 включён
	//scanf("%s",fname);
	printf("Считана строка: %s\n",fname);
	printf("sizeof строки: %lu\n", sizeof(fname));
	printf("strlen строки: %d\n", (int)strlen(fname));
	if(strlen(fname)+1 == sizeof(fname))
	// Если слово max длины и перенос строки [10] не появится. Из-за fgets >= не нужно.
	{
		fname[strlen(fname)] = 0;
		// Не залезет на следующий массив. Бесполезно, если нам выдали чистую память
		// (массив из 0), но это может быть не так
	} else {
		fname[strlen(fname)-1] = 0;
		// Отбрасывает перенос строки, вводимый Enter'ом
	}
	printf("Обработана строка: %s\n",fname);
	printf("sizeof строки: %lu\n", sizeof(fname));
	printf("strlen строки: %d\n", (int)strlen(fname));
	printf("последний символ строки (sizeof-1): %d (%c)\n", fname[sizeof(fname)-1], fname[sizeof(fname)-1]);
	printf("последний символ строки (strlen-1): %d (%c)\n", fname[strlen(fname)-1], fname[strlen(fname)-1]);
	printf("6й символ строки: %d (%c)\n", fname[6-1], fname[6-1]);
	
	for(int n = 0; n<=9; n++)
	{
		printf("%d (%c) ",fname[n],fname[n]);
	}
	printf("\n");
	printf("Конец\n");
}














































//fgets(s,10,stdin);