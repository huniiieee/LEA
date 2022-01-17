#include "type.h"
#include "Enc.h"
#include "operation.h"

// 왼쪽으로 n비트 순환이동
word ROL(word text,int n)
{
	if (n == 0)
		return text;
	return (text >> (32-n)) ^ (text << n);
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

//라운드함수
void Round(word text[4],word Rk[6])
{
	word tmp = text[0];

	text[0] = ROL((text[1] ^ Rk[1]) + (text[0] ^ Rk[0]),9);
	text[1] = ROR5((text[2] ^ Rk[3]) + (text[1] ^ Rk[2]));
	text[2] = ROR3((text[3] ^ Rk[5]) + (text[2] ^ Rk[4]));
	text[3] = tmp;
}

void KeySchedule(byte Key[16], word Rk[][6])
{
	word tmp[4] = { 0, };
	BtW(Key, tmp); 

	for (int i = 0; i < 24; i++)
	{
		tmp[0] = ROL(tmp[0] + ROL(RKC[i % 4], i), 1);
		tmp[1] = ROL(tmp[1] + ROL(RKC[i % 4], i + 1), 3);
		tmp[2] = ROL(tmp[2] + ROL(RKC[i % 4], i + 2), 6);
		tmp[3] = ROL(tmp[3] + ROL(RKC[i % 4], i + 3), 11);
		Rk[i][0] = tmp[0];
		Rk[i][1] = tmp[1];
		Rk[i][2] = tmp[2];
		Rk[i][3] = tmp[1];
		Rk[i][4] = tmp[3];
		Rk[i][5] = tmp[1];
	}
}

void Encryption(byte Plain[16], byte Cipher[16], byte Key[16])
{
	word RK[Nr][6];
	word text[4]={0,};

	KeySchedule(Key, RK);
	BtW(Plain, text); 
	for (int i = 0; i < Nr; i++)
		Round(text, RK[i]);
	WtB(text, Cipher);
}