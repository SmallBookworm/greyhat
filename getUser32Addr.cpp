#include <windows.h>
#include <iostream>

typedef void(*MYPROC)(LPTSTR);

int main(int argc, char *argv[]){
    HINSTANCE LibAddr,KernelAddr;
    MYPROC ProcAddr;

    // 获取User32.dll基地址
    LibAddr= LoadLibrary("user32.dll");
    printf("user32.dll 动态库基地址 = 0x%x \n", LibAddr);

    // 获取kernel32.dll基地址
    KernelAddr=LoadLibrary("kernel32.dll");
    printf("kernel32.dll 动态库基地址 = 0x%x \n", KernelAddr);

    // 获取MessageBox基地址
    ProcAddr=(MYPROC)GetProcAddress(LibAddr,"MessageBoxA");
    printf("MessageBoxA 函数相对地址 = 0x%x \n", ProcAddr);

    // 获取ExitProcess基地址
    ProcAddr=(MYPROC)GetProcAddress(KernelAddr, "ExitProcess");
    printf("ExitProcess 函数相对地址 = 0x%x \n", ProcAddr);

    system("pause");
    return 0;
}