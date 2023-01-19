#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//This program was  made for linux and will not work on windows
int main(){
    while(true){
        int num = (rand() % (57 - 48 + 1)) + 48;
        printf("%d\n",num);
    }
    return 0;
}