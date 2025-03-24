#include <stdio.h>

int main()
{
  int num;
  for(int i = 0; i < 10; i++)
  {
    printf("Digite um nuemro:\n", num);
    scanf("%d", &num);
    printf("O numero digitado foi:%d\n", num);
  }

  return 0;
}
