/*
 * @Author: Junhu Li
 * @Date: 2021-11-16 20:07:19
 * @version: 
 * @LastEditors: Junhu Li
 * @LastEditTime: 2021-11-16 21:09:57
 * @Description: 自定义实现vector
 * @FilePath: \dataStruct&algorithm\Vector.cpp
 * Talk is cheap, Show me the code
 */

#include <iostream>

template<typename Object>
class Vector{
public:
    // 有参构造函数
    // 防止隐式类型转换
    explicit Vector(int initSize = 0):m_Size(initSize), m_Capacity(initSize + SPARE_CAPACIT) {
        // 对象指针申请空间
        objects = new Object[m_Capacity];
    }

    // 拷贝构造函数
    Vector(const Vector& rhs) {
        // 显示调用操作符=
        operator=(rhs);
    }

    // 析构函数
    ~Vector() {
        delete[] objects;
    }

    // 操作符=重载
    const Vector& operator=(const Vector& rhs) {
        // 判断是否属于同一个对象
        if (this != &rhs) {
            // 释放旧对象空间
            delete[] objects;
            // 修改变量并分配空间
            m_Size = rhs.size();
            m_Capacity = rhs.m_Capacity;
            objects = new Object[capacity()];
            // 循环赋值，需要用到重载运算符[]
            for (int i = 0; i < m_Size; i++) {
                objects[i] = rhs.objects[i];
            }
        }

        return *this;
    }

    // 操作符[]重载, 原因见1.7.2节
    Object& operator[](int index) {
        return objects[index];
    }
    const Object& operator[](int index) const{
        return objects[index];
    }

    // 修改数组的大小
    void resize(int newSize) {
        // 是否需要成倍扩展数组容量
        if (newSize > m_Size) {
            reverse(newSize * 2 + 1);
        }
        m_Size = newSize;
    }

    // 修改数组的容量
    void reverse(int newCapacity) {
        if (newCapacity < m_Capacity) {
            return ;
        }
        Object* oldArray = objects;
        objects = new Object[newCapacity];
        m_Capacity = newCapacity;
        for (int i = 0; i < m_Size; i++) {
            objects[i] = oldArray[i];
        }
        delete[] oldArray;
    }


    // vector大小
    int size() {
        return m_Size;
    }

    // vector容量
    int capacity() {
        return m_Capacity;
    }

    // 判断是否为空
    bool empty() {
        return size() == 0;
    }

    // 插入
    void push_back(const Object& x) {
        // 如果数组大小已经到了数组容量，扩展数组容量
        if (m_Size == m_Capacity) {
            reverse(m_Capacity * 2 + 1);
        }
        objects[m_Size++] = x;
    }

    // 删除
    void pop_back() {
        m_Size--;
    }

    // 返回末尾元素
    const Object& back() const{
        return objects[m_Size - 1];
    }

    // 迭代器
    typedef Object* iterator;
    typedef const Object* const_iterator;

    // 返回首元素地址
    iterator begin() {
        return &objects[0];
    }

    const_iterator begin() const{
        return &objects[0];
    }

    // 返回第一个不存在元素的地址
    iterator end() {
        return &objects[size()];
    }

    const_iterator end() const{
        return &objects[size()];
    }

    enum {SPARE_CAPACIT = 16};
private:
    int m_Size;
    int m_Capacity;
    Object *objects;
};

template<typename Object>
void print(Object& objects) {
    for (int i = 0; i < objects.size(); i++) {
        std::cout << objects[i] << " ";
    }
    std::cout << std::endl;
}

// 简单测试
int main()
{
    Vector<int> arr;
    // 增加元素
    for (int i = 0; i < 5; i++) {
        arr.push_back(i);
    }
    print(arr);
    // 末尾元素
    int back_item = arr.back();
    std::cout << back_item << std::endl;

    // 删除末尾元素
    arr.pop_back();
    print(arr);

    // 返回大小
    std::cout << arr.size() << std::endl;
    // 返回容量
    std::cout << arr.capacity() << std::endl;
    return 0;
}