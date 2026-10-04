#include <wchar.h>
#include <stdlib.h>
#include "options.h"
#include "../utils.h"

void cezar(wchar_t *choice, const wchar_t *cABC){
    wchar_t ABC[100]; 
    wchar_t text_input[100];
    int k1;
    wchar_t k2[100]; 

    initCEAZAR(cABC,k2,&k1,text_input,ABC);

    while(1){
        system("clear");

        wprintf(L"CEZAR MENU\n1)Text\n2)First key(nr)\n3)Second key(Text)\n4)Cypher\n5)Decypher\n6)Reset Alphabet\n7)Show current config\nEsc)Go back\n\n");

        iChoice(choice);
        
        switch (*choice)
        {
            case '1':
                inputText(cABC, text_input);
                break;
            case '2':
                inputK1(&k1);
                break;
            case '3':
                inputK2(cABC, k2, ABC);
                break;
            case '4':
                makeCypher(&k1, text_input, ABC);
                break;
            case '5':
                decipher(&k1, text_input, ABC);
                break;
            case '6':
                resetABC(cABC, ABC, k2);
                break;
            case '7':
                show(text_input, &k1, k2, ABC);
                break;
            case 27: return;  
        }
    } 
}