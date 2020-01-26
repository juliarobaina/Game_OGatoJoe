#include "rr.h"

void escreverArquivo(Jogador player){


	//criando a variável ponteiro para o arquivo 
	FILE *ponteiro_do_arquivo;
	char nome[11];
	int pontos; 

	//abrindo o arquivo (usar "a" que escreve no final e cria um arquivo caso ele não exista)
	ponteiro_do_arquivo = fopen("ranking.txt", "a");

	
	/*fgets(player.nome, 11, stdin);
	
	int r = strlen(player.nome);//Pegar tamanho da string
	
	if(player.nome[r - 1] == '\n')//verificando se e quebra de linha. Não quero iso no arquivo
		player.nome[r - 1] = '\0';
	
	setbuf(stdin,0);//limpando buffer

	printf("Pontos: ");
	scanf(" %d",&player.pontos);*/

	//escrevendo o nome no arquivo
	fprintf(ponteiro_do_arquivo, "%s",player.nome);
	fprintf(ponteiro_do_arquivo, " ");
	fprintf(ponteiro_do_arquivo, "%d\n",player.pontos);
	
	//fechando o arquivo 
	fclose(ponteiro_do_arquivo);
}

long isVazio(const char* nomeArquivo){//verifica se o arquivo está vazio

	FILE* arquivo = fopen(nomeArquivo,"rb");//ler em modo binário

	if(arquivo == NULL)
		return 0;

	fseek(arquivo,0,SEEK_END);//Coloca no final do arquivo
	long size = ftell(arquivo);//Calcula o tamanho
	fclose(arquivo);//fecha o arquivo
	return size;//retorna tamanho total do arquivo

	
}

int comparador(const void* a, const void* b){//auxilia o qsort
	int pri = ((struct jogador*)b)->pontos;
	int seg = ((struct jogador*)a)->pontos;

	return (pri - seg);
}

void ordenar(){

	if(isVazio("ranking.txt") <= 0){
		printf("Arquivo esta vazio, Nao tem nada pra ordenar\n");
		return;
	}

	FILE *arquivo;
	
	Jogador player[3];

	//abrindo o arquivo (usar "a" que escreve no final e cria um arquivo caso ele não exista)
	arquivo = fopen("ranking.txt", "r");

	//ler o arquivo enquanto ele não chega no final e armazenar os 3 jogadores
	int tamTotal = 0;	
	
	for(int i = 0;!feof(arquivo) && i < 3;i++){//passar os valores do arquivo para a estrutura
		fscanf(arquivo,"%s %d\n", player[i].nome,&player[i].pontos);
		tamTotal++;
	}

	qsort(player,tamTotal,sizeof(Jogador),comparador);//ordenar a struct em ordem Decrescente

	//for(int i = 0;i < tamTotal;i++)//imprimir valores ordenados em ordem Decrescente
		//printf("player %d = %s : %i\n",i, player[i].nome ,player[i].pontos);

	//fechando o arquivo 
	fclose(arquivo);

	arquivo = fopen("ranking.txt", "w");

	for(int i = 0;!feof(arquivo) && i < tamTotal;i++){
		fprintf(arquivo, "%s %d\n",player[i].nome, player[i].pontos);
	}

	//fechando o arquivo 
	fclose(arquivo);

}

int quantasLinhas(FILE* arquivo){

	//FILE *arquivo;

	//abrindo o arquivo (usar "a" que escreve no final e cria um arquivo caso ele não exista)
	
	//arquivo = fopen("ranking.txt", "r");

	if(arquivo == NULL){
		return -1;
	}

	int tamTotal = 0;
	char c = fgetc(arquivo);

	while(!feof(arquivo)){//passar os valores do arquivo para a estrutura
		if(c == '\n')
			tamTotal++;
		c = fgetc(arquivo);
	}

	//fclose(arquivo);
	
	return tamTotal;
}
int quantasLinhasVenceu(){

	FILE *arquivo;

	//abrir para ler	
	arquivo = fopen("ranking.txt", "r");

	if(arquivo == NULL){
		printf("Nao abriu arquivo na funcao quantasLinhasVenceu\n");
		return -1;
	}

	int tamTotal = 0;
	char c = fgetc(arquivo);

	while(!feof(arquivo)){//passar os valores do arquivo para a estrutura
		if(c == '\n')
			tamTotal++;
		c = fgetc(arquivo);
	}

	rewind(arquivo);

	fclose(arquivo);

	
	return tamTotal;
}

void troca(Jogador pontoNovo){//nessa função já estou com o máximo de valores

	FILE *arquivo;

	//abrir para ler
	arquivo = fopen("ranking.txt", "r");

	Jogador player[3];

	for(int i = 0;!feof(arquivo) && i < 3;i++){//passar os valores do arquivo para a estrutura
		fscanf(arquivo,"%s %d\n", player[i].nome,&player[i].pontos);
	}

	/* o menor valor é o último. Se o novo valor for maior que o último
	   troca, se não mantém os dados.
	*/
	if(pontoNovo.pontos > player[2].pontos){
		player[2].pontos = pontoNovo.pontos;
		strcpy(player[2].nome,pontoNovo.nome);//realiza a cópia entre strings
	}

	qsort(player,3,sizeof(Jogador),comparador);//ordena em ordem decrescente

	//fechando o arquivo 
	fclose(arquivo);

	arquivo = fopen("ranking.txt", "w");//destrói o que tem dentro

	for(int i = 0;!feof(arquivo) && i < 3;i++){//coloca no arquivo os dados ordenados
		fprintf(arquivo, "%s %d\n",player[i].nome, player[i].pontos);
	}

	fclose(arquivo);

}

void venceuRanking(Jogador pontoNovo){

	if(quantasLinhasVenceu() == 0){//Se for o 1º registro, apenas escrevo
		escreverArquivo(pontoNovo);
	}else{
		int esc = quantasLinhasVenceu();

		if(esc < 3){//se ainda não atingi o máximo, continuo apenas escrevendo e ordenando
			escreverArquivo(pontoNovo);
			ordenar();
		}else{
			troca(pontoNovo);//atingi o máximo, apenas troco valores
		}
	}	
}

int lerArquivo(SDL_Texture** jogTexto,SDL_Surface** jogSurface,SDL_Rect* jogRect,
				SDL_Texture** jogPontosTexto,SDL_Surface** jogPontosSurface,SDL_Rect* jogPontosRect){

	

	FILE *arquivo;

	//abrir para ler
	arquivo = fopen("ranking.txt", "r");

	if(arquivo == NULL){
		printf("Erro ao abrir arquivo na funcao lerArquivo\n");
		return -1;
	}

	int tamTotal = quantasLinhas(arquivo);
	rewind(arquivo);

	if(tamTotal > 0){
		Jogador player[tamTotal];
		SDL_Color colorR = {0xFF,0xA5,0x00,0xFF};
		
		
		for(int i = 0;!feof(arquivo) && i < tamTotal;i++){//passar os valores do arquivo para a estrutura
			fscanf(arquivo,"%s %d\n", player[i].nome,&player[i].pontos);
		}

		//TTF_Font *fontRanking = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",40);
		
		int inc = 335;//175

		char str[3];

		for(int j = 0;j < tamTotal;j++){

				if(jogSurface[j] != NULL){
					SDL_FreeSurface(jogSurface[j]);
					jogSurface[j] = NULL;
				}
				jogSurface[j] = TTF_RenderUTF8_Solid(font,player[j].nome,colorR);	
				
				if(jogPontosSurface[j] != NULL){
					SDL_FreeSurface(jogPontosSurface[j]);
					jogPontosSurface[j] = NULL;
				}
				sprintf(str,"%d",player[j].pontos);
				jogPontosSurface[j] = TTF_RenderUTF8_Solid(font,str,colorR);

				if(jogTexto[j] != NULL){
					SDL_DestroyTexture(jogTexto[j]);
					jogTexto[j] = NULL;
				
				}
				jogTexto[j] = SDL_CreateTextureFromSurface(renderer,jogSurface[j]);

				if(jogPontosTexto[j] != NULL){
					SDL_DestroyTexture(jogPontosTexto[j]);
					jogPontosTexto[j] = NULL;
				}
				jogPontosTexto[j] = SDL_CreateTextureFromSurface(renderer,jogPontosSurface[j]);


				jogRect[j].w = jogSurface[j]->w;
				jogRect[j].h = jogSurface[j]->h;
				jogRect[j].x = (LARGURA_JANELA/7) - (jogSurface[j]->w/12) + 10;
				jogRect[j].y = (ALTURA_JANELA) - inc;
				SDL_QueryTexture(jogTexto[j],NULL,NULL,&jogRect[j].w,&jogRect[j].h);
				SDL_FreeSurface(jogSurface[j]);
				jogSurface[j] = NULL;

				
				
				jogPontosRect[j].w = jogPontosSurface[j]->w;
				jogPontosRect[j].h = jogPontosSurface[j]->h;
				if(player[j].pontos == 10)
					jogPontosRect[j].x = (LARGURA_JANELA) - (jogPontosSurface[j]->w * 6) - 10;
				else
					jogPontosRect[j].x = (LARGURA_JANELA) - (jogPontosSurface[j]->w * 11) - 10;
				
				jogPontosRect[j].y = (ALTURA_JANELA) - inc;
				SDL_QueryTexture(jogPontosTexto[j],NULL,NULL,&jogPontosRect[j].w,&jogPontosRect[j].h);
				SDL_FreeSurface(jogPontosSurface[j]);
				jogPontosSurface[j] = NULL;

				inc -= 80;
			
		}
		
		
		

		
		for(int i = 0;i < tamTotal;i++)//imprimir valores ordenados em ordem Decrescente
			printf("player %d = %s : %i\n",i, player[i].nome ,player[i].pontos);
	
		return 1;
	}

	return 0;
	

	fclose(arquivo);

}
