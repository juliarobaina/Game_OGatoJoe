#include "fases.c"

int main(){

	SDL_Window *window = NULL;
	SDL_Texture *backgroundTextura = NULL;
	//SDL_Texture *blocos = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *sinal = NULL;
	SDL_Texture *caixa = NULL;
	SDL_Texture *gatoJoe = NULL;
	//SDL_Texture *cao = NULL;
	Bloco chao[8];
	PosicaoBloco chaoPosicao[8];

	Bloco blocosLeft[4];
	PosicaoBloco blocosPosicaoLeft[4];

	Bloco blocosRight[4];
	PosicaoBloco blocosPosicaoRight[4];

	Bloco obstaculos[10];
	PosicaoBloco obstaculosPosicao[10];

	Heroi catJoe;
	PosicaoHeroi catPosicao;
	PosicaoHeroi catJoePosicao;

	
	Bloco sinalR;
	PosicaoBloco sinalRPos;
	Bloco racao[1];
	PosicaoBloco racaoPos[1];

	//Controlar eventos
	SDL_Event event;

	

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		printf("Error ao iniciar SDL %s\n",SDL_GetError());

	}else{
		//Criando janela
		window = SDL_CreateWindow("Menu",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LARGURA_JANELA,ALTURA_JANELA,SDL_WINDOW_SHOWN);

		if(window == NULL){

			printf("Error na janela %s\n",SDL_GetError());

		}else{
			//Inicializa IMG_Load()
			if(IMG_Init(IMG_INIT_PNG) < 0){

				printf("Erro ao iniciar IMG_INIT %s\n",IMG_GetError());

			}else{
				//criando renderer
				renderer = SDL_CreateRenderer(window,-1,0);

				//criando textura da imagem de fundo
				backgroundTextura = carregarTextura(renderer,"../img/BG.png");
				
				//criar Chão
				for(int i = 0; i < 8;i++){
					chao[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
					chaoPosicao[i].loadRect.w = 125;
					chaoPosicao[i].loadRect.h = 60;
					
					if(i == 0)
						chaoPosicao[0].loadRect.x = 0;
					else
						chaoPosicao[i].loadRect.x = chaoPosicao[i - 1].loadRect.x + 125;
					
					chaoPosicao[i].loadRect.y = 580;
				}

				//criar blocos esquerdos
				for(int i = 0; i < 4;i++){
					blocosLeft[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
					blocosPosicaoLeft[i].loadRect.w = 60;
					blocosPosicaoLeft[i].loadRect.h = 60;
					
					if(i == 0)
						blocosPosicaoLeft[0].loadRect.x = 0;
					else
						blocosPosicaoLeft[i].loadRect.x = blocosPosicaoLeft[i - 1].loadRect.x + 60;
					
					blocosPosicaoLeft[i].loadRect.y = 380;
				}

				


				//criar blocos direitos
				for(int i = 0; i < 4;i++){
					blocosRight[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
					blocosPosicaoRight[i].loadRect.w = 60;
					blocosPosicaoRight[i].loadRect.h = 60;
					
					if(i == 0)
						blocosPosicaoRight[i].loadRect.x = 940;
					else
						blocosPosicaoRight[i].loadRect.x = blocosPosicaoRight[i - 1].loadRect.x - 60;
					
					blocosPosicaoRight[i].loadRect.y = 180;
				}

				//obstáculo terrestre
				obstaculos[0].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[0].loadRect.w = 60;
				obstaculosPosicao[0].loadRect.h = 60;
				obstaculosPosicao[0].loadRect.x = 500;
				obstaculosPosicao[0].loadRect.y = 520;

				obstaculos[1].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[1].loadRect.w = 60;
				obstaculosPosicao[1].loadRect.h = 60;
				obstaculosPosicao[1].loadRect.x = 580;
				obstaculosPosicao[1].loadRect.y = 415;
				obstaculos[2].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[2].loadRect.w = 60;
				obstaculosPosicao[2].loadRect.h = 60;
				obstaculosPosicao[2].loadRect.x = obstaculosPosicao[1].loadRect.x + 60;
				obstaculosPosicao[2].loadRect.y = 415;

				obstaculos[3].loadBloco = carregarTextura(renderer,"../img/flutua1_1.png");
				obstaculosPosicao[3].loadRect.w = 150;
				obstaculosPosicao[3].loadRect.h = 60;
				obstaculosPosicao[3].loadRect.x = obstaculosPosicao[1].loadRect.x - 145;
				obstaculosPosicao[3].loadRect.y = 150;

				


				//Gato Joe, herói do jogo
				catJoe.loadBloco = carregarTextura(renderer,"../img/gato.png");
				catPosicao.loadRect.w = 100;
				catPosicao.loadRect.h = 100;
				catPosicao.loadRect.x = 0;
				catPosicao.loadRect.y = 0;


				catJoePosicao.loadRect.w = 100;
				catJoePosicao.loadRect.h = 100;
				catJoePosicao.loadRect.x = 10;		
				catJoePosicao.loadRect.y = 492;
				//ALTURA_JANELA - catPosicao.loadRect.h - 28;
				//380-72

				sinalR.loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
				
				sinalRPos.loadRect.w = 60;
				sinalRPos.loadRect.h = 60;
				sinalRPos.loadRect.x = 650;
				sinalRPos.loadRect.y = 356;

				racao[0].loadBloco = carregarTextura(renderer,"../img/racao.png");
				
				racaoPos[0].loadRect.w = 30;
				racaoPos[0].loadRect.h = 30;
				racaoPos[0].loadRect.x = 620;
				racaoPos[0].loadRect.y = 392;
				

				//int limiteChao = ALTURA_JANELA - catPosicao.loadRect.h - 28;//492
				//Controla GameLoop
				int fechar = 0;
				//parametros botao
				int x,y;
				//inicio do GetTicks
				Uint32 inicioGetTick;

				//Controlar eventos
				SDL_Event event;
				
				float flPreviousTime = 0;
				float flCurrentTime = SDL_GetTicks();

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				const Uint8 *state = SDL_GetKeyboardState(NULL);

				int bloco1X = 536;
				int bloco1L = 128;
				int blocoH = 538;

				int bigBloco1 = 480;
				/*CRIANDO AS CAIXAS DE COLISÃO*/
				PosicaoBloco caixaBlocoLeft;
				caixaBlocoLeft.loadRect.x = 0;
				caixaBlocoLeft.loadRect.y = 385;//380
				caixaBlocoLeft.loadRect.w = 240;
				caixaBlocoLeft.loadRect.h = 60;

				PosicaoBloco caixaBlocoChao;
				caixaBlocoChao.loadRect.x = 510;//500-510
				caixaBlocoChao.loadRect.y = 525;//520
				caixaBlocoChao.loadRect.w = 42;//60 - 42
				caixaBlocoChao.loadRect.h = 60;

			

				PosicaoBloco caixaBlocoRight2;
				caixaBlocoRight2.loadRect.x = 585;//585
				caixaBlocoRight2.loadRect.y = 418;//418
				caixaBlocoRight2.loadRect.w = 100;
				caixaBlocoRight2.loadRect.h = 50;

				PosicaoBloco caixaBlocoRight;
				caixaBlocoRight.loadRect.x = 760;
				caixaBlocoRight.loadRect.y = 180;
				caixaBlocoRight.loadRect.w = 240;
				caixaBlocoRight.loadRect.h = 60;


				PosicaoBloco caixaBlocoMovel2;
				caixaBlocoMovel2.loadRect.x = 408;//464
				caixaBlocoMovel2.loadRect.y = 155;//155
				caixaBlocoMovel2.loadRect.w = 140;
				caixaBlocoMovel2.loadRect.h = 60;

				PosicaoBloco caixaBlocoRacao1;
				caixaBlocoRacao1.loadRect.x = 605;
				caixaBlocoRacao1.loadRect.y = 392;
				caixaBlocoRacao1.loadRect.w = 1;
				caixaBlocoRacao1.loadRect.h = 30;
				/*CRIANDO AS CAIXAS DE COLISÃO*/
				
				/*
					do lazy foo

				*/
				

				while(fechar != 1){
					printf("I'm here x= %d y= %d\n",catJoePosicao.loadRect.x,catJoePosicao.loadRect.y);
					//printf("BATEU_BL=%d -- BATEU_BL2=%d -- bateu_bl3=%d -- bateu_bl4=%d\n",BATEU_BL,BATEU_BL2,BATEU_BL3,BATEU_BL4);
					//printf("gatoup = %d\n",GATOUP);
					inicioGetTick = SDL_GetTicks();//tempo em milisegundos
					if(lazyFoo(catJoePosicao.loadRect, caixaBlocoMovel2.loadRect))
						printf("Colisão caixaBlocoRight2 %d\n",catJoePosicao.loadRect.x);
					/*else
						printf("Not Function caixaBlocoRight2\n");*/
					//if(lazyFoo(catJoePosicao.loadRect, caixaBlocoChao.loadRect))
						//printf("I'm here x= %d y= %d\n",catJoePosicao.loadRect.x,catJoePosicao.loadRect.y);
						//printf("BLABLABLA\n");
					/*else
						printf("it's over\n");
					
					
					/*if(lazyFoo(catJoePosicao.loadRect, caixaBlocoLeft2.loadRect))
						printf("Colisão caixaBlocoLeft2\n");
					else
						printf("Not Function caixaBlocoLeft2\n");
					if(lazyFoo(catJoePosicao.loadRect, caixaBlocoLeft.loadRect))
						printf("Colisão caixaBlocoLeft\n");
					else
						printf("Not Function caixaBlocoLeft\n");
					if(lazyFoo(catJoePosicao.loadRect, caixaBlocoChao.loadRect))
						printf("Colisão caixaBlocoChao\n");
					else
						printf("Not Function caixaBlocoChao\n");
					
					
					if(lazyFoo(catJoePosicao.loadRect, caixaBlocoRight.loadRect))
						printf("Colisão caixaBlocoRight\n");
					else
						printf("Not Function caixaBlocoRight\n");
					if(lazyFoo(catJoePosicao.loadRect, caixaBlocoMovel1.loadRect))
						printf("Colisão caixaBlocoMovel1\n");
					else
						printf("Not Function caixaBlocoMovel1\n");
					if(lazyFoo(catJoePosicao.loadRect, caixaBlocoMovel2.loadRect))
						printf("Colisão caixaBlocoMovel2\n");
					else
						printf("Not Function caixaBlocoMovel2\n");*/
					
					naoPassaDoLimiteDaJanela(&catJoePosicao.loadRect);
					
					if(GATOUP){
						snow(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
						emma(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
						
						cair(&catJoePosicao.loadRect);
						arrow(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
						felicity(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);
					}else{
						if(catJoePosicao.loadRect.x >= 449 && catJoePosicao.loadRect.x <= 526 && catJoePosicao.loadRect.y < 432){
							catJoePosicao.loadRect.y += 3;
							if(catPosicao.loadRect.y == 900)
								catJoePosicao.loadRect.x -= 1;

							if(catJoePosicao.loadRect.y >= 432)
								catJoePosicao.loadRect.y = 432;
							
						}
						henry(&catJoePosicao.loadRect);

						neal(&catJoePosicao.loadRect,&caixaBlocoRacao1.loadRect,catJoePosicao.loadRect,caixaBlocoRacao1.loadRect, racao,&sinalR,renderer);
					}

					if(PODEDESCER){
						obstaculosPosicao[3].loadRect.y += 3;

						if(obstaculosPosicao[3].loadRect.y >= 409){
							obstaculosPosicao[3].loadRect.y = 409;
							caixaBlocoMovel2.loadRect.y = 407;
							if(catJoePosicao.loadRect.x >= 526 && catJoePosicao.loadRect.x <= 668){
								BLOQUEIA_CAT = 0;

							}
							
							
						}
						regina(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);

						if(PODEANDAR){
							if(obstaculosPosicao[3].loadRect.x <= 435 && obstaculosPosicao[3].loadRect.y == 409){
								obstaculosPosicao[3].loadRect.x -= 2;
								catJoePosicao.loadRect.x -= 2;
								if(obstaculosPosicao[3].loadRect.x <= 235){
									obstaculosPosicao[3].loadRect.x = 235;
									caixaBlocoMovel2.loadRect.x = 180;
									PODEANDAR = 0;
									BLOQUEIA_CAT = 0;

								
								}
							}
							BATEU_BL2 = 0;
							BATEU_BL3 = 0;

						}
					}

					
					
					while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse

						encerrarJogo(event, &fechar);

						if(event.type == SDL_KEYDOWN){
						
							if(state[SDL_SCANCODE_UP]){
								GATOUP = 1;

								emma(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
								snow(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
								
								cair(&catJoePosicao.loadRect);
								arrow(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
								felicity(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);

							}
							if(state[SDL_SCANCODE_RIGHT]){


								zangado(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);

							
								

									thor(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);


									soneca_Right(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);

								

									moveSpriteCatRight(&catPosicao.loadRect);

									if(lazyFoo(catJoePosicao.loadRect,caixaBlocoChao.loadRect))
										catJoePosicao.loadRect.y = 432;


									august(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
									
									if(BLOQUEIA_CAT){

									}else
										pularMaisAlto_Right(&catJoePosicao.loadRect);
										//catJoePosicao.loadRect.x += 3;

									
									
									
								


							}if(state[SDL_SCANCODE_LEFT] ){
								
								zangado(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
								
								soneca(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
								

								moveSpriteCatLeft(&catPosicao.loadRect);

								if(BLOQUEIA_CAT){

								}else

									pularMaisAlto_Left(&catJoePosicao.loadRect);

								wonderWoman(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);

							}if(state[SDL_SCANCODE_DOWN]){
									//catJoePosicao.loadRect.y +=3;
									//if(catJoePosicao.loadRect.x >= 449 && catJoePosicao.loadRect.x <= 515)
										//catJoePosicao.loadRect.y = 432;
									
							}
						
						}

					}

					//Limpando tela
					SDL_RenderClear(renderer);
					//background
					SDL_RenderCopy(renderer,backgroundTextura,NULL,NULL);
					
					//Blocos esquerdos
					renderCopySprites(renderer, blocosLeft, blocosPosicaoLeft, 4);
					//Blocos direitos
					renderCopySprites(renderer, blocosRight, blocosPosicaoRight, 4);
					//Chão
					renderCopySprites(renderer, chao, chaoPosicao, 8);
					//obstaculos
					renderCopySprites(renderer, obstaculos, obstaculosPosicao, 4);
	
					renderCopySprites(renderer, &sinalR, &sinalRPos, 1);
					renderCopySprites(renderer, racao, racaoPos, 1);

					//Gato Joe
					SDL_RenderCopy(renderer,catJoe.loadBloco,&catPosicao.loadRect,&catJoePosicao.loadRect);
					//Imprimindo na tela
					SDL_RenderPresent(renderer);
					//Frame Rate
					controlFrameRate(inicioGetTick);
				}

			}//else da IMG

		}//else da Window

	}//else do SDL_Init





	//encerrando tudo
	SDL_DestroyWindow(window);
	window = NULL;
	
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyTexture(backgroundTextura);
	backgroundTextura = NULL;

	SDL_DestroyTexture(sinalR.loadBloco);
	sinalR.loadBloco = NULL;

	SDL_DestroyTexture(racao[0].loadBloco);
	racao[0].loadBloco = NULL;


	for(int i = 0;i < 8; i++){
		SDL_DestroyTexture(chao[i].loadBloco);
		chao[i].loadBloco = NULL;
	}

	for(int i = 0; i < 4; i++){
		SDL_DestroyTexture(blocosLeft[i].loadBloco);
		blocosLeft[i].loadBloco = NULL;
		SDL_DestroyTexture(blocosRight[i].loadBloco);
		blocosRight[i].loadBloco = NULL;
		
	}
	

	for(int i = 0; i < 4; i++){
		SDL_DestroyTexture(obstaculos[i].loadBloco);
		obstaculos[i].loadBloco = NULL;
	}

	

	SDL_DestroyTexture(catJoe.loadBloco);
	
	IMG_Quit();
	SDL_Quit();


	return 0;
}
