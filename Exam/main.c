
#include<stdio.h> // для scanf, printf, fgets
#include<stdlib.h> // для динамических массивов: malloc, free

double *Matrix;

void Process(double *matr, int N, int M);


void Process(double *matr, int N, int M)
{
  double Max, S;
  int Mr/*,Mc*/;
  S = 0;
  Max = matr[0];
  Mr = 0;
  //Mc = 0;
  
  for(int r = 0; r<N; r++)
    for(int c = 0; c<M; c++)
    {
      if(matr[r*M+c]>Max)
      {
	Max = matr[r*M+c];
	Mr = r;
	//Mc = c;
      }
    }
  for(int c = 0; c<M; c++)
  {
    S = 0;
    for(int r = 0; r<N; r++)
    {
      if(r!=Mr)
	S += matr[r*M+c];
    }
    matr[Mr*M+c] = S;
  }
  return;
}


int main(void)
{
  // Переменные
  int Rows,Cols; // Rows = N, Cols = M
  double N;
  FILE *pfIN, *pfOUT;
  printf("НАЧАЛО");
  Rows = Cols = N = 0;
  
  // Открытие файла
  pfIN = fopen("input.txt","r");
  pfOUT = fopen("output.txt","w");
  if( (pfIN == NULL)||(pfOUT == NULL) )
  { return -1; 
  }
  
  // Чтение длин
  if( (!(fscanf(pfIN,"%d",&Rows)==1))||
      (!(fscanf(pfIN,"%d",&Cols)==1)) )
  { return -1; 
  }
  
  // Создание массива
  Matrix = malloc(Rows*Cols*sizeof(double));
  for(int r = 0; r<Rows; r++)
    for(int c = 0; c<Cols; c++)
    {
      if( !(fscanf(pfIN,"%lf",&N)==1) ) // Не учитывает, если ввели чисел с избытком
      { free(Matrix);
	return -1;
      }
      Matrix[r*Cols+c] = N;
    }
    
  // Проверка и обработка матрицы в функции
  Process(Matrix, Rows, Cols);
  
  // Вывод
  for(int r = 0; r<Rows; r++)
    for(int c = 0; c<Cols; c++)
    {
      N = Matrix[r*Cols+c];
      if( !(fprintf(pfOUT,"%lf ",N)==1) )
      { //free(Matrix);
	//return -1; 
      }
    }
    
  // Конец
  free(Matrix);
  fclose(pfIN);
  fclose(pfOUT);
  printf("КОНЕЦ!");
  return 0;
}