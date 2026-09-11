#include <wchar.h>
#include <stdlib.h>
#include <wctype.h>
#include "options.h"
#include "../validation.h"

wchar_t ABC[100]; 
wchar_t text_input[100];
int k1;
wchar_t k2[100]; 

void initCEAZAR(const wchar_t *cABC){
    wcscpy(ABC, cABC);
    k2[0] = '\0';
    k1 = 0;
    text_input[0] = '\0';
}

void inputText(const wchar_t *cABC){
    wint_t c;

    do {
        system("clear");
        wprintf(L"Input text: ");

        wscanf(L"%99ls", text_input);

        if(verifyText(text_input,cABC)){
            while ((c = getwchar()) != L'\n' && c != WEOF);       
            for (int i = 0; i < wcslen(text_input); i++) text_input[i] = towupper(text_input[i]); 
            break;
        }

        wprintf(L"WARNING USE VALID letters\n\n");

        while ((c = getwchar()) != L'\n' && c != WEOF);       

        getwchar();
    } while(1);
}

void inputK1(){
    wint_t c;

    do {
        system("clear");
        wprintf(L"Input key1: ");

        if(wscanf(L"%d", &k1) == 1 && k1 != 0 ) {
            while ((c = getwchar()) != L'\n' && c != WEOF);
            break;
        }

        wprintf(L"\n\nWARNING USE VALID NUMBER!!!");

        while ((c = getwchar()) != L'\n' && c != WEOF);

        getwchar();
    } while(1);
}

void inputK2(const wchar_t *cABC){
    wint_t c;

    do {
        system("clear");
        wprintf(L"Input alpahbet key: ");

        wscanf(L"%99ls", k2);   

       if(verifyText(k2,cABC) || wcslen(k2) <= 31 || wcslen(k2) >= 7){
            while((c = getwchar()) != L'\n' && c != WEOF);
            break;    
        }

        wprintf(L"WARNING USER ONLY LETTERS(MIN7/MAX31)!!! ");
 
        
        while((c = getwchar()) != L'\n' && c != WEOF);
        getwchar();
    } while(1);

    for (int i = 0; i < wcslen(k2); i++) k2[i] = towupper(k2[i]);


    int tj = 0; 
    wchar_t tempk2[32] = {0};


    for (int i = 0; i < wcslen(k2); i++){
        if(wcschr(tempk2, k2[i]) == NULL){
           tempk2[tj] = k2[i];
           tj++;
        } 
    }

    tempk2[tj] = L'\0';

    int n = wcslen(tempk2);

    for(int i = 0; i < n; i++){
        wchar_t s;

        s = ABC[i];
        
        if (ABC[i] == tempk2[i]) continue;

        ABC[i] = tempk2[i];

        for (int j = i + 1; j < 31; j++){
            if(tempk2[i] != ABC[j]){
                wchar_t temp = ABC[j];
                ABC[j] = s;
                s = temp;
            } else {
                ABC[j] = s;
                break;
            }
        }
    }

    wprintf(L"New alphabe: %ls\n", ABC);

    getwchar();
}

void makeCypher(){
    system("clear");
    wchar_t cypher[100];

    if(!k1 || !wcslen(text_input)){
        wprintf(L"PLEASE PROVIDE AT LEAST K1 AND TEXT!!!");
        getwchar();
        return;
    }

    int i = 0;

    while(text_input[i] != 0){
        int j = 0;

        while(ABC[j] != 0 ){
            if(ABC[j] == text_input[i]){
                cypher[i] = ABC[(j+k1)%31];
                break;
            }

            j++;
        }

        i++;
    }        

    cypher[i] = L'\0';

    wprintf(L"Result: %ls", cypher);

    getwchar();  
}

void decipher(){
    system("clear");
    wchar_t decypherTxt[100];

    if(!k1 || !wcslen(text_input)){
        wprintf(L"PLEASE PROVIDE AT LEAST K1 AND TEXT!!!");
        getwchar();
        return;
    }

    int i = 0;

    while(text_input[i] != 0){
        int j = 0;

        while(ABC[j] != 0 ){
            if(ABC[j] == text_input[i]){
                decypherTxt[i] = j-k1 >= 0 ? ABC[(j-k1)%31] : ABC[(j-k1)%31 + 31];
                break;
            }

            j++;
        }

        i++;
    }        

    decypherTxt[i] = L'\0';

    wprintf(L"Result: %ls", decypherTxt);

    getwchar();  
}

void resetABC(const wchar_t *cABC){
    system("clear");
    wprintf(L"ALPHABET && K2 RESETED SUCCESFULLY!!!");
    wcscpy(ABC, cABC);
    k2[0] = '\0';
    getwchar();
}

void show(){
    system("clear");
    wprintf(L"CURRENT CONFIG\n\n");
    wprintf(L"Text: %ls\n", text_input);
    wprintf(L"K1: %d\n", k1);
    wprintf(L"K2: %ls\n", k2);
    wprintf(L"Current Alphabet: %ls\n", ABC);

    getwchar();
}

