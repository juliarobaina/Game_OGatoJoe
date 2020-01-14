#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>

double tempo_de_jogo;
double comecarjogo();
double timer(); 
double delta;

int main (void){

	comecarjogo();
	int jogando = 1;

	int str;
	char st[3];
	char st2[3];

	float start = SDL_GetTicks();

while(jogando == 1){

	float num = SDL_GetTicks() - start;
	char convertido[16];
    sprintf(st, "%.3f",num);

    if(num < 10000){
  		strncpy(st2, st, 1);
  		printf("Tempo: %s |||||||||||||||||| mundo paralelo: %s\n",st,st2);
    }
  	else{
  		strncpy(st2, st, 2);
      printf("Tempo: %s |||||||||||||||||| mundo paralelo: %s\n",st,st2);
  	}

  	if(num == 120000){
  		printf("GAME OVER\n");
  		exit(1);
  	}

	    
	//printf("Timer: %f\n",SDL_GetTicks() - start);
			

	

	
		str = SDL_GetTicks() - start;
		
	if((SDL_GetTicks() - start) == 12000){
		printf("60s\n");
		exit(1);
	}
	//timer();

		/*if(delta >= 0.1 / 60){
			printf("Duvido se mudou\n");
			comecarjogo();
		}
*/
		//printf("%lf\n",(double)SDL_GetTicks());
		/*if(timer() < (double) 3600000 / 60){
			//continua jogando
			printf("continue a nadar \n");
			printf("%f\n", (double) timer() * 0.001);
		}
		else if (timer() >= (double) 3600000 / 60){
			//perdeu 
			printf("Oops\n");
			printf("%f\n", timer() * 0.001);

				}
			}*/

/*
SDL_Surface *minSurface = NULL;
SDL_Surface *sepSurface = NULL; 
SDL_Surface *segSurface = NULL;

	struct tempo_jogo{
	int min; 
	int seg;
};

struct tempo_jogo tempo;
	tempo.min = 2;
	tempo.seg = 59;
//quando dá play no jogo inicia 

if(jogando == 1){
	if (pause == 1){

	}else if(pause == 0){

		for(int i = 0; i < 3;i++){
				tempo.seg = 59;
			
			for(tempo.seg;tempo.seg >= 0;tempo.seg--){
				if((tempo.seg == 0) && (tempo.min == 0)){
					printf("perdeu o jogo\n");
				}else{
				//printf("%d:%d\n", tempo.min, tempo.seg);
				SDL_Surface *minSurface = TTF_RenderUTF8_Solid(font,tempo.min,color); //minutos
				minTexto = SDL_CreateTextureFromSurface(renderer,minSurface);
				SDL_Surface *sepSurface = TTF_RenderUTF8_Solid(font,":",color); //dois pontos
				sepTexto = SDL_CreateTextureFromSurface(renderer,sepSurface);
				SDL_Surface *segSurface = TTF_RenderUTF8_Solid(font,tempo.seg,color); //segundos
				segTexto = SDL_CreateTextureFromSurface(renderer,segSurface);

				SDL_Rect minRect;  //dos minutos
				minRect.w = 12;
				minRect.h = 12;
				minRect.x = 120;
				minRect.y = 10;

				SDL_QueryTexture(minTexto,NULL,NULL,&minRect.w,&minRect.h);

				SDL_Rect sepRect; // dos dois pontos
 				sepRect.w = 12;
				sepRect.h = 12;
				sepRect.x = 120 + minRect.x;
				sepRect.y = 10;

				SDL_QueryTexture(sepTexto,NULL,NULL,&sepRect.w,&sepRect.h);
				 
				SDL_Rect segRect;  //dos segundos
				segRect.w = 12;
				segRect.h = 12;
				segRect.x = 120 + minRect.x + sepRect.x;
				segRect.y = 10;

				SDL_QueryTexture(segTexto,NULL,NULL,&segRect.w,&segRect.h);

				SDL_FreeSurface(minSurface);
				SDL_FreeSurface(sepSurface);
				SDL_FreeSurface(segSurface);

				SDL_RenderCopy(renderer,min,NULL,&minRect);
				SDL_RenderCopy(renderer,sep,NULL,&sepRect);
				SDL_RenderCopy(renderer,seg,NULL,&segRect);

				}

			} //fim do for
	
		tempo.min = tempo.min - 1;
		}//fim do for
	}//fim do if 

}*/
	}
	return 0;
}


	double comecarjogo(){
		double start_timer;
		delta = (double) 0.0;
		tempo_de_jogo = 0;
		start_timer = (double) SDL_GetTicks();
		return start_timer;
	}

	double timer(){

		tempo_de_jogo = (double) (SDL_GetTicks() - comecarjogo());
		delta = tempo_de_jogo * 0.01;
		return tempo_de_jogo;
	}

	
	


