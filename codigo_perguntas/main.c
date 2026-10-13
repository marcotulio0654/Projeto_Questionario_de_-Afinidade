#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    char *areas[4] = {"TI", "Mecanica", "Eletrica", "Culinaria"};

    char *pergunta[28] =
    {
        "Você tem disciplina para seguir regras rígidas de segurança?",
        "A água conduz eletricidade?",
        "Você tem disciplina para trabalhar constantemente utilizando EPIs",
        "Você se sente confortável em realizar trabalhos em altura?",
        "Você tem facilidade com identificação de cores/símbolos e seus significados?",
        "6",
        "7",
        "Você tem paciência e facilidade para lidar com ferramentas manuais?",
        "Andar com o carro sempre na reserva de combustível pode estragar a bomba de combustível?",
        "Você tem facilidade com desmontar um objeto e montar novamente do mesmo jeito?",
        "Você tem receio com se sujar de óleo, graxa e/ou semelhantes?",
        "Você tem bom ouvido para identificar leves alterações em ritmos ou tons?",
        "13",
        "14",
        "Você consegue lidar bem com passar várias horas do dia sentado em frente a um computador?",
        "Usar a mesma senha para todas as minhas contas na internet é seguro?",
        "Você gosta de jogos que exigem pensamento lógico?",
        "Você tem paciência de testar e aprender por conta própria?",
        "Você tem facilidade se colocar em situação de pensar sobre um assunto como se não soubesse nada sobre ele?",
        "20",
        "21",
        "Você consegue lidar bem com críticas diretas e prazos apertados?",
        "Pode colocar vasilhas de vidro temperado dentro do micro-ondas?",
        "Você consegue trabalhar em um ambiente quente por muito tempo?",
        "Você tem facilidade em trabalhar em grupo?",
        "Você consegue trabalhar sob grandes exigências e/ou criticas diretas?",
        "27",
        "28"
    };

    int area_pergunta[28] =
    {
        2,
        2,
        2,
        2,
        2,
        2,
        2,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        3,
        3,
        3,
        3,
        3,
        3,
        3
    };

    int pontos[4] = {0};
    int r = 0;
    int max = 0;
    int total = 28;

    printf("responda com 1 [sim] ou 0 [nao]");

           for (int i = 0; i < total; i++)
{
    printf("\n\n%d) %s ", i + 1, pergunta[i]);

        if (scanf("%d", &r) != 1 || (r != 0 && r != 1))
        {
            printf("entrada invalida");

        }

           pontos[area_pergunta[i]] += r;
    }

    for (int i = 1; i < 4; i++)
{
    if (pontos[i] > pontos[max])
        {
            max = i;
        }
    }

    printf("\nMaior afinidade: %s (%d pontos)", areas[max], pontos[max]);

           for (int i = 0; i < 4; i++)
{
    printf("\n%s: %d", areas[i], pontos[i]);
}

return 0;
}
