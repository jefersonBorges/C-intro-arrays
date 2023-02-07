#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM_VENDEDORES 5
#define TAM_MESES 3

/*
void exibeMelhorVendedor(float vendas[TAM_VENDEDORES][TAM_MESES]);
void exibePiorMes(float vendas[TAM_VENDEDORES][TAM_MESES]);
void insereVendas(float vendas[TAM_VENDEDORES][TAM_MESES]);
*/

void insereVendas(int meses, int vendedores, float array[][TAM_VENDEDORES]);
void exibeMelhorVendedor(int meses, int vendedores, float array[][TAM_VENDEDORES]);
void exibePiorMes(int meses, int vendedores, float array[][TAM_VENDEDORES]);

int main(){
    setlocale(LC_ALL,"Portugues");
    float vendas[TAM_MESES][TAM_VENDEDORES];
    insereVendas(TAM_MESES,TAM_VENDEDORES, vendas);
    exibeMelhorVendedor(TAM_MESES,TAM_VENDEDORES, vendas);
    exibePiorMes(TAM_MESES,TAM_VENDEDORES, vendas);
}

void insereVendas(int meses, int vendedores, float array[][TAM_VENDEDORES]){
    for(int i = 0; i < meses; i++){
        for(int j = 0; j < vendedores; j++){
            printf("\nDigite o valor vendido para o %i mes do vendedor %i\n", i+1, j+1);
            scanf("%f", &array[i][j] );
            fflush(stdin);
            printf("%.2f", array[i][j]);
        }
    }
}
void exibeMelhorVendedor(int meses, int vendedores, float array[][TAM_VENDEDORES]){
    float maiorValor = 0.00;
    int vendedorMaiorValor = 0;
    for(int i = 0; i < meses; i++){
        for(int j = 0; j < vendedores; j++){
            float valor = array[i][j];
            if(valor > maiorValor){
                maiorValor = valor;
                vendedorMaiorValor = j+1;
            }
        }
    }
    printf("\nO vendedor com maior valor em vendas : %i vendeu %.2f", vendedorMaiorValor, maiorValor);
}
void exibePiorMes(int meses, int vendedores, float array[][TAM_VENDEDORES]){
    float menorValorTotal = 0.00;
    int mesMenorValor = 0;
    for(int i = 0; i < meses; i++){
        float valor = 0;
        for(int j = 0; j < vendedores; j++){
            valor += array[i][j];
        }
        if(i==0){
            menorValorTotal = valor;
            mesMenorValor = i+1;
        } else if ( valor < menorValorTotal){
            menorValorTotal = valor;
            mesMenorValor = i+1;
        }
    }
    printf("\nO mes com menor valor em vendas : %i vendeu %.2f", mesMenorValor, menorValorTotal);
}