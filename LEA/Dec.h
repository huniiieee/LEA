#ifndef _DEC_H_
#define _DEC_H_

#include "type.h"


void Dec_Round(word text[4], word Rk[6]);
void Dec_KeySchedule(byte Key[16], word Rk[][6]);
void Decryption(byte Cipher[16], byte Plain[16], byte Key[16]);


#endif