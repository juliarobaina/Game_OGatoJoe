#include "fases.c"
#include "fase1.c"
#include "menu.c"
#include "gameOver.c"
#include "creditos.c"
#include "ranking.c"

int main(){

	int corre = 0;//Variável que controla o game loop
	int fechar = 0;
	if(iniciarSDL()){
		window = criarJanela();

		if(window != NULL){
		
			if(iniciarIMG()){

				if(iniciarTTF()){//Inicando ttf para usar texto

					if(iniciarMusica()){

						//criar tela de renderizção, onde os objetos vão ser desenhados
						renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);//Antes estava 0, porém não é o melhor, o melhor é o renderer software para esse caso

						coinSound = Mix_LoadWAV( "../music/moeda1.wav" );
						moverSound = Mix_LoadWAV( "../music/mover.wav" );

						while(fechar != 1){
							
							if(corre == 0){//Volta para o menu

								corre = menu();
								
							}else if(corre == 2){//Vai para a 1ª fase
								
								corre = fase1();

							}else if(corre == 3){
								//tela de como jogar
								//corre = comoJogar();
							}else if(corre == 4){//Tela de ranking, quem coletou mais moedas
								corre = ranking();
							}
							else if(corre == 5){//Tela de créditos
								corre = creditos();
							}else if(corre == 6){
								corre = gameOver();
							}else if(corre == 7){
								corre = venceuTela();
							}else if(corre == 1){

								SDL_Delay(120);
								fechar = 1;
							}
							
							while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse
								
								encerrarJogo(event, &fechar);//Termina a execução do programa
							}

						}
					}
				}
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyTexture(backgroundTextura);
	backgroundTextura = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	som = NULL;
	SDL_DestroyTexture(notSom);
	notSom = NULL;
	Mix_FreeMusic(musica);
	musica = NULL;
	Mix_FreeChunk(botao);
	botao = NULL;
	Mix_FreeChunk(coinSound);
	coinSound = NULL;
	Mix_FreeChunk(moverSound);
	moverSound = NULL;

	destruirWRBTS();

	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
	TTF_Quit();

	return 0;
}