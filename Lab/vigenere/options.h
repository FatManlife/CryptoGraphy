#ifndef OPTIONS_VIGENRE_H
#define OPTIONS_VIGENRE_H

void textInputVigenere(const wchar_t *cABC, wchar_t *message, int n);
void initViginere(wchar_t *message);
void showViginere(wchar_t *message, wchar_t *cypher, wchar_t *key);
void keyInputVigenere(const wchar_t *cABC, wchar_t *key, const int n);
void cypherVigenre(const wchar_t *ABC, wchar_t *message, wchar_t *key, wchar_t *cypher);
void decypherVigenere(const wchar_t *ABC, wchar_t *message, wchar_t *key, wchar_t *cypher);

#endif