#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	
	//Variaveis
	int opcao;
	int posicao;
	char char_posicao;
	//Posoção
	int p[4][4];
	//Letras X e O
	char l[4][4];
	int acabou = 0;
	int i, j, certo;
	int jogadas = 1;
	char vez = 'X';
	char again;
	int numo, numx = 0;
	
	//Verificações
	void verifica(){
		if(vez == 'X'){
				numx++;
			}else{
				numo++;
			}
		
			//Verifica as possibilidades igual o outro
			for(i = 1; i < 4; i++){
				j = 1;
				if(l[j][i] == vez && l[j+1][i] == vez && l[j+2][i] == vez){
					printf("\n Parabens, Jogador %c venceu\n", vez);
					acabou = 1;
					break;
				}else if(l[i][j] == vez && l[i][j+1] == vez && l[i][j+2] == vez){
					printf("\n Parabens, Jogador %c venceu\n", vez);
					acabou = 1;
					break;
				}else if(l[j][j] == vez && l[j+1][j+1] == vez && l[j+2][j+2] == vez){			
					printf("\n Parabens, Jogador %c venceu\n", vez);
					acabou = 1;
					break;
				}else if(l[j][j+2] == vez && l[j+1][j+1] == vez && l[j+2][j] == vez){			
					printf("\n Parabens, Jogador %c venceu\n", vez);
					acabou = 1;
					break;
				}else if(numx == 5 && i == 3 || i == 3 && numo == 5){
					printf("\nDeu velha\n");
					acabou = 1;
					break;
				}		
			}
			
			//Troca a vez
			if(vez == 'X'){
				vez = 'O';
			}else{
				vez = 'X';
			}
	}
	
	//Função para mostrar como está o jogo
	void jogo(){
			printf("\n\n %c # %c # %c \n", l[1][1], l[1][2], l[1][3]);
			printf("###########\n");
			printf(" %c # %c # %c \n", l[2][1], l[2][2], l[2][3]);
			printf("###########\n");
			printf(" %c # %c # %c \n\n", l[3][1], l[3][2], l[3][3]);	
		}
	
	//Função para escolha da posição
	void escolha(){	
		switch(posicao){
			case 1: if(p[1][1] == 1){
				printf("\nPosicao 1 ja foi escolhida\n");
			}else{
				p[1][1] = 1;
				l[1][1] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 2: if(p[1][2] == 1){
				printf("\nPosicao 2 ja foi escolhida\n");
			}else{
				p[1][2] = 1;
				l[1][2] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 3: if(p[1][3] == 1){
				printf("\nPosicao 3 ja foi escolhida\n");
			}else{
				p[1][3] = 1;
				l[1][3] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 4: if(p[2][1] == 1){
				printf("\nPosicao 4 ja foi escolhida\n");
			}else{
				p[2][1] = 1;
				l[2][1] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 5: if(p[2][2] == 1){
				printf("\nPosicao 5 ja foi escolhida\n");
			}else{
				p[2][2] = 1;
				l[2][2] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 6: if(p[2][3] == 1){
				printf("\nPosicao 6 ja foi escolhida\n");
			}else{
				p[2][3] = 1;
				l[2][3] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 7: if(p[3][1] == 1){
				printf("\nPosicao 7 ja foi escolhida\n");
			}else{
				p[3][1] = 1;
				l[3][1] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 8: if(p[3][2] == 1){
				printf("\nPosicao 8 ja foi escolhida\n");
			}else{
				p[3][2] = 1;
				l[3][2] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 9: if(p[3][3] == 1){
				printf("\nPosicão 9 ja foi escolhida\n");
			}else{
				p[3][3] = 1;
				l[3][3] = vez;
				certo = 1;
				jogo();
			} ; break;
			default: printf("\nColoque a posicao correta\n"); break;
		}
	}
	
	do{
		opcao = 0;
		system("cls");
		printf("################################### \n\n");
		printf("JOGO DA VELHA \n\n");
		printf("################################### \n\n");
		printf("\n1.Jogo Aleatorio \n2.Jogo Manual\n3. Sair\n");
		scanf("%d", &opcao);
		//Escolhe a opcao desejada
		switch(opcao){
			case 1: 
		printf(" 1 # 2 # 3 \n");
		printf("###########\n");
		printf(" 4 # 5 # 6 \n");
		printf("###########\n");
		printf(" 7 # 8 # 9 \n\n");
		
		srand(time(NULL));
		
		//RLimpa o Jogo
		for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			p[i][j] = 0;
			l[i][j] = ' ';
		}
		}
		
		//Jogo
		while(acabou == 0){
			//Número da Jogada
			printf("\nJogada %d\n", jogadas);
			
			//Loop ate o robo escolher certo a posição 
			certo = 0;
			while(certo != 1){
			//Escolhe a posição
			posicao = 1 + (rand() % 9);
			escolha(); //função
			}
			
			verifica();
			
			//Contagem da Rodada
			jogadas++;
			
			
		} 
			numx = 0;
			numo = 0;
			acabou = 0;
			system("pause"); break;
			case 2: 
		
		//Limpa o Jogo
		for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			p[i][j] = 0;
			l[i][j] = ' ';
		}
		}
			
		printf(" 1 # 2 # 3 \n");
		printf("###########\n");
		printf(" 4 # 5 # 6 \n");
		printf("###########\n");
		printf(" 7 # 8 # 9 \n\n");
		
		
		while(acabou == 0){	
		
			//Escolha certa
			certo = 0;
			while(certo != 1){
			printf("\nDigite a posicao que voce deseja 1, 2, 3, 4, 5, 6, 7, 8, 9: ");
			scanf("%s", &char_posicao);
			if(isdigit(char_posicao) == 1){
				posicao = char_posicao - '0';
				escolha();
			}else{
				printf("Digite um numero!!");
			}
			
		}
		
			verifica();
			
		} 
			numx = 0;
			numo = 0;
			acabou = 0;
			system("pause") ; break;
			//Caso a pessoa queira sair
			case 3: printf("\nTchau"); break;
			//Caso ela escolha errado
			default: printf("\nEscolha uma das opcoes!!"); break;
		}
	} while(opcao != 3);
	//Fim
	getch();
	return 0;
}
