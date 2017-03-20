#include <iostream>
using namespace std;

#pragma pack(push, 1)
struct TestStruct
{
	char c1;
	short s;
	char c2;
	int i;
};

#pragma pack(pop)

// struct TestStruct
// {
// 	char c1;
// 	char c2;
// 	short s;
// 	int i;
// };

int main(int argc, char const *argv[])
{
	struct TestStruct a;

	cout << "sizeof(struct TestStruct) = " << sizeof(struct TestStruct) << endl;
	cout << "c1 " << static_cast<const void *>(&a.c1)
	     << " s " << static_cast<const void *>(&a.s)
	     << " c2 "<< static_cast<const void *>(&a.c2)
	     << " i " << static_cast<const void *>(&a.i)
	     << endl;

	return 0;
}

/*
1、定义
sizeof是C语言的一种单目操作符，它并不是函数。sizeof操作符以字节形式给出了其操作数所占存储空间的大小。操作数可以是一个表达式或括在括号内的类型名。操作数所占存储空间的大小由操作数的类型决定。作用就是返回一个对象或者类型所占的内存字节数。
2、语法
sizeof有如下三种语法形式：
(1) sizeof( object ); // sizeof( 对象 );
(2) sizeof( type_name ); // sizeof( 类型 );
(3) sizeof object; // sizeof 对象;
所以，
int i;
sizeof( i );    // ok
sizeof i;       // ok
sizeof( int );  // ok
sizeof int;     // error
实际上，sizeof计算对象的大小也是转换成对对象类型的计算，也就是说，同种类型的不同对象其sizeof值都是一致的。这里，对象可以进一步延伸至表达式，即sizeof可以对一个表达式求值，编译器根据表达式的最终结果类型来确定大小，一般不会对表达式进行计算。
如：
sizeof(2);  //2的类型为int，所以等价于 sizeof( int );
sizeof( 2 + 3.14 ); // 3.14的类型为double，2也会被提升成double类型，所以等价于 sizeof( double );
sizeof也可以对一个函数调用求值，其结果是函数返回类型的大小，函数并不会被调用，我们来看一个完整的例子：
char foo()
{
printf("foo() has been called.\n");
return 'a';
}
int main()
{
sz = sizeof( foo() );
// foo() 的返回值类型为char，所以sz = sizeof(char )，foo()并不会被调
printf("sizeof( foo() ) = %d\n", sz);
}
C99标准规定，函数、不能确定类型的表达式以及位域（bit-field）成员不能被计算sizeof值，即sizeof操作符不能用于函数类型，不完全类型或位字段。不完全类型指具有未知存储大小的数据类型，如未知存储大小的数组类型、未知内容的结构或联合类型、void类型等。下面这些写法都是错误的：
sizeof( foo );  // error
void foo2() { }
sizeof( foo2() );  // error
struct S
{
unsigned int f1 : 1;  // error 属于位字段
unsigned int f2 : 5;
unsigned int f3 : 12;
};
sizeof( S.f1 );  // error
3、sizeof的常量性
sizeof的计算发生在编译时刻，所以它可以被当作常量表达式使用，如：
char ary[ sizeof( int ) * 10 ]; // ok
最新的C99标准规定sizeof也可以在运行时刻进行计算，如下面的程序在Dev-C++中可以正确执行：
int n;
n = 10; // n动态赋值
char ary[n]; // C99也支持数组的动态定义
printf("%d\n", sizeof(ary)); // ok. 输出10
但在没有完全实现C99标准的编译器中就行不通了，上面的代码在VC6中就通不过编译。所以我们最好还是认为sizeof是在编译期执行的，这样不会带来错误，让程序的可移植性强些。
4、基本数据类型的sizeof
这里的基本数据类型指short、int、long、float、double这样的简单内置数据类型，由于它们都是和系统相关的，所以在不同的系统下取值可能不同，这务必引起我们的注意，尽量不要在这方面给自己程序的移植造成麻烦。
一般的，在32位编译环境中，sizeof(int)的取值为4。
5、指针变量的sizeof
指针是来存放地址的，那么sizeof指针变量当然等于计算机内部地址总线的宽度。所以在32位计算机中，一个指针变量的返回值必定是4（注意结果是以字节为单位），可以预计，在将来的64位系统中指针变量的sizeof结果为8。
char* pc = "abc";
int* pi;
string* ps;
char** ppc = &pc;
void (*pf)();  // 函数指针
sizeof( pc );  // 结果为4
sizeof( pi );  // 结果为4
sizeof( ps );  // 结果为4
sizeof( ppc ); // 结果为4
sizeof( pf );  // 结果为4
指针变量的sizeof值与指针所指的对象没有任何关系。
6、数组的sizeof
数组的sizeof值等于数组所占用的内存字节数，如：
char a1[] = "abc";
int a2[3];
sizeof( a1 ); // 结果为4，字符末尾还存在一个NULL终止符
sizeof( a2 ); // 结果为3*4=12（依赖于int）
一些朋友刚开始时把sizeof当作了求数组元素的个数，现在，你应该知道这是不对的，那么应该怎么求数组元素的个数呢？通常有下面两种写法：
int c1 = sizeof( a1 ) / sizeof( char ); // 总长度/单个元素的长度
int c2 = sizeof( a1 ) / sizeof( a1[0] ); // 总长度/第一个元素的长度
写到这里，提一问，下面的c3，c4值应该是多少呢？
void foo3(char a3[3])
{
int c3 = sizeof( a3 ); // c3 ==
}
void foo4(char a4[])
{
int c4 = sizeof( a4 ); // c4 ==
}
也许当你试图回答c4的值时已经意识到c3答错了，是的，c3!=3。这里函数参数a3已不再是数组类型，而是蜕变成指针，相当于char* a3，为什么？仔细想想就不难明白，我们调用函数foo3时，程序会在栈上分配一个大小为3的数组吗不会！数组是“传址”的，调用者只需将实参的地址传递过去，所以a3自然为指针类型(char*），c3的值也就为4。
7、结构体的sizeof
这是初学者问得最多的一个问题，所以这里有必要多费点笔墨。让我们先看一个结构体
struct S1
{
char c;
int i;
};
问sizeof(s1)等于多少聪明的你开始思考了，char占1个字节，int占4个字节，那么加起来就应该是5。是这样吗？你在你机器上试过了吗？也许你是对的，但很可能你是错的！VC6中按默认设置得到的结果为8。这是因为结构体遵循字节对齐原则，为什么需要字节对齐？计算机组成原理教导我们这样有助于加快计算机的取数速度，否则就得多花指令周期了。为此，编译器默认会对结构体进行处理（实际上其它地方的数据变量也是如此），让宽度为2的基本数据类型（short等）都位于能被2整除的地址上，让宽度为4的基本数据类型（int等）都位于能被4整除的地址上，以此类推。这样，两个数中间就可能需要加入填充字节，所以整个结构体的sizeof值就增长了。
字节对齐的细节和编译器实现相关，但一般而言，满足三个准则：
(1) 结构体变量的首地址能够被其最宽基本类型成员的大小所整除；
(2) 结构体每个成员相对于结构体首地址的偏移量（offset）都是成员大小的整数倍，如有需要编译器会在成员之间加上填充字节（internal adding）；
(3) 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在最末一个成员之后加上填充字节（trailing padding）。
由于结构体的成员可以是复合类型，比如另外一个结构体，所以在寻找最宽基本类型成员时，应当包括复合类型成员的子成员，而不是把复合成员看成是一个整体。但在确定复合类型成员的偏移位置时则是将复合类型作为整体看待。
这里叙述起来有点拗口，思考起来也有点挠头，还是让我们看看例子吧：
struct S3
{
char c1;
S1 s;
char c2
};
S1的最宽简单成员的类型为int，S3在考虑最宽简单类型成员时是将S1“打散”看的，所以S3的最宽简单类型为int，这样，通过S3定义的变量，其存储空间首地址需要被4整除，整个sizeof(S3)的值也应该被4整除。sizeof(S3)的值为16。
到这里，朋友们应该对结构体的sizeof有了一个全新的认识，但不要高兴得太早，有一个影响sizeof的重要参量还未被提及，那便是编译器的pack指令。它是用来调整结构体对齐方式的，不同编译器名称和用法略有不同，VC6中通过#pragma pack实现，也可以直接修改/Zp编译开关。#pragma pack的基本用法为：#pragma pack( n )，n为字节对齐数，其取值为1、2、4、8、16，默认是8，如果这个值比结构体成员的sizeof值小，那么该成员的偏移量应该以此值为准，即是说，结构体成员的偏移量应该取二者的最小值，公式如下：
offsetof( item ) = min( n, sizeof( item ) )
再看示例：
#pragma pack(push) // 将当前pack设置压栈保存
#pragma pack(2)    // 必须在结构体定义之前使用
struct S1
{
char c;
int i;
};
struct S3
{
char c1;
S1 s;
char c2
};
#pragma pack(pop) // 恢复先前的pack设置
计算sizeof(S1)时，min(2, sizeof(i))的值为2，所以i的偏移量为2，加上sizeof(i)等于6，能够被2整除，所以整个S1的大小为6。同样，对于sizeof(S3)，s的偏移量为2，c2的偏移量为8，加上sizeof(c2)等于9，不能被2整除，添加一个填充字节，所以sizeof(S3)等于10。
注意，“空结构体”（不含数据成员）的大小不为0，而是1。
8、含位域结构体的sizeof
前面已经说过，位域成员不能单独被取sizeof值，我们这里要讨论的是含有位域的结构体的sizeof，只是考虑到其特殊性而将其专门列了出来。
C99规定int、unsigned int和bool可以作为位域类型，但编译器几乎都对此作了扩展，允许其它类型类型的存在。
使用位域的主要目的是压缩存储，其大致规则为：
(1) 如果相邻位域字段的类型相同，且其位宽之和小于类型的sizeof大小，则后面的字段将紧邻前一个字段存储，直到不能容纳为止；
(2) 如果相邻位域字段的类型相同，但其位宽之和大于类型的sizeof大小，则后面的字段将从新的存储单元开始，其偏移量为其类型大小的整数倍；
(3) 如果相邻的位域字段的类型不同，则各编译器的具体实现有差异，VC6采取不压缩方式，Dev-C++采取压缩方式；
(4) 如果位域字段之间穿插着非位域字段，则不进行压缩；
(5) 整个结构体的总大小为最宽基本类型成员大小的整数倍。
示例1：
struct BF1
{
char f1 : 3;
char f2 : 4;
char f3 : 5;
};
位域类型为char，第1个字节仅能容纳下f1和f2，所以f2被压缩到第1个字节中，而f3只能从下一个字节开始。因此sizeof(BF1)的结果为2。
示例2：
struct BF2
{
char f1 : 3;
short f2 : 4;
char f3 : 5;
};
由于相邻位域类型不同，在VC6中其sizeof为6，在Dev-C++中为2。
示例3：
struct BF3
{
char f1 : 3;
char f2;
char f3 : 5;
};
非位域字段穿插在其中，不会产生压缩，在VC6和Dev-C++中得到的大小均为3。
9、联合体的sizeof
结构体在内存组织上是顺序式的，联合体则是重叠式，各成员共享一段内存，所以整个联合体的sizeof也就是每个成员sizeof的最大值。结构体的成员也可以是复合类型，这里，复合类型成员是被作为整体考虑的。
所以，下面例子中，U的sizeof值等于sizeof(s)。
struct S1
{
char f1;
int f2;
char *f3;
};
union U
{
int i;
char c;
S1 s;
};
*/