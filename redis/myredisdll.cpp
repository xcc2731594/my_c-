
#define BUILD_DLL
#include "pch.h"
#include "demoDLL.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hiredis.h>
#pragma comment(lib,"D:/redis-5.0.14.1/msvs/x64/Release/hiredis.lib")
#pragma comment(lib,"D:/redis-5.0.14.1/msvs/x64/Release/Win32_Interop.lib")

int addNum(int a, float b[])
{
    redisContext* c = redisConnect("127.0.0.1", 6379);
    if (c->err)
    {
        printf("Connect to redisServer faile:%s\n", c->errstr);
    }
    const char *command1 = "set name \0";
    char* command = new char[10000000];
    

    const char* pt = command;
    while (*(command1) != '\0')
    {
        *(command++) = *(command1++);
    }
    

    //拼接字符串
    char  temp[10] =  {};
    for (int i = 0; i < a; i++)
    {
        sprintf_s(temp, "%f", b[i]);
        for (int i = 0; i <4; i++)
        {
            *(command++) = temp[i];
        }
        *(command++) = ',';
        
    }

    *command = '\0';
    printf(pt);
    redisReply* r = (redisReply*)redisCommand(c, pt);
    printf("Successful!");
    return 0;
}

 
