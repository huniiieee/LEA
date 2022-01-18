#include "operation.h"

// 왼쪽으로 n비트 순환이동
word ROL(word text, int n)
{
	if (n == 0)
		return text;
	return (text >> (32 - n)) ^ (text << n);
}

//오른쪽으로 5비트 순환이동
word ROR5(word text)
{
	return (text >> 5) ^ ((text & 0x1f) << 27);
}

//오른쪽으로 3비트 순환이동
word ROR3(word text)
{
	return (text >> 3) ^ ((text & 0x7) << 29);
}

//오른쪽으로 3비트 순환이동
word ROR9(word text)
{
	return (text >> 9) ^ ((text & 0x1ff) << 23);
}


//바이트 배열과 값이 같은 워드배열 생성
void BtW(byte plain[Nb],word text[Nb/4])
{
	for (int i = 0; i < Nb / 4; i++)
		text[i] = 0;
	for (int i = 0; i < Nb; i++)
		text[i / 4] += (word)plain[i] << (8 * (i % 4));
}

//워드 배열과 값이 같은 바이트배열 생성
void WtB(word text[Nb / 4], byte cipher[Nb])
{
	for (int i = 0; i<Nb; i++)
		cipher[i] = (text[i / 4] >> (8 * (i % 4))) & 0xff;
}

