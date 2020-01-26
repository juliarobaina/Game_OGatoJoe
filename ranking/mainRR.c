#include "rr.c"

int main(int argc, char const *argv[]){

	int rep;
	Jogador novo;
	
	//setbuf(stdin,0);//limpando buffer
	
		printf("Nome: ");

		fgets(novo.nome, 11, stdin);
	
		int r = strlen(novo.nome);//Pegar tamanho da string
		
		if(novo.nome[r - 1] == '\n')//verificando se e quebra de linha. Não quero iso no arquivo
			novo.nome[r - 1] = '\0';
		
		setbuf(stdin,0);//limpando buffer

		printf("Pontos: ");
		scanf("%d",&novo.pontos);
	

	venceuRanking(novo);

	lerArquivo();

	/*escreverArquivo();

	printf("Joga %d\n",JOGADORES_CHEIO);

	printf("Deu %d",quantasLinhas());


	if(ordenar()){
		printf("Sucesso\n");
	}else{
		printf("foi o isVazio\n");
	}*/


	return 0;
}