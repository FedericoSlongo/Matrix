#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifdef _WIN32
    #include <windows.h>
#endif

int main(){
    //The variable that is going have the char, the varibale that as the delay if used and the color if the user wants it
    int num, delay, color;
    //If the user wants color
    char do_color;

    #ifdef _WIN32
        //Color changing for windows
        printf("Do you want a different color from default? [y,n]\n");
        scanf("%c",&do_color);
        if(do_color == 'y'){
            printf("Do you want: \n[0]Green\n[1]Red\n[2]Red\nIf you don't want to change the color just type a random number\n");
            scanf("%d",&color);
            switch (color)
            {
            case 0:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                break;
            case 1:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                break;
            case 2:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                break;
            
            default:
                break;
            }
        }
    #elif __linux__
        //Color changing for Linux
        printf("Do you want a different color from default? [y,n]\n");
        scanf("%c",&do_color);
        if(do_color == 'y'){
            printf("Do you want: \n[0]Yellow\n[1]Red\n[2]Green\n[3]Blue\n[4]Purple[5]Cyan\nIf you don't want to change the color just type a random number\n");
            scanf("%d",&color);
            switch (color)
            {
            case 0:
                printf("\033[33");
                break;
            case 1:
                printf("\033[31m");
                break;
            case 2:
                printf("\033[32m");
                break;
            case 3:
                printf("\033[34m");
                break;
            case 4:
                printf("\033[35m");
                break;
            case 5:
                printf("\033[36m");
                break;
            
            default:
                break;
            }
        }
    #endif

    printf("If you don't want a delay insert 0 (reccomended)\nIf you want to have a delay between printing of each new character insert the dalay (in second)\n");
    fflush(stdin);
    scanf("%d",&delay);
    fflush(stdin);

    while(true){
        //The code that randomly decides what character will be printed next
        switch (rand() % 3)
        {
        case 0:
            num = (rand() % (57 - 48 + 1)) + 48;
            break;
        case 1:
            num = (rand() % (90 - 65 + 1)) + 65;
            break;
        case 2:
            num = (rand() % (121 - 97 + 1)) + 97;
            break;
        default:
            break;
        }

        //Sleep even if set to 0 seems to introduce a delay so I just skip it if it's not needed
        if(!(delay == 0))
            _sleep(delay);

        //Prints things 
        for (int i = 0; i < (rand() % (30 - 3 + 1)) + 3; i++)
            printf(" ");
        
        printf("%c",num);
    }
    return 0;
}
