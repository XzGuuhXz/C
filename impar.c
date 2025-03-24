#include <stdio.h>

int main()
{
  int num;

  scanf("%d", &num);

  while(num > 0)
  {
    if(num % 2 == 1)
    {
      printf("O Numero %d é impar\n\n", num);
      num--;
    }
    if(num % 2 == 2)
    {
      printf("O Numero %d é par\n\n", num);
      num--;
    }
    num--;
  }
  return 0;
}
