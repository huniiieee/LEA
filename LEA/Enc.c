#include "type.h"
#include "Enc.h"
#include "operation.h"



//라운드함수
#if 0
void Enc_Round(word text[4], word Rk[6])
{
	word tmp = text[0];
	byte tmp2[4] = { 0, };
	byte tmp3[4] = { 0, };
	word tmp4 = 0;
	byte carry = 0;
	text[1] ^= Rk[1];
	text[0] ^= Rk[0];
	
	for (int i = 0; i < 4; i++)
		tmp2[i] = (text[1] >> (8 * (i % 4))) & 0xff;
	
	for (int i = 0; i < 4; i++)
		tmp3[i] = (text[0] >> (8 * (i % 4))) & 0xff;

	for (int i = 0; i < 4; i++)
	{
		tmp2[i] = tmp3[i]+tmp2[i]+carry;
		if (tmp2[i] <= tmp3[i])
			carry = 1;
		else
			carry = 0;
	}

	for (int i = 0; i < 4; i++)
		tmp4 += (word)tmp2[i] << (8 * (i % 4));
	text[1] ^= Rk[1];
	text[0] ^= Rk[0];
	text[0] = ROL(tmp4, 9);


	text[2] ^= Rk[3];
	text[1] ^= Rk[2];
	for (int i = 0; i < 4; i++)
		tmp2[i] = (text[2] >> (8 * (i % 4))) & 0xff;
	for (int i = 0; i < 4; i++)
		tmp3[i] = (text[1] >> (8 * (i % 4))) & 0xff;

	carry = 0;
	tmp4 = 0;
	for (int i = 0; i < 4; i++)
	{
		tmp2[i] = tmp3[i] + tmp2[i] + carry;
		if (tmp2[i] <= tmp3[i])
			carry = 1;
		else
			carry = 0;
	}

	for (int i = 0; i < 4; i++)
		tmp4 += (word)tmp2[i] << (8 * (i % 4));

	text[2] ^= Rk[3];
	text[1] ^= Rk[2];
	text[1] = ROR5(tmp4);

	
	text[3] ^= Rk[5];
	text[2] ^= Rk[4];
	for (int i = 0; i < 4; i++)
		tmp2[i] = (text[3] >> (8 * (i % 4))) & 0xff;
	for (int i = 0; i < 4; i++)
		tmp3[i] = (text[2] >> (8 * (i % 4))) & 0xff;

	carry = 0;
	tmp4 = 0;
	for (int i = 0; i < 4; i++)
	{
		tmp2[i] = tmp3[i] + tmp2[i] + carry;
		if (tmp2[i] <= tmp3[i])
			carry = 1;
		else
			carry = 0;
	}

	for (int i = 0; i < 4; i++)
		tmp4 += (word)tmp2[i] << (8 * (i % 4));

	text[3] ^= Rk[5];
	text[2] ^= Rk[4];
	text[2] = ROR3(tmp4);

	text[3] = tmp;
}
#endif
#if 1
void Enc_Round(word text[4], word Rk[6])
{
	word tmp = text[0];

	text[0] = ROL((text[1] ^ Rk[1]) + (text[0] ^ Rk[0]), 9);
	text[1] = ROR5((text[2] ^ Rk[3]) + (text[1] ^ Rk[2]));
	text[2] = ROR3((text[3] ^ Rk[5]) + (text[2] ^ Rk[4]));
	text[3] = tmp;
}
#endif

void Enc_KeySchedule(byte Key[16], word Rk[][6])
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
	printf("%08x\n", Rk[23][0]);
}

void Encryption(byte Plain[16], byte Cipher[16], byte Key[16])
{
	word RK[Nr][6];
	word text[4]={0,};

	Enc_KeySchedule(Key, RK);
	BtW(Plain, text); 
	for (int i = 0; i < Nr; i++)
		Enc_Round(text, RK[i]);
	WtB(text, Cipher);
}