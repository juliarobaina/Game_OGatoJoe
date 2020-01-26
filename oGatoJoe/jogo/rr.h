#ifndef _RR_H_
#define _RR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogador{
	char nome[6];
	int pontos;
}Jogador;


void escreverArquivo(Jogador player);
void ordenar();
int lerArquivo(SDL_Texture** jogTexto,SDL_Surface** jogSurface,SDL_Rect* jogRect,
				SDL_Texture** jogPontosTexto,SDL_Surface** jogPontosSurface,SDL_Rect* jogPontosRect);
int comparador(const void* a, const void* b);
long isVazio(const char* nomeArquivo);
void troca(Jogador pontoNovo);
int quantasLinhas(FILE* arquivo);
int quantasLinhasVenceu();
void venceuRanking(Jogador pontoNovo);


#endif
