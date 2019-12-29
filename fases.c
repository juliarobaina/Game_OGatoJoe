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

void continuarMovimentoCatJoe(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe, int* chegouTeto){
	//Quando o usuário soltar a tecla de pulo ele continua o movimento do estado final do personagem
	//avalia as variáveis globais GATODOWN e GATOJUMPRIGHT->se V então cai para a direita

	if(GATODOWN == 1){
		
		if(dRectGatoJoe->y > 400 && *chegouTeto != 1){
			

			if(dRectGatoJoe->y <= 445){
				dRectGatoJoe->y -= 2;	
				if(GATOJUMPRIGHT == 1){
					dRectGatoJoe->x += 1;
				}							
			}else{
				if(BIGBLOCO1AR == 1){
					dRectGatoJoe->y += 3;
				}else{
					dRectGatoJoe->y -= 3;
					if((dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && dRectGatoJoe->y <= 440){
						printf("AJHDK\n");
						BIGBLOCO1AR = 1;
					
					}
				}

				sRectGatoJoe->y = 292;
				sRectGatoJoe->x += 100;
				if(sRectGatoJoe->x >= 200){
					sRectGatoJoe->x = 100;
				}

				if(GATOJUMPRIGHT == 1){
					if((dRectGatoJoe->x >= 536 && dRectGatoJoe->x <= 572) && dRectGatoJoe->y > 492){
						dRectGatoJoe->x -= 20;
						GATOJUMPRIGHT = 0;
					}
					dRectGatoJoe->x += 1;
				}
			}

		}else{
			if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 530;
					if(GATOJUMPRIGHT == 1){
						GATOJUMPRIGHT = 0;
					}
					sRectGatoJoe->y = 0;
					sRectGatoJoe->x = 100;
				}else{

					dRectGatoJoe->y += 3;
					*chegouTeto = 1;
					if(GATOJUMPRIGHT == 1){
						dRectGatoJoe->x += 1;
					}
				}
		
		}
		
		if(dRectGatoJoe->y >= 492){
			dRectGatoJoe->y = 492;
			GATODOWN = 0;
			*chegouTeto = 0;
			sRectGatoJoe->y = 0;
			sRectGatoJoe->x = 100;
			if(GATOJUMPRIGHT == 1){
				GATOJUMPRIGHT = 0;
			}	
			
			BIGBLOCO1AR = 0;
			
		}
	}



}

int minimo(int a, int b){

	if(a > b)
		return a;
	else 
		return b;
}

void pular(SDL_Rect* catImg,SDL_Rect* catJoe,SDL_Rect* limiteTop,int limiteChao){

	int chegou = 0;

	
	if(catJoe->x >= 0 && catJoe->x <= 240){
		printf("limiteTop %d\n",limiteTop->y);
		printf("catJ %d\n",catJoe->y);
		
		if(catJoe->y <= 380+60){
			catJoe->y += 4;
			if(catJoe->y >= 380+60){
				catJoe->y -= 4;
			}
			printf("Entrei :|\n");
		}
		
	}
	
	//if(catJoe->y >= limiteTop->y){
	//	catJoe->y -= 3;
	//}
}
/*void colisao(Caixa* box,SDL_Rect* dRectGatoJoe,int repeticao,Uint32 inicioGetTick,int* chegouTeto){

	int tamTotal[repeticao];
	 

	for(int i = 0; i < repeticao; i++){

		tamTotal[i] = box[i].x + (repeticao * box[i].w);

		/*if(dRectGatoJoe->x >= box[i].x && dRectGatoJoe->x <= tamTotal[i]){
			if(dRectGatoJoe->y < (box[i].y + box[i].h)){
				dRectGatoJoe->y += 3;
			}
				dRectGatoJoe->y -= 3;
		}
	
		
			if((dRectGatoJoe->x >= box[i].x && dRectGatoJoe->x <= tamTotal[i]) && dRectGatoJoe->y <= 492 && LEFTBLOCK[] != 1){
					printf("Entrei gato esta %d\n",dRectGatoJoe->x);
					
					//Para fazer um efeito de pulo mais convincente!!!

					if(dRectGatoJoe->y <= 456){
						dRectGatoJoe->y -= (100 / 40) % inicioGetTick;
						
					}
					else {
						dRectGatoJoe->y -= (100 / SPRITEFPS) % inicioGetTick;
						
					}
					
					GATOUP = 1;
					if(dRectGatoJoe->y <= box[i].y+box[i].h) LEFTBLOCK[i] = 1;//350(440)

				}else if((dRectGatoJoe->x >= box[i].x && dRectGatoJoe->x <= tamTotal[i]) && LEFTBLOCK[i] != 0){
					
					//if(CONT > 1)
						//dRectGatoJoe->y += (100 / 40) % inicioGetTick;
						
					//else
						dRectGatoJoe->y += (100 / SPRITEFPS) % inicioGetTick;
					
					if(dRectGatoJoe->y >= 492){
						dRectGatoJoe->y = 492;
						LEFTBLOCK = 0;
						*chegouTeto = 1;	
						//CONT = 0;
					} 
				}
		}
	

}
*/

void diferenteRightUP(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,int* chegouTeto){
	printf("Entrei\n");
	if(*chegouTeto != 1){
		
		if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 216){
			
			if(dRectGatoJoe->y > 300 && LEFTBLOCK != 1){//ERA >=
			
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 440) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 300 && LEFTBLOCK != 0){
			
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;

				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
			if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 290 && LEFTBLOCK != 1){//ERA >=
	
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 178) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 290 && LEFTBLOCK != 0){

				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;

				if(dRectGatoJoe->y >= 290){
					dRectGatoJoe->y = 290;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}
		}else if(dRectGatoJoe->x > 216 && dRectGatoJoe->x < 222){

			if(dRectGatoJoe->y > 400 && LEFTBLOCK != 1){//ERA >=

				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 400) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){

				dRectGatoJoe->y += 3;
				
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}else if(dRectGatoJoe->x > 229 && dRectGatoJoe->x <= 234){
			if(dRectGatoJoe->y > 430 && LEFTBLOCK != 1){//ERA >=
	
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 430) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
		
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}else if(dRectGatoJoe->x > 234 && dRectGatoJoe->x <= 394){
			if(dRectGatoJoe->y > 473 && LEFTBLOCK != 1){//ERA >=

				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 473) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
		
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;
				if(dRectGatoJoe->y > 473 && dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
			if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 1){//ERA >=

				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 213) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 0){
		
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;
				if(dRectGatoJoe->y >= 325){
					dRectGatoJoe->y = 325;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}
		}else if(dRectGatoJoe->x > 394 && dRectGatoJoe->x < 402){
			if(dRectGatoJoe->y > 436 && LEFTBLOCK != 1){//ERA >=

				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 436) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
			
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}
		else if(dRectGatoJoe->x >= 542 && dRectGatoJoe->x < 547){
			if(dRectGatoJoe->y > 436 && LEFTBLOCK != 1){//ERA >=
			
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 436) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
		
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}
		else if(dRectGatoJoe->x >= 547 && dRectGatoJoe->x < 704){
			if(dRectGatoJoe->y > 473 && LEFTBLOCK != 1){//ERA >=
			
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 473) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
			
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
			if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 1){//ERA >=
			
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 213) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 0){
		
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;
				if(dRectGatoJoe->y >= 325){
					dRectGatoJoe->y = 325;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}

		}else if(dRectGatoJoe->x >= 704 && dRectGatoJoe->x < 714){
			if(dRectGatoJoe->y > 436 && LEFTBLOCK != 1){//ERA >=
				
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 436) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
		
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}else if(dRectGatoJoe->x >= 724 && dRectGatoJoe->x < 940){
			
			if(dRectGatoJoe->y > 2 && dRectGatoJoe->y <= 90 && LEFTBLOCK != 1){//ERA >=
				
				dRectGatoJoe->y -= 3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 22){
			
					LEFTBLOCK = 1;
				} 
			
			}else if(dRectGatoJoe->y > 2 && dRectGatoJoe->y <= 90 && LEFTBLOCK != 0){
		
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;
				if(dRectGatoJoe->y >= 90){
					dRectGatoJoe->y = 90;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}
			if(dRectGatoJoe->y > 350 && LEFTBLOCK != 1){
				
				dRectGatoJoe->y -= 3;
				GATOUP = 1;
				if(dRectGatoJoe->y <= 380) LEFTBLOCK = 1;
		
			}else if(dRectGatoJoe->y >= 373 && LEFTBLOCK != 0){
				
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 1;
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}

		}
		else{
			
		
			if(dRectGatoJoe->y > 350 && LEFTBLOCK != 1){
				
				dRectGatoJoe->y -= 3;
				GATOUP = 1;
				if(dRectGatoJoe->y <= 380) LEFTBLOCK = 1;
		
			}else if(dRectGatoJoe->y >= 373 && LEFTBLOCK != 0){
				
				dRectGatoJoe->y += 3;
				dRectGatoJoe->x += 50;
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}
	}

}
void diferenteRight(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe){
	if(dRectGatoJoe->x >= 428 && dRectGatoJoe->x <= 438 /*&& dRectGatoJoe->x <= 428+107 && dRectGatoJoe->y >= 492-60*/){
		printf("Fuuiii\n");
		dRectGatoJoe->x -= 3;
		if(dRectGatoJoe->y >= 492){
			dRectGatoJoe->y = 492;
		}
	}
}
void puloFase3(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,int* chegouTeto){
	printf("Entrei %d \n",dRectGatoJoe->x);
	if(*chegouTeto != 1){
		
		if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 216){
			
			if(dRectGatoJoe->y > 300 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 440) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 300 && LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
			if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 290 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 178) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 290 && LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 290){
					dRectGatoJoe->y = 290;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}
		}else if(dRectGatoJoe->x > 216 && dRectGatoJoe->x < 222){

			if(dRectGatoJoe->y > 400 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 400) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}else if(dRectGatoJoe->x > 229 && dRectGatoJoe->x <= 234){
			if(dRectGatoJoe->y > 430 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 430) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}else if(dRectGatoJoe->x > 234 && dRectGatoJoe->x <= 394){
			if(dRectGatoJoe->y > 473 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 473) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y > 473 && dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
			if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 213) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 325){
					dRectGatoJoe->y = 325;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}
		}else if(dRectGatoJoe->x > 394 && dRectGatoJoe->x < 402){
			if(dRectGatoJoe->y > 436 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 436) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}
		else if(dRectGatoJoe->x >= 542 && dRectGatoJoe->x < 547){
			if(dRectGatoJoe->y > 436 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 436) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}
		else if(dRectGatoJoe->x >= 547 && dRectGatoJoe->x < 704){
			if(dRectGatoJoe->y > 473 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 473) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
			if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 213) LEFTBLOCK = 1;
			
			}else if(dRectGatoJoe->y > 110 && dRectGatoJoe->y <= 325 && LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 325){
					dRectGatoJoe->y = 325;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}

		}else if(dRectGatoJoe->x >= 704 && dRectGatoJoe->x < 714){
			if(dRectGatoJoe->y > 436 && LEFTBLOCK != 1){//ERA >=
				printf("333333333\n");
				dRectGatoJoe->y -=3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 436) LEFTBLOCK = 1;
			
			}else if(LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
			
				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}else if(dRectGatoJoe->x >= 724 && dRectGatoJoe->x < 940){
			
			if(dRectGatoJoe->y > 2 && dRectGatoJoe->y <= 90 && LEFTBLOCK != 1){//ERA >=
				
				dRectGatoJoe->y -= 3;
				GATOUP = 1;

				if(dRectGatoJoe->y <= 22){
					printf("Pera %d\n",dRectGatoJoe->y);
					LEFTBLOCK = 1;
				} 
			
			}else if(dRectGatoJoe->y > 2 && dRectGatoJoe->y <= 90 && LEFTBLOCK != 0){
				printf("11111111\n");
				dRectGatoJoe->y += 3;
				
				if(dRectGatoJoe->y >= 90){
					dRectGatoJoe->y = 90;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
					
				} 

				
			}
			if(dRectGatoJoe->y > 350 && LEFTBLOCK != 1){
				
				dRectGatoJoe->y -= 3;
				GATOUP = 1;
				if(dRectGatoJoe->y <= 380) LEFTBLOCK = 1;
		
			}else if(dRectGatoJoe->y >= 373 && LEFTBLOCK != 0){
				
				dRectGatoJoe->y += 3;

				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}

		}
		else{
			
			printf("MICROCAMP %d leftblock %d\n",dRectGatoJoe->y,LEFTBLOCK);
			if(dRectGatoJoe->y > 350 && LEFTBLOCK != 1){
				
				dRectGatoJoe->y -= 3;
				GATOUP = 1;
				if(dRectGatoJoe->y <= 380) LEFTBLOCK = 1;
		
			}else if(dRectGatoJoe->y >= 373 && LEFTBLOCK != 0){
				
				dRectGatoJoe->y += 3;

				if(dRectGatoJoe->y >= 492){
					dRectGatoJoe->y = 492;
					LEFTBLOCK = 0;
					*chegouTeto = 1;
				} 
			}
		}
	}


}

void diferente(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,int* chegouTeto,SDL_Rect* problem,int* chegouFlutua){
	int c = 0;
	if(*chegouTeto != 1){
		//printf("GATOUP %d\n",GATOUP );
	

	if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 216){
		printf("Entrei???\n");
		if(dRectGatoJoe->y > 440 && LEFTBLOCK != 1){//ERA >=
			printf("333333333\n");
			dRectGatoJoe->y -=3;
			GATOUP = 1;

			if(dRectGatoJoe->y <= 440) LEFTBLOCK = 1;
		
		}else if(LEFTBLOCK != 0){
			printf("11111111\n");
			dRectGatoJoe->y += 3;
		
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				LEFTBLOCK = 0;
				*chegouTeto = 1;
			} 
		}
	}
	else if(dRectGatoJoe->x + 70  >= problem->x && dRectGatoJoe->x <= problem->x + 134){
		printf("2222222222\n");
		if(dRectGatoJoe->y > 440 && LEFTBLOCK != 1){
			printf("44444444444\n");
			dRectGatoJoe->y -=3;
			GATOUP = 1;
			

			if(dRectGatoJoe->y <= 440){
				LEFTBLOCK = 1;
			} 
		
		}else if(LEFTBLOCK != 0){
			printf("55555555\n");
			dRectGatoJoe->y += 3;
		
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				LEFTBLOCK = 0;
				*chegouTeto = 1;
			} 
		}else if(dRectGatoJoe->y <= 440 && LEFTBLOCK != 1){
			printf("FLASH ");
			SDL_Rect* v;
			v->x = 588;
			if(dRectGatoJoe->x > problem->x){
				*chegouFlutua = 1;
				movimentoBlocoNoAr(v,chegouFlutua);
				printf("maior o gato\n");
			}
			else if(dRectGatoJoe->x < problem->x){
				*chegouFlutua = 0;
			
				printf("maior e o bloco\n");
			}
			else
				printf("Sao iguais\n");
			printf("v->x %d\n",v->x);
			
		}
	}



	else{
		
		printf("6666\n");
		if(LEFTBLOCK != 1){
			printf("88888\n");
			dRectGatoJoe->y -= 3;
			GATOUP = 1;
			if(dRectGatoJoe->y <= 380) LEFTBLOCK = 1;
	
		}else if(LEFTBLOCK != 0){
			printf("9999999\n");
			dRectGatoJoe->y += 3;

			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				LEFTBLOCK = 0;
				*chegouTeto = 1;
			} 
		}
	}
}
}
void d(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe, int* chegouTeto,Uint32 inicioGetTick){

	/*
		400 é o limite que o gato pode alcançar no pulo, chegou teto é para saber se o gato já chegou no chão (rsrs).
		(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) isso serve para se o gato estiver somente embaixo desse bloco.
		dRectGatoJoe->y <= 492 do chão pra cima, LEFTBLOCK variável global para saber se já bateu a cabeça no bloco.
		GATOUP variável global para saber se o gato já pulou e está no ar.
		if(dRectGatoJoe->y <= 440) LEFTBLOCK = 1; condição para: o gato já bateu a cabeça no bloco? LEFTBLOCK recebe 1
		para não entrar mais no IF.

		(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && LEFTBLOCK != 0 já bati a cabeça no bloco, posso descer.
		if(dRectGatoJoe->y >= 492) se chegou no chão ou passou, LEFTBLOCK recebe 0 para não entrar mais na condição
		e chegouTeto recebe 1 para parar de pular.
	*/

	//sprite(inicioGetTick);
	if(dRectGatoJoe->y > 250 && *chegouTeto != 1){ //200(400)
		printf("gatinho %d\n",dRectGatoJoe->x-36);
		if((dRectGatoJoe->x-38 >= 0 && dRectGatoJoe->x-38 <= 180) && dRectGatoJoe->y <= 492 && LEFTBLOCK != 1){
			/*INÍCIO*/
			//Para fazer um efeito de pulo mais convincente!!!
			if(dRectGatoJoe->y <= 456){
				dRectGatoJoe->y -= (100 / 40) % inicioGetTick;
				
			}
			else {
				dRectGatoJoe->y -= (100 / SPRITEFPS) % inicioGetTick;
				
			}
			/*FIM*/
			GATOUP = 1;
			if(dRectGatoJoe->y <= 440) LEFTBLOCK = 1;//350(440)

		}else if((dRectGatoJoe->x-38 >= 0 && dRectGatoJoe->x-38 <= 180) && LEFTBLOCK != 0){
			
			//if(CONT > 1)
				//dRectGatoJoe->y += (100 / 40) % inicioGetTick;
				
			//else
				dRectGatoJoe->y += (100 / SPRITEFPS) % inicioGetTick;
			
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				LEFTBLOCK = 0;
				*chegouTeto = 1;	
				//CONT = 0;
			} 
		}else if(LEFTBLOCK != 1){
			dRectGatoJoe -= 3;
		}



	}

}

void teclaUP(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe, int* chegouTeto){//chegouTetoBlocoLeft

	if(dRectGatoJoe->y > 400 && *chegouTeto != 1){
								printf("Entrei aqui 1\n");
								if(dRectGatoJoe->y <= 425){
									printf("Entrei aqui 2\n");
									dRectGatoJoe->y -= 4;
									if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 3\n");
										dRectGatoJoe->x += 1;
									}
								}else{
									printf("Entrei aqui 4\n");
									if(BIGBLOCO1AR == 0){
										printf("Entrei aqui 5\n");
										dRectGatoJoe->y -= 6;
									}
									if((dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && dRectGatoJoe->y <= 440){
										printf("Entrei aqui 6\n");
										BIGBLOCO1AR = 1;
										GATODOWN = 1;
									}
									if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 7\n");
										if((dRectGatoJoe->x >= 536 && dRectGatoJoe->x <= 572) && dRectGatoJoe->y > 492){
											printf("Entrei aqui 8\n");
											dRectGatoJoe->x -= 20;
											GATOJUMPRIGHT = 0;
										}
										dRectGatoJoe->x += 1;
									}
									if(dRectGatoJoe->y <= 492){
										printf("Entrei aqui 9\n");
										sRectGatoJoe->x = 100;
										sRectGatoJoe->y = 292;
									}else{
										printf("Entrei aqui 10\n");
										sRectGatoJoe->x = 0;
									}
								}

							}else{
									printf("Entrei aqui 11\n");
								dRectGatoJoe->y += 6;
								if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
									dRectGatoJoe->y = 492;
									GATOJUMPRIGHT = 0;
										printf("Entrei aqui 12\n");
								}
								*chegouTeto = 1;
								if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 13\n");
									if((dRectGatoJoe->x >= 536 && dRectGatoJoe->x <= 572) && dRectGatoJoe->y > 492){
										dRectGatoJoe->x -= 20;
										GATOJUMPRIGHT = 0;
										printf("Entrei aqui 14\n");
									}
										dRectGatoJoe->x += 1;
																
								}
							}

							if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
									printf("Entrei aqui 15\n");
								*chegouTeto = 0;
								if(dRectGatoJoe->y > 300 && *chegouTeto != 1){
										printf("Entrei aqui 16\n");
									if(dRectGatoJoe->y <= 325){
											printf("Entrei aqui 17\n");
										dRectGatoJoe->y -= 4;
										if(GATOJUMPRIGHT == 1){
												printf("Entrei aqui 18\n");
											dRectGatoJoe->x += 1;
										}
									}else{
											printf("Entrei aqui 19\n");
										dRectGatoJoe->y -= 6;
										if(GATOJUMPRIGHT == 1){
												printf("Entrei aqui 20\n");
											dRectGatoJoe->x += 1;
										}
									}
								}else{
										printf("Entrei aqui 21\n");
									dRectGatoJoe->y += 6;
									if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
										dRectGatoJoe->y = 530;
										GATOJUMPRIGHT = 0;
											printf("Entrei aqui 22\n");
									}
									*chegouTeto = 1;
									if(GATOJUMPRIGHT == 1){
											printf("Entrei aqui 23\n");
										dRectGatoJoe->x += 1;
									}
									//colisao left
								}
							}

							if(dRectGatoJoe->y >= 617){
									printf("Entrei aqui 24\n");
								dRectGatoJoe->y = 617;
								*chegouTeto = 0;
								if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 25\n");
									GATOJUMPRIGHT = 0;
								}
								
							}	
}

void teclaRight_DontUP(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao,int* bloco1X){

	//Se o personagem estiver no ar e a tecla pulo não estiver mais pressionada e o usuário pressionar a tecla direita então o personagem cai para a direita
	if(catJoePosicao->y < 617){
		//catJoePosicao->x += 1;	
		GATOJUMPRIGHT = 1;
	}else{
		//Verifica se o personagem está no chão e se V então poderá andar para a direita
		catPosicao->y = 100;
		catPosicao->x += 100;
	
		catJoePosicao->x += 3;
	
		if(catPosicao->x >= 1000){
			catPosicao->x = 100;
		}

		//colisão com o bloco1 pequeno estático no chão
		if(catJoePosicao->x >= *(bloco1X) && catJoePosicao->x <= 572){
			catJoePosicao->x-= 20;

		}
	}
}

void movimentoBlocoNoAr(SDL_Rect* obstaculosPosicao, int* chegouFlutua){

	//faz o 1º bloco que está no ar se mover
	printf("Valor de chegouFlutua is %d\n",*chegouFlutua);
	if(obstaculosPosicao->x <= 588 && *(chegouFlutua) != 1){

		obstaculosPosicao->x += 1;
		
	}else{
		
		obstaculosPosicao->x -= 1;
		if(obstaculosPosicao->x == 588){
			*(chegouFlutua) = 1;
		}

		if(obstaculosPosicao->x <= 260){
			*(chegouFlutua) = 0;
		}
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
//teclaUP(&catJoePosicao.loadRect,&catPosicao.loadRect,&chegouTetoBlocoLeft);