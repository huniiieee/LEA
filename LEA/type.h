#ifndef _TYPE_H_
#define _TYPE_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

//평문 또는 암호문을 구성하는 바이트의 개수
#define Nb 16

//비밀키를 구성하는 바이트의 개수
#define Nk 16

//라운드 수(Nk가 16이면 24, 24이면,28, 그리고 32이면 32)
#define Nr 24

typedef uint8_t byte;
typedef uint32_t word;

static word RKC[8] = { 0xc3efe9db,0x44626b02,0x79e27c8a,0x78df30ec,0x715ea49e,0xc785da0a,0xe04ef22a,0xe5c40957 };


#endif