## C库函数手册(string.h)
### 分类函数,所在函数库为string.h

### 1. strcpy 
- 函数名 : ***strcpy***
- 功 能 : 拷贝一个字符串到另一个
- 用 法 : **char *strcpy(char *destin, char *source)**;
- 程序例:
```
#include <stdio.h>
#include <string.h>
int main(void)
{
    char string[10];
    char *str1 = "abcdefghi";
    strcpy(string, str1);

    printf("%s\n", string);
    return 0;
}
```

### 2. strncpy
- 函数名 : ***strncpy***
- 功能 ： 将字符串src中最多n个字符复制到字符数组dest中(它并不像strcpy一样遇到NULL才停止复制，而是等凑够n个字符才开始复制），返回指向dest的指针
- 原型 ： **char * strncpy(char *dest, char *src, size_t n)**; 　
- 程序例 :
```
#include <stdio.h>
#include <string.h>
int main(void)
{
    char string[10];
    char *str1 = "abcdefghi";
    strncpy(string, str1, 3);

    printf("%s\n", string);
    return 0;
}
```

### 3. strcat
- 函数名 : ***strcat***
- 功能 : 字符串拼接函数
- 用法 : **char *strcat(char *destin, char *source)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char destination[25];
    char *blank = " ", *c = "C++", *Borland = "Borland";
    strcpy(destination, Borland);
    strcat(destination, blank);
    strcat(destination, c);
    printf("%s\n", destination);
    return 0;
}
```

### 4. strchr
- 函数名 : ***strchr***
- 功能 : 在一个串中查找给定字符的第一个匹配之处
- 用法 : **char *strchr(char *str, char c)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char string[15];
    char *ptr, c = 'r';
    strcpy(string, "This is a string");
    ptr = strchr(string, c);
    if (ptr)
        printf("The character %c is at position: %d\n", c, ptr - string);
    else
        printf("The character was not found\n");
    return 0;
}
```

### 5. strcmp
- 函数名 : ***strcmp***
- 功能 : 串比较看Asic码，str1 > str2，返回值 > 0；两串相等，返回0
- 用法 : **int strcmp(char *str1, char *str2)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char *buf1 = "aaa", *buf2 = "bbb", *buf3 = "ccc";
    int ptr;
    ptr = strcmp(buf2, buf1);
    if (ptr > 0)
        printf("buffer 2 is greater than buffer 1\n");
    else
        printf("buffer 2 is less than buffer 1\n");
    ptr = strcmp(buf2, buf3);
    if (ptr > 0)
        printf("buffer 2 is greater than buffer 3\n");
    else
        printf("buffer 2 is less than buffer 3\n");
    return 0;
}
```

### 6. strnicmp
- 函数名 : ***strnicmp***
- 功能 : 将一个串中的一部分与另一个串比较, 不管大小写
- 用法 : **int strnicmp(char *str1, char *str2, unsigned maxlen)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char *buf1 = "BBB", *buf2 = "bbb";
    int ptr;
    ptr = strnicmp(buf2, buf1);
    if (ptr > 0)
        printf("buffer 2 is greater than buffer 1\n");
    if (ptr < 0)
        printf("buffer 2 is less than buffer 1\n");
    if (ptr == 0)
        printf("buffer 2 equals buffer 1\n");
    return 0;
}
```

### 7. strlen
- 函数名 : ***strlen***
- 功能 : strlen函数求的是字符串的长度，它求得方法是从字符串的首地址开始到遇到第一个'\0'停止计数,如果你只定义没有给它赋初值，这个结果是不定的，它会从字符串首地址一直记下去，直到遇到'\0'才会停止。
- 原型 : **size_t strlen(const char *s)**;
- 程序例 : 
```
#include<stdio.h>
#include <string.h>
int main()
{
    int i = 0;
    char *he = "Hello,world";
    i = strlen(he);
    printf("字符串长度为%d\n", i);
    return 0;
}
//运行结果：字符串长度为11
```

### 8. strcspn
- 函数名 : ***strcspn***
- 功能 : 在串中查找第一个给定字符集内容的段
- 用法 : **int strcspn(char *str1, char *str2)**;
- 程序例 :
```
#include <stdio.h>
#include <string.h>
#include <alloc.h>
int main(void)
{
    char *string1 = "1234567890";
    char *string2 = "747DC8";
    int length;
    length = strcspn(string1, string2);
    printf("Character where strings intersect is at position %d\n", length);
    return 0;
}
```

### 9. strdup
- 函数名 : ***strdup***
- 功能 : 将串拷贝到新建的位置处
- 用法 : **char *strdup(char *str)**;
- 程序例 :
```
#include <stdio.h>
#include <string.h>
#include <alloc.h>
int main(void)
{
    char *dup_str, *string = "abcde";
    dup_str = strdup(string);
    printf("%s\n", dup_str);
    free(dup_str);
    return 0;
}
```

### 10. stricmp
- 函数名 : ***stricmp***
- 功能 : 以大小写不敏感方式比较两个串
- 用法 : **int stricmp(char *str1, char *str2)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char *buf1 = "BBB", *buf2 = "bbb";
    int ptr;
    ptr = stricmp(buf2, buf1);
    if (ptr > 0)
        printf("buffer 2 is greater than buffer 1\n");
    if (ptr < 0)
        printf("buffer 2 is less than buffer 1\n");
    if (ptr == 0)
        printf("buffer 2 equals buffer 1\n");
    return 0;
}
```

### 11. strerror
- 函数名 : ***strerror***
- 功能 : 返回指向错误信息字符串的指针
- 用法 : **char *strerror(int errnum)**;
- 程序例 :
```
#include <stdio.h>
#include <errno.h>
int main(void)
{
    char *buffer;
    buffer = strerror(errno);
    printf("Error: %s\n", buffer);
    return 0;
}
```

### 12. strcmpi
- 函数名 : ***strcmpi***
- 功能 : 将一个串与另一个比较, 不管大小写
- 用法 : **int strcmpi(char *str1, char *str2)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char *buf1 = "BBB", *buf2 = "bbb";
    int ptr;
    ptr = strcmpi(buf2, buf1);
    if (ptr > 0)
        printf("buffer 2 is greater than buffer 1\n");
    if (ptr < 0)
        printf("buffer 2 is less than buffer 1\n");
    if (ptr == 0)
        printf("buffer 2 equals buffer 1\n");
    return 0;
}
```

### 13. strnicmp
- 函数名 : ***strnicmp***
- 功能: 不注重大小写地比较两个串
- 用法: **int strnicmp(char *str1, char *str2, unsigned maxlen)**;
- 程序例:
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char *buf1 = "BBBccc", *buf2 = "bbbccc";
    int ptr;
    ptr = strnicmp(buf2, buf1, 3);
    if (ptr > 0)
        printf("buffer 2 is greater than buffer 1\n");
    if (ptr < 0)
        printf("buffer 2 is less than buffer 1\n");
    if (ptr == 0)
        printf("buffer 2 equals buffer 1\n");
    return 0;
}
```

### 14. strnset
- 函数名 : ***strnset***
- 功能 : 将一个字符串前n个字符都设为指定字符
- 用法 : **char *strnset(char *str, char ch, unsigned n)**;
- 程序例 :
```
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *string = "abcdefghijklmnopqrstuvwxyz";
    char letter = 'x';
    printf("string before strnset: %s\n", string);
    strnset(string, letter, 13);
    printf("string after strnset: %s\n", string);
    return 0;
}
```

### 15. strpbrk
- 函数名 : ***strpbrk***
- 功能 : 在串中查找给定字符集中的字符
- 用法 : **char *strpbrk(char *str1, char *str2)**;
- 程序例 :
```
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *string1 = "abcdefghijklmnopqrstuvwxyz";
    char *string2 = "onm";
    char *ptr;
    ptr = strpbrk(string1, string2);
    if (ptr)
        printf("strpbrk found first character: %c\n", *ptr);
    else
        printf("strpbrk didn't find character in set\n");
    return 0;
}
```

### 16. strrchr
- 函数名: ***strrchr***
- 功能: 在串中查找指定字符的最后一个出现
- 用法: **char *strrchr(char *str, char c)**;
- 程序例:
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char string[15];
    char *ptr, c = 'r';
    strcpy(string, "This is a string");
    ptr = strrchr(string, c);
    if (ptr)
        printf("The character %c is at position: %d\n", c, ptr - string);
    else
        printf("The character was not found\n");
    return 0;
}
```

### 17. strrev
- 函数名 : ***strrev***
- 功能 : 串倒转
- 用法 : **char *strrev(char *str)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char *forward = "string";
    printf("Before strrev(): %s\n", forward);
    strrev(forward);
    printf("After strrev(): %s\n", forward);
    return 0;
}
```

### 18. strset
- 函数名 : ***strset***
- 功能: 将一个串中的所有字符都设为指定字符
- 用法: **char *strset(char *str, char c)**;
- 程序例:
```
#include <stdio.h>
#include <string.h>
int main(void)
{
    char string[10] = "123456789";
    char symbol = 'c';
    printf("Before strset(): %s\n", string);
    strset(string, symbol);
    printf("After strset(): %s\n", string);
    return 0;
}
```

### 19. strstr
- 函数名 : ***strstr***
- 功能 : 在串中查找指定字符串的第一次出现
- 用法 : **char *strstr(char *str1, char *str2)**;
- 程序例 :
```
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *str1 = "Borland International", *str2 = "nation", *ptr;
    ptr = strstr(str1, str2);
    printf("The substring is: %s\n", ptr);
    return 0;
}
```

### 20. strtod
- 函数名 : ***strtod***
- 功能 : 将字符串转换为double型值
- 用法 : **double strtod(char *str, char **endptr)**;
- 程序例 :
```
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char input[80], *endptr;
    double value;
    printf("Enter a floating point number:");
    gets(input);
    value = strtod(input, &endptr);
    printf("The string is %s the number is %lf\n", input, value);
    return 0;
}
```

### 21. strtok
- 函数名 : ***strtok***
- 功能 : 查找由在第二个串中指定的分界符分隔开的单词
- 用法 : **char *strtok(char *str1, char *str2)**;
- 程序例 :
```
#include <string.h>
#include <stdio.h>
int main(void)
{
    char input[16] = "abc,d";
    char *p;
    /* strtok places a NULL terminator
    in front of the token, if found */
    p = strtok(input, ",");
    if (p) printf("%s\n", p);
    /* A second call to strtok using a NULL
    as the first parameter returns a pointer
    to the character following the token */
    p = strtok(NULL, ",");
    if (p) printf("%s\n", p);
    return 0;
}
```

### 22. strtol
- 函数名 : ***strtol***
- 功能 : 将串转换为长整数
- 用法 : **long strtol(char *str, char **endptr, int base)**;
- 程序例 :
```
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    char *string = "87654321", *endptr;
    long lnumber;
    /* strtol converts string to long integer */
    lnumber = strtol(string, &endptr, 10);
    printf("string = %s long = %ld\n", string, lnumber);
    return 0;
}
```

### 23. strupr
- 函数名 : ***strupr***
- 功能 : 将串中的小写字母转换为大写字母
- 用法 : **char *strupr(char *str)**;
- 程序例 :
```
#include <stdio.h>
#include <string.h>
int main(void)
{
    char string[ ] = "abcdefghijklmnopqrstuvwxyz", *ptr;//定义为数组才能修改
    /* converts string to upper case characters */
    ptr = strupr(string);
    printf("%s\n", ptr);
    return 0;
}
```

### 24. swab
- 函数名: ***swab***
- 功能: 交换字节
- 用法: **void swab (char *from, char *to, int nbytes)**;
- 程序例:
```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char source[15] = "rFna koBlrna d";
char target[15];
int main(void)
{
    swab(source, target, strlen(source));
    printf("This is target: %s\n", target);
    return 0;
}
```