#include <wchar.h>
#include <stdlib.h>
#include "../utils.h"
#include "options.h"

void vigenere(wchar_t *choice, const wchar_t *cABC){
    const int n = 100; 
    wchar_t message[n];
    wchar_t cypher[n];
    wchar_t key[n];

    initViginere(message);

    while(1){
        system("clear");

        wprintf(L"VIGENERE MENU\n1)Mesaj\n2)Criptogramă\n3)Cheie\n4)Criptare\n5)Decriptare\n6)Show current config\nEsc)Go back\n\n");

        iChoice(choice);
        
        switch (*choice)
        {
            case '1':
                textInputVigenere(cABC, message, n);
                break;
            case '2':
                textInputVigenere(cABC, cypher, n);
                break;
            case '3':
                keyInputVigenere(cABC,key,n);
                break;
            case '4':
                cypherVigenre(cABC,message,key,cypher);
                break;
            case '5':
                decypherVigenere(cABC,message,key,cypher);
                break;
            case '6':
                showViginere(message, cypher, key);
                break;
            case 27: return;  
        }
    } 
}