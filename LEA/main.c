#include "type.h"
#include "operation.h"
#include "Enc.h"
#include "Dec.h"

int main()
{
	byte Key[16] = { 0x0f,0x1e,0x2d,0x3c,0x4b,0x5a,0x69,0x78,0x87,0x96,0xa5,0xb4,0xc3,0xd2,0xe1,0xf0 };
	byte Plain[16] = { 0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f };
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