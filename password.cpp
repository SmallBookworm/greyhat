#include <windows.h>
#include <stdio.h>
#include <string.h>

#pragma comment(linker,"/section:.data,RWE")

unsigned char shellcode[] = "\x83\xec\x50"
"\x33\xdb"
"\x53"
"\x68\x74\x21\x20\x20"
"\x68\x61\x6c\x65\x72"
"\x8b\xc4"
"\x53"
"\x68\x6b\x20\x20\x20"
"\x68\x73\x68\x61\x72"
"\x68\x6f\x20\x6c\x79"
"\x68\x68\x65\x6c\x6c"
"\x8b\xcc"
"\x53"
"\x50"
"\x51"
"\x53"
"\xb8\x00\xa0\x0a\x77"
"\xff\xd0"
"\x53"
"\xb8\x080\x74\xb3\x76"
"\xff\xd0";

int main(int argc, char **argv)
{
    LoadLibrary("user32.dll");
    __asm
    {
        lea eax, shellcode
        call eax
    }
    return 0;
}
