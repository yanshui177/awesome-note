## C语言标准库：字符串转换为数字

### 1 . atoi函数（将字符串转换成整型数）
- 相关函数 : atof，atol，atrtod，strtol，strtoul
- 表头文件 : *#include<stdlib.h>*
- 定义函数 : ***int atoi(const char *nptr)***;
- 函数说明 : atoi()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。
- 返回值 : 返回转换后的整型数。
- 附加说明 : atoi()与使用strtol(nptr，(char**)NULL，10)；结果相同。
- 例程序 :
```
#include <ctype.h>
#include <stdio.h>
int atoi (char s[]);
int main(void )
{
    char s[100];
    gets(s);
    printf("integer=%d\n", atoi(s));
    return 0;
}
int atoi (char s[])
{
    int i, n, sign;
    for(i = 0; isspace(s[i]); i++) //跳过空白符 ;
        sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == ' -') //跳过符号 i++;
        for(n = 0; isdigit(s[i]); i++)
            n = 10 * n + (s[i] - '0'); //将数字字符转换成整形数字
    return sign * n;
}
```

### itoa（把一整数转换为字符串 ）
- 例程序：
```
#include <ctype.h>
#include <stdio.h>
void itoa (int n, char s[]); //atoi 函数：将ｓ转换为整形数
int main(void )
{
    int n;
    char s[100];
    printf("Input n:\n");
    scanf("%d", &n);
    printf("the string : \n");
    itoa (n, s);
    return 0;
}
void itoa (int n, char s[])
{
    int i, j, sign;
    if((sign = n) < 0)     //记录符号
        n = -n;                //使n成为正数
    i = 0;
    do
    {
        s[i++] = n % 10 + '0'; //取下一个数字
    }
    while ((n /= 10) > 0); //删除该数字
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    for(j = i; j >= 0; j--) //生成的数字是逆序的，所以要逆序输出
        printf("%c", s[j]);
}
```
> 注意，atoi是标准库函数，itoa不是，用到itoa的时候可以用sprintf()a函数代替。

### atof（将字符串转换成浮点型数） 
- 相关函数 : atoi，atol，strtod，strtol，strtoul
- 表头文件 : #include <stdlib.h>
- 定义函数 : double atof(const char *nptr);
- 函数说明 : atof()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转 换，并将结果返回。参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分，如123.456或123e-2。返回值 返回转换后的浮点型数。
- 附加说明 : atof()与使用strtod(nptr,(char**)NULL)结果相同。 

### atol（将字符串转换成长整型数） 
- 相关函数 : atof，atoi，strtod，strtol，strtoul
- 表头文件 : #include<stdlib.h>
- 定义函数 : long atol(const char *nptr);
- 函数说明 : atol()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。
- 返回值 : 返回转换后的长整型数。
- 附加说明 : atol()与使用strtol(nptr,(char**)NULL,10)；结果相同。 

### gcvt（将浮点型数转换为字符串，取四舍五入） 
- 相关函数 : ecvt，fcvt，sprintf
- 表头文件 : #include<stdlib.h>
- 定义函数 : char *gcvt(double number，size_t ndigits，char *buf);
- 函数说明 : gcvt()用来将参数number转换成ASCII码字符串，参数ndigits表示显示的位数。gcvt()与ecvt()和fcvt()不同的地方 在于，gcvt()所转换后的字符串包含小数点或正负符号。若转换成功，转换后的字符串会放在参数buf指针所指的空间。
- 返回值 : 返回一字符串指针，此地址即为buf指针。

### strtod（将字符串转换成浮点数） 
- 相关函数 : atoi，atol，strtod，strtol，strtoul
- 表头文件 : #include<stdlib.h>
- 定义函数 : double strtod(const char *nptr,char **endptr);
- 函数说明 : strtod()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，到出现非数字或字符串结束时('\0')才结束转 换，并将结果返回。若endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr传回。参数nptr字符串可包含正负号、 小数点或E(e)来表示指数部分。如123.456或123e-2。
- 返回值 : 返回转换后的浮点型数。

### strtol（将字符串转换成长整型数）
- 相关函数 : atof，atoi，atol，strtod，strtoul
- 表头文件 : #include<stdlib.h>
- 定义函数 : long int strtol(const char *nptr,char **endptr,int base);
- 函数说明 : strtol()会将参数nptr字符串根据参数base来转换成长整型数。参数base范围从2至36，或0。参数base代表采用的进制方式，如 base值为10则采用10进制，若base值为16则采用16进制等。当base值为0时则是采用10进制做转换，但遇到如'0x'前置字符则会使用 16进制做转换。一开始strtol()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束 时('\0')结束转换，并将结果返回。若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回。
返回值 返回转换后的长整型数，否则返回ERANGE并将错误代码存入errno中。
附加说明 ERANGE指定的转换字符串超出合法范围。 

### strtoul（将字符串转换成无符号长整型数） 
- 相关函数 : atof，atoi，atol，strtod，strtol
- 表头文件 : #include<stdlib.h>
- 定义函数 : unsigned long int strtoul(const char *nptr,char **endptr,int base);
- 函数说明 : strtoul()会将参数nptr字符串根据参数base来转换成无符号的长整型数。参数base范围从2至36，或0。参数base代表采用的进制方 式，如base值为10则采用10进制，若base值为16则采用16进制数等。当base值为0时则是采用10进制做转换，但遇到如'0x'前置字符则 会使用16进制做转换。一开始strtoul()会扫描参数nptr字符串，跳过前面的空格字符串，直到遇上数字或正负符号才开始做转换，再遇到非数字或 字符串结束时('\0')结束转换，并将结果返回。若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返 回。
返回值 返回转换后的长整型数，否则返回ERANGE并将错误代码存入errno中。
附加说明 ERANGE指定的转换字符串超出合法范围。 

### toascii（将整型数转换成合法的ASCII 码字符） 
- 相关函数 : isascii，toupper，tolower
- 表头文件 : #include<ctype.h>
- 定义函数 : int toascii(int c)
- 函数说明 : toascii()会将参数c转换成7位的unsigned char值，第八位则会被清除，此字符即会被转成ASCII码字符。
- 返回值 : 将转换成功的ASCII码字符值返回。