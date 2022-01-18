#ifndef _ENC_H_
#define _ENC_H_



#include "type.h"


void Enc_Round(word text[4], word Rk[6]);
void Enc_KeySchedule(byte Key[16], word Rk[][6]);
void Encryption(byte Plain[16], byte Cipher[16], byte Key[16]);

#endif