#include <stdio.h>
#include <stdlib.h>

//Gustavo Henrique Pereira Ferreira

void list0()
{
  system("clear");

  int x;
  int y;

  printf("\tO primeiro valor é: %d\n\tO primeiro endereço é: %p \n\n", x, &x);
  printf("\tO segundo valor é: %d\n\to segundo endereço é: %p\n\n", y, &y);

  if(x > y)
  {
    printf("\tO primeiro valor é maior: %d que o segundo valor\n", x);
  }
  if(x < y)
  {
    printf("\nO segundo valor é maior: %d que o primeiro valor\n", y);
  }
  if(x == y)
  {
    printf("\tOs dois valores são iguais\n");
    printf("\tO primeiro valor é: %d\n\tO segundo valor é: %d\n\n", x, y);
  } 
  if(&x > &y)
  {
    printf("\tO primeiro endereço é maior: %p que o segundo endereço\n\n", &x);
  }
  if(&x < &y)
  {
    printf("\tO segundo endereço é maior: %p que o primeiro endereço\n\n", &y);
  }
  if(&x == &y)
  {
    printf("\tOs endereço é iguais\n");
    printf("\tO primeiro endereço é: %p\n\tO segundo endereço é: %p\n\n", &y, y);
  }
}

void list1()
{
  system("clear");

  int i;
  int j;

  printf("\tDigite o primeiro valor:");
  scanf("%d", &i);

  printf("\tDigite o segundo valor:");
  scanf("%d", &j);
  
  printf("\n");

  printf("\tO primeiro valor é: %d\n\tO primeiro endereço é: %p\n\n", i, &i);
  printf("\tO segundo valor é: %d\n\tO segundo endereço é: %p\n\n", j, &j);

  if(&i > &j)
  {
    printf("\tO menor endereço é: %p\n\tO conteudo do menor endereço é: %d\n\n", &j, j);
  }
  if(i == j)
  {
    printf("\tEles são iguais\n"); 
    printf("\tO primeiro valor é: %d\n\tO primeiro endereço é: %p\n\n", i, &i);
    printf("\tO segundo valor é: %d\n\tO segundo endereço é: %p\n\n", j, &j);
  }
}

void list2()
{
  system("clear");

  int vet[15];
  int *A;

  A = &vet[0];  
  
  printf("\tNumeros aleatorio prenchido automaticamente e seus valores\n\n");
  for(int i = 0; i < 15; i++)
  {
    *(A + i) = rand() % 20;
    printf("\tO endereço é: %p\n\tO conteudo é: %d\n\n", &vet[i], *(A + i));
  }
}

void list3()
{
  system("clear");

  char mat[3][5];

  int A = 65;

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 5; j++)
    { 
      mat[i][j] = A;
      A++;
    } 
  }
  printf("\n");

  printf("\t Letra do Alfabeto       Endereço\n");
  for(int i = 0; i < 3; i++)
  {
    printf("\n\t");
    for(int j = 0; j < 5; j++)
    {
     printf(" %c - %p", mat[i][j], &mat[i][j]);
    }
  }
}

void list4()
{
  system("clear");

  int vet[4];
  int *X;

  X = vet;

  for(int i = 0; i < 4; i++)
  {
    printf("\tDigite um valor: ");
    scanf("%d", (X + i));
  }
  
  printf("\n");

  printf("\tEndereços e valores\n\n");
  for(int i = 0; i < 4; i++)
  {
    printf("\t%p\t\t%d\n", (X + i), vet[i]);
  } 

  printf("\n");

  printf("\tEndereço e valores impresso ao contrario\n\n");
  for(int i = 3; i >= 0; i--)
  {
    printf("\t%p\t\t%d\n", (X + i), *(X + i));
  }

  printf("\n");

  printf("\tEndereços que possuem elemetos pares e o valores dentro dos endereços\n");
  for(int i = 0; i < 4; i++)
  {
    if(*(X + i) % 2 == 0)
    {
      printf("\n\t%p\t%d", (X + i), vet[i]);
    }
  }

  printf("\n\n");
  
  printf("\timpressão dos endereço e valores multiplicado por 3 3\n\n");
  for(int i = 0; i < 4; i++)
  {
    printf("\t%p\t%d\n", (X + i), *(X + i) * 3);
  }
  printf("\n");  
}

void list5()
{
  system("clear");

  int vet[10];
  int *A = &vet[0];
  int *B = &vet[9];

  for(int i = 0; i < 10; i++)
  {
    *(A + i) = (( i + 1) * 10);
  }
  printf("\tNumeros multiplos de  10\n\n");
  for(int i = 0; i < 10; i++)
  {
    printf("\t%d\n", *(A + i));
  }

  printf("\n");
  
  printf("\tNumeros na saida pedida\n\n");
  for(int i = 0; i < 10; i++)
  {
    printf("\t%d %d\n", *(A + i), *(B - i));
  }
}

void list6()
{
  system("clear");

  int i;
  int *j;
  int **k;
  int ***l;
  
  j = &i;
  k = &j;
  l = &k;

  printf("\tResultado de um numero aleatorio multiplicando  i por 2, j por 3, k por 4\n\n");
  
  i = (rand() % 10) + 1;

  printf("\tO valor de i é: %d\n\n", i);

  printf("\ti multiplicado por 2\n\n");
  printf("\t%d\n\n", *(j) * 2);

  printf("\ti multiplicado por j vezes 3\n\n");
  printf("\t%d\n\n", **(k) * 3);

  printf("\ti multiplicado por k vezes 4\n\n");
  printf("\t%d\n\n", ***(l) * 4);
}

int main()
{
  system("clear");
  
  int opc;

  do
  {
    printf("\n\n\tBem-Vindo ao menu de exercicio\n");
    printf("\n\texercicio - 1(0)\n\texercicio - 2(1)\n\texercicio - 3(2)\n\texerxicio - 4(3)\n\texercicio - 5(4)\n\texercicio - 6(5)\n\texercicio - 7(6)\n\t0 para encera o programa\n\n");
    printf("\tDigite o numero do exercicio que deseja: ");
    scanf("%d", &opc);

    printf("\n");
    
    switch(opc) 
    case 1:
    { 
      list0();
      break;
    }
    switch (opc) 
    case 2:
    {
      list1();
      break;
    }
    switch(opc)
    case 3:
    {
      list2();
      break;
    }
    switch(opc)
    case 4:
    {
      list3();
      break;
    }
    switch(opc)
    case 5:
    {
      list4();
      break;
    }
    switch(opc)
    case 6:
    {
      list5();
      break;
    }
    switch(opc)
    case 7:
    {
      list6();
      break;
    }
  } while (opc != 0);
  return 0;
}
