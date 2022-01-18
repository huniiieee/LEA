#include "operation.h"
#include "type.h"

void Dec_Round(word text[4], word Rk[6])
{
	word tmp[4] = { 0, };
	memcpy(tmp, text, 16);

	text[0] = tmp[3];
	text[1] = (ROR9(tmp[0]) - (text[0] ^ Rk[0])) ^ Rk[1];
	text[2] = (ROL((tmp[1]),5) - (text[1] ^ Rk[2])) ^ Rk[3];
	text[3]= (ROL((tmp[2]),3) - (text[2] ^ Rk[4])) ^ Rk[5];
}

void Dec_KeySchedule(byte Key[16], word Rk[][6])
{
	word tmp[4] = { 0, };
	BtW(Key, tmp);

	for (int i = 0; i < 24; i++)
	{
		tmp[0] = ROL(tmp[0] + ROL(RKC[i % 4], i), 1);
		tmp[1] = ROL(tmp[1] + ROL(RKC[i % 4], i + 1), 3);
		tmp[2] = ROL(tmp[2] + ROL(RKC[i % 4], i + 2), 6);
		tmp[3] = ROL(tmp[3] + ROL(RKC[i % 4], i + 3), 11);
		Rk[23 - i][0] = tmp[0];
		Rk[23 - i][1] = tmp[1];
		Rk[23 - i][2] = tmp[2];
		Rk[23 - i][3] = tmp[1];
		Rk[23 - i][4] = tmp[3];
		Rk[23 - i][5] = tmp[1];
	}
}
void Decryption(byte Cipher[16], byte Plain[16], byte Key[16])
{
	word RK[Nr][6];
	word text[4] = { 0, };

	Dec_KeySchedule(Key, RK);
	BtW(Cipher, text);
	for (int i = 0; i < Nr; i++)
		Dec_Round(text, RK[i]);
	WtB(text, Plain);
}