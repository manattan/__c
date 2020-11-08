#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <unistd.h>

// ２人で行う指スマの勝率を考える.
// 100回でなく、10^n回を考えるとさらに1/2になっていくと考えられるが、非常に結果が出るのが遅くなる.
// def go() と def push() は同じである

// 「指スマ 〇！」の発言数字を返す
int go(int x)
{
    // xは場に存在する指の数
    srand((unsigned int)time(NULL));
    int fin;
    fin = rand() % (x + 1);
    sleep(1);
    return fin;
}

// あげる指数をランダムで返す
int push(int x)
{
    // xは自分の指の本数
    srand((unsigned int)time(NULL));
    int fin;
    fin = rand() % (x + 1);
    sleep(1);
    return fin;
}

// 一回のターンを行う。自分の本数しか変わらないので自分の指の本数変化を出力する
int turn(int me, int you)
{
    // meは自分の指の本数、youは相手の指の本数

    // 発言された指の本数
    int get;
    get = go(me + you);

    //それぞれがあげた本数
    int mefin, youfin, allfin;
    mefin = push(me);
    youfin = push(you);
    allfin = mefin + youfin;

    if (allfin == get)
    {
        printf("win!\n");
        me -= 1;
    }

    return me;
}

int main(void)
{
    int a = 2, b = 2;
    // player=0でa,player=1でbが発言
    int player = 0;

    int wina = 0, winb = 0;
    for (int i = 0; i < 100; i++)
    {
        // 先攻後攻を交互にやる
        if (i % 2 == 0)
        {
            player = 0;
        }
        else
        {
            player = 1;
        }
        do
        {
            printf("現在,aさんは指%d本, bさんは指%d本あります.\n", a, b);
            if (player == 0)
            {
                printf("次はaの番です.\n");
                a = turn(a, b);
                player = 1;
            }
            else
            {
                printf("次はbの番です.\n");
                b = turn(b, a);
                player = 0;
            }
            printf("現在a=%d,b=%d\n", a, b);
        } while (a && b);

        if (a == 0)
        {
            printf("aの勝ち!\n");
            wina += 1;
        }
        else if (b == 0)
        {
            printf("bの勝ち!\n");
            winb += 1;
        }
    }

    printf("100回繰り返した時、aは%d回勝ち,bは%d回勝ちました.\n", wina, winb);

    return 0;
}