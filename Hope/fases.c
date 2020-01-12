#include "fases.h"


SDL_Texture *carregarTextura(SDL_Renderer *render,char *pathImage){

	SDL_Surface *imagem = NULL;
	SDL_Texture *texturaFuncao = NULL;
	imagem = IMG_Load(pathImage);

	
	if(imagem == NULL){
		printf("Erro na imagem da funcao texture %s\n",IMG_GetError());
	}else{
		texturaFuncao = SDL_CreateTextureFromSurface(render,imagem);
		if(texturaFuncao == NULL){
			printf("Erro na textura da funcao %s\n",SDL_GetError());
		}else{			
			return texturaFuncao;
		}
	}	
}

void controlFrameRate(Uint32 inicioGetTick){
	if( (1000 / FPS) > SDL_GetTicks() - inicioGetTick){
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - inicioGetTick));
	}
}
void sprite(Uint32 inicioGetTick){
	if( (1000 / SPRITEFPS) > SDL_GetTicks() - inicioGetTick){
		SDL_Delay((1000 / SPRITEFPS) - (SDL_GetTicks() - inicioGetTick));
	}
}

void encerrarJogo(SDL_Event event, int* fechar){

	if(event.type == SDL_QUIT){
		*fechar = 1;
	}

	if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
		*fechar = 1;
	}
}

void renderCopySprites(SDL_Renderer* renderer, Bloco* bl, PosicaoBloco* pb, int qtdLoop){

	for(int i = 0; i < qtdLoop; i++){
		SDL_RenderCopy(renderer,bl[i].loadBloco,NULL,&pb[i].loadRect);
	}
}

int lazyFoo(SDL_Rect a, SDL_Rect b){

	//The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x + 20;
    a.w = 72;
    rightA = a.x + a.w;
    topA = a.y;
    a.h = 91;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    //If none of the sides from A are outside B
    return 1;	
}

void emma(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	//523
	if(dRectGatoJoe->x >= 529 && dRectGatoJoe->x <= 668){
		//SETAR PARA 0 VARIAVEL BATEU_BL2 PARA FUNCIONAR CORRETAMENTE
			//BATEU_BL2 = 0;

		//INÍCIO DA FUNÇÃO DE JUMP DO BLOCORIGHT2	
		if(dRectGatoJoe->y > b.y){
			if(lazyFoo(a,b)){
				dRectGatoJoe->y += 6;
			}

			if(lazyFoo(a,b) && BATEU_BL != 1){
				BATEU_BL = 1;
				dRectGatoJoe->y += 6;
			}else if(!(lazyFoo(a,b)) && BATEU_BL != 1){
				dRectGatoJoe->y -= 3;
				
			}else if(BATEU_BL != 0){

				if(dRectGatoJoe->y >= 492){
					
					dRectGatoJoe->y = 492;
					BATEU_BL = 0;
					GATOUP = 0;
				}else{
					dRectGatoJoe->y += 6;
				}
			}
		}
		else if(dRectGatoJoe->y < b.y){
			if(dRectGatoJoe->y > 217&& BATEU_BL != 1){
			
				if(dRectGatoJoe->y <= 217)
					BATEU_BL = 1;
				dRectGatoJoe->y -= 3;

				

			}else if(dRectGatoJoe->y <= 217 && BATEU_BL != 1){
				
				BATEU_BL = 1;
			}
					
			else if(BATEU_BL != 0){
				
				dRectGatoJoe->y += 3;

				if(dRectGatoJoe->y > 327){
					dRectGatoJoe->y = 327;
					BATEU_BL = 0;
					GATOUP = 0;
				}
					
			}
		}

		
	}
	
}

void snow(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	
	if(dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 528){//515

		if(dRectGatoJoe->y > 262 && BATEU_BL2 != 1){
			
				if(dRectGatoJoe->y <= 262)
					BATEU_BL2 = 1;
				dRectGatoJoe->y -= 3;
				if(dRectGatoJoe->x > 516 && dRectGatoJoe->y > 327)
					dRectGatoJoe->x -= 10;				

			}else if(dRectGatoJoe->y <= 262 && BATEU_BL2 != 1){
				
				BATEU_BL2 = 1;

			}
					
			else if(BATEU_BL2 != 0){
				
				dRectGatoJoe->y += 3;
				if(dRectGatoJoe->x > 516 && dRectGatoJoe->y > 327)
					dRectGatoJoe->x -= 10;

				if(dRectGatoJoe->y > 432){
					dRectGatoJoe->y = 432;
					BATEU_BL2 = 0;
					GATOUP = 0;
				}
					
			}

			
		
	}
}



void henry(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 529) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) || (dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 323 && PODEDESCER) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 214 && !PODEDESCER) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196 && PODEDESCER) )){
		
		if(BLOQUEIA_CAT){

		}else{

			dRectGatoJoe->y += 3;
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				BATEU_BL3 = 0;
			}



		}

		
	}
}

void regina(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	
	if(dRectGatoJoe->x > 323 && dRectGatoJoe->x < 526){//>=392
		if(lazyFoo(a,b) && dRectGatoJoe->y < 327){
			dRectGatoJoe->y += 3;
		}else if(dRectGatoJoe->y >= 327 && lazyFoo(a,b)){
			dRectGatoJoe->y = 327;
			BLOQUEIA_CAT = 1;
			PODEANDAR = 1;
		}
	}
}

void zangado(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(dRectGatoJoe->y <= 432 && dRectGatoJoe->y >= 328 && dRectGatoJoe->x < 590 && lazyFoo(a,b)){
		dRectGatoJoe->x -= 6;
	}
	else if(dRectGatoJoe->y <= 459 && dRectGatoJoe->y >= 328 && dRectGatoJoe->x >= 590 && lazyFoo(a,b)){
		dRectGatoJoe->x += 6;
	}

}

void soneca(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	
	if(lazyFoo(a,b) && dRectGatoJoe->x > 484)
		dRectGatoJoe->x += 6;
	else if(lazyFoo(a,b) && dRectGatoJoe->x < 484)
		dRectGatoJoe->x -= 6;
}

void soneca_Right(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){
	
	if(lazyFoo(a,b) && dRectGatoJoe->x < 484)
		dRectGatoJoe->x -= 6;
	else if(lazyFoo(a,b) && dRectGatoJoe->x > 484)
		dRectGatoJoe->x += 6;
}

void thor(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(lazyFoo(a,b) && dRectGatoJoe->x < 590)
		dRectGatoJoe->x -= 6;
	else if(lazyFoo(a,b) && dRectGatoJoe->x > 590)
		dRectGatoJoe->x += 6;
}

void moveSpriteCatRight(SDL_Rect* sRectGatoJoe){

	//catPosicao

	sRectGatoJoe->y = 100;
	sRectGatoJoe->x += 100;
	if(sRectGatoJoe->x >= 1000){
		sRectGatoJoe->x = 100;
	}
}
void moveSpriteCatLeft(SDL_Rect* sRectGatoJoe){

	if(sRectGatoJoe->y < 900){
		sRectGatoJoe->y = 900;
	}									
	
	if(sRectGatoJoe->x <= 0){
		sRectGatoJoe->x = 1000;
	}
	sRectGatoJoe->x -= 100;
}

void pularMaisAlto_Left(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 523) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) ) && dRectGatoJoe->y < 492){
		dRectGatoJoe->x -= 6;
	}else{

		dRectGatoJoe->x -= 3;
	}
}
void pularMaisAlto_Right(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 523) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) ) && dRectGatoJoe->y < 492){
		dRectGatoJoe->x += 6;
	}else{

		dRectGatoJoe->x += 3;
	}
}



void wonderWoman(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(dRectGatoJoe->y <= 426 && dRectGatoJoe->y >= 291 && dRectGatoJoe->x < 235 && lazyFoo(a,b)){
		printf("Ne Possivel\n");
		dRectGatoJoe->x += 6;
	}

}

void arrow(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(PODEDESCER){
		if(dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 323){
			if(dRectGatoJoe->y > 217 && BATEU_BL != 1){
				
				if(dRectGatoJoe->y <= 217)
					BATEU_BL = 1;
				dRectGatoJoe->y -= 3;

				

			}else if(dRectGatoJoe->y <= 217 && BATEU_BL != 1){
				
				BATEU_BL = 1;
			}
					
			else if(BATEU_BL != 0){
				
				dRectGatoJoe->y += 3;

				if(dRectGatoJoe->y > 327){
					dRectGatoJoe->y = 327;
					BATEU_BL = 0;
					GATOUP = 0;
				}
					
			}
		}
	}


}

void felicity(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 214){

		if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196){
			
			if(dRectGatoJoe->y < b.y){
				if(dRectGatoJoe->y > 162 && BATEU_BL != 1){
				
					if(dRectGatoJoe->y <= 162)
						BATEU_BL = 1;
					dRectGatoJoe->y -= 3;

					

				}else if(dRectGatoJoe->y <= 162 && BATEU_BL != 1){
					
					BATEU_BL = 1;
				}
						
				else if(BATEU_BL != 0){
					
					dRectGatoJoe->y += 3;

					if(dRectGatoJoe->y >= 291){
						dRectGatoJoe->y = 291;
						BATEU_BL = 0;
						GATOUP = 0;
					}
						
				}
			}

			

		}
		
		if(dRectGatoJoe->y > b.y){
			if(lazyFoo(a,b)){
				dRectGatoJoe->y += 6;
			}

			if(lazyFoo(a,b) && BATEU_BL != 1){
				BATEU_BL = 1;
				dRectGatoJoe->y += 6;
			}else if(!(lazyFoo(a,b)) && BATEU_BL != 1){
				dRectGatoJoe->y -= 3;
				
			}else if(BATEU_BL != 0){

				if(dRectGatoJoe->y >= 492){
					
					dRectGatoJoe->y = 492;
					BATEU_BL = 0;
					GATOUP = 0;
				}else{
					dRectGatoJoe->y += 6;
				}
			}
		}
		
	}
}

void august(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196){
		if(dRectGatoJoe->y <= 291 && dRectGatoJoe->y >= 154){
				if(dRectGatoJoe->x > 180){
					dRectGatoJoe->x -= 6;
				}
		}
	}else if(dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 323 && PODEDESCER && !PODEANDAR){
		if(dRectGatoJoe->y <= 327 && dRectGatoJoe->y >= 211 && dRectGatoJoe->x > 317)
			dRectGatoJoe->x -= 6;
	}
}

void neal(SDL_Rect* dRectGatoJoe,SDL_Rect* racaoRect,SDL_Rect a,SDL_Rect b, Bloco* racaoB,Bloco* sinalR,SDL_Renderer* renderer){

	if(lazyFoo(a,b)	&& dRectGatoJoe->x >= 575 && dRectGatoJoe->x <= 588){
		racaoRect->x = 8000;
		racaoRect->y = 8000;
		racaoRect->w = 0;
		racaoRect->h = 0;

		racaoB[0].loadBloco = NULL;
		sinalR->loadBloco = NULL;
		sinalR->loadBloco = carregarTextura(renderer,"../img/sinalGreen.png");
		PODEDESCER = 1;
		BLOQUEIA_CAT = 1;
	}
}


void cair(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 529) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 214 && !PODEDESCER) ||  (dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 323 && PODEDESCER) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196 && PODEDESCER) /*|| (dRectGatoJoe->x >= 392 && dRectGatoJoe->x <= 518)*/ )){
		
		BATEU_BL = 0;
		BATEU_BL2 = 0;

		if(dRectGatoJoe->y < 492 && BATEU_BL3 == 0 && GATOUP){
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				
				//BATEU_BL3 = 2;
			}
				GATOUP = 0;
				dRectGatoJoe->y += 3;
		}


		if(dRectGatoJoe->y == 492 && BATEU_BL3 == 0){
			dRectGatoJoe->y -= 3;
			BATEU_BL3 = 1;
		}else if(dRectGatoJoe->y < 492 && BATEU_BL3 == 1){
			
			if(dRectGatoJoe->y <= 322)	
				BATEU_BL3 = 2;
			dRectGatoJoe->y -= 3;
		}else if((dRectGatoJoe->y < 492 && BATEU_BL3 == 2)){
			dRectGatoJoe->y += 3;
			//BATEU_BL3 = 2;
		}else if(dRectGatoJoe->y >= 492 && BATEU_BL3 == 2){
			dRectGatoJoe->y = 492;
			GATOUP = 0;
			BATEU_BL3 = 0;
		}
	}
}

void naoPassaDoLimiteDaJanela(SDL_Rect* dRectGatoJoe){

	if(dRectGatoJoe->x + dRectGatoJoe->w >= LARGURA_JANELA)
		dRectGatoJoe->x -= 6;

	if(dRectGatoJoe->x <= 0)
		dRectGatoJoe->x += 6;

}

int movimentoInimigo(SDL_Rect* dRectDog,SDL_Rect* sRectDog,int* chegou,int vivo){
	
	//faz o 1º bloco que está no ar se mover
	printf("Valor de chegouFlutua is %d\n",*chegou);

    //...


    

	if(vivo){
		
		if(dRectDog->x <= 895 && *(chegou) != 1){//586 895

			dRectDog->x += 1;
			
			moveSpriteCatRight(sRectDog);
		}else{
			
			moveSpriteCatLeft(sRectDog);

			if(dRectDog->x >= 895){
				*(chegou) = 1;
			}

			if(dRectDog->x <= 586){
				*(chegou) = 0;
			}

			dRectDog->x -= 1;
		}


	}else{
		return 0;
	}

	return 1;

}

void gatoMorreu(SDL_Rect* dRectGatoJoe,SDL_Rect* dRectDog, SDL_Rect a,SDL_Rect b,SDL_Rect* sRectGatoJoe){


	if(GATOMORREU == 0){
		if(lazyFoo(a,b)){

			sRectGatoJoe->y = 400;
			sRectGatoJoe->x = 900;


			

			printf("GATO MORREU\n");
			GATOMORREU = 1;
		}
	}



}
