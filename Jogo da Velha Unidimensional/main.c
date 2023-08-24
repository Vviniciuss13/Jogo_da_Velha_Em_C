#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	//Variaveis
	int opcao;
	int posicao;
	char char_posicao;
	//Posição
	int p[10];
	//Letras X e O
	char l[10];
	int acabou = 0;
	int i, certo, j;
	int jogadas = 1;
	char vez = 'X';
	int numo, numx = 0;
	
	
	void verificacao(){
			if(vez == 'X'){
				numx++;
			}else{
				numo++;
			}
			
			j = 1;
			
			//Verifica as possibilidades de ganhar
			for(i = 1; i <= 3; i++){
                //Verifica Horizontalmente
                if(l[j] == vez && l[j+1] == vez && l[j+2] == vez){
                    printf("\nParabens, o jogador %c ganhou!!\n", vez);
                    acabou = 1;
                    break;
                //Verifica verticalmente
                }else if(l[i] == vez && l[i+3] == vez && l[i+6] == vez){
                    printf("\nParabens, o jogador %c ganhou!!\n", vez);
                    acabou = 1;
                    break;
                //Verifica diagonal
                }else if(l[1] == vez && l[5] == vez && l[9] == vez || 
				l[3] == vez && l[5] == vez && l[7] == vez){
                    printf("\nParabens, o jogador %c ganhou\n", vez);
                    acabou = 1;
                    break;
                }else if(numx == 5 && i == 3 || i == 3 && numo == 5){
                	printf("\nDeu velha\n");
                	acabou = 1;
                	break;
				}
				j = j + 3;
            }
				//Troca a vez do Jogador
				if(vez == 'X'){
					vez = 'O';
				}else{
					vez = 'X';
				}
	}
	
	
	//Função para mostrar como está o jogo
	void jogo(){
			printf("\n\n %c # %c # %c \n", l[1], l[2], l[3]);
			printf("###########\n");
			printf(" %c # %c # %c \n", l[4], l[5], l[6]);
			printf("###########\n");
			printf(" %c # %c # %c \n\n", l[7], l[8], l[9]);	
		}
	
	//Função para escolha da posição
	void escolha(){
		switch(posicao){
			case 1: if(p[1] == 1){
				printf("\nPosicao 1 ja foi escolhida\n");
			}else{
				p[1] = 1;
				l[1] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 2: if(p[2] == 1){
				printf("\nPosicao 2 ja foi escolhida\n");
			}else{
				p[2] = 1;
				l[2] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 3: if(p[3] == 1){
				printf("\nPosicao 3 ja foi escolhida\n");
			}else{
				p[3] = 1;
				l[3] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 4: if(p[4] == 1){
				printf("\nPosicao 4 ja foi escolhida\n");
			}else{
				p[4] = 1;
				l[4] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 5: if(p[5] == 1){
				printf("\nPosicao 5 ja foi escolhida\n");
			}else{
				p[5] = 1;
				l[5] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 6: if(p[6] == 1){
				printf("\nPosicao 6 ja foi escolhida\n");
			}else{
				p[6] = 1;
				l[6] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 7: if(p[7] == 1){
				printf("\nPosicao 7 ja foi escolhida\n");
			}else{
				p[7] = 1;
				l[7] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 8: if(p[8] == 1){
				printf("\nPosicao 8 ja foi escolhida\n");
			}else{
				p[8] = 1;
				l[8] = vez;
				certo = 1;
				jogo();
			} ; break;
			case 9: if(p[9] == 1){
				printf("\nPosicão 9 ja foi escolhida\n");
			}else{
				p[9] = 1;
				l[9] = vez;
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
		for(i = 0; i <= 9; i++){
			p[i] = 0;
            l[i] = ' ';
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
			
			verificacao();
			
			//Contagem da Rodada
			jogadas++;
			
			
		} 
			numx = 0;
			numo = 0;
			acabou = 0;
			system("pause") ; break;
			
			case 2: 	
		
		for(i = 0; i <= 9; i++){
			p[i] = 0;
            l[i] = ' ';
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
			}
		}
		
			verificacao();
			
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
