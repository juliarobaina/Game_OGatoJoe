int comoJogar(){

	SDL_Surface *surfaceFont = NULL;
	SDL_Texture *voltarTexto = NULL;
	SDL_Texture *patadegato = NULL;


	//parametros botao
	int x,y;

	//Musica de fundo
	m2 = Mix_LoadMUS("../music/violao1-2.mp3");
	
	
	//Efeito sonoro botao
	botao = Mix_LoadWAV( "../music/beep.wav" );

				
	//criando textura da imagem de fundo
	if(backgroundTextura != NULL){
		SDL_DestroyTexture(backgroundTextura);
		backgroundTextura = NULL;
		backgroundTextura = carregarTextura(renderer,"../img/comoJogar.png");
	}else
		backgroundTextura = carregarTextura(renderer,"../img/comoJogar.png");

			

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
			SDL_Surface *voltarSurface = TTF_RenderUTF8_Solid(font,"Voltar",color);
			
			voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
			
			SDL_Rect voltarRect;
			
			voltarRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12);
			voltarRect.y = (ALTURA_JANELA) -100;//- (voltar->h/2);
			voltarRect.w = voltarSurface->w;
			voltarRect.h = voltarSurface->h;

			SDL_QueryTexture(voltarTexto,NULL,NULL,&voltarRect.w,&voltarRect.h);


			//pata de gato
			patadegato = carregarTextura(renderer,"../img/patadegato2.png");
			SDL_Rect pataRect;
			pataRect.w = 25;
			pataRect.h = 25;
			pataRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12) - 40;
			pataRect.y = (ALTURA_JANELA + 7) - (voltarSurface->w/2 + voltarSurface->h/2);


			SDL_FreeSurface(voltarSurface);
			voltarSurface = NULL;

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
				
			}else if(notSom != NULL && Mix_PausedMusic()){
			
				SDL_DestroyTexture(notSom);
				notSom = NULL;
				notSom = carregarTextura(renderer,"../img/semsom1.png");
			}else if(!Mix_PausedMusic()){
				
				SDL_DestroyTexture(som);
				som = NULL;
				som = carregarTextura(renderer,"../img/som4.png");
				
			}

			
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

							//Botao Voltar
							if(x >= voltarRect.x && x <= voltarRect.x+voltarRect.w && y >= voltarRect.y && y <= voltarRect.y+voltarRect.h){
									SDL_FreeSurface(voltarSurface);
									SDL_DestroyTexture(voltarTexto);
									voltarSurface = TTF_RenderUTF8_Solid(font,"Voltar",color2);
									voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
									
							}else{
									SDL_FreeSurface(voltarSurface);
									SDL_DestroyTexture(voltarTexto);
									voltarSurface = TTF_RenderUTF8_Solid(font,"Voltar",color);
									voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
							}	
							break;
						case SDL_MOUSEBUTTONUP:
							x = event.motion.x;
							y = event.motion.y;

							if(event.button.button == SDL_BUTTON_LEFT){

								if(x >= voltarRect.x && x <= voltarRect.x+voltarRect.w && y >= voltarRect.y && y <= voltarRect.y+voltarRect.h){
									
									//encerrando tudo
									SDL_DestroyTexture(backgroundTextura);
									backgroundTextura = NULL;
									SDL_DestroyTexture(patadegato);
									patadegato = NULL;
									SDL_DestroyTexture(voltarTexto);
									voltarTexto = NULL;
									if(som == NULL){
										Mix_FreeChunk(botao);
										botao = NULL;
									}else
										Mix_PlayChannel( -1,botao, 0 );
									

									fechar = 1;
									return 0;
								}

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
									   Mix_PlayMusic(m2, -1 );
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
					//voltar
					SDL_RenderCopy(renderer,voltarTexto,NULL,&voltarRect);
					//Som
					SDL_RenderCopy(renderer,som,NULL,&somRect);
					//Not som
					SDL_RenderCopy(renderer,notSom,NULL,&somRect);
					//Imprimindo na tela
					SDL_RenderPresent(renderer);
					//Frame Rate
					controlFrameRate(inicioGetTick);
					
				}
			
	

	//encerrando tudo
	SDL_DestroyTexture(patadegato);
	patadegato = NULL;
	SDL_DestroyTexture(voltarTexto);
	voltarTexto = NULL;

}