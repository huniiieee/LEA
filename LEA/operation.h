#ifndef _OPERATION_H_
#define _OPERATION_H_



#include "type.h"

word ROL(word text, int n);
word ROR5(word text);
word ROR3(word text);
word ROR9(word text);
void BtW(byte plain[Nb], word text[Nb / 4]);
void WtB(word text[Nb / 4], byte cipher[Nb]);

#endif