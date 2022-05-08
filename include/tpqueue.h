// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
private:
    T arr[100];
    int pervoe;
    int poslednee;

public:
    TPQueue() : pervoe(0), poslednee(0) {}
    void push(T z1) {
        if (poslednee - pervoe >= size) {
            throw "Full!";
        } else {
            int z2 = poslednee - 1;
            while ((z2 >= pervoe) && (arr[z2 % size].prior < z1.prior)) {
                arr[(z2 + 1) % size] = arr[z2 % size];
                z2--;
            }
            arr[(z2 + 1) % size] = z1;
            poslednee++;
        }
    }
    T front() {
        return arr[pervoe % size];
    }
    T back() {
        return arr[(poslednee - 1) % size];
    }
    T pop() {
        return arr[(pervoe++) % size];
    }
};
struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
