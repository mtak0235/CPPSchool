#include <iostream>
template<class Data>
class QueueArray {
    Data data[100];
    int cnt = 0;
    public:
    bool enqueue(Data t) {
        if (cnt== 100)
            return false;
        data[cnt++] = t;
        return true;
    }
    Data dequeue() {
        if (!cnt) return -1;
        Data ret = data[0];
        for (int i = 0; i < cnt - 1; i++)
            data[i] = data[i + 1];
        cnt--;
        return ret;
    }
    void display() {
        for (int i = 0; i < cnt; i++) {
            std::cout << data[i] << " ";
        }
        std::cout <<std::endl;
    }
};

template<class Data>
class Node{
    public:
    Data data;
    Node *next;
    Node(Data data, Node *next = NULL):data(data), next(next) {};
};
template<class V>
class QueueLL {
    public:
    V *data = NULL;
    void enqueue(V v) {
        if (!data) {
            data = new V(v);
            return ;
        }
        V *t = data;
        while (t->next) 
            t = t->next;
        t->next = new V(v);
    }
    void dequeue() {
            if (!data) return ;
            V *d = data;
            data =  d->next;
            delete d;
    }
    void display() {
        V *t = data;
        while (t) {
            std::cout << t->data << " ";
            t = t->next;
        }
        std::cout << std::endl;
    }
    ~QueueLL() {
        V *t = data;
        while (t && t->next) {
            V *d = t;
            t = t->next;
            delete d;
        }
    }
};
int main() {
    QueueArray<int> qa;
    for (int i = 0; i < 10; i++)
        qa.enqueue(i);
    std::cout << "queue made by array\n";
    qa.display();
    for (int i = 0; i < 5; i++)
        qa.dequeue();
    qa.display();
    QueueLL<Node<int>> ql;
    std::cout << "queue made by linked list\n";
    for (int i = 0; i < 10; i++) {
        Node<int> n(i);
        ql.enqueue(n);
    }
    ql.display();
    for (int i = 0; i < 5; i++)
        ql.dequeue();
    ql.display();
}