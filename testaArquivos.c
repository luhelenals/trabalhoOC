#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#include<math.h>

typedef struct arquivos
{
    char nome[20];
    int tamanho;
}arquivos;

int main ()
{
    //iniciando variáveis de tempo
    double ti, tf, tempo;
    ti = tf = tempo = 0;
    struct timeval tempoIni, tempoFim;
    gettimeofday(&tempoIni,NULL);

    arquivos testes[3];

    strcpy(testes[0].nome,"speakNowBinary.txt");
    testes[0].tamanho = 500;
    
    strcpy(testes[1].nome,"folkloreBinary.txt");
    testes[1].tamanho = 1080;

    strcpy(testes[2].nome,"fearlessBinary.txt");
    testes[2].tamanho = 700;

    int tam, i, j, m, n, num, x, y;

    for(y=0; y<3; y++)
    {
        tam = testes[y].tamanho;
        for(x=0; x<100; x++)//roda código 100 vezes
        {
            FILE *arquivo = fopen(testes[y].nome,"r");

            //verificando se arquivo foi aberto corretamente
            if(!arquivo)
            {
                printf("\nErro");
                return 0;
            }

            int in[tam][tam];
            float out[tam][tam], dist, menor; 

            for(i=0; i<tam; i++)
            {
                for(j=0; j<tam; j++)
                {
                    fscanf(arquivo,"%d",&num);
                    in[i][j] = num;
                }
            }

            for(i=0; i<tam; i++)
            {
                for(j=0; j<tam; j++)
                {
                    if(in[i][j] == 0)
                    {
                    //calcula distância entre 0 e o 1 mais próximo
                    menor = sqrt((tam-1)*(tam-1)*2); //menor inicia com a maior distância possível
                        for(m=0; m<tam; m++)
                        {
                            for(n=0; n<tam; n++)
                            {
                                if(in[m][n] == 1)
                                {
                                    dist = (float)sqrt((i-m)*(i-m) + (j-n)*(j-n));
                                    if(dist <= menor) menor = dist;
                                }
                            }
                        }
                        out[i][j] = menor;
                    }
                    else out[i][j] = 0;
                }
            }
            
            fclose(arquivo);

            //calculando tempo gasto
            gettimeofday(&tempoFim,NULL);
            tf = (double)tempoFim.tv_usec + ((double)tempoFim.tv_sec * 100000.0);
            ti = (double)tempoIni.tv_usec + ((double)tempoIni.tv_sec * 100000.0);
            tempo = (tf - ti)/1000;

            //armazenando tempo gasto num arquivo .txt
            char resultado[30];
            strcpy(resultado, "tempos_");
            strcat(resultado, testes[y].nome);

            FILE *arqTempo = fopen(resultado,"a");
            if(!arqTempo) printf("\nErro arquivo de tempo");
            else fprintf(arqTempo,"%.3f\n",tempo);
        }
    }
    return 0;
}