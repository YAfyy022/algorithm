//
// Created by GuoylyL on 2022/9/16.
//
//堆结构 就是用数组实现二叉树 完全二叉树
//一个数组组成的二叉树中  左孩子 2i+1 右孩子 2i+2 父节点 （i-1）/2 向下取整
//不使用0位置， i的左孩子 2i（i<<1） 右孩子 2i+1(i<<1 | 1) 父节点 i/2(i>>1) 向下取整， 因为i位置频繁计算左孩子的下标，则可进行位运算
//大根堆 ： i >= 2i && i >> 2i+1
//小根堆 ： i<= 2i && i<= 2i+1
#include <iostream>
#include <vector>
#include <queue>

void my_swap(std::vector<int> &arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

class Heap {
public:
    Heap(const int limit) : limit(limit), HeapSize(0) {
        for (int i = 0; i < limit; i++) {
            heap.push_back(0);
        }
    }

    bool isFull() {
        if (HeapSize == limit)
            return true;
    }

    bool isEmpty() {
        return HeapSize == 0;
    }

    // 新加进来的数，现在停在了index位置，请依次往上移动，
    // 移动到0位置，或者干不掉自己的父亲了，停！
    void heap_insert(int index) {
        while (heap[index] > heap[(index - 1) / 2]) {
            my_swap(heap, index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }

    void push(int data) {
        if (HeapSize == limit) {
            throw HeapSize;
        }
        heap[this->HeapSize] = data;
        heap_insert(this->HeapSize++);
    }

    //heapify 从index位置往下看，不断的下沉，停止条件为 我的孩子都不在比我大或者没有孩子时
    void heapify(int index, int heapSize) {
        int left = 2 * index + 1;
        while (left < heapSize) {
            // 两个孩子中，谁的值大，把下标给largest
            // 1）只有左孩子，left -> largest
            // 2) 同时有左孩子和右孩子，右孩子的值<= 左孩子的值，left -> largest
            // 3) 同时有左孩子和右孩子并且右孩子的值> 左孩子的值， right -> largest
            int largest = heap[left] < heap[left + 1] && left + 1 < heapSize ? left + 1 : left;
            largest = heap[index] > heap[largest] ? index : largest;
            if (largest == index) break;
            my_swap(heap, index, largest);
            index = largest;
            left = 2 * index + 1;
        }
    }

    // 用户此时，让你返回最大值，并且在大根堆中，把最大值删掉
    // 剩下的数，依然保持大根堆组织
    int pop() {
        int max = heap[0];
        my_swap(heap, 0, --HeapSize);
        heapify(0, HeapSize);
        return max;
    }

    void veiw() {

        for (auto i: heap) {
            std::cout << i << ',';
        }
        std::cout << '\n';
    }

    void heapSort() {
        if (heap.empty()) return;
        for (int i = 0; i < heap.size(); i++) {
            heap_insert(i);
        }
        //std::cout<<get_length(arr)<<'\n';
        int heapSize = heap.size();
        my_swap(heap, 0, --heapSize);
        while (heapSize > 0) {
            heapify(0, heapSize);
            my_swap(heap, 0, --heapSize);
        }
    }


private:
    std::vector<int> heap;
    const int limit;
    int HeapSize;
};

//int main(){
//    Heap h(21);
//    for(int i =0;i<21;i++){
//        h.push((rand()%100)*i);
//    }
//    h.veiw();
//    int max = h.pop();
//    std::cout << "the max is : "<<max <<std::endl;
//    h.veiw();
//    h.heapSort();
//    h.veiw();
//    return 0;
//}

