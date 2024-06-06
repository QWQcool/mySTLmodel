#pragma once
#include<iostream>

// 1.拷贝构造函数
// 2.处理析构函数
// 3.单链表修改为双链表
class Int_List
{
private:
    struct Node
    {
        int val;
        Node* next;
    };
    Node* head;

public:
    Int_List() : head(nullptr) {}

    ~Int_List()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void Insert(int value)
    {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* lastNode = head;
            while (lastNode->next != nullptr)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
        }
    }

    void PrintList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool DeleteNode(int value)
    {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->val != value)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            return false; // 没有找到值为value的节点
        }

        if (previous == nullptr)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        return true;
    }
};
class Int_Double_List
{
private:
    struct Node
    {
        int val;
        Node* next;
        Node* prev;
    };
    struct Node* _begin;
    struct Node* _end;
public:
    Int_Double_List()
    {
        _begin = new Node;
        _end = new Node;
        _begin->next = _end;
        _begin->prev = nullptr;
        _end->next = nullptr;
        _end->prev = _begin;
    }

    ~Int_Double_List()
    {
        Node* temp = _begin;
        while (temp != nullptr)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    Int_Double_List(const Int_Double_List& other)
    {
        _begin = new Node;
        _end = new Node;
        _begin->next = _end;
        _begin->prev = nullptr;
        _end->next = nullptr;
        _end->prev = _begin;

        // 遍历other双链表，将每个节点复制到新双链表中
        const Node* temp = other._begin->next;
        while (temp != other._end)
        {
            Node* newNode = new Node;
            newNode->val = temp->val; // 复制节点值
            newNode->next = _end; // 将新节点链接到当前的末尾节点之前
            newNode->prev = _end->prev; // 将新节点的前驱设置为当前末尾节点的前驱
            _end->prev->next = newNode; // 更新当前末尾节点的前驱的下一个节点为新节点
            _end->prev = newNode; // 更新当前末尾节点的前驱为新节点
            temp = temp->next;
        }
    }

    void Tail_Insert(int value)
    {
        Node* temp = new Node;
        temp->val = value; // 设置新节点的值
        temp->next = _end; // 将新节点链接到当前的末尾节点之前
        temp->prev = _end->prev; // 将新节点的前驱设置为当前末尾节点的前驱
        _end->prev->next = temp; // 更新当前末尾节点的前驱的下一个节点为新节点
        _end->prev = temp; // 更新当前末尾节点的前驱为新节点
    }
    void Head_Insert(int value)
    {
        Node* temp = new Node;
        temp->val = value;
        temp->next = _begin->next;
        temp->prev = _begin;
        _begin->next->prev = temp;
        _begin->next = temp;
    }

    void Print()
    {
        Node* temp = _begin->next;
        while (temp != _end)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void PrintR()
    {
        Node* temp = _end->prev;
        while (temp != _begin)
        {
            std::cout << temp->val << " ";
            temp = temp->prev;
        }
        std::cout << "\n";
    }

    bool Delete(int value)
    {
        Node* temp = _begin->next;
        while (temp != _end)
        {
            if (temp->val == value)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

};