## C库函数手册(ctype.h)
### 分类函数,所在函数库为ctype.h

- **int isalpha(int ch)**  
若ch是字母('A'-'Z','a'-'z')返回非0值,否则返回0
- **int isalnum(int ch)**  
若ch是字母('A'-'Z','a'-'z')或数字('0'-'9')返回非0值,否则返回0
- **int isascii(int ch)** 
若ch是字符(ASCII码中的0-127)返回非0值,否则返回0
- **int iscntrl(int ch)** 
若ch是作废字符(0x7F)或普通控制字符(0x00-0x1F)返回非0值,否则返回0
- **int isdigit(int ch)** 
若ch是数字('0'-'9')返回非0值,否则返回0
- **int isgraph(int ch)**
若ch是可打印字符(不含空格)(0x21-0x7E)返回非0值,否则返回0
- **int islower(int ch)** 
若ch是小写字母('a'-'z')返回非0值,否则返回0
- **int isprint(int ch)** 
若ch是可打印字符(含空格)(0x20-0x7E)返回非0值,否则返回0
- **int ispunct(int ch)**
若ch是标点字符(0x00-0x1F)返回非0值,否则返回0
- **int isspace(int ch)**
若ch是空格(' '),水平制表符('	'),回车符(' '),走纸换行('f'),垂直制表符('v'),换行符(' ')返回非0值,否则返回0
- **int isupper(int ch)**
若ch是大写字母('A'-'Z')返回非0值,否则返回0
- **int isxdigit(int ch)**
若ch是16进制数('0'-'9','A'-'F','a'-'f')返回非0值,否则返回0
- **int tolower(int ch)**
若ch是大写字母('A'-'Z')返回相应的小写字母('a'-'z')
- **int toupper(int ch)**
若ch是小写字母('a'-'z')返回相应的大写字母('A'-'Z')

> 来源：http://blog.chinaunix.net/uid-54182-id-2386112.html