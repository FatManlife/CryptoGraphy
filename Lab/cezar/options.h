#ifndef OPTIONS_CEZAR_H
#define OPTIONS_CEZAR_H

void inputText(const wchar_t *cABC, wchar_t *text_input);
void inputK1(int *k1);
void inputK2(const wchar_t *cABC, wchar_t *k2, wchar_t *ABC);
void makeCypher(int *k1 ,wchar_t *text_input, wchar_t *ABC);
void decipher(int *k1, wchar_t *text_input, wchar_t *ABC);
void resetABC(const wchar_t *cABC, wchar_t *ABC, wchar_t *k2);
void show(wchar_t *text_input, int *k1, wchar_t *k2, wchar_t *ABC);
void initCEAZAR(const wchar_t *cABC, wchar_t *k2, int *k1, wchar_t *text_input, wchar_t *ABC);

#endif