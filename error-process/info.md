
# 错误表示
## C部分函数通过全局变量来表示错误
有一些函数比如read(), write(), open() 出错之后，返回值有语义。真正的错误会被赋值在errno上，需要去判断errno, 参考 errno_demo.c
1. atoi(), atof(), atol() 或是 atoll() 等函数不会设置 errno的
2. libc 又给出了一个新的函数strtol()，这个函数在出错时会设置全局变量errno

## Go语言通过返回error来表示错误
一个函数可能返回不同类型的错误，可以使用switch分别去处理错误

## java 使用try catch finally


# 资源清理
- C里面可以使用goto failCleanResourceFunc；goto不是很好用（参考goto_demo.c），可以使用do while 0 然后在while里面return，参考 dowhile0_demo.c
- C++里面有RALL机制，通过构造函数分配内存，通过析构函数回收内存。当变量离开作用域之后，资源自动被释放，参考 rall.cpp
- go里面当出现异常可以使用defer去对异常进行recover，也可以在defer中执行资源回收清理，参考defer_demo.go

# 异常捕捉
- 使用try（执行程序） catch（错误异常捕捉） finally（资源清理）
- 异常捕捉可能对性能有影响，那是因为一旦异常被抛出，函数也就跟着 return 了。而程序在执行时需要处理函数栈的上下文，这会导致性能变得很慢，尤其是函数栈比较深的时候。但异常情况是少数

# 错误分类
- 资源错误 （配置对应的告警等）
- 代码逻辑错误 （异常捕捉）
- 参数等用户输入错误 （错误码）

# 异步编程的错误处理
- 使用回调函数, 参考callback_demo.go
- 使用promise设计模式。通过channel或者waitgroup等待异步执行结束后，通过判断返回执行不同的逻辑 参考promise_demo.go


# 错误分类
- fatal 重大错误
- error 资源错误（网络请求或者内存不足等）
- warning 引起关注
- info 输出一些进度或者信息
- debug 便于定位异常
