#include "type.h"



word ROL(word text, int n);
word ROR5(word text);
word ROR3(word text);
void Round(word text[4], word Rk[6]);
void KeySchedule(byte Key[16], word Rk[][6]);
void Encryption(byte Plain[16], byte Cipher[16], byte Key[16]);

