#ifndef _TYPE_H_
#define _TYPE_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

//�� �Ǵ� ��ȣ���� �����ϴ� ����Ʈ�� ����
#define Nb 16

//���Ű�� �����ϴ� ����Ʈ�� ����
#define Nk 16

//���� ��(Nk�� 16�̸� 24, 24�̸�,28, �׸��� 32�̸� 32)
#define Nr 24

typedef uint8_t byte;
typedef uint32_t word;

static word RKC[8] = { 0xc3efe9db,0x44626b02,0x79e27c8a,0x78df30ec,0x715ea49e,0xc785da0a,0xe04ef22a,0xe5c40957 };


#endif