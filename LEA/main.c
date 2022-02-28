#include "type.h"
#include "operation.h"
#include "Enc.h"
#include "Dec.h"

int main()
{
	//byte Key[16] = { 0x0f,0x1e,0x2d,0x3c,0x4b,0x5a,0x69,0x78,0x87,0x96,0xa5,0xb4,0xc3,0xd2,0xe1,0xf0 };

	byte Key[16] = { 0x2b,0x7e ,0x15 ,0x16 ,0x28 ,0xae ,0xd2 ,0xa6 ,0xab ,0xf7 ,0x15 ,0x88 ,0x09 ,0xcf ,0x4f ,0x3c };
	byte Plain[16] = { 0x65 ,0x23 ,0xB2 ,0x1E ,0xEB ,0xC1 ,0xA4 ,0x1A ,0x27 ,0x05 ,0x0D ,0x1F ,0xDF ,0x01 ,0x56 ,0x0A };
	byte Cipher[16] = { 0, };
	printf("Plain: ");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", Plain[i]);
	}
	printf("\nKey: ");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", Key[i]);
	}
	printf("\n----------------------------Encryption----------------------------");
	printf("\nCipher: ");
	Encryption(Plain, Cipher, Key);
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", Cipher[i]);
	}
	printf("\nKey: ");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", Key[i]);
	}
	printf("\n----------------------------Decryption----------------------------");
	printf("\nPlain: ");
	Decryption(Cipher, Plain, Key);
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", Plain[i]);
	}

	return 0;
}