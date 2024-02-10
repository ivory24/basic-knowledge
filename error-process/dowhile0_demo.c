#include <stdio.h>
#include <stdlib.h>

// 为了避免全局变量产生野指针，释放完之后设置为NULL
// 局部变量是不需要设置为NULL的，因为局部变量分配在栈上，局部变量指向的内存是malloc分配在堆上的。局部变量被释放后不会出现野指针
#define VDS_INNER_FREE(pMem) if (NULL != pMem) { \
    free(pMem);     \
    pMem = NULL; \
}

#define VDS_NAME_LEN (256)

#define VDS_COMMON_OK (0)
#define VDS_COMMON_FAIL (-1)
#define VDS_COMMON_OTHER_ERR (-2)

int proc()
{
    char *pcFName = NULL;
    char *pcLName = NULL;
    char *pcMName = NULL;


    int lRet = VDS_COMMON_FAIL;

    do {
        // memset将一块内存初始化，一般分配出来内存后建议初始化为0，可以减少bug
        // sizeof说要兼容平台哈哈哈，也没太懂不就是1
        pcFName = (char *) malloc(sizeof(char) * VDS_NAME_LEN);
        if (NULL == pcFName) {
            lRet = VDS_COMMON_OTHER_ERR;
            break;
        }
        pcLName = (char *) malloc(sizeof(char) * VDS_NAME_LEN);
        if (NULL == pcLName) {
            lRet = VDS_COMMON_OTHER_ERR;
            VDS_INNER_FREE(pcFName);
            break;
        }
        pcMName = (char *) malloc(sizeof(char) * VDS_NAME_LEN);
        if (NULL == pcMName) {
            lRet = VDS_COMMON_OTHER_ERR;
            VDS_INNER_FREE(pcLName);
            VDS_INNER_FREE(pcFName);
            break;
        }
        lRet = VDS_COMMON_OK;
    } while(0);

    if (VDS_COMMON_OK != lRet) {
        // 也可以直接返回，看应用场景，返回的code使用者需要能识别
        return 1;
    }

    return 0;
}

int main() {
    int x = 5;

    do {
        if (x > 0) {
            printf("x is positive\n");
            break;
        }

        printf("x is non-positive\n");
    } while (0);

    printf("This is the end of the program\n");

    int res = proc();
    printf("This is the result %d\n", res);

    return 0;
}