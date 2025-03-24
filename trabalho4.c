#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 3
#define MAX_PRODUCTS 5

// Definição dos tipos de registros
struct Categoria
{
    char codigo;
    char nome[50];
};

struct Produto
{
    int ID;
    char nome[50];
    char codigo_categoria;
    float preco;
};

// Declaração dos vetores para armazenar categorias e produtos
struct Categoria categorias[MAX_CATEGORIES];
struct Produto produtos[MAX_PRODUCTS];

// Variáveis globais para controlar o número de categorias e produtos cadastrados
int num_categorias = 0;
int num_produtos = 0;

// Função para exibir o menu de opções
void exibir_menu()
{
    printf("\nMenu:\n");
    printf("1. Inserir categoria\n");
    printf("2. Inserir produto\n");
    printf("3. Atualizar categoria\n");
    printf("4. Atualizar produto\n");
    printf("5. Excluir categoria\n");
    printf("6. Excluir produto\n");
    printf("7. Listar produtos cadastrados\n");
    printf("8. Sair\n");
}

// Função para inserir uma nova categoria
void inserir_categoria()
{
    if (num_categorias >= MAX_CATEGORIES)
    {
        printf("Limite de categorias atingido!\n");
        return;
    }

    struct Categoria nova_categoria;
    printf("Digite o código da categoria: ");
    scanf(" %c", &nova_categoria.codigo);

    // Verifica se a categoria já existe
    for (int i = 0; i < num_categorias; i++)
    {
        if (categorias[i].codigo == nova_categoria.codigo)
        {
            printf("Categoria já existe!\n");
            return;
        }
    }

    printf("Digite o nome da categoria: ");
    scanf(" %[^\n]", nova_categoria.nome);

    categorias[num_categorias++] = nova_categoria;
    printf("Categoria inserida com sucesso!\n");
}

// Função para inserir um novo produto
void inserir_produto()
{
    if (num_produtos >= MAX_PRODUCTS)
    {
        printf("Limite de produtos atingido!\n");
        return;
    }

    struct Produto novo_produto;
    printf("Digite o ID do produto: ");
    scanf("%d", &novo_produto.ID);

    // Verifica se o ID já existe
    for (int i = 0; i < num_produtos; i++)
    {
        if (produtos[i].ID == novo_produto.ID)
        {
            printf("ID de produto já existe!\n");
            return;
        }
    }

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo_produto.nome);

    printf("Digite o código da categoria: ");
    scanf(" %c", &novo_produto.codigo_categoria);

    // Verifica se a categoria existe
    int categoria_existente = 0;
    for (int i = 0; i < num_categorias; i++)
    {
        if (categorias[i].codigo == novo_produto.codigo_categoria)
        {
            categoria_existente = 1;
            break;
        }
    }
    if (!categoria_existente)
    {
        printf("Categoria não existe!\n");
        return;
    }

    printf("Digite o preço do produto: ");
    scanf("%f", &novo_produto.preco);

    produtos[num_produtos++] = novo_produto;
    printf("Produto inserido com sucesso!\n");
}

// Função para atualizar uma categoria existente
void atualizar_categoria()
{
    char codigo;
    printf("Digite o código da categoria a ser atualizada: ");
    scanf(" %c", &codigo);

    for (int i = 0; i < num_categorias; i++)
    {
        if (categorias[i].codigo == codigo)
        {
            printf("Digite o novo nome da categoria: ");
            scanf(" %[^\n]", categorias[i].nome);
            printf("Categoria atualizada com sucesso!\n");
            return;
        }
    }

    printf("Categoria não encontrada!\n");
}

// Função para atualizar um produto existente
void atualizar_produto()
{
    int ID;
    printf("Digite o ID do produto a ser atualizado: ");
    scanf("%d", &ID);

    for (int i = 0; i < num_produtos; i++)
    {
        if (produtos[i].ID == ID)
        {
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]", produtos[i].nome);
            printf("Digite o novo código da categoria: ");
            scanf(" %c", &produtos[i].codigo_categoria);

            // Verifica se a nova categoria existe
            int categoria_existente = 0;
            for (int j = 0; j < num_categorias; j++)
            {
                if (categorias[j].codigo == produtos[i].codigo_categoria)
                {
                    categoria_existente = 1;
                    break;
                }
            }
            if (!categoria_existente)
            {
                printf("Categoria não existe!\n");
                return;
            }

            printf("Digite o novo preço do produto: ");
            scanf("%f", &produtos[i].preco);
            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }

    printf("Produto não encontrado!\n");
}

// Função para excluir uma categoria
void excluir_categoria()
{
    char codigo;
    printf("Digite o código da categoria a ser excluída: ");
    scanf(" %c", &codigo);

    // Verifica se existem produtos associados à categoria
    for (int i = 0; i < num_produtos; i++)
    {
        if (produtos[i].codigo_categoria == codigo)
        {
            printf("Não é possível excluir a categoria pois existem produtos associados a ela!\n");
            return;
        }
    }

    for (int i = 0; i < num_categorias; i++)
    {
        if (categorias[i].codigo == codigo)
        { //categoria excluida
            categorias[i].codigo = '0';
            printf("Categoria excluída com sucesso!\n");
            return;
        }
    }

    printf("Categoria não encontrada!\n");
}

// Função para excluir um produto
void excluir_produto()
{
    int ID;
    printf("Digite o ID do produto a ser excluído: ");
    scanf("%d", &ID);

    for (int i = 0; i < num_produtos; i++)
    { //exclusão do produto
        if (produtos[i].ID == ID)
        {
            produtos[i].ID = 0;
            printf("Produto excluído com sucesso!\n");
            return;
        }
    }

    printf("Produto não encontrado!\n");
}

// Função para listar todos os produtos cadastrados
void listar_produtos()
{
    printf("\nListagem de produtos cadastrados:\n");
    printf("ID\tNome do Produto\tCategoria\tPreço\n");
    for (int i = 0; i < num_produtos; i++)
    { // Verifica se o produto foi excluído
        if (produtos[i].ID != 0)
        {
            printf("%d\t%s\t\t%c\t\t%.2f\n", produtos[i].ID, produtos[i].nome, produtos[i].codigo_categoria, produtos[i].preco);
        }
    }
}

int main()
{
    int opcao;
    
    system("clear");
  
    do
    {

        exibir_menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        system("clear");

        switch (opcao)
        {
        case 1:
            inserir_categoria();
            break;
        case 2:
            inserir_produto();
            break;
        case 3:
            atualizar_categoria();
            break;
        case 4:
            atualizar_produto();
            break;
        case 5:
            excluir_categoria();
            break;
        case 6:
            excluir_produto();
            break;
        case 7:
            listar_produtos();
            break;
        case 8:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }

        
    } while (opcao != 8);

    return 0;
}
