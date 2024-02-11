#include <iostream>

class MemoryBlock
{
public:
    // 构造函数，分配内存
    explicit MemoryBlock(size_t size)
        : m_size(size), m_data(new int[size])
    {
        std::cout << "MemoryBlock: 构造函数, 分配 " << m_size << " 个整数" << std::endl;
    }

    // 析构函数，释放内存
    ~MemoryBlock()
    {
        std::cout << "MemoryBlock: 析构函数, 释放 " << m_size << " 个整数" << std::endl;
        delete[] m_data;
    }

    // 获取内存块的大小
    size_t size() const
    {
        return m_size;
    }

private:
    size_t m_size;
    int *m_data;
};

int main()
{
    {
        MemoryBlock block(5); // 分配 5 个整数
        std::cout << "MemoryBlock 的大小: " << block.size() << std::endl;
    } // 当 block 离开作用域时，析构函数会自动调用，释放内存

    return 0;
}


// g++ rall.cpp -o rall