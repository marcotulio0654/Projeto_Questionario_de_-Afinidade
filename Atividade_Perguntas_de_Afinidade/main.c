#include <stdio.h>
#include <stdlib.h>

int main()
{
    char perguntas[4][100] = {"Eu tenho disciplina para seguir regras rígidas de segurança?","Eu tenho paciência e facilidade para lidar com ferramentas manuais?","Eu consigo me lidar bem com passar várias horas do dia sentado em frente a um computador?","Eu consigo me lidar bem com críticas diretas e prazos apertados?"};
    int referencia[4] = {0,1,2,3};
    int resposta[4] = {0,0,0,0};
    int ELE = 0;
    int MEC = 0;
    int TI = 0;
    int CUL = 0;
    for(int i = 0; i < 4; i++)
    {
        printf("%s\n", perguntas[i]);
        scanf("%d",&resposta[i]);
    }
    for(int i = 0; i < 4; i++)
    {
        if(referencia[i] == 0)ELE = ELE + resposta[i];
        if(referencia[i] == 1)MEC = MEC + resposta[i];
        if(referencia[i] == 2)TI = TI + resposta[i];
        if(referencia[i] == 3)CUL = CUL + resposta[i];
    }
    printf("\n--------------\n\n");
    printf("ELE = %d \nMEC = %d \nTI = %d \nCUL =  %d",ELE,MEC,TI,CUL);
    printf("\n--------------\n\n");
    if(ELE > MEC && ELE > TI && ELE > CUL) printf("Maior afinidade com Eletrica");
    if(MEC > ELE && MEC > TI && MEC > CUL) printf("Maior afinidade com Mecanica");
    if(TI > ELE && TI > MEC && TI > CUL) printf("Maior afinidade com TI");
    if(CUL > ELE && CUL > MEC && CUL > TI) printf("Maior afinidade com Culinaria");
    printf("\n\n");
    return 0;
}
