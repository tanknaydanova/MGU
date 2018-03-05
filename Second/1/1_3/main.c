#include<stdio.h>
#include<math.h>

const double eps = 1e-16;
const double Eps = 1e-16;

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
  double X;
  X=0;
  (*pIter)++;
  printf("Шаг %u, ",*pIter);
  if( Compare( (-f(A))+f(B),0,eps) )
  {
    printf("Прямая вышла горизонталдьной\n"); //Подумать, что здесь делать
  } else {
    X=(A*f(B)+B* (-f(A)) )/( (-f(A)) +f(B));
    printf("X = %lf\n",X);
  }
  if( Compare(f(X),0,Eps) )
  {
    return X;
  } else {
    if( *pIter<100 )
    {
      return Root(f, X, B, pIter);
    } else {
      printf("Ошибка, превышен лимит шагов");
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
   * Ищет один из корней уравнения на отрезке с точностью eps
   * Уравнение задано в программе
   * Ввод ограничен форматом, неограничена точность
   * Точность вывода (формат) - 16 цифр после запятой
   */
  double A,B;
  unsigned int Iter;
  A=B=Iter=0;
  printf("-------------main.c-------------\n");
  printf("Ищет корень уравнения на отрезке\n");
  printf("Точность: 16 цифр после запятой\n");
  printf("Э Псилон [16] = %.16lf\n",eps);
  
  printf("Задайте начало отрезка: ");
  scanf("%lf",&A);
  printf("и конец: ");
  scanf("%lf",&B);
  
  printf("Корень X = %.16lf\n",Root(F,A,B,&Iter));
  printf("Конец рекурсии на шаге %u\n",Iter);
  
  printf("-------------END-------------\n");
  return 0;
}