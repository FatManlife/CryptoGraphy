#include <wchar.h>
#include <stdlib.h>
#include "options.h"
#include "../utils.h"

void cezar(wchar_t *choice, const wchar_t *cABC){
    initCEAZAR(cABC);

    while(1){
        system("clear");

        wprintf(L"CEZAR MENU\n1)Text\n2)First key(nr)\n3)Second key(Text)\n4)Cypher\n5)Decypher\n6)Reset Alphabet\n7)Show current config\nEsc)Go back\n\n");

        iChoice(choice);
        
        switch (*choice)
        {
            case '1':
                inputText(cABC);
                break;
            case '2':
                inputK1();
                break;
            case '3':
                inputK2(cABC);
                break;
            case '4':
                makeCypher();
                break;
            case '5':
                decipher();
                break;
            case '6':
                resetABC(cABC);
                break;
            case '7':
                show();
                break;
            case 27: return;  
        }
    } 
}