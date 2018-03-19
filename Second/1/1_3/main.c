#include<stdio.h> // для scanf, printf, fgets
#include<math.h> // для тригонометрии в польз.-ской ф.-ции
#include<time.h> // для измерения времени, втч clock 

const double eps = 1e-16;
const double Eps = 1e-16;

int RootEx = 1; // Root existance, есть ли корень

int Compare(const double A1, const double A2, const double eps);
double Root( double (*f)(double x), double A, double B,
	     unsigned int *iter );
double F(double x);


int Compare(const double A1, const double A2, const double eps)
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

double Root( double (*f)(double x), double A, double B,
	     unsigned int *pIter )
{
  double X,X0;
  X = X0 = 0;
  (*pIter)++;
  printf("Шаг %u, ",*pIter);
  if( Compare( (-f(A))+f(B),0,eps) )
  {
    printf("Прямая вышла горизонтальной\n"); //Подумать, что здесь делать
    RootEx = 0;
    return 0;
  } else {
    X0 = A;
    X=( A*f(B)+B*(-f(A)) )/( (-f(A))+f(B) );
    //printf("X = %.16lf; X0 = %.16lf\n",X,X0);
    //printf("X = %.16lf; Delta %.16lf\n",X,X-X0);
    printf("X = %e\n",X);
  }
  if( Compare(f(X),0,Eps) )
  {
    return X;
  } else {
    if( *pIter<10000 )
    {
      return Root(f, X, B, pIter);
    } else {
      printf("Ошибка, превышен лимит шагов\n");
      RootEx = 0;
      return 0;
    }
  }
}

double F(double x)
{
  return x*x-1;
}

// Похлопотать с выводом до нужного знака

int main(void)
{
  /*
   * Ищет один из корней уравнения на отрезке с точностью Eps
   * и точностью eps для арифметики
   * Уравнение задано в программе
   * В программе можно установить предел рекурсии
   * Ввод ограничен форматом, неограничена точность
   * Точность вывода (формат) - 16 цифр после запятой
   */
  double A,B,RootX;
  unsigned int Iter;
  clock_t TimeStart, TimeEnd;
  A=B=Iter=RootX=0;
  printf("-------------main.c-------------\n");
  printf("Ищет корень уравнения на отрезке\n");
  printf("Точность: 16 цифр после запятой\n");
  printf("Э Псилон [16] = %.16lf\n",eps);
  
  printf("Задайте начало отрезка: ");
  scanf("%lf",&A);
  printf("и конец: ");
  scanf("%lf",&B);
  
  TimeStart = clock(); // Отсчёт времени
  RootX = Root(F,A,B,&Iter);
  if( RootEx )
  {
    printf("Корень X = %.16lf\n",RootX);
  } else {
    printf("Корень не найден\n");
  }
  printf("Конец рекурсии на шаге %u\n",Iter);
  TimeEnd = clock(); // Отсчёт времени кончился
  printf("Сделано за время %.0f мс.\n",difftime(TimeEnd,TimeStart) );
  //printf("Сделано за время %lf\n",(TimeEnd-TimeStart)/(CLOCKS_PER_SEC*1.0) );
  printf("-------------END-------------\n");
  return 0;
}