#include <wchar.h>
#include <stdlib.h>
#include <wctype.h>
#include <stdio.h>
#include "../validation.h"

void initViginere(wchar_t *message, wchar_t *cypher, wchar_t *key){
    message[0] = '\0';
    cypher[0] = '\0';
    key[0] = '\0';
}

void textInputVigenere(const wchar_t *cABC, wchar_t *text, const int n){
    wint_t c;

    do {
        system("clear");
        wprintf(L"Input Text: ");

        fgetws(text, n, stdin);

        size_t len = wcslen(text);

        if (len > 0 && text[len - 1] == L'\n')
            text[len - 1] = L'\0';

        removeSpaces(text);

        if(verifyText(text,cABC) && wcslen(text) > 0 ){
            for (int i = 0; i < wcslen(text); i++) text[i] = towupper(text[i]); 
            break;
        }

        wprintf(L"FOLOSIȚI LITERE VALIDE\n\n");

        while ((c = getwchar()) != L'\n' && c != WEOF);       

        getwchar();
    } while(1);
}

void keyInputVigenere(const wchar_t *cABC, wchar_t *key, const int n){
    wint_t c;

    do { system("clear");
        wprintf(L"Input Key: ");

        fgetws(key, n, stdin);

        size_t len = wcslen(key);

        if (len < 7){
            wprintf(L"CHEIA TREBUIE SĂ FIE MAI MARE DE 6 CARACTERE\n\n");
            getwchar();
            continue;
        }

        if (key[len - 1] == L'\n')
            key[len - 1] = L'\0';

        removeSpaces(key);

        if(verifyText(key,cABC) && wcslen(key) > 0 ){
            for (int i = 0; i < wcslen(key); i++) key[i] = towupper(key[i]); 
            break;
        }

        wprintf(L"FOLOSIȚI LITERE VALIDE\n\n");

        while ((c = getwchar()) != L'\n' && c != WEOF);       

        getwchar();
    } while(1);
}

void cypherVigenre(const wchar_t *ABC, wchar_t *message, wchar_t *key, wchar_t *cypher){
    system("clear");

    int la = wcslen(ABC);
    int lm = wcslen(message);
    int lk = wcslen(key); 

    if(lm == 0 || lk == 0){
        wprintf(L"INTRDOU MAI ÎNTÂNI CHEIA ȘI MESAJUL");
        return;
    }

    int ctr = 0;
    int n1 = lm/lk;
    int n2 = lm%lk;

    for(int i = 0, temp; i < n1; i++){
        for(int j = 0; j < lk; j++){
            temp = 0;

            for(int z = 0; z < la; z++){
                if(message[ctr] == ABC[z]){
                    temp = z;
                    break;
                }
            }

            for(int z = 0; z < la; z++){
                if(key[j] == ABC[z]){
                    cypher[ctr] = ABC[(z + temp)%31];
                    break;
                }
            }

            ctr++;
        }
    }

    for(int i = 0, temp; i < n2; i++){            
        temp = 0;

        for(int z = 0; z < la; z++){
            if(message[ctr] == ABC[z]){
                temp = z;
                break;
            }
        }

        for(int z = 0; z < la; z++){
            if(key[i] == ABC[z]){
                cypher[ctr] = ABC[(z + temp)%31];
                break;
            }
        }

        ctr++;
    }

    cypher[ctr] = '\0';

    wprintf(L"CRIPTAREA A FOST REALIZATĂ CU SUCCES\nCRIPTOGRAMA E %ls", cypher);

    getwchar();
}

void decypherVigenere(const wchar_t *ABC, wchar_t *message, wchar_t *key, wchar_t *cypher){
    system("clear");

    int la = wcslen(ABC);
    int lc = wcslen(cypher);
    int lk = wcslen(key); 

    if(lc == 0 || lk == 0){
        wprintf(L"INTRDOU MAI ÎNTÂNI CHEIA ȘI CRIPTOGRAMA");
        return;
    }

    int ctr = 0;
    int n1 = lc/lk;
    int n2 = lc%lk;

    for(int i = 0, temp; i < n1; i++){
        for(int j = 0; j < lk; j++){
            temp = 0;

            for(int z = 0; z < la; z++){
                if(cypher[ctr] == ABC[z]){
                    temp = z;
                    break;
                }
            }

            for(int z = 0; z < la; z++){
                if(key[j] == ABC[z]){
                    message[ctr] = ABC[(temp - z + 31)%31];
                    break;
                }
            }

            ctr++;
        }
    }

    for(int i = 0, temp; i < n2; i++){            
        temp = 0;

        for(int z = 0; z < la; z++){
            if(cypher[ctr] == ABC[z]){
                temp = z;
                break;
            }
        }

        for(int z = 0; z < la; z++){
            if(key[i] == ABC[z]){
                message[ctr] = ABC[(temp - z + 31)%31];
                break;
            }
        }

        ctr++;
    }

    message[ctr] = '\0';

    wprintf(L"DECRIPTAREA A FOST REALIZATĂ CU SUCCES\nMESAJUL E %ls", message);

    getwchar();
}



void showViginere(wchar_t *message, wchar_t *cypher, wchar_t *key){
    system("clear"); 
    wprintf(L"CONFIGURAȚII CURENTE: \n\n");
    wprintf(L"Mesaju: %ls\n", message);
    wprintf(L"Criptogramă: %ls\n", cypher);
    wprintf(L"Cheie: %ls\n", key);

    getwchar();
}