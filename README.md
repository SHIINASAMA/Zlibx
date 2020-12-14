# Zlibx
<kbd>Zlibx</kbd>是在<kbd>[Zlib](https://github.com/shiinasama/zlib)</kbd>上的一次结构上的尝试。与Zlib最主要的区别在于剔除了自己手动处理消息循环，改成消息的映射。

同样在这里演示一个简单的Demo

~~~c++
#include "ZWindow.h"
int main()
{
    ZWindow* win = new ZWindow(L"Hello", 300, 300, 600, 400);
    win->Create();
    win->Run();
    return 0;
}
~~~

大部分信息仍可参考[Zlib的主页](https://github.com/shiinasama/zlib)