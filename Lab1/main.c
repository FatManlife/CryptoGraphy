#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<wchar.h>
#include<wctype.h>
#include "utils.h"
#include "./cezar/menu.h"

wchar_t choice; 
const wchar_t *cABC = L"AĂÂBCDEFGHIÎJKLMNOPQRSȘTȚUVWXYZ";

int main (){
    setlocale(LC_ALL, "en_US.UTF-8"); 

    while (1) {
        system("clear");

        wprintf(L"LAB MENU\n1)Cezar cypher\nEsc)Exit\n\n");

        iChoice(&choice);

        switch(choice){
            case '1':
                cezar(&choice, cABC);
                break;
            case 27: exit(0); 
        }
    }

    return 0;
}

