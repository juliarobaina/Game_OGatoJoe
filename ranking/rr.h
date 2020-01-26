#ifndef _RR_H_
#define _RR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogador{
	char nome[11];
	int pontos;
}Jogador;


void escreverArquivo(Jogador player);
void ordenar();
void lerArquivo();
int comparador(const void* a, const void* b);
long isVazio(const char* nomeArquivo);
void troca(Jogador pontoNovo);
int quantasLinhas();
void venceuRanking(Jogador pontoNovo);


#endif