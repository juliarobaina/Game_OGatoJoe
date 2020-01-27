#ifndef _FASES_H_
#define _FASES_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <string.h>

#define LARGURA_JANELA 1000
#define ALTURA_JANELA 620
#define FPS 60
#define SPRITEFPS 30


#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

typedef struct bloco{
	SDL_Texture* loadBloco;
	
}Bloco;
typedef struct heroi{
	SDL_Texture* loadBloco;
	
}Heroi;

typedef struct posicaoBloco{
	SDL_Rect loadRect;
}PosicaoBloco;

typedef struct posicaoHeroi{
	SDL_Rect loadRect;
}PosicaoHeroi;


int GATODOWN = 0;
int GATOUP = 0;
int LEFTBLOCK = 0;
int GATOJUMPRIGHT = 0;
int BIGBLOCO1AR = 0;
int LIMITD;
int BATEU_BL = 0;
int BATEU_BL2 = 0;
int BATEU_BL3 = 0;
int GATORIGHT = 0;
int BATEU_BL4 = 0;

int PODEDESCER = 0;
int PODEANDAR = 0;
int BLOQUEIA_CAT = 0;

int GATOMORREU = 0;
int VIDASGATO = 3;
int PONTUACAO = 0;

SDL_Window *window = NULL;
SDL_Texture *backgroundTextura = NULL;
SDL_Renderer *renderer = NULL;

//inicio do GetTicks
Uint32 inicioGetTick;


SDL_Event event;

SDL_Color color = {00,36,220,255};
SDL_Texture *som = NULL;
SDL_Texture *notSom = NULL;
Mix_Music *musica = NULL;
Mix_Music *m2 = NULL;
Mix_Music *m3 = NULL;
Mix_Music *m4Historia = NULL;
Mix_Music *m5 = NULL;
Mix_Chunk *botao = NULL;
Mix_Chunk *coinSound = NULL;
Mix_Chunk *moverSound = NULL;


//Carregando fonte
TTF_Font *font;




	SDL_Texture *carregarTextura(SDL_Renderer *render,char *pathImage);
	void controlFrameRate(Uint32 inicioGetTick);
	void sprite(Uint32 inicioGetTick);
	void teclaRight_DontUP(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao,int* bloco1X);
	void movimentoBlocoNoAr(SDL_Rect* obstaculosPosicao, int* chegouFlutua);
	void encerrarJogo(SDL_Event event, int* fechar);
	void renderCopySprites(SDL_Renderer* renderer, Bloco* bl, PosicaoBloco* pb, int qtdLoop);
	int lazyFoo(SDL_Rect a, SDL_Rect b);
	void emma(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void snow(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void henry(SDL_Rect* dRectGatoJoe);
	void regina(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void zangado(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void soneca(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void soneca_Right(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void thor(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void moveSpriteCatRight(SDL_Rect* sRectGatoJoe);
	void moveSpriteCatLeft(SDL_Rect* sRectGatoJoe);
	void pularMaisAlto_Left(SDL_Rect* dRectGatoJoe);
	void pularMaisAlto_Right(SDL_Rect* dRectGatoJoe);
	void wonderWoman(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void arrow(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void felicity(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void august(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b,Bloco* racaoB);
	void august_left(SDL_Rect* dRectGatoJoe,Bloco* racaoB);
	void neal(SDL_Rect* dRectGatoJoe,SDL_Rect* racaoRect,SDL_Rect* racaoRect2,SDL_Rect* racaoRect3,
				SDL_Rect a,SDL_Rect b,SDL_Rect c,SDL_Rect d,Bloco* racaoB,Bloco* sinalR,Bloco* sinalR2,
				Bloco* sinalV,SDL_Renderer* renderer);
	void turtle(SDL_Rect* dRectGatoJoe);
	void cair(SDL_Rect* dRectGatoJoe);
	void naoPassaDoLimiteDaJanela(SDL_Rect* dRectGatoJoe);
	int movimentoInimigo(SDL_Rect* dRectDog,SDL_Rect* sRectDog,int* chegou,int vivo);
	void reiniciar(PosicaoBloco* obstaculosPosicao, PosicaoBloco* caixaBlocoMovel2, SDL_Rect* dRectGatoJoe,
	Bloco* sinalR,Bloco* racao, PosicaoBloco* racaoPos1,PosicaoBloco* racaoPos3,PosicaoBloco* coinRect,Bloco* coinB,
	Bloco* sinalV);
	void gatoMorreu(SDL_Rect* dRectGatoJoe,SDL_Rect* dRectDog, SDL_Rect a,SDL_Rect b,SDL_Rect* sRectGatoJoe,
	PosicaoBloco* obstaculosPosicao, PosicaoBloco* caixaBlocoMovel2,Bloco* sinalR,Bloco* racao,
	PosicaoBloco* racaoPos1,PosicaoBloco* racaoPos3,PosicaoBloco* coinRect,Bloco* coinB,Bloco* sinalV);
	int venceu(SDL_Rect* dRectGatoJoe,SDL_Rect* leiteRect,SDL_Rect a,SDL_Rect b,Bloco* leiteB);
	int iniciarSDL();
	SDL_Window* criarJanela();
	int iniciarIMG();
	void criarChao(Bloco* chao,PosicaoBloco* chaoPosicao);
	void criarBlocosEsquerdos(Bloco* blocosLeft, PosicaoBloco* blocosPosicaoLeft);
	void criarBlocosDireitos(Bloco* blocosRight, PosicaoBloco* blocosPosicaoRight);
	void iniciarObstaculos(Bloco* obstaculos, PosicaoBloco* obstaculosPosicao);
	void iniciarGato(Heroi* catJoe, PosicaoHeroi* catPosicao, PosicaoHeroi* catJoePosicao);
	void iniciarSinais(Bloco* sinalR,Bloco* sinalR2,PosicaoBloco* sinalRPos,PosicaoBloco* sinalRPos2);
	void iniciarRacao(Bloco* racao,PosicaoBloco* racaoPos);
	void iniciarInimigo(Bloco* inimigo,PosicaoBloco* sRect_inimigoPos,PosicaoBloco* dRect_inimigoPos);
	void iniciarLeite(Bloco* leite,PosicaoBloco* leitePos);
	void cairEntreBlocos(PosicaoHeroi* catJoePosicao,PosicaoHeroi* catPosicao);
	void destruirWRBTS();
	void destruirFase1(Heroi* catJoe,Bloco* sinalR,Bloco* sinalR2,
	Bloco* racao,Bloco* inimigo, Bloco* leite,Bloco* chao,
	Bloco* blocosLeft,Bloco* blocosRight, Bloco* obstaculos,
	Bloco* timerImg,SDL_Texture* minTexto,SDL_Texture* segTexto,
	SDL_Texture* sepaTexto,SDL_Texture* zeroTexto,SDL_Texture* fase,
	Bloco* vidaImg,SDL_Texture* vidaTextura,Bloco* coin,Bloco* coinImg,
	SDL_Texture* coinTextura);
	int iniciarTTF();
	void pegarMoeda(PosicaoBloco* coinRect,Bloco* coinB,SDL_Rect a,PosicaoBloco* b,int max);
	void iniciarTimer(Bloco* timerImg, PosicaoBloco* timerImgPos);
	void iniciarCoins(Bloco* coin,PosicaoBloco* dRectCoin,PosicaoBloco* sRectCoin);
	void iniciarVidaImg(Bloco* vidaImg,PosicaoBloco* vidaImgPos,SDL_Rect* vidaRect);
	void renderMoeda(Bloco* coin,PosicaoBloco* sRectCoin,PosicaoBloco* dRectCoin);
	int iniciarMusica();
	void henry2(SDL_Rect* dRectGatoJoe);
	void pularMaisAlto_Left2(SDL_Rect* dRectGatoJoe);
	void pularMaisAlto_Right2(SDL_Rect* dRectGatoJoe);
	void lua(SDL_Rect* dRectGatoJoe);
	void neal2(SDL_Rect* dRectGatoJoe,SDL_Rect* racaoRect,SDL_Rect a,SDL_Rect b,
				Bloco* racaoB,Bloco* sinalR,SDL_Renderer* renderer);
	void cair2(SDL_Rect* dRectGatoJoe);
	void flamenco(SDL_Rect* dRectGatoJoe);
	void espanhol(SDL_Rect* dRectGatoJoe);
	void rasgueado(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void palheta(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b,SDL_Rect c,SDL_Rect d);
	void cavaquinho(SDL_Rect* dRectGatoJoe);
	void escaleta(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void bumbo(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect c);
	void colisaoBlocoBaixoR(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo2E(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo3E(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo4E(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo5E(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixoE(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo2R(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo3R(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo4R(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void colisaoBlocoBaixo5R(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b);
	void naoPassaDoLimiteDaJanela2(SDL_Rect* dRectGatoJoe);
	int movimentoInimigo2(SDL_Rect* dRectDog,SDL_Rect* sRectDog,int* chegou,int vivo,int aleatorio);
	void reiniciar2(PosicaoBloco* obstaculosPosicao, PosicaoBloco* caixaBlocoMovel2, SDL_Rect* dRectGatoJoe,
	Bloco* sinalR,Bloco* racao, PosicaoBloco* racaoPos1,PosicaoBloco* coinRect,Bloco* coinB);
	void gatoMorreu2(SDL_Rect* dRectGatoJoe,SDL_Rect* dRectDog, SDL_Rect a,SDL_Rect b,SDL_Rect* sRectGatoJoe,
	PosicaoBloco* obstaculosPosicao, PosicaoBloco* caixaBlocoMovel2,Bloco* sinalR,Bloco* racao,
	PosicaoBloco* racaoPos1,PosicaoBloco* coinRect,Bloco* coinB,SDL_Rect c);
	void criarChao2(Bloco* chao,PosicaoBloco* chaoPosicao);
	void criarBlocosT(Bloco* chao,PosicaoBloco* chaoPosicao);
	void iniciarObstaculos2(Bloco* obstaculos, PosicaoBloco* obstaculosPosicao);
	void iniciarGato2(Heroi* catJoe, PosicaoHeroi* catPosicao, PosicaoHeroi* catJoePosicao);
	void iniciarSinais2(Bloco* sinalR,PosicaoBloco* sinalRPos);
	void iniciarRacao2(Bloco* racao,PosicaoBloco* racaoPos);
	void iniciarInimigo2_1(Bloco* inimigo,PosicaoBloco* sRect_inimigoPos,PosicaoBloco* dRect_inimigoPos);
	void iniciarInimigo2_2(Bloco* inimigo,PosicaoBloco* sRect_inimigoPos,PosicaoBloco* dRect_inimigoPos,int aleatorio);
	void iniciarLeite2(Bloco* leite,PosicaoBloco* leitePos);
	void destruirFase2(Heroi* catJoe,Bloco* sinalR,
	Bloco* racao,Bloco* inimigo, Bloco* leite,Bloco* chao,
	Bloco* blocosLeftT, Bloco* obstaculos,
	Bloco* timerImg,SDL_Texture* minTexto,SDL_Texture* segTexto,
	SDL_Texture* sepaTexto,SDL_Texture* zeroTexto,SDL_Texture* fase,
	Bloco* vidaImg,SDL_Texture* vidaTextura,Bloco* coin,Bloco* coinImg,
	SDL_Texture* coinTextura,Bloco* inimigo2);
	void pegarMoeda2(PosicaoBloco* coinRect,Bloco* coinB,SDL_Rect a,PosicaoBloco* b,int max);
	void iniciarCoins2(Bloco* coin,PosicaoBloco* dRectCoin,PosicaoBloco* sRectCoin);
	int movimentoInimigo3(SDL_Rect* dRectDog,SDL_Rect* sRectDog,int* chegou,int vivo);





#endif