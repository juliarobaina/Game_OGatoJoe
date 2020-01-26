#include "rr.c"
#include <string.h>
int venceuTela(/*int* reboot*/){

	SDL_Surface *surfaceFont = NULL;
	
	SDL_Texture *voltarTexto = NULL;
	SDL_Texture *jogarnovamenteTexto = NULL;
	SDL_Texture *patadegato = NULL;

	SDL_Texture *totalTexto = NULL;
	SDL_Texture *pontosTexto = NULL;
	SDL_Surface *totalSurface = NULL;
	SDL_Surface *pontosSurface = NULL;
	SDL_Rect totalRect;
	SDL_Rect pontosRect;

	SDL_Texture *inputTexto = NULL;


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
		backgroundTextura = carregarTextura(renderer,"../img/venceu.png");
	}else
		backgroundTextura = carregarTextura(renderer,"../img/venceu.png");

				
	int fechar = 0;
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	const Uint8 *state = SDL_GetKeyboardState(NULL);

				//Inicando ttf para usar texto
			/*if(TTF_Init() < 0){
				printf("Error no TTF %s\n",TTF_GetError());
			}*/

			//Carregando fonte
			//TTF_Font *font = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",40);
			//Cor da fonte
			SDL_Color color = {0xFF,0xA5,0x00,0xFF};//aceita hexadecimal desse modo ou rgba  ex{155,155,255,255}
			//cor do mouse quando tem hover
			SDL_Color color2 = {155,155,255,255};
			
			//Códigos para o botão voltar
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *voltarSurface = TTF_RenderUTF8_Solid(font,"Menu",color);
			
			voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
			
			SDL_Rect voltarRect;
			
			voltarRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12);
			voltarRect.y = (ALTURA_JANELA/2) + (voltarSurface->h/2) + voltarSurface->w + 60;//- (voltar->h/2);
			voltarRect.w = voltarSurface->w;
			voltarRect.h = voltarSurface->h;

			SDL_QueryTexture(voltarTexto,NULL,NULL,&voltarRect.w,&voltarRect.h);

			 // código para o botão jogar novamente
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *jogarnovamenteSurface = TTF_RenderUTF8_Solid(font,"Jogar Novamente",color);
			
			jogarnovamenteTexto = SDL_CreateTextureFromSurface(renderer,jogarnovamenteSurface);
			
			SDL_Rect jogarnovamenteRect;
			
			jogarnovamenteRect.x = (LARGURA_JANELA/2) - (jogarnovamenteSurface->w/2) - 70;
			jogarnovamenteRect.y = (ALTURA_JANELA/2) + (voltarSurface->h/2) + voltarSurface->w + 60;//- (voltar->h/2);
			jogarnovamenteRect.w = jogarnovamenteSurface->w - 60;
			jogarnovamenteRect.h = jogarnovamenteSurface->h;

			SDL_QueryTexture(jogarnovamenteTexto,NULL,NULL,&jogarnovamenteRect.w,&jogarnovamenteRect.h);


			//pata de gato
			patadegato = carregarTextura(renderer,"../img/patadegato2.png");
			SDL_Rect pataRect;
			pataRect.w = 25;
			pataRect.h = 25;
			pataRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12) - 40;
			pataRect.y = (ALTURA_JANELA - 16) - (voltarSurface->w/2 + voltarSurface->h/2);


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
				Mix_PlayMusic(m2,-1);	
				printf("Sem 3\n");
			}else if(notSom != NULL && Mix_PausedMusic()){
				printf("Sem 4\n");
				SDL_DestroyTexture(notSom);
				notSom = NULL;
				notSom = carregarTextura(renderer,"../img/semsom1.png");
			}else if(!Mix_PausedMusic()){
				printf("Sem 2\n");
				SDL_DestroyTexture(som);
				som = NULL;
				som = carregarTextura(renderer,"../img/som4.png");
				Mix_PlayMusic(m2,-1);
			}

			TTF_Font *font2 = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",25);
			totalSurface = TTF_RenderUTF8_Solid(font2,"Total de Moedas: ",color);
			totalTexto = SDL_CreateTextureFromSurface(renderer,totalSurface);
			
			
			totalRect.x = 72;
			totalRect.y = ALTURA_JANELA/12;//- (jogarSurface->h/2);
			totalRect.w = totalSurface->w;
			totalRect.h = totalSurface->h;

			SDL_QueryTexture(totalTexto,NULL,NULL,&totalRect.w,&totalRect.h);
			SDL_FreeSurface(totalSurface);
			totalSurface = NULL;

			char moeda[2];
			sprintf(moeda,"%d",PONTUACAO);
			pontosSurface = TTF_RenderUTF8_Solid(font2,moeda,color);
			pontosTexto = SDL_CreateTextureFromSurface(renderer,pontosSurface);
			
			
			pontosRect.x = 218 + 72;//totalSurface + totalRect.x
			pontosRect.y = ALTURA_JANELA/12;//- (jogarSurface->h/2);
			pontosRect.w = pontosSurface->w;
			pontosRect.h = pontosSurface->h;
			SDL_QueryTexture(pontosTexto,NULL,NULL,&pontosRect.w,&pontosRect.h);
			SDL_FreeSurface(pontosSurface);
			pontosSurface = NULL;

			TTF_Font *font4 = TTF_OpenFont("../fonts/Roboto_Mono/RobotoMono-Bold.ttf",17);
			SDL_Surface *inputSurface = TTF_RenderUTF8_Solid(font,"Digite seu nome",color);
	
			inputTexto = SDL_CreateTextureFromSurface(renderer,inputSurface);
			
			SDL_Rect inputRect;
			
			inputRect.x = (LARGURA_JANELA/2) - (inputSurface->w/2);
			inputRect.y = (ALTURA_JANELA/2) -100;//- (jogarSurface->h/2);
			inputRect.w = inputSurface->w;
			inputRect.h = inputSurface->h;

			SDL_QueryTexture(inputTexto,NULL,NULL,&inputRect.w,&inputRect.h);

			SDL_FreeSurface(inputSurface);
			inputSurface = NULL;
			


			//Tocando música de fundo
			//Mix_PlayMusic(musica,-1);

				char nomeMAX[6] = "     ";
				Jogador novoJogador;
				
				int cont = 0;
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

							//Para receber o nome do Jogador
							if (cont < 5){
								if(event.type == SDL_KEYDOWN){
									//verificar a tecla que foi pressionada
								 	switch(event.key.keysym.sym){
										case SDLK_a: 
											nomeMAX[cont] = 'A';
											cont++;
										break;
										case SDLK_b: 
											nomeMAX[cont] = 'B';
											cont++;
										break;
										 case SDLK_c:
						                 
					                        nomeMAX[cont]= 'C';
					                        cont++;
						                    
						                    break;
						                case SDLK_d:
						                    
						                        nomeMAX[cont]= 'D';
						                        cont++;
						                    
						                    break;
						                case SDLK_e:
						                    
						                        nomeMAX[cont]='E';
						                        cont++;
						                    
						                    break;
						                case SDLK_f:
						                    
						                        nomeMAX[cont]='F';
						                        cont++;
						                    
						                    break;
						                case SDLK_g:
						                    
						                        nomeMAX[cont]='G';
						                        cont++;
						                    
						                    break;
						                case SDLK_h:
						                    
						                        nomeMAX[cont]='H';
						                        cont++;
						                    
						                    break;
						                case SDLK_i:
						                    
						                        nomeMAX[cont]='I';
						                        cont++;
						                    
						                    break;
						                case SDLK_j:
						                    
						                        nomeMAX[cont]='J';
						                        cont++;
						                    
						                    break;
						                case SDLK_k:
						                    
						                        nomeMAX[cont]='K';
						                        cont++;
						                    
						                    break;
						                case SDLK_l:
						                    
						                        nomeMAX[cont]='L';
						                        cont++;
						                    
						                    break;
						                case SDLK_m:
						                    
						                        nomeMAX[cont]='M';
						                        cont++;
						                    
						                    break;
						                case SDLK_n:
						                    
						                        nomeMAX[cont]='N';
						                        cont++;
						                    
						                    break;
						                case SDLK_o:
						                    
						                        nomeMAX[cont]='O';
						                        //sprintf(nomeMAX,"%s%c",nomeMAX,'o');
						                        cont++;
						                        //printf("%s\n",nomeMAX);
						                    
						                    break;
						                case SDLK_p:
						                    
						                        nomeMAX[cont]='P';
						                        cont++;
						                    
						                    break;
						                case SDLK_q:
						                    
						                        nomeMAX[cont]='Q';
						                        cont++;
						                    
						                    break;
						                case SDLK_r:
						                    
						                        nomeMAX[cont]='R';
						                        cont++;
						                    
						                    break;
						                case SDLK_s:
						                    
						                        nomeMAX[cont]='S';
						                        cont++;
						                    
						                    break;
						                case SDLK_t:
						                    
						                        nomeMAX[cont]='T';
						                        cont++;
						                    
						                    break;
						                case SDLK_u:
						                    
						                        nomeMAX[cont]='U';
						                        cont++;
						                    
						                    break;
						                case SDLK_v:
						                    
						                        nomeMAX[cont]='V';
						                        cont++;
						                    
						                    break;
						                case SDLK_w:
						                    
						                        nomeMAX[cont]='W';
						                        cont++;
						                    
						                    break;
						                case SDLK_x:
						                    
						                        nomeMAX[cont]='X';
						                        cont++;
						                    
						                    break;
						                case SDLK_y:
						                    
						                        nomeMAX[cont]='Y';
						                        cont++;
						                    
						                    break;
						                case SDLK_z:
						                    
						                        nomeMAX[cont]='Z';
						                        cont++;
						                    
						                    break;
						                case SDLK_0:
						                    
						                        nomeMAX[cont]='0';
						                        cont++;
						                    
						                    break;
						                case SDLK_1:
						                    
						                        nomeMAX[cont]='1';
						                        cont++;
						                    
						                    break;
						                case SDLK_2:
						                    
						                        nomeMAX[cont]='2';
						                        cont++;
						                    
						                    break;
						                case SDLK_3:
						                    
						                        nomeMAX[cont]='3';
						                        cont++;
						                    
						                    break;
						                case SDLK_4:
						                    
						                        nomeMAX[cont]='4';
						                        cont++;
						                    
						                    break;
						                case SDLK_5:
						                    
						                        nomeMAX[cont]='5';
						                        cont++;
						                    
						                    break;
						                case SDLK_6:
						                    
						                        nomeMAX[cont]='6';
						                        cont++;
						                    
						                    break;
						                case SDLK_7:
						                    
					                        nomeMAX[cont]='7';
					                        cont++;
						                    
						                    break;
						                case SDLK_8:
						                    
					                        nomeMAX[cont]='8';
					                        cont++;
						                    
						                    break;
						                case SDLK_9:
						                    
					                        nomeMAX[cont]= '9';
					                        cont++;
						                    
						                    break;
						                case SDLK_BACKSPACE:
						                    
					                        nomeMAX[cont-1]= event.key.keysym.sym;
					                        cont--;
					                        inputSurface = TTF_RenderUTF8_Solid(font4,nomeMAX,color);
											inputTexto = SDL_CreateTextureFromSurface(renderer,inputSurface);
						                    
						                    break;
									}

									
									
								}

								

								if(cont == 1){//Apaga o placeholder e começa a escrever
									SDL_FreeSurface(inputSurface);
									SDL_DestroyTexture(inputTexto);
									inputSurface = TTF_RenderUTF8_Solid(font4,nomeMAX,color);
									inputTexto = SDL_CreateTextureFromSurface(renderer,inputSurface);
								
								}else if(cont > 1){//continua escrevendo
									inputSurface = TTF_RenderUTF8_Solid(font4,nomeMAX,color);
									inputTexto = SDL_CreateTextureFromSurface(renderer,inputSurface);
								}
								

							}
								 
								
							
							/*if (event.type == SDL_KEYDOWN)
           					 {
				                if (contador_name > 0)
				                {
				                	printf("PAROU STOP\n");
				                	exit(1);
								}

								if(contador_name < 5){
									if(event.key.keysym.sym == SDLK_a){
										name[contador_name] = event.key.keysym.sym;
										contador_name++;
									}
									//name[contador_name] = event.key.keysym.sym;
									//contador_name++;
								}else if(contador_name >= 5){
									name[0] = event.key.keysym.sym;
									contador_name = 1;
								}
								//if(event.key.keysym.sym == SDLK_a){
									//printf("Apertei no A");
									//exit(1);
								/*}if(event.key.keysym.sym == SDLK_BACKSPACE){
									name[contador_name--] = '\0';
								}
							}*/

							
									
								
							
							
						

						switch(event.type){
							case SDL_MOUSEMOTION:
								x = event.motion.x;
								y = event.motion.y;

								//Botao Voltar
								if(x >= voltarRect.x && x <= voltarRect.x+voltarRect.w && y >= voltarRect.y && y <= voltarRect.y+voltarRect.h){
										SDL_FreeSurface(voltarSurface);
										SDL_DestroyTexture(voltarTexto);
										voltarSurface = TTF_RenderUTF8_Solid(font,"Menu",color2);
										voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
										pataRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12) - 40;
										pataRect.y = (ALTURA_JANELA - 16) - (voltarSurface->w/2 + voltarSurface->h/2);

										
								}else{
										SDL_FreeSurface(voltarSurface);
										SDL_DestroyTexture(voltarTexto);
										voltarSurface = TTF_RenderUTF8_Solid(font,"Menu",color);
										voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
								}	

				
								//botão jogar novamente
								if(x >= jogarnovamenteRect.x && x <= jogarnovamenteRect.x+jogarnovamenteRect.w && y >= jogarnovamenteRect.y && y <= jogarnovamenteRect.y+jogarnovamenteRect.h){
										SDL_FreeSurface(jogarnovamenteSurface);
										SDL_DestroyTexture(jogarnovamenteTexto);
										jogarnovamenteSurface = TTF_RenderUTF8_Solid(font,"Jogar Novamente",color2);
										jogarnovamenteTexto = SDL_CreateTextureFromSurface(renderer,jogarnovamenteSurface);
										pataRect.x = jogarnovamenteSurface->w/2 - voltarSurface->w + ((LARGURA_JANELA/2) - (jogarnovamenteSurface->w));
										pataRect.y = (ALTURA_JANELA - 16) - (voltarSurface->w/2 + voltarSurface->h/2);

										
								}else{
										SDL_FreeSurface(jogarnovamenteSurface);
										SDL_DestroyTexture(jogarnovamenteTexto);
										jogarnovamenteSurface = TTF_RenderUTF8_Solid(font,"Jogar Novamente",color);
										jogarnovamenteTexto = SDL_CreateTextureFromSurface(renderer,jogarnovamenteSurface);
								}	


								break;
							case SDL_MOUSEBUTTONUP:
								x = event.motion.x;
								y = event.motion.y;

						
								if(event.button.button == SDL_BUTTON_LEFT){

									if(x >= voltarRect.x && x <= voltarRect.x+voltarRect.w && y >= voltarRect.y && y <= voltarRect.y+voltarRect.h){
										printf("Clicou menu\n");
										//Mix_PlayChannel( -1,botao, 0 );
										
										printf("valor do jogador novo %s\n",novoJogador.nome);
										
										if(cont == 5){
											SDL_DestroyTexture(backgroundTextura);
											backgroundTextura = NULL;
											SDL_DestroyTexture(patadegato);
											patadegato = NULL;
											SDL_DestroyTexture(voltarTexto);
											voltarTexto = NULL;
											SDL_DestroyTexture(jogarnovamenteTexto);
											jogarnovamenteTexto = NULL;
											SDL_DestroyTexture(totalTexto);
											totalTexto = NULL;
											SDL_DestroyTexture(pontosTexto);
											pontosTexto = NULL;
											//Mix_FreeMusic(m3);
											//m3 = NULL;
											if(som == NULL){
												Mix_FreeChunk(botao);
												botao = NULL;
											}else
												Mix_PlayChannel( -1,botao, 0 );

											strcpy(novoJogador.nome,nomeMAX);
											novoJogador.pontos = PONTUACAO;
											venceuRanking(novoJogador);

											PONTUACAO = 0;
											fechar = 1;
											
											return 0;//vai pro menu
										}
										
									}

									if(x >= jogarnovamenteRect.x && x <= jogarnovamenteRect.x+jogarnovamenteRect.w && y >= jogarnovamenteRect.y && y <= jogarnovamenteRect.y+jogarnovamenteRect.h){
										printf("Clicou jogar novamente\n");
										//Mix_PlayChannel( -1,botao, 0 );
										
										printf("valor do jogador novo %s\n",novoJogador.nome);
										
										if(cont == 5){
											SDL_DestroyTexture(backgroundTextura);
											backgroundTextura = NULL;									
											SDL_DestroyTexture(patadegato);
											patadegato = NULL;
											SDL_DestroyTexture(voltarTexto);
											voltarTexto = NULL;
											SDL_DestroyTexture(jogarnovamenteTexto);
											jogarnovamenteTexto = NULL;
											SDL_DestroyTexture(totalTexto);
											totalTexto = NULL;
											SDL_DestroyTexture(pontosTexto);
											pontosTexto = NULL;
											printf("CLIQUEI EM SAIR DO GAMEOVER\n");
											
											if(som == NULL){
												Mix_FreeChunk(botao);
												botao = NULL;
											}else
												Mix_PlayChannel( -1,botao, 0 );

											strcpy(novoJogador.nome,nomeMAX);
											novoJogador.pontos = PONTUACAO;
											venceuRanking(novoJogador);

											PONTUACAO = 0;
											fechar = 1;
											
											return 2;
										}
										
										
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
					//jogar novamente
					SDL_RenderCopy(renderer,jogarnovamenteTexto,NULL,&jogarnovamenteRect);
					//Som
					SDL_RenderCopy(renderer,som,NULL,&somRect);
					//Not som
					SDL_RenderCopy(renderer,notSom,NULL,&somRect);
					//Total de pontos
					SDL_RenderCopy(renderer,totalTexto,NULL,&totalRect);
					SDL_RenderCopy(renderer,pontosTexto,NULL,&pontosRect);

					//write on picture
					SDL_RenderCopy(renderer,inputTexto,NULL,&inputRect);

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
	SDL_DestroyTexture(jogarnovamenteTexto);
	jogarnovamenteTexto = NULL;
	SDL_DestroyTexture(totalTexto);
	totalTexto = NULL;
	SDL_DestroyTexture(pontosTexto);
	pontosTexto = NULL;
	SDL_DestroyTexture(inputTexto);
	inputTexto = NULL;


}