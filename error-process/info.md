
# 错误表示
## C部分函数通过全局变量来表示错误
有一些函数比如read(), write(), open() 出错之后，返回值有语义。真正的错误会被赋值在errno上，需要去判断errno
1. atoi(), atof(), atol() 或是 atoll() 等函数不会设置 errno的
2. libc 又给出了一个新的函数strtol()，这个函数在出错时会设置全局变量errno

## Go语言通过返回error来表示错误
一个函数可能返回不同类型的错误，可以使用switch分别去处理错误

## java 使用try catch finally


# 资源清理

- C里面可以使用goto failCleanResourceFunc；goto不是很好用，可以使用do while 0 然后在while里面return，可以看demo
