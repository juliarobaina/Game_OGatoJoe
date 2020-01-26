int historia(){
	SDL_Surface *surfaceFont = NULL;
	SDL_Texture *nextTexto = NULL;
	SDL_Texture *patadegato = NULL;


	//parametros botao
	int x,y;

	//Musica de fundo
	m4Historia = Mix_LoadMUS("../music/procura2.wav");
	//Mix_PauseMusic ();
	//Mix_HaltMusic();

	//musica = Mix_LoadMUS("../music/openM.mp3");
	//Mix_PlayMusic(musica,-1);
	
	//Efeito sonoro botao
	botao = Mix_LoadWAV( "../music/beep.wav" );

				
	//criando textura da imagem de fundo
	if(backgroundTextura != NULL){
		SDL_DestroyTexture(backgroundTextura);
		backgroundTextura = NULL;
		backgroundTextura = carregarTextura(renderer,"../img/historia.png");
	}else
		backgroundTextura = carregarTextura(renderer,"../img/historia.png");

			

	int fechar = 0;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	const Uint8 *state = SDL_GetKeyboardState(NULL);


			//Carregando fonte
			//TTF_Font *font = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",40);
			//Cor da fonte
			SDL_Color color = {0xFF,0xA5,0x00,0xFF};//aceita hexadecimal desse modo ou rgba  ex{155,155,255,255}
			//cor do mouse quando tem hover
			SDL_Color color2 = {155,155,255,255};
			
			//Códigos para o botão jogar
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *nextSurface = TTF_RenderUTF8_Solid(font,"Avançar",color);
			
			nextTexto = SDL_CreateTextureFromSurface(renderer,nextSurface);
			
			SDL_Rect nextRect;
			
			nextRect.x = (LARGURA_JANELA) - (nextSurface->w) - 20;
			nextRect.y = (ALTURA_JANELA) - 120;//- (next->h/2);
			nextRect.w = nextSurface->w;
			nextRect.h = nextSurface->h;

			SDL_QueryTexture(nextTexto,NULL,NULL,&nextRect.w,&nextRect.h);


			//pata de gato
			patadegato = carregarTextura(renderer,"../img/patadegato2.png");
			SDL_Rect pataRect;
			pataRect.w = 25;
			pataRect.h = 25;
			pataRect.x = (LARGURA_JANELA) - (nextSurface->w) - 56;
			pataRect.y = (ALTURA_JANELA + 7) - (nextSurface->w/2 + nextSurface->h/2);


			SDL_FreeSurface(nextSurface);
			nextSurface = NULL;

			//Para música
			//som
			//som = carregarTextura(renderer,"../img/som4.png");
			SDL_Rect somRect;
			somRect.w = 30;
			somRect.h = 25;
			somRect.x = LARGURA_JANELA - 100;
			somRect.y = ALTURA_JANELA/12;
			if(som != NULL && !Mix_PausedMusic()){
				SDL_DestroyTexture(som);
				som = NULL;
				som = carregarTextura(renderer,"../img/som4.png");
				Mix_PlayMusic(m4Historia,-1);	
				printf("Sem 3\n");
			}else if(notSom != NULL && Mix_PausedMusic()){
				printf("Sem 4\n");
				SDL_DestroyTexture(notSom);
				notSom = NULL;
				notSom = carregarTextura(renderer,"../img/semsom1.png");
				Mix_HaltMusic();
			
			}else if(!Mix_PausedMusic()){
				printf("Sem 2\n");
				SDL_DestroyTexture(som);
				som = NULL;
				som = carregarTextura(renderer,"../img/som4.png");
				Mix_PlayMusic(m4Historia,-1);
			}
			//Mix_PlayMusic(m4Historia,-1);
			//Tocando música de fundo
			
			
				while(fechar != 1){
					
					inicioGetTick = SDL_GetTicks();//tempo em milisegundos

					while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse

						if(event.type == SDL_QUIT){
							fechar = 1;
							
							return 1;
						}
						if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
							fechar = 1;
							
							return  1;
						}
					

						switch(event.type){
						case SDL_MOUSEMOTION:
							x = event.motion.x;
							y = event.motion.y;

							//Botao next
							if(x >= nextRect.x && x <= nextRect.x+nextRect.w && y >= nextRect.y && y <= nextRect.y+nextRect.h){
									SDL_FreeSurface(nextSurface);
									SDL_DestroyTexture(nextTexto);
									nextSurface = TTF_RenderUTF8_Solid(font,"Avançar",color2);
									nextTexto = SDL_CreateTextureFromSurface(renderer,nextSurface);
									
							}else{
									SDL_FreeSurface(nextSurface);
									SDL_DestroyTexture(nextTexto);
									nextSurface = TTF_RenderUTF8_Solid(font,"Avançar",color);
									nextTexto = SDL_CreateTextureFromSurface(renderer,nextSurface);
							}	
							break;
						case SDL_MOUSEBUTTONUP:
							x = event.motion.x;
							y = event.motion.y;

							if(event.button.button == SDL_BUTTON_LEFT){

								if(x >= nextRect.x && x <= nextRect.x+nextRect.w && y >= nextRect.y && y <= nextRect.y+nextRect.h){
									printf("Clicou Avançar\n");
									//Mix_PlayChannel( -1,botao, 0 );
									//encerrando tudo
									SDL_DestroyTexture(backgroundTextura);
									backgroundTextura = NULL;
									SDL_DestroyTexture(patadegato);
									patadegato = NULL;
									SDL_DestroyTexture(nextTexto);
									nextTexto = NULL;
									if(som == NULL){
										Mix_FreeChunk(botao);
										botao = NULL;
									}else
										Mix_PlayChannel( -1,botao, 0 );
									
									Mix_FreeMusic(m4Historia);
									m4Historia = NULL;
									fechar = 1;
									return 2;
								}

								if(x >= somRect.x && x <= somRect.x+somRect.w && y >= somRect.y && y <= somRect.y+somRect.h){
									printf("X%d\n",x);
									printf("X%d\n",y);
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
									   Mix_PlayMusic(m4Historia, -1 );
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
						break;

						}
					}

					//Limpando tela
					SDL_RenderClear(renderer);
					//background
					SDL_RenderCopy(renderer,backgroundTextura,NULL,NULL);
					//pata de gato
					SDL_RenderCopy(renderer,patadegato,NULL,&pataRect);
					//next
					SDL_RenderCopy(renderer,nextTexto,NULL,&nextRect);
					//Som
					//SDL_RenderCopy(renderer,som,NULL,&somRect);
					//Not som
					//SDL_RenderCopy(renderer,notSom,NULL,&somRect);
					//Imprimindo na tela
					SDL_RenderPresent(renderer);
					//Frame Rate
					controlFrameRate(inicioGetTick);
					
				}
			
	

	//encerrando tudo
	SDL_DestroyTexture(patadegato);
	patadegato = NULL;
	SDL_DestroyTexture(nextTexto);
	nextTexto = NULL;

}