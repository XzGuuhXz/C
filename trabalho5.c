#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq_entrada;
FILE *arq_saida;

int TAM = 30;

struct pessoas
{
    char *nome;
    char *sobrenome;
    int idade;
    char *sexo;
    char *estado;
};

struct pessoas *p;

void abrir_arquivo()
{
    arq_entrada = fopen("/home/gustavo/Faculdade/Algoritimos/t_end/pessoas.txt", "r");

    if (arq_entrada == NULL)
    {
        printf("\n\tNão foi possível abrir o arquivo de entrada\n\n");
        exit(1);
    }
}

void le_pessoas(struct pessoas *p, int TAM)
{
    char nome[20];
    char sobrenome[20];
    char sexo[10];
    char estado[10];
    int idade;

    for (int i = 0; i < TAM; i++)
    {
        fscanf(arq_entrada, "%[^;]; %[^;]; %d; %[^;]; %[^;];\n", nome, sobrenome, &idade, sexo, estado);

        p[i].nome = malloc((strlen(nome) + 1) * sizeof(char));
        p[i].sobrenome = malloc((strlen(sobrenome) + 1) * sizeof(char));
        p[i].sexo = malloc((strlen(sexo) + 1) * sizeof(char));
        p[i].estado = malloc((strlen(estado) + 1) * sizeof(char));

        if (p[i].nome == NULL || p[i].sobrenome == NULL || p[i].sexo == NULL || p[i].estado == NULL)
        {
            printf("Erro na alocação de memória\n");
            exit(1);
        }

        strcpy(p[i].nome, nome);
        strcpy(p[i].sobrenome, sobrenome);
        strcpy(p[i].sexo, sexo);
        strcpy(p[i].estado, estado);
        p[i].idade = idade;
    }
}

void escreve_pessoas(struct pessoas *p, int TAM)
{
    arq_saida = fopen("saida_pessoas.txt", "w");

    if (arq_saida == NULL)
    {
        printf("\n\tNão foi possível abrir o arquivo de saída\n\n");
        exit(1);
    }

    for (int i = 0; i < TAM; i++)
    {
        fprintf(arq_saida, "Nome: %s\n", p[i].nome);
        fprintf(arq_saida, "Sobrenome: %s\n", p[i].sobrenome);
        fprintf(arq_saida, "Idade: %d\n", p[i].idade);
        fprintf(arq_saida, "Sexo: %s\n", p[i].sexo);
        fprintf(arq_saida, "Estado: %s\n\n", p[i].estado);
    }

    fclose(arq_saida);
    printf("Dados gravados no arquivo de saída 'saida_pessoas.txt'.\n");
}

void exibir_pessoas(struct pessoas *p, int TAM)
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Nome: %s\n", p[i].nome);
        printf("Sobrenome: %s\n", p[i].sobrenome);
        printf("Idade: %d\n", p[i].idade);
        printf("Sexo: %s\n", p[i].sexo);
        printf("Estado: %s\n\n", p[i].estado);
    }
}

void libera_memoria(struct pessoas *p, int TAM)
{
    for (int i = 0; i < TAM; i++)
    {
        free(p[i].nome);
        p[i].nome = NULL;

        free(p[i].sobrenome);
        p[i].sobrenome = NULL;

        free(p[i].sexo);
        p[i].sexo = NULL;

        free(p[i].estado);
        p[i].estado = NULL;
    }

    free(p);
    p = NULL;
}

int main()
{
    system("clear");

    struct pessoas *p = malloc(TAM * sizeof(struct pessoas));

    if (p == NULL)
    {
        printf("Erro na alocação de memória\n");
        exit(1);
    }
    
    abrir_arquivo();
    le_pessoas(p, TAM);
    fclose(arq_entrada);

    int opcao;

    do
    {
        printf("\n\tMENU:\n");
        printf("\n\t1 - Exibir pessoas\n");
        printf("\n\t2 - Salvar pessoas em arquivo\n");
        printf("\n\t3 - Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
            exibir_pessoas(p, TAM);
            break;

            case 2:
            escreve_pessoas(p, TAM);
            break;

            case 3:
            printf("Saindo...\n");
            break;

            default:
            printf("\n\tOpção inválida. Tente novamente.\n\n");
        }

    } while (opcao != 3);

    libera_memoria(p, TAM);

    return 0;
}
