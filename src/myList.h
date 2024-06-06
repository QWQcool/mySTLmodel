#pragma once
#include<iostream>

// 1.�������캯��
// 2.������������
// 3.�������޸�Ϊ˫����
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
            return false; // û���ҵ�ֵΪvalue�Ľڵ�
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

        // ����other˫������ÿ���ڵ㸴�Ƶ���˫������
        const Node* temp = other._begin->next;
        while (temp != other._end)
        {
            Node* newNode = new Node;
            newNode->val = temp->val; // ���ƽڵ�ֵ
            newNode->next = _end; // ���½ڵ����ӵ���ǰ��ĩβ�ڵ�֮ǰ
            newNode->prev = _end->prev; // ���½ڵ��ǰ������Ϊ��ǰĩβ�ڵ��ǰ��
            _end->prev->next = newNode; // ���µ�ǰĩβ�ڵ��ǰ������һ���ڵ�Ϊ�½ڵ�
            _end->prev = newNode; // ���µ�ǰĩβ�ڵ��ǰ��Ϊ�½ڵ�
            temp = temp->next;
        }
    }

    void Tail_Insert(int value)
    {
        Node* temp = new Node;
        temp->val = value; // �����½ڵ��ֵ
        temp->next = _end; // ���½ڵ����ӵ���ǰ��ĩβ�ڵ�֮ǰ
        temp->prev = _end->prev; // ���½ڵ��ǰ������Ϊ��ǰĩβ�ڵ��ǰ��
        _end->prev->next = temp; // ���µ�ǰĩβ�ڵ��ǰ������һ���ڵ�Ϊ�½ڵ�
        _end->prev = temp; // ���µ�ǰĩβ�ڵ��ǰ��Ϊ�½ڵ�
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