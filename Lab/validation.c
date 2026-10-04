#include <wchar.h>
#include <wctype.h>
#include "validation.h"

unsigned verifyText(wchar_t *s, const wchar_t *ABC){
    for (int i = 0; i < wcslen(s); i++ )if (wcschr(ABC, towupper(s[i])) == NULL) return 0;

    return 1;
}

void removeSpaces(wchar_t *text){
    int j = 0;

    for(int i = 0; text[i] != 0; i++){
        if(!iswspace(text[i])){
            text[j] = text[i];
            j++;
        }
    }

    text[j] = L'\0';
}