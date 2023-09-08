#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void corf(int r, int g, int b){printf("\e[48;2;%d;%d;%dm", r, g, b);}
void corn(void){printf("\e[m");}
void pos(int lin, int col){printf("\e[%d;%dH", lin, col);}
void limpa(void){printf("\e[2J");}

void barra_rgb(int r, int g, int b){
    r = (r/5)*5;
    g = (g/5)*5;
    b = (b/5)*5;
    pos(7, 0);
    for (int i = 0; i < 256; i++){
        if(i == r){
            corf(255, 255, 255);
            printf(" ");
            i+=4;
        }else{
            corf(i, 0, 0);
            printf(" ");
            i+=4;
        }
        
    }corn();
    printf("\n");
    for (int n = 0; n < 256; n++){
        if(n == g){
            corf(255, 255, 255);
            printf(" ");
            n+=4;
        }else{
            corf(0, n, 0);
            printf(" ");
            n+=4;
        }
        
    }corn();
    printf("\n");
    for (int j = 0; j < 256; j++){
        if(j == b){
            corf(255, 255, 255);
            printf(" ");
            j+=4;
        }else{
            corf(0, 0, j);
            printf(" ");
            j+=4;
        }
    }corn();
    printf("\n");
}

float pontuacao(float r_pc, float g_pc, float b_pc, float r_user, float g_user, float b_user ){
    float pior_pontuacao_r, pontos_r, pior_pontuacao_g, pontos_g, pior_pontuacao_b, pontos_b, total_points;
    if(r_pc > 127){
        if(r_pc >= r_user){
            pior_pontuacao_r = r_pc;
            pontos_r = (r_user * 100)/pior_pontuacao_r;
        }else if(r_user > r_pc){
            pior_pontuacao_r = r_pc;
            r_user = r_user - r_pc;
            pontos_r = (((r_user*100)/pior_pontuacao_r)-100)*(-1);
        }
    }else{
        if(r_pc >= r_user){
        pior_pontuacao_r = 255 - r_pc;
        pontos_r = ((((r_pc-r_user)*100)/pior_pontuacao_r)-100)*(-1);
        }else if(r_user > r_pc){
            pior_pontuacao_r = 255 - r_pc;
            pontos_r = ((((r_user-r_pc)*100)/pior_pontuacao_r)-100)*(-1);
        }
    }
     if(g_pc > 127){
        if(g_pc >= g_user){
            pior_pontuacao_g = g_pc;
            pontos_g = (g_user * 100)/pior_pontuacao_g;
        }else if(g_user > g_pc){
            pior_pontuacao_g = g_pc;
            g_user = g_user-g_pc;
            pontos_g = (((g_user*100)/pior_pontuacao_g)-100)*(-1);
        }
    }else{ 
        if(g_pc >= g_user){
        pior_pontuacao_g = 255 - g_pc;
        pontos_g = ((((g_pc-g_user)*100)/pior_pontuacao_g)-100)*(-1);
        }else if(g_user > g_pc){
            pior_pontuacao_g = 255 - g_pc;
            pontos_g = ((((g_user-g_pc)*100)/pior_pontuacao_g)-100)*(-1);
        }
    }
     if(b_pc > 127){
        if(b_pc >= b_user){
            pior_pontuacao_b = b_pc;
            pontos_b = (b_user * 100)/pior_pontuacao_b;
        }else if(b_user > b_pc){
            pior_pontuacao_b = b_pc;
            b_user = b_user-b_pc;
            pontos_b = (((b_user*100)/pior_pontuacao_b)-100)*(-1);
        }
    }else{
       if(b_pc >= b_user){
        pior_pontuacao_b = 255 - b_pc;
        pontos_b = ((((b_pc-b_user)*100)/pior_pontuacao_b)-100)*(-1);
        }else if(b_user > b_pc){
            pior_pontuacao_b = 255 - b_pc;
            pontos_b = ((((b_user-b_pc)*100)/pior_pontuacao_b)-100)*(-1);
        }
    }
    total_points = (pontos_r+pontos_g+pontos_b)/3;
    pos(3, 30);
    printf("Pontuacao atual: %.2f \n", total_points);
    return total_points;
}

void quadrado_pc(int r, int g, int b){
    int linha, coluna;
    linha = 10;
    coluna = 5;
    corf(r, g, b);
    for (int i = 0; i < coluna; i++){
        for(int n = 0; n < linha; n++){
            printf(" ");
        }printf("\n");
    }corn();
} 

void quadrado_user(int r, int g, int b){
    int linha, coluna, aux = 1;
    linha = 10;
    coluna = 5;
    corf(r, g, b);
    pos(1,15);
    for (int i = 0; i < coluna; i++){
        for(int n = 0; n < linha; n++){
            printf(" ");
        }
    printf("\n");
    aux++;
    pos(aux, 15);
    }corn();
}


int main(){
    srand(time(0));
    float matriz[3][1];
    char nickname_1[16] = {"n"};
    char nickname_2[16] = {"n"};
    char nickname_3[16] = {"n"};
    matriz[0][0] = 0;
    matriz[1][0] = 0;
    matriz[2][0] = 0;
    INICIO_GAME:
    pos(1,0);
    float pontuacao_final;
    int continuar_jogando = 1;
    int color_pc[3]= {rand()%255, rand()%255, rand()%255};
    int r_user = 0, g_user = 0, b_user = 0, tentativas = 0;
        quadrado_pc(color_pc[0], color_pc[1], color_pc[2]);
        barra_rgb(300, 300, 300);
        while (tentativas < 5 && (color_pc[0] != r_user || color_pc[1] != g_user || color_pc[2] != b_user)){
            pos(11, 0);
            printf("Voce tem %i tentativas \n", 5-tentativas);
            JOGADA_RED:
            printf("Digite a quantia de VERMELHO entre 0 e 255 ");
            scanf("%i", &r_user);
            if(r_user <= 255 && r_user >= 0){
                JOGADA_GREEN:
                printf("Digite a quantia de VERDE entre 0 e 255 ");
                scanf("%i", &g_user);
                if(g_user <= 255 && g_user >= 0){
                    JOGADA_BLUE:
                    printf("Digite a quantia de AZUL entre 0 e 255 ");
                    scanf("%i", &b_user);
                    if(b_user <= 255 && b_user >= 0){
                        quadrado_user(r_user, g_user, b_user);
                        tentativas++;
                        limpa();
                        pos(0, 0);
                        quadrado_pc(color_pc[0], color_pc[1], color_pc[2]);
                        quadrado_user(r_user, g_user, b_user);
                        pontuacao(color_pc[0], color_pc[1], color_pc[2], r_user, g_user, b_user);
                        barra_rgb(r_user, g_user, b_user);
                        printf("Seus ultimos valores: R%d G%d B%d \n", r_user, g_user, b_user);
                    }else{
                        printf("Digite um valor valido entre 0 e 255 \n");
                        goto JOGADA_BLUE;
                    }
                }else{
                    printf("Digite um valor valido entre 0 e 255 \n");
                    goto JOGADA_GREEN;
                }
            }else{
                printf("Digite um valor valido entre 0 e 255 \n");
                goto JOGADA_RED;
            }
        }
        pontuacao_final = pontuacao(color_pc[0], color_pc[1], color_pc[2], r_user, g_user, b_user);
        if(pontuacao_final > matriz[0][0]){
            pos(11,0);
            for (int k = 0; k<16;k++){
                nickname_3[k] = nickname_2[k];
                nickname_2[k] = nickname_1[k];
            }
            printf("Voce entrou no ranking top3, digite seu nome ");
            scanf("%19s", nickname_1);
            matriz[2][0] = matriz[1][0];
            matriz[1][0] = matriz[0][0];
            matriz[0][0] = pontuacao_final;
        }else if( pontuacao_final > matriz[1][0]){
            for (int j = 0; j<16;j++){
                nickname_3[j] = nickname_2[j];
            }
            pos(11,0);
            printf("Voce entrou no ranking top3, digite seu nome ");
            scanf("%19s", nickname_2);
            matriz[2][0] = matriz[1][0];
            matriz[1][0] = pontuacao_final;
        }else if(pontuacao_final > matriz[2][0]){
             pos(11,0);
             printf("Voce entrou no ranking top3, digite seu nome ");
             scanf("%19s", nickname_3);
             matriz[2][0] = pontuacao_final;
        }
        if(color_pc[0] == r_user && color_pc[1] == g_user && color_pc[2] == b_user){
            tentativas = 0;
            pos(13, 0);
            printf("PARABENS, VOCE VENCEU \n");
            printf("Ranking Top 3 \n 1- %f  \n 2- %f \n 3- %f \n", matriz[0][0], matriz[1][0], matriz[2][0]);
            printf("Deseja jogar novamente? Digite 1 para sim ou 0 para nao "); 
            scanf("%i", &continuar_jogando);
            if(continuar_jogando == 1){
                limpa();
                goto INICIO_GAME;
            }else{
            printf("OBRIGADO PELA JOGATINA, VOLTE SEMPRE");
        }
        }else{
            pos(13, 0);
            printf("Ranking Top 3 \n 1- %s ... %.2f \n 2- %s ... %.2f \n 3- %s ... %.2f \n",nickname_1, matriz[0][0], nickname_2, matriz[1][0], nickname_3, matriz[2][0]);
            printf("\nOs numeros eram: Red %d Green %d Blue %d \n", color_pc[0], color_pc[1], color_pc[2]);
            printf("Voce perdeu, deseja jogar novamente? Digite 1 para sim ou 0 para nao ");
            scanf("%i", &continuar_jogando);
            if(continuar_jogando == 1){
                tentativas = 0;
                limpa();
                goto INICIO_GAME;
            }else{
                printf("OBRIGADO PELA JOGATINA, VOLTE SEMPRE \n");
            }
        }
}