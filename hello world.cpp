#include <iostream>
using namespace std;

// 告诉编译器使用 std 命名空间。命名空间是 C++ 中一个相对新的概念，是一种用来避免命名冲突的机制，它可以将一段代码的名称隔离开，使其与其他代码的名称不冲突。
// 有些名字容易冲突，所以会使用命名空间的方式进行区分，具体来说就是加个前缀。比如 C++ 标准库里面定义了 vector 容器，自己也写了个 vector 类，这样名字就冲突了。
// 于是标准库里的名字都加上 std:: 的前缀，必须用 std::vector 来引用。同理，自己的类也可以加个自定义的前缀。
// 但是经常写全名会很繁琐，所以在没有冲突的情况下可以偷懒，写一句 using namespace std;，接下去的代码就可以不用写前缀直接写 vector 了。

int main()
{
   cout << "hello world" <<endl;
   #if 0
      cout << "hello world~" <<endl;
   #endif
   return 0;
}
/*
#if 0 ... #endif 属于条件编译，0 即为参数。
此外，我们还可以使用 #if 0 ... #endif 来实现注释，且可以实现嵌套，格式为：
#if 0
   code
#endif 
你可以把 #if 0 改成 #if 1 来执行 code 的代码。
这种形式对程序调试也可以帮助，测试时使用 #if 1 来执行测试代码，发布后使用 #if 0 来屏蔽测试代码。
#if 后可以是任意的条件语句。
下面的代码如果 condition 条件为 true 执行 code1 ，否则执行 code2。
#if condition
  code1
#else
  code2
#endif
*/
