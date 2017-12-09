
#include<stdio.h> // для scanf, printf, fgets
#include<string.h> // для операций со строками: str~

//char s[10]={22};
char fname[10] = {0};

int main(void)
{
	printf("Начало\n");
	
	/*for(int n = 1; n<=10; n++)
	{
		printf("%d",s[n]);
	}*/
	
	for(int n = 0; n<=9; n++)
	{
		printf("%d",fname[n]);
	}
	printf("\n");
	
	fgets(fname,sizeof(fname),stdin); // strlen или sizeof
	//scanf("%s",fname);
	fname[strlen(fname)-1] = 0;
	
	printf("%s\n",fname);
	printf("END\n%lu | %d | %c | %d | %d\n",
		   sizeof(fname),
		   fname[sizeof(fname)-1],
		   fname[strlen(fname)-1],
		   (int)strlen(fname),
		   fname[6-1]);
	
	
	for(int n = 0; n<=9; n++)
	{
		printf("%d ",fname[n]);
	}
	printf("\n");
	printf("Конец\n");
}














































//fgets(s,10,stdin);