#include "operation.h"

//����Ʈ �迭�� ���� ���� ����迭 ����
void BtW(byte plain[Nb],word text[Nb/4])
{
	for (int i = 0; i < Nb / 4; i++)
		text[i] = 0;
	for (int i = 0; i < Nb; i++)
		text[i / 4] += (word)plain[i] << (8 * (i % 4));
}

//���� �迭�� ���� ���� ����Ʈ�迭 ����
void WtB(word text[Nb / 4], byte cipher[Nb])
{
	for (int i = 0; i<Nb; i++)
		cipher[i] = (text[i / 4] >> (8 * (i % 4))) & 0xff;
}

