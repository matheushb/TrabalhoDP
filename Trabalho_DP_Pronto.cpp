#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define c 10

char	userMot[c] = "testemot", senhaMot[c]="12345", 
	userAdm[c] = "testeadm", senhaAdm[c]="12345", 	   
	placaCaminhao[4][8] = {"ABC1234","DEF5678","GHI9012","JKL3456"},
	disponivelCaminhao[4][13] = {"disponível","indisponível","disponível","disponível"},
	rotaCaminhao[4][20] = {"Zona 1","Zona 3","Zona 2","Zona 4"}, 
	   
	dataColeta[6][15] = {"10/04/2023","09/04/2023","08/04/2023","07/04/2023","06/04/2023","Registrar Dia"},
	jornada[12][6] = {"02:03","07:53",
	"09:00","18:03",
	"05:00","09:00",
	"20:00","23:00",
	"15:00","23:00",
        "00:00","00:00"},
        dataOcorrencia[4][12] = {"","30/03/2023","27/03/2023","20/03/2023"},
	nomeOcorrencia[4][50] = {"Registrar Ocorrencia.","Falta de Combustível.","Conteiner Danificado.","Veículo com defeito.",},
	mensagemOcorrencia[4][150] = {"","O caminhão DEF5678 está com falta de combustível.","Lixeira apresentando problemas na rota.","Caminhão apresentando defeitos em relação aos freios."},
	respostaOcorrencia[4][150] = {"","Abastecimento Solicitado.","",""};
	   
char 	modo[15], modoCaminhao[15], resp, user[c], senha[c], msgLogin[16]="";
		
int lixoColetado[6] = {30230,28800,31000,36000,27000,33000}, opt = 0, opt2 = 0, cargo, indiceCaminhao[6] = {1,3,0,1,3,0}, contaLogin=0;
bool login=false, edit=true, editOcorrencia=false, editCaminhao=true, sair=false;

bool verificaHorario(char horario[]);
bool verificaData (char data[]);
void recebeDadosColeta(int indice, int indiceJornada);
void getLogin(char *log, char *pass);
void recebeDadosCaminhao(int indice);
void respondeOcorrencia(int indice);

int main() {
    setlocale(LC_ALL, "Portuguese");
	do{
		login=false;
        opt=0;
		cargo=0;
		strcpy(msgLogin,"");
		do{
			switch(opt){ // Menu inicial
				case 0:
					do{	                  
						system("CLS");
						printf("                                               _____           _     _\n                                              |  _  |___ ___  |_|___| |_ ___\n                                              |   __|  _| . | | | -_|  _| . |\n                                              |__|  |_| |___|_| |___|_| |___|\n                                                            |___|\n                                                   _____     _ _\n                                                  |     |___| |_|_ _ ___\n                                                  | | | | -_| | | | |_ -|\n                                                  |_|_|_|___|_|_|___|___|\n\n");
						printf("\n\n\n\n\n\n\n                                                  1-Motoristas\n                                                  2-Admnistradores\n\n\n                                                  9-Sair\n\n                                                  %s\n\n------------------------------------------------------------------------------------------------------------------------>",msgLogin);
						scanf("%i",&opt);
						fflush(stdin);
						contaLogin=0;
	                }while(opt!=1 && opt!=2 && opt!=9);
					break;	
				
				case 1: //login motorista
					do{
                        system("CLS");
    					printf("                                               Login Motorista\n                                        (login: testemot | senha: 12345)\n\n");
                        getLogin(user, senha);
                        contaLogin++;
                    }while(contaLogin<3 && strcmp(user,userMot)!=0 && strcmp(senha,senhaMot)!=0);
					if(strcmp(user,userMot)==0 && strcmp(senha,senhaMot)==0) {
						login=true;
						opt=3;
						cargo=1;
					}else{
						opt=0;
						strcpy(msgLogin,"Login Incorreto!");
					}
					break;
				
				case 2: //login ADM
                     do{
    					system("CLS");
    					printf("                                               Login Admnistrador\n                                        (login: testeadm | senha: 12345)\n\n");
    					getLogin(user, senha);
    					contaLogin++;
                     }while(contaLogin < 3 && strcmp(user,userAdm)!=0 && strcmp(senha,senhaAdm)!=0);
					if(strcmp(user,userAdm)==0 && strcmp(senha,senhaAdm)==0) {
						login=true;
						opt=3;
						cargo=2;
					}else{
						opt=0;
						strcpy(msgLogin,"Login Incorreto!");
					}
					break;
				case 9:
					return 0;
					break;
			} 
		}while(opt!=3); // fim do menu inicial
		opt=0;
		if(cargo==1 && login==true) { //menu motorista
	        
	  		do {
		        system("CLS");
				printf("\n                                                  Portal do Motorista\n\n\n\n\n\n\n\n                                                  1 - Caminhões\n                                                  2 - Diário de bordo\n                                                  3 - Ocorrências\n\n\n                                                  9 - Sair\n\n\n\n\n\n\n\n\n\n\n------------------------------------------------------------------------------------------------------------------------>");
		        scanf("%i", &opt);
		        fflush(stdin);
		        switch (opt) { 
		            case 1:
		                do{
							system("CLS");
							printf("\nLista de Caminhões\n\n0 - %s\n1 - %s\n2 - %s\n3 - %s\n\nSelecione um caminhão (0-3) ou 9 para voltar: ",placaCaminhao[0],placaCaminhao[1],placaCaminhao[2],placaCaminhao[3]);
						    scanf("%d", &opt2);
						    fflush(stdin);
						    switch(opt2) {
						        case 0:
						            system("CLS");
									printf("Caminhão 0:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\nAperte ENTER para voltar. ",placaCaminhao[0],disponivelCaminhao[0], rotaCaminhao[0]);
							        getchar();
									break;
								case 1:
						            system("CLS");
									printf("Caminhão 1:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\nAperte ENTER para voltar. ",placaCaminhao[1],disponivelCaminhao[1], rotaCaminhao[1]);
							        getchar();
									break;
								case 2:
						            system("CLS");
									printf("Caminhão 2:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\nAperte ENTER para voltar. ",placaCaminhao[2],disponivelCaminhao[2], rotaCaminhao[2]);
							        getchar();
									break;
								case 3:
						            system("CLS");
									printf("Caminhão 3:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\nAperte ENTER para voltar. ",placaCaminhao[3],disponivelCaminhao[3], rotaCaminhao[3]);
							        getchar();
									break;
							    default:
							    	printf("\nOpção inválida!\n");
									break;
							}
						}while(opt2!=9);
					break;		
					case 2:
				        do{
	    					system("CLS");
	    					if(edit==false)
								strcpy(modo,"Edição");
							else
								strcpy(modo,"Visualização");						
							printf("\nDiário de Bordo                      Modo: %s\n\n0 - %s                    6 - Alternar modo (edição/Visualização)\n1 - %s\n2 - %s\n3 - %s\n4 - %s\n5 - %s\n...\n\nSelecione uma opção (0-6) ou 9 para voltar: ",modo,dataColeta[5],dataColeta[0],dataColeta[1],dataColeta[2],dataColeta[3],dataColeta[4]);
	    				    scanf("%d", &opt2);
	    				    fflush(stdin);
	    				    switch(opt2) { // dias diario de bordo
									case 1:
	    					            system("CLS");
	    								if(edit==false){
	                                       	recebeDadosColeta(0,0);
	                                    }else
											printf("\nCaminhão: %19s\nData  %23s\nInicio da jornada: %10s\nFim da Jornada: %13s\nLixo Coletado(KG): %8ikg \n\nAperte ENTER para voltar",placaCaminhao[indiceCaminhao[0]],dataColeta[0],jornada[0],jornada[1],lixoColetado[0]);
		    						    getchar();
		    							break;
	    							case 2:
	    					            system("CLS");
	    								if(edit==false){
	                                       	recebeDadosColeta(1,2);
	                                    }else
											printf("\nCaminhão: %19s\nData  %23s\nInicio da jornada: %10s\nFim da Jornada: %13s\nLixo Coletado(KG): %8ikg \n\nAperte ENTER para voltar",placaCaminhao[indiceCaminhao[1]],dataColeta[1],jornada[2],jornada[3],lixoColetado[1]);
	    						        getchar();
	    								break;
	    							case 3:
	    					            system("CLS");
	    								if(edit==false){
	                                       	recebeDadosColeta(2,4);
	                                    }else
											printf("\nCaminhão: %19s\nData  %23s\nInicio da jornada: %10s\nFim da Jornada: %13s\nLixo Coletado(KG): %8ikg \n\nAperte ENTER para voltar",placaCaminhao[indiceCaminhao[2]],dataColeta[2],jornada[4],jornada[5],lixoColetado[2]);
	    						        getchar();
	    								break;
	    							case 4:
	    					            system("CLS");
	    								if(edit==false){
	                                       	recebeDadosColeta(3,6);
	                                    }else
											printf("\nCaminhão: %19s\nData  %23s\nInicio da jornada: %10s\nFim da Jornada: %13s\nLixo Coletado(KG): %8ikg \n\nAperte ENTER para voltar",placaCaminhao[indiceCaminhao[3]],dataColeta[3],jornada[6],jornada[7],lixoColetado[3]);
	    						        getchar();
	    								break;
	    							case 5:
	    					            system("CLS");
	    								if(edit==false){
	                                       	recebeDadosColeta(4,8);
	                                    }else
											printf("\nCaminhão: %19s\nData  %23s\nInicio da jornada: %10s\nFim da Jornada: %13s\nLixo Coletado(KG): %8ikg \n\nAperte ENTER para voltar",placaCaminhao[indiceCaminhao[4]],dataColeta[4],jornada[8],jornada[9],lixoColetado[4]);
	    						        getchar();
	    								break;
	    							case 0:
	    					            system("CLS");
	    								if(edit==false || strcmp(dataColeta[5],"Registrar Dia")==0){
	                                       	recebeDadosColeta(5,10);
	                                    }else
	                                         printf("\nCaminhão: %19s\nData  %23s\nInicio da jornada: %10s\nFim da Jornada: %13s\nLixo Coletado(KG): %10i \n\nAperte ENTER para voltar",placaCaminhao[indiceCaminhao[5]],dataColeta[5],jornada[10],jornada[11],lixoColetado[5]);
	                                         getchar();
	                                    break;
									case 6:
										if(edit==true)
										edit=false;
										else
											edit=true;
	    								break;
	    						    default:
	    						    	printf("\nOpção inválida!\n");
	    								break;
	    				    }
						}while(opt2!=9);
				    break;		
				    case 3:
	                    do{
							system("CLS");
							printf("\nLista de Ocorrências\n\n0 - %s  (%s)\n1 - %s  (%s)\n2 - %s  (%s)\n3 - %s   (%s)\n\nSelecione uma ocorrência (0-3) ou 9 para voltar: ",nomeOcorrencia[0],dataOcorrencia[0],nomeOcorrencia[1],dataOcorrencia[1],nomeOcorrencia[2],dataOcorrencia[2],nomeOcorrencia[3],dataOcorrencia[3]);
						    scanf("%d", &opt2);
						    fflush(stdin);
						    switch(opt2) {
						        case 0:
						            system("CLS");
									if (editOcorrencia==false || strcmp(nomeOcorrencia[0],"Registrar Ocorrencia")==0){
										
										printf("Digite o nome da ocorrência: ");
										fgets(nomeOcorrencia[0],50,stdin);
										nomeOcorrencia[0][strcspn(nomeOcorrencia[0], "\n")] = '\0';
										fflush(stdin);
											
										do{
											printf("Digite a data da ocorrência(xx/yy/2023): ");
											fgets(dataOcorrencia[0],11,stdin);
											fflush(stdin);
										}while(verificaData(dataOcorrencia[0])==false);
										
										printf("Descreva a ocorrência: ");
										fgets(mensagemOcorrencia[0],151,stdin);
										fflush(stdin);
										
										printf("\n\nAperte ENTER para voltar. ");
										editOcorrencia=true;
										
									}else
										printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nAperte ENTER para voltar. ",dataOcorrencia[0],nomeOcorrencia[0],mensagemOcorrencia[0],respostaOcorrencia[0]);
							        getchar();
									break;
								case 1:
						            system("CLS");
									printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nAperte ENTER para voltar. ",dataOcorrencia[1],nomeOcorrencia[1],mensagemOcorrencia[1],respostaOcorrencia[1]);
							        getchar();
									break;
								case 2:
						            system("CLS");
									printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nAperte ENTER para voltar. ",dataOcorrencia[2],nomeOcorrencia[2],mensagemOcorrencia[2],respostaOcorrencia[2]);
							        getchar();
									break;
								case 3:
						            system("CLS");
									printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nAperte ENTER para voltar. ",dataOcorrencia[3],nomeOcorrencia[3],mensagemOcorrencia[3],respostaOcorrencia[3]);
							        getchar();
									break;
							    default:
							    	printf("\nOpção inválida!\n");
									break;
							}
						}while(opt2!=9);
	                    break;
				}
			}while (opt != 9);
		}else if(cargo==2 && login==true) { //Portal do admnistrador
			do{
				system("CLS");
				printf("\n                                                Portal do Admnistrador\n\n\n\n\n\n\n\n                                                  1 - Caminhões\n                                                  2 - Ocorrências\n\n\n                                                  9 - Sair\n\n\n\n\n\n\n\n\n\n\n------------------------------------------------------------------------------------------------------------------------>");
			    scanf("%i", &opt);
			    fflush(stdin);
			    switch (opt) { 
			        case 1:
			            do{
							system("CLS");
							if (editCaminhao==false)
								strcpy(modoCaminhao,"Edição");
							else
								strcpy(modoCaminhao,"Visualização");
							printf("\nLista de Caminhões             Modo: %s\n\n0 - %s                    4 - Alternar modo (edição/Visualização)\n1 - %s\n2 - %s\n3 - %s\n\nSelecione um caminhão (0-4) ou 9 para voltar: ",modoCaminhao,placaCaminhao[0],placaCaminhao[1],placaCaminhao[2],placaCaminhao[3]);
							scanf("%d", &opt2);
							fflush(stdin);
							switch(opt2) {
								case 0:
							        system("CLS");
									if(editCaminhao==false){
										recebeDadosCaminhao(0);
									}else
										printf("Caminhão 0:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\n Aperte ENTER para voltar. ",placaCaminhao[0],disponivelCaminhao[0], rotaCaminhao[0]);
									
                                    getchar();
									break;
								case 1:
							        system("CLS");
									if(editCaminhao==false){
										recebeDadosCaminhao(1);
									}else
										printf("Caminhão 1:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\nAperte ENTER para voltar. ",placaCaminhao[1],disponivelCaminhao[1], rotaCaminhao[1]);
								    
									getchar();
									break;
								case 2:
							        system("CLS");
									if(editCaminhao==false){
										recebeDadosCaminhao(2);
									}else
										printf("Caminhão 2:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\nAperte ENTER para voltar. ",placaCaminhao[2],disponivelCaminhao[2], rotaCaminhao[2]);
								    
									getchar();
									break;
								case 3:
							        system("CLS");
									if(editCaminhao==false){
										recebeDadosCaminhao(3);
									}else
										printf("Caminhão 3:\n\nPlaca:   %s\nStatus:  %s\nRota:    %s\n\nAperte ENTER para voltar. ",placaCaminhao[3],disponivelCaminhao[3], rotaCaminhao[3]);
								    
									getchar();
									break;
								case 4:
									if(editCaminhao==false) 
										editCaminhao=true;
									else
										editCaminhao=false;
									break;
								default:
								    printf("\nOpção inválida!\n");
									break;
							}
							
						}while(opt2!=9);
					break;
					case 2: //responder ocorrencias
					do{
							system("CLS");
							printf("\nLista de Ocorrências:\n\n");
							for(int x=0;x<=3;x++){
								if(strcmp(dataOcorrencia[x],"")!=0)
									printf("%i - %s (%s)\n",x,nomeOcorrencia[x],dataOcorrencia[x]);
							}
							printf("\n\nSelecione uma ocorrência ou digite 9 para voltar: ");
						    scanf("%d", &opt2);
						    fflush(stdin);
						    switch(opt2) {
						        case 0:
						            system("CLS");
									printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nDigite \"R\" para responder ou ENTER para voltar: ",dataOcorrencia[0],nomeOcorrencia[0],mensagemOcorrencia[0],respostaOcorrencia[0]);
									if(strcmp(respostaOcorrencia[0],"")==0) {
										respondeOcorrencia(0);
									}
									getchar();
									break;
								case 1:
						            system("CLS");
									printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nDigite \"R\" para responder ou ENTER para voltar: ",dataOcorrencia[1],nomeOcorrencia[1],mensagemOcorrencia[1],respostaOcorrencia[1]);
							        
									if(strcmp(respostaOcorrencia[1],"")==0) {
										respondeOcorrencia(1);
									}
									getchar();
									break;
								case 2:
						            system("CLS");
									printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nDigite \"R\" para responder ou ENTER para voltar: ",dataOcorrencia[2],nomeOcorrencia[2],mensagemOcorrencia[2],respostaOcorrencia[2]);
							        if(strcmp(respostaOcorrencia[2],"")==0) {
										respondeOcorrencia(2);
									}
									getchar();
									break;
								case 3:
						            system("CLS");
									printf("\nAutor: testemot\nData: %s\nNome Ocorrencia: %s\n\nOcorrencia: %s\n\nResposta: %s\n\n\nDigite \"R\" para responder ou ENTER para voltar: ",dataOcorrencia[3],nomeOcorrencia[3],mensagemOcorrencia[3],respostaOcorrencia[3]);
							        if(strcmp(respostaOcorrencia[3],"")==0) {
										respondeOcorrencia(3);
									}
									getchar();
									break;
							    default:
							    	printf("\nOpção inválida!\n");
									break;
							}
						}while(opt2!=9);
					break; //fim case 2		
				}
			}while(opt!=9);		
		}
	}while(sair==false);
	getchar();
	return 0;	
}

void respondeOcorrencia(int indice) {
	char resp;
	scanf("%c",&resp);
	fflush(stdin);
	if(resp==114 || resp==82){
		printf("\nResposta: ");
		gets(respostaOcorrencia[indice]);
	}
}

bool verificaHorario(char horario[]) {
	int hora, min;
	bool resultado = true;	
	sscanf(horario,"%d:%d",&hora,&min);	
	if(hora<0 || hora>24)
		resultado=false;
	if(min<0 || min>60)
		resultado=false;
		
	return resultado;
}

bool verificaData (char data[]) {
	int dia,mes,ano;
	bool resultado=true;
	
	sscanf(data,"%d/%d/%d",&dia,&mes,&ano);
	if(dia<1 ||dia>31)
		resultado=false;
	if(mes<1 || mes>12)
		resultado=false;
	if(ano!=2023)
		resultado=false;	
	return resultado;
}

void recebeDadosCaminhao(int indice) {
	int status;
	do{
		printf("Digite a placa do caminhão(7c): ");
		fgets(placaCaminhao[indice],8,stdin);
		fflush(stdin);
	}while(strlen(placaCaminhao[indice]) != 7);
	do{
		printf("Digite o status do caminhão (0 - Indisponível | 1 - Disponível): ");
		scanf("%i",&status);
		fflush(stdin);
	}while(status!=0 && status != 1);
	if(status==1)
		strcpy(disponivelCaminhao[indice],"Disponível");	
	else
		strcpy(disponivelCaminhao[indice],"Indisponível");
	do{
		printf("Digite a rota do caminhão(<20c): ");
		fgets(rotaCaminhao[indice],21,stdin);
		fflush(stdin);
	}while(strlen(rotaCaminhao[indice]) < 1 || strlen(rotaCaminhao[indice]) > 20);
	printf("\nAperte ENTER para voltar.");
}

void recebeDadosColeta(int indice, int indiceJornada) {
	do{
		system("cls");
		for(int x=0;x<=3;x++)
			printf("%i - %s\n",x,placaCaminhao[x]);
		printf("Qual caminhão foi utilizado na jornada: ");
		scanf("%i",&indiceCaminhao[indice]);
		fflush(stdin);
	}while(indiceCaminhao[indice]<0 ||indiceCaminhao[indice]>3);
	
	do{
        printf("Qual a data(xx/yy/2023): ");
    	fgets(dataColeta[indice],11,stdin);
        fflush(stdin);
    }while(verificaData(dataColeta[indice])==false);
    do{
        printf("Horario Inicio da Jornada(xx:yy): ");
        fgets(jornada[indiceJornada],6,stdin);
        fflush(stdin);
   }while(verificaHorario(jornada[indiceJornada])==false);
   do{
        printf("Horario Fim da Jornada (xx:yy): ");
        fgets(jornada[indiceJornada+1],6,stdin);
        fflush(stdin);
    }while(verificaHorario(jornada[indiceJornada+1])==false);
    do{
        printf("Lixo Coletado em KG(xx): ");
        scanf("%i",&lixoColetado[indice]);
        fflush(stdin);
   }while(lixoColetado[indice]==0);
   edit=true;
   printf("\n\nAperte ENTER para continuar. ");	
}

void getLogin(char *log, char *pass){

	printf("\n\n\n\n\n\n\n                                                Usuário: ");
	fgets(log,c,stdin);
	fflush(stdin);
	log[strcspn(log,"\n")] = '\0';
				
	printf("                                                Senha: ");
	fgets(pass,c,stdin);
	fflush(stdin);
	pass[strcspn(pass,"\n")] = '\0';


}
