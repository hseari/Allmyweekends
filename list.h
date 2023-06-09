#pragma once

template <typename T>
class Node {
public:
    T val;
    Node* next;    //указатель на след эл
    Node(T val) : val(val), next(nullptr) {}; //конструктор
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

        for (int i = 0; i < ind; i++) { //идем по листу пока не дойдем до ind
            prev = curr;
            curr = curr->next;
        }
        prev->next = n;  //связываем предыдущий с новым
        n->next = curr;  //связываем новый с текущим
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
        if (begin = end) {  //1 елемент
            remove_front();
            return;
        }
        Node* n = begin;
        while (n->next != end) //идем до почти конца листа
            n = n->next;
        n->next = nullptr;
        delete end;
        end = n;  //присваем концу указатель на предпоследний элемент
        size--;
    }
    //4
    template <typename T>
    void remove_val(int val) {

        Node* prev = nullptr;
        Node* curr = begin;
        while (curr != nullptr) {  //идем пока не дойдем до конца
            if (curr->val == val) {
                if (prev == nullptr)
                    begin = curr->next;
                else
                    prev->next = curr->next;    //связываем предыдущий со следующим, то есть огибаем текущий (1-2-3 => 1-(2-)3 => 1-3)
                delete curr;
                size--;
                return;
            }
            prev = curr;   //перемещаемся вправо
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

        Node* curr = begin;  //текущий
        Node* prev = nullptr;  //предыдущий

        for (int i = 0; i < ind; i++) {  //идем до индекса
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next; //связываем предыдущий со следующим, то есть огибаем текущий (1-2-3 => 1-(2-)3 => 1-3)
        delete curr; //удаляем текущий
        size--;
    }
    //6
    template <typename T>
    int find_val(int val) {
        Node* curr = begin;
        int ind = 0;
        if (empty()) return -1;
        else {
            while (curr != nullptr) {  //идем по списку пока не найдем значение, вернем индекс
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
