#ifndef PQ_HPP
#define PQ_HPP

#include <iostream>
#include <vector>
#include <cassert>

using std::cout;
using std::endl;
using std::vector;

template <class T>
class pq {
    private:
        struct  item;
        vector<item> heap;

        //Helper functions
        int     left(int);
        int     right(int);
        int     parent(int);
        int     min_child(int);
        void    heapify_up(int);
        void    heapify_down(int);
        void    swap(item&, item&);
    public:
        pq()    {};
        void    insert(T, int);
        T       first();
        int     first_priority();
        T       remove_first();
        int     size();
        bool    is_empty();
        void    display_heap();
};

template <class T>
struct pq<T>::item {
    T   data;
    int priority;

    item(T Data, int Priority) {
        data = Data;
        priority = Priority;
    }
};

template <class T>
int pq<T>::left(int parent) {
    int l = 2 * parent + 1;
    if (l < heap.size()) {
        return l;
    } else {
        return -1;
    }
}

template <class T>
int pq<T>::right(int parent) {
    int r = 2 * parent + 2;
    if (r < heap.size()) {
        return r;
    } else {
        return -1;
    }
}

template <class T>
int pq<T>::min_child(int parent) {
    int l = left(parent);
    int r = right(parent);
    if (l == -1) {
        return -1;
    } else if (r == -1) {
        return l;
    } else if (heap[r].priority < heap[l].priority) {
        return r;
    } else {
        return l;
    }
}

template <class T>
int pq<T>::parent(int child) {
    int p = (child - 1) / 2;
    if (p < 0) {
        return -1;
    } else {
        return p;
    }
}

template <class T>
void pq<T>::swap(item& a, item& b) {
    item temp = a;
    a = b;
    b = temp;
}

template <class T>
void pq<T>::heapify_up(int child) {
    while (parent(child) != -1 && heap[parent(child)].priority > heap[child].priority) {
        swap(heap[parent(child)], heap[child]);
        child = parent(child);
    }
}

template <class T>
void pq<T>::heapify_down(int parent) {
    while (min_child(parent) != -1 && heap[parent].priority > heap[min_child(parent)].priority) {
        swap(heap[min_child(parent)], heap[parent]);
        parent = min_child(parent);
    }
}

template <class T>
bool pq<T>::is_empty() {
    return heap.empty();
}

template <class T>
T pq<T>::first() {
    assert(!is_empty());
    return heap[0].data;
}

template <class T>
int pq<T>::first_priority() {
    assert(!is_empty());
    return heap[0].priority;
}

template <class T>
int pq<T>::size() {
    return heap.size();
}

template <class T>
void pq<T>::insert(T data, int priority) {
    heap.push_back(item(data, priority));
    heapify_up(heap.size() - 1);
}

template <class T>
T pq<T>::remove_first() {
    assert(!is_empty());
    T first = heap[0].data;
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify_down(0);
    return first;
}

template <class T>
void pq<T>::display_heap() {
    cout << "Data     --> ";
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i].data << " ";
    }
    cout << endl;
    cout << "Priority --> ";
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i].priority << " ";
    }
    cout << endl;
    cout << endl;
}

#endif