#include <stdio.h>
#include <string.h>

/*Nome:Gustavo Hnerique Pereira Ferreira*/
/*Nome:Enzo Mantovani Bertoletti*/

FILE * file;

struct info
{ 
  char nome[100];
  int hora;
  int minuto;
  int idade;
  int sala;
};

struct info INFO[15];

int arq()
{
  
  for(int i = 0; i < 15; i++)
  {
    INFO[i].sala = 0;
  }

  file = fopen("/home/gustavo/Algoritimos/trabalhos/filmes.txt","r");

  if(file == NULL)
  {
    printf("Nao foi aberto corretamente a lista \n");

    return 1;
  }

  int i = 0;
  
  while(feof(file) == 0)
  {
    fscanf(file, "%[^\t] ", INFO[i].nome);
    fscanf(file, "%d\n", &INFO[i].hora);
    fscanf(file, "%d\n",  &INFO[i].sala);
    fscanf(file, "%d\n", &INFO[i].idade);
    i++;
    if(i >= 5)
    {
      break;
    }
  }
  
  fclose(file);
  i--;

  return 0;
}

void lista()
{

  for(int i = 0; i < 15; i++)
  { 
    if(INFO[i].sala == 0)
    {
      continue;
    }
    printf("Nome: %s - Hora: %d - Sala: %d - Idade: %d\n", INFO[i].nome,  INFO[i].hora, INFO[i].sala, INFO[i].idade); 
  }

}

int excluir()
{
  int exc;

  printf("Digite a sala que o filme esta passando para ser excluido:\n");
  scanf("%d", &exc);
  
  for(int i= 0; i < 15; i++)
  {
    if(exc == INFO[i].sala)
    {
      INFO[i].sala = 0;
      break;
    }
  }
  
  printf("\tFILME EXCLUIDO COM SUCESSO\n\n");

  return 1;
}

int adicionar()
{
  int i;

  for(i = 0; i < 15; i++)
  {
    if(INFO[i].sala == 0)
    {  
      printf("Coloque as informação do novo filme\n");
      printf("Nome:  - Hora:  - Sala:  - Idade: \n");
      scanf("%s %d %d %d", INFO[i].nome,  &INFO[i].hora, &INFO[i].sala, &INFO[i].idade); 
      break;
    }



  }
 
  return 1;
}

int main()
{
  arq();

  int opc = 0;

  do
  {

    printf("\n\tDIGITE A OPÇÃO QUE DESEJA\n");
    printf("\n1 - Lista de Filmes\n2 - Adicionar Filmes\n3 - Exluir Filmes\n0 - Sair do Programa\n\n");
    scanf("%d", &opc);

    switch(opc) 
    case 1:
    {
      lista();
      break;
    }
    switch(opc) 
    case 2:
    {
        adicionar();
        break;
    }
    switch(opc) 
    case 3:
    {
      excluir();
      break;
    }
  }while(opc != 0);
  

  return 0;
}
