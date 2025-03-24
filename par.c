#include <stdio.h>

int main()
{
  int var;
  int soma;

  var = 100;

  while(var > 0)
  {
    if(var % 2 == 0)
    {
      printf("a soma de %d + %d = %d\n", var, var, soma = var + var);
      printf("A soma de todos os numeros pares é: %d\n\n", soma = soma + var);

      var--;
    }

    var--;
  }

  return 0;
}
