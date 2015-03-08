## qsort 函数说明

qsort包含在<stdlib.h>头文件中，此函数根据你给的比较条件进行快速排序，通过指针移动实现排序。排序之后的结果仍然放在原数组中。使用qsort函数必须自己写一个比较函数。

### 函数原型 

***void qsort ( void * base, size_t num, size_t size, int ( * comparator ) ( const void *, const void * ) );***

Sorts the num elements of the array pointed by base, each element size bytes long, using the comparator function to determine the order.
The sorting algorithm used by this function compares pairs of values by calling the specified comparator function with two pointers to elements of the array.
The function does not return any value, but modifies the content of the array pointed by base reordering its elements to the newly sorted order.

- **base** Pointer to the first element of the array to be sorted.(数组起始地址)
- **num** Number of elements in the array pointed by base.(数组元素个数)
- **size** Size in bytes of each element in the array.(每一个元素的大小)
- **comparator** Function that compares two elements.(函数指针，指向比较函数)

1、The function must accept two parameters that are pointers to elements, type-casted as void*. These parameters should be cast back to some data type and be compared.
2、The return value of this function should represent whether elem1 is considered less than, equal to, or greater than elem2 by returning, respectively, a negative value, zero or a positive value.

### 使用qsort进行排序 ##

- 定义比较函数
- 调用qsort

### 排序例子

- char 字符排序
```
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b)
{
	return *(char *)a - *(char *)b;
}

int main()
{
	char num[] = {'2','3','4','1','2','6','1','2','3','4'};
	int i;
	qsort(num,10,sizeof(num[0]),cmp);
	for(i = 0;i < 10;i++)
	{
		printf("%c ",num[i]);
	}
	printf("\n");
	return 0;
}
```

- int值排序
``` C
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int num[] = {2, 3, 4, 1, 2, 6, 1, 2, 3, 4};
	int i;
	qsort(num,10,sizeof(num[0]),cmp);
	for(i = 0;i < 10;i++)
	{
		printf("%c ",num[i]);
	}
	printf("\n");
	return 0;
}
```
- double值排序
```C
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b)
{
	return *(double *)a > *(double *)b ? 1 : -1;
}

int main()
{
	double num[] = {2.4,3.2,4.5,1.2,2.7,0.6,1.234,2.0,3,4};
	int i;
	qsort(num,10,sizeof(num[0]),cmp);
	for(i = 0;i < 10;i++)
	{
		printf("%f ",num[i]);
	}
	printf("\n");
	return 0;
}
```

- struct结构体排序
```C
/* qsort example */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int price;
    int id;
} order;
order list[10];
int i = 0;

int compare (const void *a, const void *b)
{

    order *orderA = (order *)a;
    order *orderB = (order *)b;

    if ( orderB->price  != orderA->price )
        return orderB->price - orderA->price;
    else
        return orderB->id - orderA->id;
}

int main ()
{

    int n;
    srand ( time(NULL) );
    printf("Before sorting\n");
    for(i = 0; i < 10; i++)
    {
        list[i].price = rand() % 10;
        list[i].id = i;
        printf ("Order id = %d Price = %d \n", list[i].id, list[i].price);
    }
    printf("AFTER sorting\n");

    qsort (list, 10, sizeof(order), compare);
    for (n = 0; n < 10; n++)
        printf ("Order id = %d Price = %d \n", list[n].id, list[n].price);
    return 0;
}
```