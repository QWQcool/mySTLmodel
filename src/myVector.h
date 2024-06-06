#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#include <cstddef> // 包含size_t
#include<iostream>

// 动态数组
class Int_Vector
{
private:
    int* _pArr = nullptr;
    int _capacity = 0;
    int _size = 0;
public:
    Int_Vector()
    {
        ReAlloc(2);//初始化大小为2
    }

    Int_Vector(const Int_Vector& vec) :_pArr(nullptr), _size(vec._size), _capacity(vec._capacity)
    {
        _pArr = new int[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _pArr[i] = vec._pArr[i];
        }
    }

    Int_Vector& operator=(const Int_Vector& vec) {
        if (this == &vec) {
            return *this;
        }
        delete[] _pArr;
        _size = vec._size;
        _capacity = vec._capacity;
        _pArr = new int[_capacity];
        for (int i = 0; i < _size; i++) {
            _pArr[i] = vec._pArr[i];
        }

        return *this;
    }


    ~Int_Vector()
    {
        delete[] _pArr;
    }

    void push_back(int val)
    {
        if (_size >= _capacity) {
            ReAlloc(_capacity * 2); // 扩容
        }
        _pArr[_size] = val;
        _size++;
    }

    int& at(int index)
    {
        if (index >= _size) {
            std::cerr << "Index out of bounds." << std::endl;
            exit(1); // 或者抛出异常
        }
        return _pArr[index];
    }

    int& operator[](int index)
    {
        return _pArr[index];
    }
    void erase(int index)
    {
        if (index > _size)
        {
            std::cout << "error index" << std::endl;
            return;
        }
        for (int i = index; i < _size - 1; ++i)
        {
            _pArr[i] = _pArr[i + 1];
        }
        --_size;
    }
    void ReAlloc(int newCapacity) {
        int* newBlock = new int[newCapacity];
        if (newCapacity < _size)
            _size = newCapacity;
        for (int i = 0; i < _size; ++i)
            newBlock[i] = _pArr[i];
        delete[] _pArr;
        _pArr = newBlock;
        _capacity = newCapacity;
    }
    void display() const {
        for (int i = 0; i < _size; ++i) {
            std::cout << _pArr[i] << " ";
        }
        std::cout << std::endl;
    }
};

template <class T>
class Vector {
public:
    // 构造函数
    Vector()  { ReAlloc(2); } // 初始化容量为2
    // 析构函数
    ~Vector() { Clear(); delete[] m_Data; }
    // 返回当前向量的大小
    size_t Size() const  { return m_Size; }
    // 返回当前向量的容量
    size_t Capacity() const  { return m_Capacity; }
    // 检查向量是否为空
    bool Empty() const  { return Size() == 0; }
    // 在向量的末尾添加元素
    void PushBack(const T& value);
    // 删除最后一个元素
    void PopBack();
    void Clear();
    void insert(size_t pos);

    // 访问元素
    T& operator[](size_t index) 
    {
        if (index >= Size()) 
        {
            throw std::out_of_range("Index out of range");
        }
        return m_Data[index];
    }

    // 常量访问元素
    const T& operator[](size_t index) const 
    {
        if (index >= Size()) 
        {
            throw std::out_of_range("Index out of range");
        }
        return m_Data[index];
    }

private:
    void ReAlloc(size_t newCapacity) {
        T* newBlock = new T[newCapacity];

        // ensure no overflow
        if (newCapacity < m_Size)
            m_Size = newCapacity;

        // move all the elements to the new block
        for (int i = 0; i < m_Size; ++i)
            newBlock[i] = m_Data[i];

        // delete the old space and update old members
        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
    T* m_Data = nullptr; // 存储元素的数组
    size_t m_Size = 0;   // 当前元素数量
    size_t m_Capacity = 0;// 可容纳的最大元素数量
};

template <class T>
void Vector<T>::PushBack(const T& value) {
    if (m_Size >= m_Capacity) {
        ReAlloc(m_Capacity * 2); // 扩容
    }
    m_Data[m_Size] = value;
    ++m_Size;
}

template<typename T>
void PrintVector(const Vector<T>& vector) {
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i] << std::endl;

    std::cout << "---------------------------" << std::endl;
}

#endif // VECTOR_H
