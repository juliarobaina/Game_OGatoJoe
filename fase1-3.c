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
	int totalBlocoLeft_Y = 440;//posicao Y do bloco esquerdo + o tamanho do bloco

	Bloco blocosRight[4];
	PosicaoBloco blocosPosicaoRight[4];

	Bloco obstaculos[10];
	PosicaoBloco obstaculosPosicao[10];

	Heroi catJoe;
	PosicaoHeroi catPosicao;
	PosicaoHeroi catJoePosicao;


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
				obstaculosPosicao[1].loadRect.x = 610;
				obstaculosPosicao[1].loadRect.y = 415;
				obstaculos[2].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[2].loadRect.w = 60;
				obstaculosPosicao[2].loadRect.h = 60;
				obstaculosPosicao[2].loadRect.x = obstaculosPosicao[1].loadRect.x + 60;
				obstaculosPosicao[2].loadRect.y = 415;

				obstaculos[3].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[3].loadRect.w = 60;
				obstaculosPosicao[3].loadRect.h = 60;
				obstaculosPosicao[3].loadRect.x = 300;
				obstaculosPosicao[3].loadRect.y = 415;
				obstaculos[4].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[4].loadRect.w = 60;
				obstaculosPosicao[4].loadRect.h = 60;
				obstaculosPosicao[4].loadRect.x = obstaculosPosicao[3].loadRect.x + 60;
				obstaculosPosicao[4].loadRect.y = 415;

				obstaculos[5].loadBloco = carregarTextura(renderer,"../img/flutua1_1.png");
				obstaculosPosicao[5].loadRect.w = 150;
				obstaculosPosicao[5].loadRect.h = 60;
				obstaculosPosicao[5].loadRect.x = blocosPosicaoLeft[3].loadRect.x + 80;
				obstaculosPosicao[5].loadRect.y = 150;

				obstaculos[6].loadBloco = carregarTextura(renderer,"../img/flutua1_1.png");
				obstaculosPosicao[6].loadRect.w = 150;
				obstaculosPosicao[6].loadRect.h = 60;
				obstaculosPosicao[6].loadRect.x = obstaculosPosicao[5].loadRect.x + 200;
				obstaculosPosicao[6].loadRect.y = 150;

				//Gato Joe, herói do jogo
				catJoe.loadBloco = carregarTextura(renderer,"../img/gato.png");
				catPosicao.loadRect.w = 100;
				catPosicao.loadRect.h = 100;
				catPosicao.loadRect.x = 0;
				catPosicao.loadRect.y = 0;


				catJoePosicao.loadRect.w = 100;
				catJoePosicao.loadRect.h = 100;
				catJoePosicao.loadRect.x = 300;		
				catJoePosicao.loadRect.y = 492;
				//ALTURA_JANELA - catPosicao.loadRect.h - 28;
				//380-72
				

				int limiteChao = ALTURA_JANELA - catPosicao.loadRect.h - 28;//492
				//Controla GameLoop
				int fechar = 0;
				//parametros botao
				int x,y;
				//inicio do GetTicks
				Uint32 inicioGetTick;
				
				//controlar objeto flutuante
				int chegouFlutua = 0;

				//bateu cabeça no bloco esquerdo
				int chegouTetoBlocoLeft = 0;

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


				while(fechar != 1){
					
					inicioGetTick = SDL_GetTicks();//tempo em milisegundos

					
					if(GATOUP == 1){
						puloFase3(&catJoePosicao.loadRect, &catPosicao.loadRect,&chegouTetoBlocoLeft);
						//d(&catJoePosicao.loadRect, &catPosicao.loadRect, &chegouTetoBlocoLeft,inicioGetTick);
						//diferente(&catJoePosicao.loadRect, &catPosicao.loadRect,&chegouTetoBlocoLeft,&bigBlocoMovel.loadRect,&chegouFlutua);
						
					}
					
					while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse

						encerrarJogo(event, &fechar);

						if(event.type == SDL_KEYDOWN){
						
							if(state[SDL_SCANCODE_UP]){
								chegouTetoBlocoLeft = 0;
								//diferente(&catJoePosicao.loadRect, &catPosicao.loadRect,&chegouTetoBlocoLeft,&bigBlocoMovel.loadRect,&chegouFlutua);
								puloFase3(&catJoePosicao.loadRect, &catPosicao.loadRect,&chegouTetoBlocoLeft);
								//d(&catJoePosicao.loadRect, &catPosicao.loadRect, &chegouTetoBlocoLeft,inicioGetTick);
							}
							if(state[SDL_SCANCODE_RIGHT] && !(state[SDL_SCANCODE_UP])){
								catJoePosicao.loadRect.x += 2;

								diferenteRight(&catJoePosicao.loadRect, &catPosicao.loadRect);
							}
							
							if(state[SDL_SCANCODE_LEFT] && !(state[SDL_SCANCODE_UP])){
								catJoePosicao.loadRect.x -= 2;

								//diferenteRight(&catJoePosicao.loadRect, &catPosicao.loadRect);
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
					renderCopySprites(renderer, obstaculos, obstaculosPosicao, 7);

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

	for(int i = 0; i < 7; i++){
		SDL_DestroyTexture(obstaculos[i].loadBloco);
		obstaculos[i].loadBloco = NULL;
	}

	

	SDL_DestroyTexture(catJoe.loadBloco);
	
	IMG_Quit();
	SDL_Quit();


	return 0;
}