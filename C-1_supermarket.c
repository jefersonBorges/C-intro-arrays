#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#define TAM_PRODUTOS 100

float adicionaValorProduto();
int adicionaProdutos(float produtos[]);
void imprimeValoresProdutos(int tamanhoLista, float produtos[]);
float retornaValorMaior(int tamanhoLista, float produtos[]);
float retornaValorMenor(int tamanhoLista, float produtos[]);
float totalGasto(int tamanhoLista, float produtos[]);
float mediaGastos(int tamanhoLista, float produtos[]);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int tamanhoLista;
    float produtos[TAM_PRODUTOS];
    float maior;
    float menor;

    tamanhoLista = adicionaProdutos(produtos);
    maior = retornaValorMaior(tamanhoLista, produtos);
    menor = retornaValorMenor(tamanhoLista, produtos);

    imprimeValoresProdutos(tamanhoLista, produtos);

    printf("O produto mais caro custa RS: %6.2f\n", maior);
    printf("O produto mais barato custa RS: %6.2f\n", menor);
    printf("A media de gasto foi RS: %6.2f\n", mediaGastos(tamanhoLista, produtos));

}
float adicionaValorProduto(){
    float valor;
    printf("\nDigite o valor do produto: \n");
    scanf("%f", &valor);
    fflush(stdin);
    return valor;
}
int adicionaProdutos(float produtos[]){
    int tamanhoLista;
    char resposta = 'S';
    int i = 0;
    while (resposta == 'S' && i <TAM_PRODUTOS){
        printf("\nDeseja cadastrar um valor? (S/N)\n");
        scanf("%c", &resposta);
        fflush(stdin);
        if(resposta == 'S'){
            produtos[i] = adicionaValorProduto();
            i++;
        } else {
            break;
        }
    }
    tamanhoLista = i;
    return tamanhoLista;
}
void imprimeValoresProdutos(int tamanhoLista, float produtos[]){
    printf("Nota fiscal: \n");
    for(int i = 0; i < tamanhoLista; i++){
        printf("\nProduto %i RS: %6.2f \n", (i+1),  produtos[i]);
    }
    printf("\n---\tValor total RS: %6.2f \t---\n", totalGasto(tamanhoLista, produtos));
}
float retornaValorMaior(int tamanhoLista, float produtos[]){
    float maiorValor;
    for(int i=0; i < tamanhoLista; i++){
        if(i == 0){
            maiorValor = produtos[i];
            continue;
        }
        if(produtos[i] > maiorValor){
            maiorValor = produtos[i];
        }
    }
    return maiorValor;
}
float retornaValorMenor(int tamanhoLista, float produtos[]){
    float menorValor;
    for(int i=0; i < tamanhoLista; i++){
        if(i == 0){
            menorValor = produtos[i];
            continue;
        }
        if(produtos[i] < menorValor){
            menorValor = produtos[i];
        }
    }
    return menorValor;
}
float totalGasto(int tamanhoLista, float produtos[]){
    float total = 0;
    for(int i = 0; i < tamanhoLista; i++){
        total += produtos[i];
    }
    return total;
}
float mediaGastos(int tamanhoLista, float produtos[]){
    float total = totalGasto(tamanhoLista, produtos);
    float media = (total / tamanhoLista);
    return media;
}