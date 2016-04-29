/*
    Exercicio:
    28/04/2016
        - Implementar os menus do programa
        - Implementar a funcao que faz cadastro ordenados
*/


#include <stdio.h>
#include <stdlib.h>

//Linux
#define CLEAR "clear"
#define PAUSE "read a"

typedef  struct game{
    char nome[64];
    char plataforma [32];
    int lancamento;
    float preco;
    struct game *proximo;
}tpGame;

void limpa_buffer(){
    //Linux
    __fpurge(stdin);
}

void ler_game(tpGame *newgame){
    printf("\nNome do jogo: ");

    limpa_buffer();
    scanf("%[^\n]s",newgame->nome);

    printf("\nPlataforma do jogo: ");
    limpa_buffer();
    scanf("%[^\n]s",newgame->plataforma);

    printf("\nAno de lancamento do jogo: ");
    limpa_buffer();
    scanf("%d",&newgame->lancamento);

    printf("\nPreco do jogo: ");
    limpa_buffer();
    scanf("%f",&newgame->preco);
}

void imprime_game(tpGame *game){

    printf("\nNome do jogo: %s",game->nome);

    printf("\nPlataforma do jogo: %s",game->plataforma);

    printf("\nAno de lancamento do jogo: %d",game->lancamento);

    printf("\nPreco do jogo: R$%0.2f\n\n",game->preco);

}

void imprime_erros(int code){
    switch (code){
        case 1: {
            printf("\nNao foi possivel alocar a memoria\n");
            break;
            }
    }
}

int aloca_mem_newgame(tpGame **newgame){
    (*newgame) = (tpGame *) malloc(sizeof(tpGame));
    (*newgame)->proximo = NULL;

    if(*newgame){
        return 0;
    }else{
        return 1;
    }
}

void cadastra_game_ordenado(tpGame *cabeca){
    // Desenvolver aqui
}

void cadastra_game_ao_final(tpGame *cabeca){
    tpGame *newgame;
    tpGame *cursor;

    cursor = cabeca;

    if(aloca_mem_newgame(&newgame)){
        // Copia o endereco previamente alocado para dentro da
        // função ler_game, a função ler_game ira gravar o que
        // foi lido no endereço que foi passado para ela
        ler_game(newgame);

        // Faz incerssão ao final da lista
        while(cursor->proximo)
            // Navega até o fim da lista
            cursor = cursor->proximo;

        // Adiciona o novo elemento no fim da lista
        cursor->proximo = newgame;


    }else{
        imprime_erros(1);
    }
}

void imprime_lista_games(tpGame *cabeca){
    tpGame *cursor;

    cursor = cabeca;

    system(CLEAR);

    printf("Estao cadastrados os seguintes jogos: \n\n");
    // Navega elemento por elemento na lista
    while(cursor->proximo){
        cursor = cursor->proximo;
        imprime_game(cursor);
    }

    printf("\n\nFim da lista de Games... pressione ENTER\n\n");

    system(PAUSE);

}

int main()
{
    tpGame cabeca;
    cabeca.proximo = NULL;

    imprime_lista_games(&cabeca);

    system(CLEAR);
    cadastra_game_ao_final(&cabeca);

    system(CLEAR);
    cadastra_game_ao_final(&cabeca);


    imprime_lista_games(&cabeca);
    //ler_game(&cabeca);

    //imprime_game(&cabeca);

    return 0;
}
