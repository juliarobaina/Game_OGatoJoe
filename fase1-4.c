#include "fases.c"
float tempo_de_jogo;
float comecarjogo();
float timer(); 

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

	Bloco inimigo;
	PosicaoBloco dRect_inimigoPos;
	PosicaoBloco sRect_inimigoPos;

	Bloco sinalR;
	PosicaoBloco sinalRPos;
	
	Bloco sinalR2;
	PosicaoBloco sinalRPos2;

	Bloco racao[2];
	PosicaoBloco racaoPos[2];

	//Controlar eventos
	SDL_Event event;
	SDL_Texture *jogarTexto = NULL;
	SDL_Texture *jogarTexto2 = NULL;
	SDL_Texture *jogarTexto3 = NULL;
	SDL_Texture *jogarTexto4 = NULL;

	

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
				catJoePosicao.loadRect.x = 700;		
				catJoePosicao.loadRect.y = 405;
				//GATOMORREU = 1;
				//ALTURA_JANELA - catPosicao.loadRect.h - 28;
				//380-72

				sinalR.loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
				
				sinalRPos.loadRect.w = 60;
				sinalRPos.loadRect.h = 60;
				sinalRPos.loadRect.x = 650;
				sinalRPos.loadRect.y = 356;

				sinalR2.loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
				
				sinalRPos2.loadRect.w = 60;
				sinalRPos2.loadRect.h = 60;
				sinalRPos2.loadRect.x = 40;
				sinalRPos2.loadRect.y = 320;

				racao[0].loadBloco = carregarTextura(renderer,"../img/racao.png");
				
				racaoPos[0].loadRect.w = 30;
				racaoPos[0].loadRect.h = 30;
				racaoPos[0].loadRect.x = 620;
				racaoPos[0].loadRect.y = 392;

				racao[1].loadBloco = carregarTextura(renderer,"../img/racao.png");
				
				racaoPos[1].loadRect.w = 30;
				racaoPos[1].loadRect.h = 30;
				racaoPos[1].loadRect.x = 100;
				racaoPos[1].loadRect.y = 355;

				inimigo.loadBloco = carregarTextura(renderer,"../img/dogOnly.png");

				sRect_inimigoPos.loadRect.w = 100;
				sRect_inimigoPos.loadRect.h = 100;
				sRect_inimigoPos.loadRect.x = 0;//880
				sRect_inimigoPos.loadRect.y = 100;//990

				dRect_inimigoPos.loadRect.w = 100;
				dRect_inimigoPos.loadRect.h = 100;
				dRect_inimigoPos.loadRect.x = 895;
				dRect_inimigoPos.loadRect.y = 492;
				

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

				PosicaoBloco caixaBlocoRacao2;
				caixaBlocoRacao2.loadRect.x = 110;
				caixaBlocoRacao2.loadRect.y = 355;
				caixaBlocoRacao2.loadRect.w = 1;
				caixaBlocoRacao2.loadRect.h = 30;

				PosicaoBloco caixaInimigo;
				caixaInimigo.loadRect.w = 100;
				caixaInimigo.loadRect.h = 100;

				/*CRIANDO AS CAIXAS DE COLISÃO*/
				
				/*
					do lazy foo

				*/
				//Inicando ttf para usar texto
				if(TTF_Init() < 0){
					printf("Error no TTF %s\n",TTF_GetError());
				}
				
				//Carregando fonte
				TTF_Font *font = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",40);
				//cor do mouse quando tem hover
				SDL_Color color = {155,155,255,255};
				//surface com codificacao utf-8 para aceitar acento
				SDL_Surface *jogarSurface = NULL;
				SDL_Surface *jogarSurface2 = NULL;
				SDL_Surface *jogarSurface3 = NULL;
				SDL_Surface *jogarSurface4 = NULL;
				
				

				/*SDL_QueryTexture(jogarTexto,NULL,NULL,&jogarRect.w,&jogarRect.h);
				SDL_FreeSurface(jogarSurface);
				jogarSurface = NULL;*/
				int dogVaiVolta = 0;
				int vivo = 1;
				int str;
				char st[2];
				char st2[3];
				char pokemon[3];
				char* hj;
				SDL_Rect jogarRect;
				SDL_Rect jogarRect2;
				SDL_Rect jogarRect3;
				SDL_Rect jogarRect4;
				int contador = 60;
				int c2 = 1;
				Uint32 start = SDL_GetTicks();
				int min;
				int seg;
				while(fechar != 1){
					
					Uint32 num = SDL_GetTicks() - start;
					
				   //	sprintf(st,"%d",num);
				   	
				    //strncpy(st2, st, 2);
				  	//printf("Tempo: %s |||||||||||||||||| mundo paralelo: %s\n",st,st2);
				  	//if(num < 10000){
				  		/*printf("Tempo: %s |||||||||||||||||| mundo paralelo: %s\n",st,"0");
				  		jogarSurface = TTF_RenderUTF8_Solid(font,"0",color);
						jogarRect.x = 200;
						jogarRect.y = 100;//- (jogarSurface->h/2);
						jogarRect.w = 500;
						jogarRect.h = 500;
						jogarTexto = SDL_CreateTextureFromSurface(renderer,jogarSurface);
						SDL_QueryTexture(jogarTexto,NULL,NULL,&jogarRect.w,&jogarRect.h);
						SDL_FreeSurface(jogarSurface);
						jogarSurface = NULL;*/

				   		//para minutos
				   		
				   		if(contador < 60){
				   			min = 0;
				   			seg = contador;
				   			
				   		}
				   		else{
				   			min = contador / 60;
				   			seg =  contador % 60; //contador - (60 * (min - 1));contador - 60 
				   		}

				   		sprintf(st,"%d",min);
				   		jogarSurface3 = TTF_RenderUTF8_Solid(font,st,color);
						jogarRect3.x = 210;
						jogarRect3.y = 100;//- (jogarSurface->h/2);
						jogarRect3.w = 500;
						jogarRect3.h = 500;
						jogarTexto3 = SDL_CreateTextureFromSurface(renderer,jogarSurface3);
						SDL_QueryTexture(jogarTexto3,NULL,NULL,&jogarRect3.w,&jogarRect3.h);
						SDL_FreeSurface(jogarSurface3);
						jogarSurface3 = NULL;

						jogarSurface4 = TTF_RenderUTF8_Solid(font,":",color);
						jogarRect4.x = 240;
						jogarRect4.y = 100;//- (jogarSurface->h/2);
						jogarRect4.w = 500;
						jogarRect4.h = 500;
						jogarTexto4 = SDL_CreateTextureFromSurface(renderer,jogarSurface4);
						SDL_QueryTexture(jogarTexto4,NULL,NULL,&jogarRect4.w,&jogarRect4.h);
						SDL_FreeSurface(jogarSurface4);
						jogarSurface4 = NULL;

						sprintf(pokemon,"%d",seg);
						printf("pokemon %s\n",pokemon );
						if((c2 % 60) == 0)
							contador--;
						c2++;
						
						jogarSurface2 = TTF_RenderUTF8_Solid(font,pokemon,color);
						jogarRect2.x = 260;//230
						jogarRect2.y = 100;//- (jogarSurface->h/2);
						jogarRect2.w = 500;
						jogarRect2.h = 500;
						jogarTexto2 = SDL_CreateTextureFromSurface(renderer,jogarSurface2);
						SDL_QueryTexture(jogarTexto2,NULL,NULL,&jogarRect2.w,&jogarRect2.h);
						SDL_FreeSurface(jogarSurface2);
						jogarSurface2 = NULL;

						if(seg < 10){
							jogarRect2.x = 280;
							
							jogarSurface = TTF_RenderUTF8_Solid(font,"0",color);
							jogarRect.x = 255;
							jogarRect.y = 100;//- (jogarSurface->h/2);
							jogarRect.w = 500;
							jogarRect.h = 500;
							jogarTexto = SDL_CreateTextureFromSurface(renderer,jogarSurface);
							SDL_QueryTexture(jogarTexto,NULL,NULL,&jogarRect.w,&jogarRect.h);
							SDL_FreeSurface(jogarSurface);
							jogarSurface = NULL;
						}else{
							jogarTexto = NULL;
							
						}
						

						if(contador < 0){
							printf("\n********** GAME OVER ************** \n");
							fechar = 1;
						}
				   // }
				  	//else{
				  		/*strncpy(st2, st, 2);
				  		
				      	printf("Tempo: %s |||||||||||||||||| mundo paralelo: %s\n",st,st2);
				      	jogarSurface = TTF_RenderUTF8_Solid(font,st2,color);
						jogarRect.x = 200;
						jogarRect.y = 100;
						jogarRect.w = 500;
						jogarRect.h = 500;
						jogarTexto = SDL_CreateTextureFromSurface(renderer,jogarSurface);
						SDL_QueryTexture(jogarTexto,NULL,NULL,&jogarRect.w,&jogarRect.h);
						SDL_FreeSurface(jogarSurface);
						jogarSurface = NULL;*/

				  	//}

				      	

				   /* if(num < 100000){
				    	num = 100000;
				    }
				    	//printf("Valor %d\n",num);
				    	SDL_Delay(1000);*/

				   
				  	

						
					
			
					printf("I'm here x= %d y= %d\n",catJoePosicao.loadRect.x,catJoePosicao.loadRect.y);
					//printf("BATEU_BL=%d -- BATEU_BL2=%d -- bateu_bl3=%d -- bateu_bl4=%d\n",BATEU_BL,BATEU_BL2,BATEU_BL3,BATEU_BL4);
					//printf("gatoup = %d\n",GATOUP);
					inicioGetTick = SDL_GetTicks();//tempo em milisegundos
					
					movimentoInimigo(&dRect_inimigoPos.loadRect,&sRect_inimigoPos.loadRect,&dogVaiVolta,vivo);
					caixaInimigo.loadRect.x = dRect_inimigoPos.loadRect.x;
						caixaInimigo.loadRect.y = dRect_inimigoPos.loadRect.y;
					gatoMorreu(&catJoePosicao.loadRect,&dRect_inimigoPos.loadRect, catJoePosicao.loadRect,dRect_inimigoPos.loadRect,&catPosicao.loadRect);
		
					


						
						if(lazyFoo(catJoePosicao.loadRect, caixaBlocoRacao2.loadRect))
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

							neal(&catJoePosicao.loadRect,&caixaBlocoRacao1.loadRect,&caixaBlocoRacao2.loadRect,catJoePosicao.loadRect,caixaBlocoRacao1.loadRect,caixaBlocoRacao2.loadRect,racao,&sinalR,&sinalR2,renderer);
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

									if(GATOMORREU){

									}else{
										GATOUP = 1;

										emma(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
										snow(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
										
										cair(&catJoePosicao.loadRect);
										arrow(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
										felicity(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);

									}
									

								}
								if(state[SDL_SCANCODE_RIGHT]){

									if(GATOMORREU){

									}else{
										zangado(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);

								
									

										thor(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);


										soneca_Right(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);

									

										moveSpriteCatRight(&catPosicao.loadRect);
										

										if(lazyFoo(catJoePosicao.loadRect,caixaBlocoChao.loadRect))
											catJoePosicao.loadRect.y = 432;


										august(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect,racao);
										
										if(BLOQUEIA_CAT){

										}else
											pularMaisAlto_Right(&catJoePosicao.loadRect);
											//catJoePosicao.loadRect.x += 3;

										
										
									}
								
										
									


								}if(state[SDL_SCANCODE_LEFT] ){

									if(GATOMORREU){

									}else{
										zangado(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
									
										soneca(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
										

										moveSpriteCatLeft(&catPosicao.loadRect);
										
										if(BLOQUEIA_CAT){

										}else

											pularMaisAlto_Left(&catJoePosicao.loadRect);

										wonderWoman(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);
									}
									
									

								}
							
							}

						}

					

					//Limpando tela
					SDL_RenderClear(renderer);
					//background
					SDL_RenderCopy(renderer,backgroundTextura,NULL,NULL);
					SDL_RenderCopy(renderer,jogarTexto,NULL,&jogarRect);
					SDL_RenderCopy(renderer,jogarTexto2,NULL,&jogarRect2);
					SDL_RenderCopy(renderer,jogarTexto3,NULL,&jogarRect3);
					SDL_RenderCopy(renderer,jogarTexto4,NULL,&jogarRect4);
					//Blocos esquerdos
					renderCopySprites(renderer, blocosLeft, blocosPosicaoLeft, 4);
					//Blocos direitos
					renderCopySprites(renderer, blocosRight, blocosPosicaoRight, 4);
					//Chão
					renderCopySprites(renderer, chao, chaoPosicao, 8);
					//obstaculos
					renderCopySprites(renderer, obstaculos, obstaculosPosicao, 4);
	
					renderCopySprites(renderer, &sinalR, &sinalRPos, 1);
					renderCopySprites(renderer, &sinalR2, &sinalRPos2, 1);
					renderCopySprites(renderer, racao, racaoPos, 2);

					//Gato Joe
					SDL_RenderCopy(renderer,catJoe.loadBloco,&catPosicao.loadRect,&catJoePosicao.loadRect);

					//Iniigo (Cachorro)
					SDL_RenderCopy(renderer,inimigo.loadBloco,&sRect_inimigoPos.loadRect,&dRect_inimigoPos.loadRect);

					//Imprimindo na tela
					SDL_RenderPresent(renderer);
					//Frame Rate
					controlFrameRate(inicioGetTick);
					
					/*if((SDL_GetTicks() - start) >= 60000){
						printf("60s\n");
						exit(1);
					}*/
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

	SDL_DestroyTexture(sinalR2.loadBloco);
	sinalR2.loadBloco = NULL;

	SDL_DestroyTexture(racao[0].loadBloco);
	racao[0].loadBloco = NULL;
	SDL_DestroyTexture(racao[1].loadBloco);
	racao[1].loadBloco = NULL;

	SDL_DestroyTexture(inimigo.loadBloco);
	inimigo.loadBloco = NULL;
	SDL_DestroyTexture(jogarTexto);
	jogarTexto = NULL;
	SDL_DestroyTexture(jogarTexto2);
	jogarTexto2 = NULL;
	SDL_DestroyTexture(jogarTexto3);
	jogarTexto3 = NULL;
	SDL_DestroyTexture(jogarTexto4);
	jogarTexto4 = NULL;

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
	TTF_Quit();

	return 0;
}


	float comecarjogo(){
		float start_timer;
		tempo_de_jogo = 0;
		start_timer = SDL_GetTicks();
		return start_timer;
	}

	float timer(){

		tempo_de_jogo = SDL_GetTicks() - comecarjogo();
		return tempo_de_jogo;
	}
