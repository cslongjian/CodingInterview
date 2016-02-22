//
//  main.c
//  Array&String
//
//  Created by Supwin_mbp002 on 16/2/22.
//  Copyright © 2016年 chenlongjian. All rights reserved.
//

#include <stdio.h>

void reverse(char* str);//2
void checkSame(char* str1,char* str2);//3
void checkEmptyChar(char* str1,int length);//4

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    //数组与字符题目练习
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
    printf("2.用C实现一个函数，反转一个null结尾的字符串");
    char *str2 = "abcd";
    reverse(str2);
    
    
    printf("\n\n");
    printf("3.给定两个字符串，确定其中一个字符串重新排列后，是否可以变为另一个字符串");
    char *str3_1 = "abcd";
    char *str3_2 = "baac";
//    这里有注意点：
//    1，空格，大小写是否包含其中
//    2，变位词，那么字符的长度是相等的。要作为优先判定条件之一
//    3，可以先自行排序，后再进行比较。不过这个得基于有直接排序的语言，Java可以
//    4，检查他们每个字符是否相等，用ascii去测试方案
    checkSame(str3_1,str3_2);
    
    printf("\n\n");
    printf("4.编写一个方法，将字符串中的空格全部替换为“&20”。假设字符的尾部有足够的空间，也知道字符的真是长度。");
    
    char *str_4 = "abc ddd b s";
    checkEmptyChar(str_4,11);
    
    printf("\n\n");
    
    return 0;
}

#pragma mark 第二题
void reverse(char *str)
{
    printf("\n");
    printf("\n输出反转前的字符：%s",str);
//    int indexMax = (int)strlen(str);
//    int indexMiddle = indexMax/2;
//    
//     printf("双数的中位数：%lu",strlen("abcdef")/2);
//     printf("\n单数数的中位数：%lu",strlen("abcde")/2);
//    char tmp;
//    char tmp2;
//    for (int i = 0 ; i<indexMiddle; i++) {
//        tmp = str[i];
//        tmp2 = str[indexMax-1];
//        str[i] = tmp2;...这里走不下去了。
//        str[indexMax-1] = tmp;
//        indexMax--;
//    }
//    
//    printf("\n输出反转后的字符：%s",str);
//    上面这段注释的。是有问题。因为卡住无法将单字符赋值给它
    
//     int indexMax = (int)strlen(str);
//    char    *start = str;
//    char    *end = str + indexMax - 1;
//    char    ch;
//    
//    if (str != NULL)
//    {
//        while (start < end)
//        {
//            ch = *start;
//            *start++ = *end;
//            *end-- = ch;
//        }
//    }
//    printf("\n输出反转后的字符：%s",str);
//    2 上面也走到 *start++ = *end;停住了
    
//    char* end = str;
//    char tmp;
//    if (str) {
//        while (*end) {
//            ++end;
//        }
//        --end;
//        
//        while (str<end) {
//            tmp = *str;
//            *str++ = *end;
//            *end-- = tmp;
//        }
//    }
//    标配解答方案也是走到 *str++ = *end;就停了。看来有点问题。这个部分的编译
    
    printf("\n输出反转后的字符：%s",str);

}

#pragma mark 第三题
void checkSame(char* str1,char* str2)
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    if (length1 != length2) {
        printf("\n两者不是变为词");
    }
    
    int letters[256] = {0};
   
    for(int i= 0 ;i<length1;i++)
    {
        if (letters[str1[i]]) {
            letters[str1[i]] = letters[str1[i]]+1;
            //            printf("\n重复出现次数---：%d",strCheck[str[i]]);
        }
        if (letters[str1[i]]>=1) {
            
        }else
        {
            letters[str1[i]] = 1;
        }
    }
    
    for (int i = 0 ; i<length2; i++) {
      letters[str2[i]] = letters[str2[i]]-1;
    }
    
    int isTrue = 1;
    for (int i = 0; i<256; i++) {
        if (letters[i]<0) {
            printf("\n不是变位词");
            isTrue = 0;
            break;
        }
    }
    
    if (isTrue) {
         printf("\n两个字符串是变位词");
    }
}

#pragma mark 第四题
void checkEmptyChar(char* str1,int length)
{
       printf("\n");
    int spacecount = 0, newLength = 0, i;
    for (i= 0 ; i<length; i++) {
        if (str1[i] == ' ') {
            spacecount++;
        }
    }
       printf("空字符有%d个",spacecount);
    
    newLength = length + spacecount * 2;
    char newstr[newLength];
    
    for (i=length-1; i>=0; i--) {
        if (str1[i] == ' ') {
            newstr[newLength-1] = '0';
            newstr[newLength-2] = '2';
            newstr[newLength-3] = '&';
            newLength = newLength-3;
        }else
        {
            newstr[newLength-1] = str1[i];
            newLength = newLength-1;
        }
    }
     printf("\n原字符为：%s",str1);
    printf("\n重新排列字符为：%s",newstr);
    
}
