#include<stdio.h>
#include<math.h>

const double eps = 1e-16;

double Root( double (*f)(double x), double A, double B );
double F(double x);

double Root( double (*f)(double x), double A, double B )
{
  double X;
  X=0;
  X=(A*f(B)+B*f(A))/(f(A)+f(B));
  return f(X);
}

double F(double x)
{
  return x-1;
}



int main(void)
{
  /*
   * Ищет один из корней уравнения на отрезке с точностью eps
   * Уравнение задано в программе
   * Ввод ограничен форматом, неограничена точность
   * Точность вывода (формат) - 16 цифр после запятой
   */
  double A,B;
  A=B=0;
  printf("-------------main.c-------------\n");
  printf("Ищет корень уравнения на отрезке\n");
  printf("Точность: 16 цифр после запятой\n");
  printf("Э Псилон [16] = %.16lf\n",eps);
  
  printf("Задайте начало отрезка: ");
  scanf("%lf",&A);
  printf("и конец: ");
  scanf("%lf",&B);
  
  printf("Корень X = %.16lf\n",Root(F,A,B));
  
  
  printf("-------------END-------------\n");
  return 0;
}