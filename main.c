#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox; // padrão

} No;

typedef struct ctrl
{
    No *ini;//no inicio
    No *fim;//no fim

} Ctrl; //controle dos inicio e fim

int inicializar(Ctrl **inicio,No **inicio2);
int inserir(Ctrl **inicio,int dado);
int remover(Ctrl **inicio);
int listar(Ctrl *inicio);
int Obter_tamanho(Ctrl *inicio);
int dividir(Ctrl *inicio,Ctrl *inicio1,Ctrl *inicio3);

int main()
{

    int o,info,tam;
    Ctrl *ini,*ini5,*ini6;
    No *ini2,*ini3,*ini4;

    ini = (Ctrl*) malloc(sizeof(Ctrl));
    inicializar(&ini,&ini2);

    ini5 = (Ctrl*) malloc(sizeof(Ctrl));
    inicializar(&ini5,&ini3);

    ini6 = (Ctrl*) malloc(sizeof(Ctrl));
    inicializar(&ini6,&ini4);

    do
    {
        printf("\n");
        printf("Opçoes\n");
        printf("1 - Inserir\n");
        printf("2- Listar\n");
        printf("3- Remover\n");
        printf("4- Obter Tamanho da lista \n");
        printf("5- Dividir Fila em duas (P1 e P2) \n");
        printf("0- Sair \n");
        scanf("%d%*c",&o);

        switch(o)
        {

        case 1:
            printf("\n");
            printf(" Dado Inserir: ");
            scanf("%d%*c",&info);
            inserir(&ini,info);

            break;


        case 2:
            listar(ini);
            break;


        case 3:
            remover(&ini);
            break;


        case 4:
            tam = Obter_tamanho(ini);
            if(tam == 0)
            {
                printf("\n Obter Tamanho impossivel. FILA Sem dados!! \n");
            }
            else
                printf("\n Tamanho da FILA:%d \n",tam);

            break;

        case 5:
            dividir(ini,ini5,ini6);
            printf("\n P1 \n");
            listar(ini5);
            printf("\n P2 \n");
            listar(ini6);

            break;


        }

    }
    while(o!=0);

    return 0;
}

int inicializar(Ctrl **inicio,No **inicio2)
{
    (*inicio) -> ini = NULL;//usar quando struct com **
    (*inicio) -> fim = NULL;

    *inicio2 = NULL;// não precisa do() pois não quero acessar nada de dentro da struct
}

int inserir(Ctrl **inicio,int dado)
{
    No *novo;

    // no-> prox // usar isso quando quero mexer no no(q seria o proximo do no)
    novo = (No*) malloc(sizeof(No));
    novo -> dado = dado;
    novo -> prox = NULL;

    if((*inicio)->ini == NULL)
    {
        (*inicio)->ini = novo;
        (*inicio)->fim = novo;

    }

    else
    {
        //ctrl->fim = novo->prox (estaria sentando para null)
        (*inicio)->fim-> prox = novo;
        (*inicio)->fim = novo;
    }
    return 0;
}

int listar(Ctrl *inicio)
{
    No *aux;
    aux = inicio->ini;//para deixar com menos ->

    if(inicio != NULL)//essa condição pode ser inicio pois é a condição de entrada
    {

        if(aux == NULL)
        {
            printf("\n FILA Vazia \n");
        }
        while(aux != NULL)
        {
            printf("Dado da FILA: %d \n",aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }

    return 0 ;
}

int remover(Ctrl **inicio)
{
    No *aux;
    aux = (*inicio)->ini;

    if(aux == NULL)
    {
        printf("\n Remoção impossivel. FILA Sem dados!! \n");
    }

    else
    {
        (*inicio)->ini = (*inicio)->ini-> prox;
        free(aux);

    }

    return 0;
}

int Obter_tamanho(Ctrl *inicio)
{
    No *aux;
    aux = inicio->ini;
    int x=0;

    if(aux == NULL)

    {
        return 0;
    }
    else
    {
        while(aux != NULL)
        {
            x++;
            aux = aux->prox;
        }
    }

    return x;

}

int dividir(Ctrl *inicio,Ctrl *inicio1,Ctrl *inicio2)
{
    No *percorre;
    int cont,x,metade,info;

    percorre = inicio->ini;
    cont = Obter_tamanho(inicio);
    metade = cont/2;

    if(percorre == NULL)

    {
        printf("\n Dividir FILA impossivel. FILA Sem dados!! \n");
    }

    else
    {
        for(x=0;x< metade;)
        {
            info = percorre->dado;
            inserir(&inicio1,info);
            x++;
            percorre = percorre->prox;

        }
        for(x = metade; x<cont;)
        {
            info = percorre->dado;
            inserir(&inicio2,info);
            x++;
            percorre = percorre->prox;
        }

    }
}





