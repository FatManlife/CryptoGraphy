#include<wchar.h>
#include "utils.h"

void iChoice(wchar_t *choice){
    wprintf(L"Your choice: ");
    *choice = getwchar();

    wint_t c;
    while((c = getwchar()) != L'\n' && c != WEOF);
}