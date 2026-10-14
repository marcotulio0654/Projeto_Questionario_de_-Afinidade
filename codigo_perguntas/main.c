#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    char *areas[4] = {"TI", "Mecanica", "Eletrica", "Culinaria"};

    char *pergunta[28] =
    {
        /*01*/"Você tem disciplina para seguir regras rígidas de segurança?",
        /*02*/"A água conduz eletricidade?",
        /*03*/"Você tem disciplina para trabalhar constantemente utilizando EPIs",
        /*04*/"Você se sente confortável em realizar trabalhos em altura?",
        /*05*/"Você tem facilidade com identificação de cores/símbolos e seus significados?",
        /*06*/"Você reage bem sob pressão e fica calmo se acontecer algum imprevisto?",
        /*07*/"A tomada residencial padrão no Brasil possui tensão de 127V ou 220V?",
        /*08*/"Você tem paciência e facilidade para lidar com ferramentas manuais?",
        /*09*/"Andar com o carro sempre na reserva de combustível pode estragar a bomba de combustível?",
        /*10*/"Você tem facilidade com desmontar um objeto e montar novamente do mesmo jeito?",
        /*11*/"Você tem receio com se sujar de óleo, graxa e/ou semelhantes?",
        /*12*/"Você tem bom ouvido para identificar leves alterações em ritmos ou tons?",
        /*13*/"Você tem disposição física para trabalhar em posições desconfortáveis?",
        /*14*/"A embreagem serve para ligar e desligar o motor das rodas?",
        /*15*/"Você consegue lidar bem com passar várias horas do dia sentado em frente a um computador?",
        /*16*/"Usar a mesma senha para todas as minhas contas na internet é seguro?",
        /*17*/"Você gosta de jogos que exigem pensamento lógico?",
        /*18*/"Você tem paciência de testar e aprender por conta própria?",
        /*19*/"Você tem facilidade se colocar em situação de pensar sobre um assunto como se não soubesse nada sobre ele?",
        /*20*/"Você tem paciência em ajudar pessoas que não tem conhecimento técnico e repetir a mesma coisa várias vezes?",
        /*21*/"Um SSD é geralmente mais rápido para ler e gravar dados do que um HD tradicional?",
        /*22*/"Você consegue lidar bem com críticas diretas e prazos apertados?",
        /*23*/"Pode colocar vasilhas de vidro temperado dentro do micro-ondas?",
        /*24*/"Você consegue trabalhar em um ambiente quente por muito tempo?",
        /*25*/"Você tem facilidade em trabalhar em grupo?",
        /*26*/"Você consegue trabalhar sob grandes exigências e/ou criticas diretas?",
        /*27*/"Você tem criatividade para criar pratos/receitas novas?",
        /*28*/"Você se considera uma pessoa muito higiênica e cuidadosa?"
    };

    int area_pergunta[28] =
    {
        /*01*/2,
        /*02*/2,
        /*03*/2,
        /*04*/2,
        /*05*/2,
        /*06*/2,
        /*07*/2,
        /*08*/1,
        /*09*/1,
        /*10*/1,
        /*11*/1,
        /*12*/1,
        /*13*/1,
        /*14*/1,
        /*15*/0,
        /*16*/0,
        /*17*/0,
        /*18*/0,
        /*19*/0,
        /*20*/0,
        /*21*/0,
        /*22*/3,
        /*23*/3,
        /*24*/3,
        /*25*/3,
        /*26*/3,
        /*27*/3,
        /*28*/3
    };

    int pontos[4] = {0};
    int pontos_mem = 0;
    char *areas_mem = "";
    int r = 0;
    int max = 0;
    int total = 28;

    printf("responda com 1 [sim] ou 0 [nao]");

    for (int i = 0; i < total; i++)
    {
        printf("\n\n%d) %s ", i + 1, pergunta[i]);
        scanf("%d", &r);
        if (r == 99) return 0;
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

    printf("\nMaior afinidade: %s (%d pontos)\n\n", areas[0], pontos[0]);

    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < pontos[i]; j++)
        {
            printf("##");
        }
        printf(" - %s: %d\n", areas[i], pontos[i]);
    }

    scanf("%d", pontos);
    return 0;
}
