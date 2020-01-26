
//#include "gameOver.c"


int fase2(){

	SDL_Texture *sinal = NULL;
	SDL_Texture *caixa = NULL;
	
	Bloco chao[4];
	for(int i = 0;i < 4; i++)
		chao[i].loadBloco = NULL;
	PosicaoBloco chaoPosicao[4];

	Bloco obstaculos[10];
	for(int i = 0;i < 10; i++)
		obstaculos[i].loadBloco = NULL;
	PosicaoBloco obstaculosPosicao[10];

	Heroi catJoe;
	catJoe.loadBloco = NULL;
	PosicaoHeroi catPosicao;
	PosicaoHeroi catJoePosicao;

	Bloco inimigo;
	inimigo.loadBloco = NULL;
	PosicaoBloco dRect_inimigoPos;
	PosicaoBloco sRect_inimigoPos;

	Bloco inimigo2;
	inimigo2.loadBloco = NULL;
	PosicaoBloco dRect_inimigoPos2;
	PosicaoBloco sRect_inimigoPos2;

	Bloco sinalR;
	sinalR.loadBloco = NULL;
	PosicaoBloco sinalRPos;

	Bloco racao;
	racao.loadBloco = NULL;
	PosicaoBloco racaoPos;

	Bloco leite;
	leite.loadBloco = NULL;
	PosicaoBloco leitePos;

	Bloco timerImg;
	timerImg.loadBloco = NULL;
	PosicaoBloco timerImgPos;
	SDL_Texture *zeroTexto = NULL;
	SDL_Texture *minTexto = NULL;
	SDL_Texture *sepaTexto = NULL;
	SDL_Texture *segTexto = NULL;

	SDL_Surface *minSurface = NULL;
	SDL_Surface *sepaSurface = NULL;
	SDL_Surface *segSurface = NULL;
	SDL_Surface *zeroSurface = NULL;

	SDL_Rect minRect;
	SDL_Rect segRect;
	SDL_Rect sepaRect;
	SDL_Rect zeroRect;

	SDL_Texture* fase = NULL;
	SDL_Surface* faseSurface;
	SDL_Rect faseRect;

	Bloco vidaImg;
	vidaImg.loadBloco = NULL;
	PosicaoBloco vidaImgPos;
	SDL_Texture *vidaTextura = NULL;
	SDL_Surface *vidaSurface = NULL;
	SDL_Rect vidaRect;

	Bloco coin[5];
	for(int i = 0;i < 5; i++)
		coin[i].loadBloco = NULL;

	PosicaoBloco dRectCoin[5];
	PosicaoBloco sRectCoin[5];
	Bloco coinImg;
	coinImg.loadBloco = NULL;
	PosicaoBloco coinImgPos;
	SDL_Texture *coinTextura = NULL;
	SDL_Surface *coinSurface = NULL;
	SDL_Rect coinRect;

	Bloco blocosLeftT[2];
	for(int i = 0;i < 2; i++)
		blocosLeftT[i].loadBloco = NULL;
	PosicaoBloco blocosPosicaoLeftT[2];

	SDL_Rect somRect;//posição do ícone de som

	int reboot = 0;
	
	//Musica de fundo
	musica = Mix_LoadMUS("../music/fase1.wav");
	//Tocando música de fundo
	//Mix_PlayMusic(musica,-1);

	//criando textura da imagem de fundo
	if(backgroundTextura != NULL){
		SDL_DestroyTexture(backgroundTextura);
		backgroundTextura = NULL;
		backgroundTextura = carregarTextura(renderer,"../img/BG.png");
	}else
		backgroundTextura = carregarTextura(renderer,"../img/BG.png");
	

	criarChao2(chao,chaoPosicao);
	printf("ATE AQUI\n");
	criarBlocosT(blocosLeftT, blocosPosicaoLeftT);
	
	iniciarObstaculos2(obstaculos, obstaculosPosicao);
	
	//Gato Joe, herói do jogo
	iniciarGato2(&catJoe,&catPosicao,&catJoePosicao);

	iniciarSinais2(&sinalR,&sinalRPos);
	
	iniciarRacao2(&racao,&racaoPos);

	srand(time(NULL));
	int aleatorio = rand() % 2;
	
	iniciarInimigo2_1(&inimigo,&sRect_inimigoPos,&dRect_inimigoPos);
	iniciarInimigo2_2(&inimigo2,&sRect_inimigoPos2,&dRect_inimigoPos2,aleatorio);

	iniciarLeite2(&leite,&leitePos);
	
	iniciarTimer(&timerImg,&timerImgPos);

	iniciarCoins2(coin,dRectCoin,sRectCoin);

	
	somRect.w = 30;
	somRect.h = 25;
	somRect.x = LARGURA_JANELA - 75;
	somRect.y = 14;

	if(som != NULL && !Mix_PausedMusic()){
		SDL_DestroyTexture(som);
		som = NULL;
		som = carregarTextura(renderer,"../img/som4.png");	
		printf("Sem 3\n");
		Mix_PlayMusic(musica,-1);
	}
	else if(notSom != NULL && Mix_PausedMusic()){
		printf("Sem 4\n");
		SDL_DestroyTexture(notSom);
		notSom = NULL;
		notSom = carregarTextura(renderer,"../img/semsom1.png");
	}
	else if(!Mix_PausedMusic()){
		printf("Sem 2\n");
		SDL_DestroyTexture(som);
		som = NULL;
		som = carregarTextura(renderer,"../img/som4.png");
		Mix_PlayMusic(musica,-1);
	}
	
	

	//Controla GameLoop
	int fechar = 0;
	//parametros botao
	int x,y;
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	/*CRIANDO AS CAIXAS DE COLISÃO*/
	PosicaoBloco caixaBloco1;
	caixaBloco1.loadRect.x = 286;
	caixaBloco1.loadRect.y = 440;//385
	caixaBloco1.loadRect.w = 35;
	caixaBloco1.loadRect.h = 150;

	PosicaoBloco caixaBloco2;
	caixaBloco2.loadRect.x = 378;
	caixaBloco2.loadRect.y = 400;//380
	caixaBloco2.loadRect.w = 57;
	caixaBloco2.loadRect.h = 150;

	PosicaoBloco caixaBloco3;
	caixaBloco3.loadRect.x = 500;
	caixaBloco3.loadRect.y = 390;//380
	caixaBloco3.loadRect.w = 35;
	caixaBloco3.loadRect.h = 150;

	PosicaoBloco caixaBloco4;
	caixaBloco4.loadRect.x = 600;
	caixaBloco4.loadRect.y = 400;//380
	caixaBloco4.loadRect.w = 55;
	caixaBloco4.loadRect.h = 50;

	PosicaoBloco caixaBloco5;
	caixaBloco5.loadRect.x = 0;
	caixaBloco5.loadRect.y = 400;//380
	caixaBloco5.loadRect.w = 200;
	caixaBloco5.loadRect.h = 150;

	PosicaoBloco caixaBloco6;
	caixaBloco6.loadRect.x = 732;
	caixaBloco6.loadRect.y = 150;//380
	caixaBloco6.loadRect.w = 40;
	caixaBloco6.loadRect.h = 60;


	PosicaoBloco caixaBlocoRight2;
	caixaBlocoRight2.loadRect.x = 560;//585
	caixaBlocoRight2.loadRect.y = 418;//418
	caixaBlocoRight2.loadRect.w = 140;
	caixaBlocoRight2.loadRect.h = 50;

	PosicaoBloco caixaBlocoMovel2;
	caixaBlocoMovel2.loadRect.x = 800;//464
	caixaBlocoMovel2.loadRect.y = 400;//155
	caixaBlocoMovel2.loadRect.w = 140;
	caixaBlocoMovel2.loadRect.h = 60;

	PosicaoBloco caixaBlocoRacao1;
	caixaBlocoRacao1.loadRect.x = 580;//605
	caixaBlocoRacao1.loadRect.y = 396;
	caixaBlocoRacao1.loadRect.w = 34;//1
	caixaBlocoRacao1.loadRect.h = 30;

	PosicaoBloco caixaInimigo;
	caixaInimigo.loadRect.w = 10;
	caixaInimigo.loadRect.h = 10;

	PosicaoBloco caixaInimigo2;
	caixaInimigo2.loadRect.w = 0;
	caixaInimigo2.loadRect.h = 20;

	PosicaoBloco caixaLeite;
	caixaLeite.loadRect.x = 728;
	caixaLeite.loadRect.y = 80;
	caixaLeite.loadRect.w = 16;
	caixaLeite.loadRect.h = 64;

	PosicaoBloco caixaCoin[5];
	caixaCoin[0].loadRect.x = 534;//tam+10, também tem +14
	caixaCoin[0].loadRect.y = 280;
	caixaCoin[0].loadRect.w = 6;//tam-22(10), também 6
	caixaCoin[0].loadRect.h = 32;

	caixaCoin[1].loadRect.x = 744;
	caixaCoin[1].loadRect.y = 482;
	caixaCoin[1].loadRect.w = 6;
	caixaCoin[1].loadRect.h = 32;

	caixaCoin[2].loadRect.x = 304;
	caixaCoin[2].loadRect.y = 280;
	caixaCoin[2].loadRect.w = 6;
	caixaCoin[2].loadRect.h = 32;

	caixaCoin[3].loadRect.x = 744;
	caixaCoin[3].loadRect.y = 452;
	caixaCoin[3].loadRect.w = 6;
	caixaCoin[3].loadRect.h = 32;

	caixaCoin[4].loadRect.x = 744;
	caixaCoin[4].loadRect.y = 422;
	caixaCoin[4].loadRect.w = 6;
	caixaCoin[4].loadRect.h = 32;

	/*CRIANDO AS CAIXAS DE COLISÃO*/
	
	int dogVaiVolta = 0;
	int dogVaiVolta2 = 0;
	int vivo = 1;

	int venceuFase2 = 0;

	const Uint8* keyState;

	int contador = 60;//contador recebe o total de segundos que eu quero que o timer faça; 60 = 1 min, 180 = 3min
	int c2 = 1;//Auxilia o controle de quando vai haver o decremento de contador. Pra ficar no tempo certo :)
	int min;
	int seg;
	char st[2];
	char st2[3];
	char pokemon[3];

	//Carregando fonte
	TTF_Font *font = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",22);
	TTF_Font *faseFont = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",30);

	//Para exibir em que fase está
	faseSurface = TTF_RenderUTF8_Solid(faseFont,"Fase 2",color);
	faseRect.x = 500 - 40;
	faseRect.y = 6;
	faseRect.w = 40;
	faseRect.h = 40;
	fase = SDL_CreateTextureFromSurface(renderer,faseSurface);
	SDL_QueryTexture(fase,NULL,NULL,&faseRect.w,&faseRect.h);
	SDL_FreeSurface(faseSurface);
	faseSurface = NULL;

	//imagem da  contagem de vidas
	iniciarVidaImg(&vidaImg,&vidaImgPos,&vidaRect);

	//indicação de quantas vidas há
	char life[2];
	
	//imagem da  contagem de moedas
	coinImg.loadBloco = carregarTextura(renderer,"../img/coinPoint.png");
	coinImgPos.loadRect.w = 42;//42
	coinImgPos.loadRect.h = 39;
	coinImgPos.loadRect.x = 200;
	coinImgPos.loadRect.y = 7;

	//indicação de quantas vidas há
	coinRect.x = 248;
	coinRect.y = 6;
	coinRect.w = 40;
	coinRect.h = 40;

	char moeda[2];
	int frameTime = 0;
	//fundoPreto = carregarTextura(renderer,"../img/fundoPreto.png");
	PAUSADO = 1;

	while(fechar != 1){

		printf("Vidas %d\n",VIDASGATO);

		printf("x = %d, y = %d\n",catJoePosicao.loadRect.x,catJoePosicao.loadRect.y);
		printf("VIDASGATO %d\n",VIDASGATO );
		if(lazyFoo(catJoePosicao.loadRect,caixaBloco4.loadRect)){
			printf("DEU LAZYFOO 4\n");
		}if(lazyFoo(catJoePosicao.loadRect,caixaBloco3.loadRect)){
			printf("DEU LAZYFOO 3\n");
		}if(lazyFoo(catJoePosicao.loadRect,caixaBloco2.loadRect)){
			printf("DEU LAZYFOO 2\n");
		}if(lazyFoo(catJoePosicao.loadRect,caixaBloco1.loadRect)){
			printf("DEU LAZYFOO 1\n");
		}if(lazyFoo(catJoePosicao.loadRect,caixaBlocoMovel2.loadRect)){
			printf("DEU LAZYFOO movel\n");
		}if(lazyFoo(catJoePosicao.loadRect,caixaBloco6.loadRect)){
			printf("DEU LAZYFOO 6\n");
			
		}if(lazyFoo(catJoePosicao.loadRect,caixaBlocoRacao1.loadRect)){
			printf("DEU LAZYFOO Racao\n");
			
		}

		inicioGetTick = SDL_GetTicks();//tempo em milisegundos
		if(PAUSADO){
		
			if(VIDASGATO > 0){

				sprintf(life,"%d",VIDASGATO);
				vidaSurface = TTF_RenderUTF8_Solid(faseFont,life,color);
				vidaTextura = SDL_CreateTextureFromSurface(renderer,vidaSurface);
				SDL_QueryTexture(vidaTextura,NULL,NULL,&vidaRect.w,&vidaRect.h);
				SDL_FreeSurface(vidaSurface);
				vidaSurface = NULL;
				sprintf(moeda,"%d",PONTUACAO);
				coinSurface = TTF_RenderUTF8_Solid(faseFont,moeda,color);
				coinTextura = SDL_CreateTextureFromSurface(renderer,coinSurface);
				SDL_QueryTexture(coinTextura,NULL,NULL,&coinRect.w,&coinRect.h);
				SDL_FreeSurface(coinSurface);
				coinSurface = NULL;




				/* INÍCIO DO CONTADOR */
				if(contador < 60){
					min = 0;
					seg = contador;
					
				}
				else{
					min = contador / 60;
					seg = contador % 60;
				}

				sprintf(st,"%d",min);
				minSurface = TTF_RenderUTF8_Solid(font,st,color);
				minRect.x = 830;
				minRect.y = 10;
				minRect.w = 40;
				minRect.h = 40;
				minTexto = SDL_CreateTextureFromSurface(renderer,minSurface);
				SDL_QueryTexture(minTexto,NULL,NULL,&minRect.w,&minRect.h);
				SDL_FreeSurface(minSurface);
				minSurface = NULL;

				sepaSurface = TTF_RenderUTF8_Solid(font,":",color);
				sepaRect.x = 850;
				sepaRect.y = 10;
				sepaRect.w = 40;
				sepaRect.h = 40;
				sepaTexto = SDL_CreateTextureFromSurface(renderer,sepaSurface);
				SDL_QueryTexture(sepaTexto,NULL,NULL,&sepaRect.w,&sepaRect.h);
				SDL_FreeSurface(sepaSurface);
				sepaSurface = NULL;

				sprintf(pokemon,"%d",seg);

				if((c2 % 60) == 0)
					contador--;
				c2++;

				segSurface = TTF_RenderUTF8_Solid(font,pokemon,color);
				segRect.x = 860;//230
				segRect.y = 10;//- (jogarSurface->h/2);
				segRect.w = 40;
				segRect.h = 40;
				segTexto = SDL_CreateTextureFromSurface(renderer,segSurface);
				SDL_QueryTexture(segTexto,NULL,NULL,&segRect.w,&segRect.h);
				SDL_FreeSurface(segSurface);
				segSurface = NULL;

				if(seg < 10){
					//pra inserir o '0' quando os segundos for menor que 10
					segRect.x = 875;
					
					zeroSurface = TTF_RenderUTF8_Solid(font,"0",color);
					zeroRect.x = 860;
					zeroRect.y = 10;//- (jogarSurface->h/2);
					zeroRect.w = 40;
					zeroRect.h = 40;
					zeroTexto = SDL_CreateTextureFromSurface(renderer,zeroSurface);
					SDL_QueryTexture(zeroTexto,NULL,NULL,&zeroRect.w,&zeroRect.h);
					SDL_FreeSurface(zeroSurface);
					zeroSurface = NULL;
				}else{
					//remove o '0' da tela
					zeroTexto = NULL;
					
				}

				if(contador < 0){
					printf("\n********** GAME OVER ************** \n");
					//catPosicao.loadRect.y = 400;
					//catPosicao.loadRect.x = 900;
					Mix_FreeMusic(musica);
					musica = NULL;
					destruirFase2(&catJoe,&sinalR,
					&racao,&inimigo,&leite,chao,blocosLeftT,obstaculos,
					&timerImg,minTexto,segTexto,sepaTexto,zeroTexto,fase,
					&vidaImg,vidaTextura,coin,&coinImg,coinTextura,&inimigo2);
					return 6;
					/*
						PAUSADO = 1;
					*/
				}

				/* FIM DO CONTADOR */
				
				frameTime++;
				if(FPS / frameTime == 6){
					frameTime = 0;
					for(int i = 0;i < 5; i++){
					
						sRectCoin[i].loadRect.x += 32;
						if(sRectCoin[i].loadRect.x > 164)
							sRectCoin[i].loadRect.x = 0;
					}
				}

				pegarMoeda2(caixaCoin,coin,catJoePosicao.loadRect,caixaCoin,5);
				
				
				
				movimentoInimigo3(&dRect_inimigoPos.loadRect,&sRect_inimigoPos.loadRect,&dogVaiVolta,vivo);
				movimentoInimigo2(&dRect_inimigoPos2.loadRect,&sRect_inimigoPos2.loadRect,&dogVaiVolta2,vivo,aleatorio);
				
				caixaInimigo.loadRect.x = dRect_inimigoPos.loadRect.x;
				caixaInimigo.loadRect.y = dRect_inimigoPos.loadRect.y;

				caixaInimigo2.loadRect.x = dRect_inimigoPos2.loadRect.x;
				caixaInimigo2.loadRect.y = dRect_inimigoPos2.loadRect.y;

				gatoMorreu2(&catJoePosicao.loadRect,&dRect_inimigoPos.loadRect, catJoePosicao.loadRect,dRect_inimigoPos.loadRect,
					&catPosicao.loadRect,obstaculosPosicao,&caixaBlocoMovel2,&sinalR,&racao,&caixaBlocoRacao1,caixaCoin,
					coin,dRect_inimigoPos2.loadRect);


				naoPassaDoLimiteDaJanela2(&catJoePosicao.loadRect);
				
				if(GATOUP){
					
					cair2(&catJoePosicao.loadRect);
					
					lua(&catJoePosicao.loadRect);
					
					neal2(&catJoePosicao.loadRect,&caixaBlocoRacao1.loadRect,catJoePosicao.loadRect,caixaBlocoRacao1.loadRect,
						&racao,&sinalR,renderer);
					flamenco(&catJoePosicao.loadRect);
					espanhol(&catJoePosicao.loadRect);
					rasgueado(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
					cavaquinho(&catJoePosicao.loadRect);
					palheta(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect,
									caixaBlocoMovel2.loadRect,caixaBloco6.loadRect);
					escaleta(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
					bumbo(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco6.loadRect);

					
				}else{
					
					henry2(&catJoePosicao.loadRect);

					neal2(&catJoePosicao.loadRect,&caixaBlocoRacao1.loadRect,catJoePosicao.loadRect,caixaBlocoRacao1.loadRect,
						&racao,&sinalR,renderer);
					venceuFase2 = venceu(&catJoePosicao.loadRect,&caixaLeite.loadRect,catJoePosicao.loadRect,caixaLeite.loadRect,&leite);
					if(venceuFase2 == 6){//venceu = 6 é ganhou o jogo
						Mix_FreeMusic(musica);
						musica = NULL;
						destruirFase2(&catJoe,&sinalR,
							&racao,&inimigo,&leite,chao,blocosLeftT,obstaculos,
							&timerImg,minTexto,segTexto,sepaTexto,zeroTexto,fase,
							&vidaImg,vidaTextura,coin,&coinImg,coinTextura,&inimigo2);
						return 7;
					}
						
				}
				if(PODEDESCER){
					printf("Valor do bloco M %d\n",caixaBlocoMovel2.loadRect.y);
					if(lazyFoo(catJoePosicao.loadRect,caixaBlocoMovel2.loadRect) && catJoePosicao.loadRect.y < caixaBlocoMovel2.loadRect.y
						&& catJoePosicao.loadRect.x > 760){
						
						if(catJoePosicao.loadRect.y > 60){
							if(catJoePosicao.loadRect.y == 336){
								BLOQUEIA_CAT = 1;
								BATEU_BL3 = 1;
							}
							
							if(BLOQUEIA_CAT){
								obstaculosPosicao[4].loadRect.y -= 3;
								caixaBlocoMovel2.loadRect.y -= 3;
								catJoePosicao.loadRect.y -= 3;
							}
							
						}else{
							BLOQUEIA_CAT = 0;
						}
						
						
					}
				}

				
				while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse
					
					//encerrarJogo(event, &fechar);
					if(event.type == SDL_QUIT){
						return 1;
					}
					if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
						return  1;
					}
					

					if(event.type == SDL_KEYDOWN){
					
						if(state[SDL_SCANCODE_UP]){

							if(GATOMORREU || BLOQUEIA_CAT){

							}else{
								GATOUP = 1;

								
								lua(&catJoePosicao.loadRect);
							
								flamenco(&catJoePosicao.loadRect);
								espanhol(&catJoePosicao.loadRect);
								rasgueado(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
								cavaquinho(&catJoePosicao.loadRect);
								palheta(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect,
									caixaBlocoMovel2.loadRect,caixaBloco6.loadRect);
								escaleta(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
								bumbo(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco6.loadRect);

							}
							

						}
						if(state[SDL_SCANCODE_RIGHT]){

							if(GATOMORREU){

							}else{
							
								moveSpriteCatRight(&catPosicao.loadRect);											
								colisaoBlocoBaixoR(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco1.loadRect);
								colisaoBlocoBaixoR(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco3.loadRect);
								//AQUI
								colisaoBlocoBaixo3R(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco2.loadRect);
								colisaoBlocoBaixo3R(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco4.loadRect);
								colisaoBlocoBaixo4R(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
								colisaoBlocoBaixo5R(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco6.loadRect);
								
								
								if(BLOQUEIA_CAT){

								}else
									pularMaisAlto_Right2(&catJoePosicao.loadRect);
						
									
							}
						
								
							


						}if(state[SDL_SCANCODE_LEFT] ){

							if(GATOMORREU){

							}else{
								

								moveSpriteCatLeft(&catPosicao.loadRect);
								colisaoBlocoBaixo2E(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco5.loadRect);
								colisaoBlocoBaixo3E(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco2.loadRect);
								
								
								colisaoBlocoBaixoE(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco1.loadRect);
								colisaoBlocoBaixoE(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco3.loadRect);
								colisaoBlocoBaixo3E(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco4.loadRect);
								colisaoBlocoBaixo4E(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
								colisaoBlocoBaixo5E(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBloco6.loadRect);

								if(BLOQUEIA_CAT){

								}else

									pularMaisAlto_Left2(&catJoePosicao.loadRect);

								
							}
							
							

						}if(state[SDL_SCANCODE_P]){//PARA PAUSAR O JOGO
							
							pausado();
							
							
							
							if(PAUSADO == 2){
								//Coloca tudo de destruir dessa fase AQUI
								//encerrando tudo
								Mix_FreeMusic(musica);
								musica =  NULL;
								destruirFase2(&catJoe,&sinalR,
								&racao,&inimigo,&leite,chao,blocosLeftT,obstaculos,
								&timerImg,minTexto,segTexto,sepaTexto,zeroTexto,fase,
								&vidaImg,vidaTextura,coin,&coinImg,coinTextura,&inimigo2);
								
								return 1;// pra fechar o menu, terminar o programa

							}else if(PAUSADO == 0){//usuário quer voltar para o menu
								//encerrando tudo
								Mix_FreeMusic(musica);
								musica =  NULL;
								destruirFase2(&catJoe,&sinalR,
								&racao,&inimigo,&leite,chao,blocosLeftT,obstaculos,
								&timerImg,minTexto,segTexto,sepaTexto,zeroTexto,fase,
								&vidaImg,vidaTextura,coin,&coinImg,coinTextura,&inimigo2);
							
								return 0;//faz voltar pro menu
							}
							
						}
					}

					if(event.type == SDL_MOUSEBUTTONUP){

						x = event.motion.x;
						y = event.motion.y;
						if(event.button.button == SDL_BUTTON_LEFT){
							if(x >= somRect.x && x <= somRect.x+somRect.w && y >= somRect.y && y <= somRect.y+somRect.h){
								//Trocar ícone do som
								if(som != NULL){
									SDL_DestroyTexture(som);
									som = NULL;
									notSom = carregarTextura(renderer,"../img/semsom1.png");
									
									Mix_FreeChunk(botao);
									botao = NULL;
								}else{
									som = carregarTextura(renderer,"../img/som4.png");
									SDL_DestroyTexture(notSom);
									notSom = NULL;	

									botao = Mix_LoadWAV("../music/beep.wav");
								}
															
								//It's Work
								if( Mix_PlayingMusic() == 0 ){
								   //Play the music
								   Mix_PlayMusic(musica, -1 );
								}
								//If music is being played
								else{
								   //If the music is paused
								   if( Mix_PausedMusic() == 1 ){
								      //Resume the music
								      Mix_ResumeMusic();
								   }
								   //If the music is playing
								   else{
								      //Pause the music
								      Mix_PauseMusic();
								   }
								}
							}
						}
					}
				}

			

				//Limpando tela
				SDL_RenderClear(renderer);
				//background
				SDL_RenderCopy(renderer,backgroundTextura,NULL,NULL);
			
				//Chão
				renderCopySprites(renderer, chao, chaoPosicao, 4);
				//obstaculos
				renderCopySprites(renderer, obstaculos, obstaculosPosicao, 6);
				
				//Sinal que muda de vermelho para verde
				if(sinalR.loadBloco != NULL)
					renderCopySprites(renderer, &sinalR, &sinalRPos, 1);
				
				//Racao para pegadinhas e atalhos
				renderCopySprites(renderer, &racao, &racaoPos, 1);
				renderCopySprites(renderer, blocosLeftT, blocosPosicaoLeftT, 2);

				//Objetivo final, pegar o Leite
				renderCopySprites(renderer, &leite, &leitePos, 1);

				//Gato Joe
				SDL_RenderCopy(renderer,catJoe.loadBloco,&catPosicao.loadRect,&catJoePosicao.loadRect);

				//Timer Imagem
				renderCopySprites(renderer, &timerImg, &timerImgPos, 1);			
				SDL_RenderCopy(renderer,minTexto,NULL,&minRect);
				SDL_RenderCopy(renderer,segTexto,NULL,&segRect);
				SDL_RenderCopy(renderer,sepaTexto,NULL,&sepaRect);
				SDL_RenderCopy(renderer,zeroTexto,NULL,&zeroRect);

				//Indicar a fase
				SDL_RenderCopy(renderer,fase,NULL,&faseRect);
				
				//Vida img do gato
				renderCopySprites(renderer, &vidaImg, &vidaImgPos, 1);
				//vida qtd
				SDL_RenderCopy(renderer,vidaTextura,NULL,&vidaRect);
				
				//moeda
				renderMoeda(coin,sRectCoin,dRectCoin);
				renderCopySprites(renderer, &coinImg, &coinImgPos, 1);
				SDL_RenderCopy(renderer,coinTextura,NULL,&coinRect);

				//Inimigo (Cachorro)
				SDL_RenderCopy(renderer,inimigo.loadBloco,&sRect_inimigoPos.loadRect,&dRect_inimigoPos.loadRect);
				SDL_RenderCopy(renderer,inimigo2.loadBloco,&sRect_inimigoPos2.loadRect,&dRect_inimigoPos2.loadRect);


				//Som
				SDL_RenderCopy(renderer,som,NULL,&somRect);
				//Not som
				SDL_RenderCopy(renderer,notSom,NULL,&somRect);						
				
				

				//Imprimindo na tela
				SDL_RenderPresent(renderer);

				//Frame Rate
				controlFrameRate(inicioGetTick);
				
			}else{//Else do vidasgato
				printf("*********** GAME OVER *********** do sem vidas\n");
				Mix_FreeMusic(musica);
				musica = NULL;
				
				destruirFase2(&catJoe,&sinalR,
					&racao,&inimigo,&leite,chao,blocosLeftT,obstaculos,
					&timerImg,minTexto,segTexto,sepaTexto,zeroTexto,fase,
					&vidaImg,vidaTextura,coin,&coinImg,coinTextura,&inimigo2);
				return 6;

				/*
					PAUSADO = 1;
				*/
			}
		}//do pausado
	
	}

			



	//encerrando tudo

	destruirFase2(&catJoe,&sinalR,
	&racao,&inimigo,&leite,chao,blocosLeftT,obstaculos,
	&timerImg,minTexto,segTexto,sepaTexto,zeroTexto,fase,
	&vidaImg,vidaTextura,coin,&coinImg,coinTextura,&inimigo2);
	PONTUACAO = 0;

}