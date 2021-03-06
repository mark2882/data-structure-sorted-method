/*為處理廣義情形，建議將Binary Heap中的元素定義為Dictionary，
每個資料項目皆有其對應的Key值(權重)，也就是Priority Queue將使用的Key。 
Min Heap：
在每一個subtree中，root之「key」要比兩個child之「key」還要小：
Key(i)<Key(2i)
Key(i)<Key(2i+1)*/
#include<iostream>
#include<vector>
using namespace std;

struct HeapNode{
    int element, key;
    HeapNode():element(0),key(0){};
    HeapNode(int node, int key):element(node), key(key){};
};


class BinaryHeap{
private:
    std::vector<HeapNode> heap;        // 存放HeapNode資料的矩陣
    
    //int FindPosition(int node);
    int GetParentNode(int node){return std::floor(node/2);};
public:
    BinaryHeap(){               // default constructor會把heap[0]給預留 
        heap.resize(1);         // 之後若新增HeapNode, 會從heap[1]開始新增
    }
    BinaryHeap(int n){
        heap.resize(n + 1);
    }
    bool IsHeapEmpty(){return (heap.size()<1);};

    // Min-Priority Queue
    void MinHeapify(int node, int length){

    int left = 2*node,          // 取得left child
        right = 2*node + 1,     // 取得right child
        smallest;               // smallest用來記錄包含root與child, 三者之中Key最小的node

    if (left <= length && heap[left].key < heap[node].key)
        smallest = left;
    else
        smallest = node;

    if (right <= length && heap[right].key < heap[smallest].key)
        smallest = right;

    if (smallest != node) {                 // 如果目前node的Key不是三者中的最小
        swap(heap[smallest], heap[node]);   // 就調換node與三者中Key最小的node之位置
        MinHeapify(smallest, length);       // 調整新的subtree成Min Heap
    }
}
    void BuildMinHeap(std::vector<int> array){

    // 將array[]的資料放進 heap之矩陣中, 並預留 heap[0] 不做使用
    for (int i = 0; i < array.size(); i++) {     
        heap[i + 1].element = i;                 // 把array[]的idx視為element
        heap[i + 1].key = array[i];              // 把array[]的數值視為key
    }
    for (int i = (int)heap.size()/2; i >= 1 ; i--) {
        MinHeapify(i, (int)heap.size()-1);     // length要減一, 因為heap從從1開始存放資料
    }
}
	void swap(struct HeapNode &p1, struct HeapNode &p2){

    struct HeapNode temp = p1;
    p1 = p2;
    p2 = temp;
}
	int FindPosition(int node){

    int idx = 0;
    for (int i = 1; i < heap.size(); i++) {
        if (heap[i].element == node) {
            idx = i;
        }
    }
    return idx;
}
    void DecreaseKey(int node, int newKey){

    int index_node = FindPosition(node);      // 找到node所在的位置index

    if (newKey > heap[index_node].key) {      // 如果不是把node的Key下修, 便終止此函式
        std::cout << "new key is larger than current key\n";
        return;
    }
    heap[index_node].key = newKey;            // 更新node之Key後, 需要檢查是否新的subtree滿足Min Heap
    while (index_node > 1 && heap[GetParentNode(index_node)].key > heap[index_node].key) {
        swap(heap[index_node], heap[GetParentNode(index_node)]);
        index_node = GetParentNode(index_node);
    }
}
    void MinHeapInsert(int node, int key){

    heap.push_back(HeapNode(node,key));    // 在heap[]尾巴新增一個node
    DecreaseKey(node, key);
}
    int Minimum(){
    return heap[1].element;
}
    int ExtractMin(){

    if (IsHeapEmpty()) {
        std::cout << "error: heap is empty\n";
        exit(-1);
    }
    int min = heap[1].element;    // 此時heap的第一個node具有最小key值
                                  // 便以min記錄其element, 最後回傳min
    // delete the first element/vertex
    heap[1] = heap[heap.size()-1];            // 把最後一個element放到第一個位置,
    heap.erase(heap.begin()+heap.size()-1);   // 再刪除最後一個element
    MinHeapify(1, (int)heap.size());          // 目前, heap[1]具有最大Key, 需要進行調整

    return min;       // 回傳heap中具有最小key的element
}             // 回傳vertex的位置index

    // void HeapSort();

    // Max-Priority Queue
};

int main(){
	int A={6,4,5,8,1,9,7}
	BinaryHeap A;
	A.
	cout<<A;
}
