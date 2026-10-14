#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "");
    int pontos[4] = {0};
    int pontos_mem = 0;
    char *areas_mem = "";
    char nome[20] = "";
    int r = 0;
    int max = 0;
    int total = 32;
    do
    {
        char *areas[4] = {"TI", "Mecanica", "Eletrica", "Culinaria"};
        char *pergunta[32] =
        {
            /*01*/" Você tem disciplina para seguir regras rígidas de segurança?",
            /*02*/" Você prefere um trabalho com atividades práticas e manuais em vez de passar o dia todo digitando ou escrevendo? ",
            /*03*/" Você tem disciplina para trabalhar constantemente utilizando EPIs (Equipamento de Proteção Individual)? ",
            /*04*/" Você se sente confortável em realizar trabalhos em altura?",
            /*05*/" Você tem facilidade com identificação de cores/símbolos e seus significados?",
            /*06*/" Quando algo para de funcionar na sua casa, você prefere tentar consertar sozinho antes de chamar um profissional? ",
            /*07*/" Você reage bem sob pressão e fica calmo se acontecer algum imprevisto?",
            /*08*/" Você prefere a certeza de seguir normas técnicas rigorosas a ter que improvisar soluções no trabalho? ",
            /*09*/" Você tem paciência e facilidade para lidar com ferramentas manuais?",
            /*10*/" Você tem facilidade com desmontar um objeto e montar novamente do mesmo jeito?",
            /*11*/" Você tem receio com se sujar de óleo, graxa e/ou semelhantes?",
            /*12*/" Você tem bom ouvido para identificar leves alterações em ritmos ou tons?",
            /*13*/" Você tem bons olhos para achar defeitos mesmo como ambiente te atrapalhando?",
            /*14*/" Você tem disposição física para trabalhar em posições desconfortáveis?",
            /*15*/" Você tem o hábito de fazer pequenos consertos ou manutenções na sua própria casa ou veículo? ",
            /*16*/" É possível colocar 10 computadores abertos cima dessa mesa?",
            /*17*/" Você consegue lidar bem com passar várias horas do dia sentado em frente a um computador?",
            /*18*/" Usar a mesma senha para todas as minhas contas na internet NÂO é seguro?",
            /*19*/" Você gosta de jogos que exigem pensamento lógico?",
            /*20*/" Você tem paciência de testar e aprender por conta própria?",
            /*21*/" Você tem facilidade se colocar em situação de pensar sobre um assunto como se não soubesse nada sobre ele?",
            /*22*/" você tem paciência para achar pequenos erros?",
            /*23*/" Você tem paciência em ajudar pessoas que não tem conhecimento técnico e repetir a mesma coisa várias vezes? ",
            /*24*/" Se um amigo tem um problema no celular ou computador, você é a pessoa que tenta ajudar a resolver? ",
            /*25*/" Você consegue lidar bem com críticas diretas e prazos apertados?",
            /*26*/" Pode colocar vasilhas de vidro temperado dentro do micro-ondas?",
            /*27*/" Você consegue trabalhar em um ambiente quente por muito tempo?",
            /*28*/" Você tem facilidade em trabalhar em grupo?",
            /*29*/" Você consegue trabalhar sob grandes exigências e/ou criticas diretas?",
            /*30*/" você tem um nariz bom para sentir aromas?",
            /*31*/" Você tem criatividade para criar pratos/receitas novas?",
            /*32*/" Você se considera uma pessoa muito higiênica e cuidadosa?"
            /*33*/
            /*34*/
            /*35*/
            /*36*/

        };

        int area_pergunta[32] =
        {
            /*01*/2,
            /*02*/2,
            /*03*/2,
            /*04*/2,
            /*05*/2,
            /*06*/2,
            /*07*/2,
            /*08*/2,
            /*09*/1,
            /*10*/1,
            /*11*/1,
            /*12*/1,
            /*13*/1,
            /*14*/1,
            /*15*/1,
            /*16*/1,
            /*17*/0,
            /*18*/0,
            /*19*/0,
            /*20*/0,
            /*21*/0,
            /*22*/0,
            /*23*/0,
            /*24*/0,
            /*25*/3,
            /*26*/3,
            /*27*/3,
            /*28*/3,
            /*29*/3,
            /*30*/3,
            /*31*/3,
            /*32*/3
            /*33*/
            /*34*/
            /*35*/
            /*36*/

        };

        printf("Olá, bem-vindo à pesquisa de afinidade com os cursos de TI, Culinaria, Mecanica e Elétrica\n\n");
        printf("Por gentileza informe o seu nome:\n");
        fgets(nome,sizeof(nome),stdin);
        nome[strcspn(nome, "\n")] = '\0';
        printf("\n\n%s para prosseguir responda com 1 quando sua resposta for 'Sim' e 0 quando sua resposta for 'Não'.\nVamos começar!\n\n",nome);
        for (int i = 0; i < total; i++)
        {
            printf("\n\n%d) %s ", i + 1, pergunta[i]);
            scanf("%d", &r);
            if (r == 99)
            {
                printf("\n\n____________\n\nObrigado a todos os participantes\n\n____________\n\n");
                break;
            }
            else
            {
                if (r != 0 && r != 1)
                {
                    printf("entrada inválida");
                    i = i-1;
                }
                else
                {
                    pontos[area_pergunta[i]] += r;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if (pontos[i] > pontos[j])
                {
                    pontos_mem = pontos[i];
                    pontos[i] = pontos[j];
                    pontos[j] = pontos_mem;
                    pontos_mem = 0;
                    areas_mem = areas[i];
                    areas[i] = areas[j];
                    areas[j] = areas_mem;
                    areas_mem = 0;
                }
            }
        }
        printf("\n\n____________\n\n");
        printf("\n%s seu resultado apresentou maior afinidade com: %s (%d pontos)\n\n", nome, areas[0], pontos[0]);

        for (int i = 0; i < 4; i++)
        {
            for(int j = 0; j < pontos[i]; j++)
            {
                printf("##");
            }
            printf(" - %s: %d\n", areas[i], pontos[i]);
        }
        printf("\n\n____________\n\nObrigado pela participação\n\n____________\n\n");
        printf("Digite 1 para um novo teste");
        scanf("%s", &pontos);
        while(getchar() != '\n');
        system("cls");
    }
    while(r != 99);
    scanf("%d", pontos);
    return 0;
}
