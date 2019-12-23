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

void continuarMovimentoCatJoe(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao, int* chegouTetoBlocoLeft){
	//Quando o usuário soltar a tecla de pulo ele continua o movimento do estado final do personagem
	//avalia as variáveis globais GATODOWN e GATOJUMPRIGHT->se V então cai para a direita

	if(GATODOWN == 1){
						
		if(catJoePosicao->y > 400 && *(chegouTetoBlocoLeft) != 1){
			

			if(catJoePosicao->y <= 425){
				catJoePosicao->y -= 2;	
				if(GATOJUMPRIGHT == 1){
					catJoePosicao->x += 1;
				}							
			}else{
				if(BIGBLOCO1AR == 1){
					catJoePosicao->y += 3;
				}else{
					catJoePosicao->y -= 3;
					if((catJoePosicao->x >= 0 && catJoePosicao->x <= 332) && catJoePosicao->y <= 480){
						
						BIGBLOCO1AR = 1;
					
					}
				}

				catPosicao->y = 292;
				catPosicao->x += 100;
				if(catPosicao->x >= 200){
					catPosicao->x = 100;
				}

				if(GATOJUMPRIGHT == 1){
					if((catJoePosicao->x >= 536 && catJoePosicao->x <= 572) && catJoePosicao->y > 530){
						catJoePosicao->x -= 20;
						GATOJUMPRIGHT = 0;
					}
					catJoePosicao->x += 1;
				}
			}

		}else{
			if((catJoePosicao->x >= 570 && catJoePosicao->x <= 682) && catJoePosicao->y >= 530){
				catJoePosicao->y = 530;
					if(GATOJUMPRIGHT == 1){
						GATOJUMPRIGHT = 0;
					}
					catPosicao->y = 0;
					catPosicao->x = 100;
				}else{

					catJoePosicao->y += 3;
					*(chegouTetoBlocoLeft) = 1;
					if(GATOJUMPRIGHT == 1){
						catJoePosicao->x += 1;
					}
				}
		
		}
		
		if(catJoePosicao->y >= 617){
			catJoePosicao->y = 617;
			GATODOWN = 0;
			*(chegouTetoBlocoLeft) = 0;
			catPosicao->y = 0;
			catPosicao->x = 100;
			if(GATOJUMPRIGHT == 1){
				GATOJUMPRIGHT = 0;
			}	
			
			BIGBLOCO1AR = 0;
			
		}
		
	}



}

void teclaUP(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao, int* chegouTetoBlocoLeft){

	if(catJoePosicao->y > 400 && *(chegouTetoBlocoLeft) != 1){
		if(catJoePosicao->y <= 425){
			catJoePosicao->y -= 4;
			if(GATOJUMPRIGHT == 1){
				catJoePosicao->x += 1;
			}
		}else{
			if(BIGBLOCO1AR == 0){
				catJoePosicao->y -= 6;
			}
			if((catJoePosicao->x >= 0 && catJoePosicao->x <= 332) && catJoePosicao->y <= 480){
				
				BIGBLOCO1AR = 1;
				GATODOWN = 1;
			}
			if(GATOJUMPRIGHT == 1){
				if((catJoePosicao->x >= 536 && catJoePosicao->x <= 572) && catJoePosicao->y > 530){
					catJoePosicao->x -= 20;
					GATOJUMPRIGHT = 0;
				}
				catJoePosicao->x += 1;
			}
			if(catJoePosicao->y <= 607){
				catPosicao->x = 100;
				catPosicao->y = 292;
			}else{
				catPosicao->x = 0;
			}
		}

	}else{
		catJoePosicao->y += 6;
		if((catJoePosicao->x >= 570 && catJoePosicao->x <= 682) && catJoePosicao->y >= 530){
			catJoePosicao->y = 530;
			GATOJUMPRIGHT = 0;
			
		}
		*(chegouTetoBlocoLeft) = 1;
		if(GATOJUMPRIGHT == 1){
			if((catJoePosicao->x >= 536 && catJoePosicao->x <= 572) && catJoePosicao->y > 530){
				catJoePosicao->x -= 20;
				GATOJUMPRIGHT = 0;
			}
				catJoePosicao->x += 1;
										
		}
	}

	if((catJoePosicao->x >= 570 && catJoePosicao->x <= 682) && catJoePosicao->y >= 530){
		*(chegouTetoBlocoLeft) = 0;
		if(catJoePosicao->y > 300 && *(chegouTetoBlocoLeft) != 1){
			if(catJoePosicao->y <= 325){
				catJoePosicao->y -= 4;
				if(GATOJUMPRIGHT == 1){
					catJoePosicao->x += 1;
				}
			}else{
				catJoePosicao->y -= 6;
				if(GATOJUMPRIGHT == 1){
					catJoePosicao->x += 1;
				}
			}
		}else{
			catJoePosicao->y += 6;
			if((catJoePosicao->x >= 570 && catJoePosicao->x <= 682) && catJoePosicao->y >= 530){
				catJoePosicao->y = 530;
				GATOJUMPRIGHT = 0;
			}
			*(chegouTetoBlocoLeft) = 1;
			if(GATOJUMPRIGHT == 1){
				catJoePosicao->x += 1;
			}
			//colisao left
		}
	}

	if(catJoePosicao->y >= 617){
		catJoePosicao->y = 617;
		*(chegouTetoBlocoLeft) = 0;
		if(GATOJUMPRIGHT == 1){
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