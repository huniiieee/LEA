#include "operation.h"

// �������� n��Ʈ ��ȯ�̵�
word ROL(word text, int n)
{
	if (n == 0)
		return text;
	return (text >> (32 - n)) ^ (text << n);
}

//���������� 5��Ʈ ��ȯ�̵�
word ROR5(word text)
{
	return (text >> 5) ^ ((text & 0x1f) << 27);
}

//���������� 3��Ʈ ��ȯ�̵�
word ROR3(word text)
{
	return (text >> 3) ^ ((text & 0x7) << 29);
}

//���������� 3��Ʈ ��ȯ�̵�
word ROR9(word text)
{
	return (text >> 9) ^ ((text & 0x1ff) << 23);
}


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

