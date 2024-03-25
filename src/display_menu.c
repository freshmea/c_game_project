#include <stdio.h>
#include <stdlib.h>

int display_menu()
{
    int menu;

    system("clear");
    printf("\t\t\t  ＿＿＿＿＿\n\t\t\t／＼＿＿＿＿＼\n\t\t\t|￣＼∩・ω・) ＼\n\t\t\t|　  ｜￣￣∪￣｜\n");
    printf("\t\t|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n\t\t   TEAM HM2J_c's TETRIS GAME\n\t\t|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n\t\t          \\ (•◡•) /\n\t\t           \\     /\n");

    
    printf("\t\t------------------------------\n");
    printf("\t\t|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n   \t\t\t  GAME MENU\n\t\t|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
    printf("\t\t------------------------------\n");

    printf("\t\t|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n\t\t   1. Game Start\n\t\t|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
    printf("\t\t|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n\t\t   2. Search history\n\t\t|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
    printf("\t\t|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n\t\t   3. Record Output\n\t\t|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
    printf("\t\t|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n\t\t   4. Quit\n\t\t|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");

    printf("\n");

    printf("             ／＞　 フ\n             | 　_　_|\n          ／` ミ＿xノ\n         /　　　　 |\n        /　 ヽ　　 ﾉ        へ    |、 ♡      |、\n       │　　|　|　|    ૮  -  ՛ ) (˚ˎ 。7    (`  - 7\n  ／￣|　　 |　|　|      / ⁻ ៸|  |、˜〵     |、⁻〵\n  (￣ヽ＿_ヽ_)__)   乀 (ˍ, ل ل   じしˍ,)ノ  じしˍ,)ノ\n  ＼二)\n");
    //printf("\t\t      ┏━━┓┏━━┓┏━━┓┏┓┏┓\n\t\t      ┗━┓┃┃┏┓┃┗━┓┃┃┃┃┃\n\t\t      ┏━┛┃┃┃┃┃┏━┛┃┃┗┛┃\n\t\t      ┃┏━┛┃┃┃┃┃┏━┛┗━┓┃\n\t\t      ┃┗━┓┃┗┛┃┃┗━┓  ┃┃\n\t\t      ┗━━┛┗━━┛┗━━┛  ┗┛\n");

    printf("Select The Number: ");
    scanf("%d", &menu);
    return menu;
}
