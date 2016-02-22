//
//  main.c
//  Array&String
//
//  Created by Supwin_mbp002 on 16/2/22.
//  Copyright © 2016年 chenlongjian. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    //数组与字符题目练习
//1设计一个算法，确定一个字符串的所有字符是否全都不同。假设不适用额外的数据结构
    printf("\n 1.设计一个算法，确定一个字符串的所有字符是否全都不同。假设不适用额外的数据结构");
    printf("\n判定字符是否重复出现。列举出来出现的次数");
    //如果是ascii码的话，就可以这样搞。。不是的话就得扩大空间
    char str[] = "abcdbflmhlb";
    int s = (int) strlen(str);
    printf("\n字符串长度：%lu",strlen(str));
    printf("\n输出的字符：%s",str);
    printf("\n输出的字符：%c",str[0]);
    printf("\n输出的字符的ascii码值：%d",str[0]);
    int strCheck[256] = {0};
    if (s>256) {
        printf("\n一定存在重复字符");
    }
    
    printf("\n\n开始搜索");
    for(int i= 0 ;i<s;i++)
    {
        if (strCheck[str[i]]) {
            strCheck[str[i]] = strCheck[str[i]]+1;
            printf("\n重复字符是：%c",str[i]);
            //            printf("\n重复出现次数---：%d",strCheck[str[i]]);
        }
        if (strCheck[str[i]]>=1) {
            
        }else
        {
            strCheck[str[i]] = 1;
        }
    }
    
    printf("\n\n搜索完毕。整理出重复字符和出现的次数");
    for (int j= 0; j<256; j++) {
        if (strCheck[j]>1) {
            char c = (char)j;
            
            printf("\n重复字符是---：%c",c);
            printf("\n重复出现次数---：%d",strCheck[j]);
        }
    }
    
    printf("\n\n");
    
    printf("\n\n");
    
    return 0;
}
