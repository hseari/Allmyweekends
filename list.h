#pragma once

template <typename T>
class Node {
public:
    T val;
    Node* next;    //��������� �� ���� ��
    Node(T val) : val(val), next(nullptr) {}; //�����������
};

template <typename T>
class list {
private:
    Node<T>* begin;
    Node<T>* end;
    int size;

public:

    list() : begin(nullptr), size(0) {}

    bool empty() {
        return begin == nullptr;
    }

    int getsize() {
        return size;
    }

    //1
    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = begin;
        begin = newNode;
        
        size++;
    }
    
    //2+
    template <typename T>
    void push_back(T val) {
        if (begin == nullptr) {
            begin = new Node<T>(val);
        }
        else {
            Node<T>* curr = begin;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node<T>(val);
        }
        size++;
    }

    //3
    template <typename T>
    void push_at(int ind, int val)
    {
        if (ind == 0) {
            push_front(val);
            return;
        }
        if (ind == size) {
            push_back(val);
            return;
        }

        Node* n = new Node<T>(val);
        Node* curr = begin;
        Node* prev = nullptr;

        for (int i = 0; i < ind; i++) { //���� �� ����� ���� �� ������ �� ind
            prev = curr;
            curr = curr->next;
        }
        prev->next = n;  //��������� ���������� � �����
        n->next = curr;  //��������� ����� � �������
        size++;
    }

   
    template <typename T>
    void remove_front() {
        Node<T>* temp = begin;
        begin = begin->next;
        delete temp;
        size--;
    }

    template <typename T>
    void remove_back() {
        if (end == nullptr) return;
        if (begin = end) {  //1 �������
            remove_front();
            return;
        }
        Node* n = begin;
        while (n->next != end) //���� �� ����� ����� �����
            n = n->next;
        n->next = nullptr;
        delete end;
        end = n;  //�������� ����� ��������� �� ������������� �������
        size--;
    }
    //4
    template <typename T>
    void remove_val(int val) {

        Node* prev = nullptr;
        Node* curr = begin;
        while (curr != nullptr) {  //���� ���� �� ������ �� �����
            if (curr->val == val) {
                if (prev == nullptr)
                    begin = curr->next;
                else
                    prev->next = curr->next;    //��������� ���������� �� ���������, �� ���� ������� ������� (1-2-3 => 1-(2-)3 => 1-3)
                delete curr;
                size--;
                return;
            }
            prev = curr;   //������������ ������
            curr = curr->next;
        }
    }
    //5
    template <typename T>
    void remove_ind(int ind) {
        if (ind == 0) {
            remove_front();
            return;
        }
        if (ind == size - 1) {
            remove_back();
            return;
        }

        Node* curr = begin;  //�������
        Node* prev = nullptr;  //����������

        for (int i = 0; i < ind; i++) {  //���� �� �������
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next; //��������� ���������� �� ���������, �� ���� ������� ������� (1-2-3 => 1-(2-)3 => 1-3)
        delete curr; //������� �������
        size--;
    }
    //6
    template <typename T>
    int find_val(int val) {
        Node* curr = begin;
        int ind = 0;
        if (empty()) return -1;
        else {
            while (curr != nullptr) {  //���� �� ������ ���� �� ������ ��������, ������ ������
                if (curr->val == val)
                    return ind;
                curr = curr->next;
                ind++;
            }
            return -1;
        }
    }
    //7
    template <typename T>
    int find_ind(int ind) {
        Node<T>* curr = begin;

        for (int i = 0; i < ind; i++)
        {
            curr = curr->next;
        }

        return curr->val;
    }

    void clear() {
        while (size)
            remove_front<T>();
    }

    template <typename T>
    T getfirstval() {
        return begin->val;
    }

    template <typename T>
    T getlastval() {
        return end->val;
    }
};
