/*���B�z�s�q���ΡA��ĳ�NBinary Heap���������w�q��Dictionary�A
�C�Ӹ�ƶ��جҦ��������Key��(�v��)�A�]�N�OPriority Queue�N�ϥΪ�Key�C 
Min Heap�G
�b�C�@��subtree���Aroot���ukey�v�n����child���ukey�v�٭n�p�G
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
    std::vector<HeapNode> heap;        // �s��HeapNode��ƪ��x�}
    
    //int FindPosition(int node);
    int GetParentNode(int node){return std::floor(node/2);};
public:
    BinaryHeap(){               // default constructor�|��heap[0]���w�d 
        heap.resize(1);         // ����Y�s�WHeapNode, �|�qheap[1]�}�l�s�W
    }
    BinaryHeap(int n){
        heap.resize(n + 1);
    }
    bool IsHeapEmpty(){return (heap.size()<1);};

    // Min-Priority Queue
    void MinHeapify(int node, int length){

    int left = 2*node,          // ���oleft child
        right = 2*node + 1,     // ���oright child
        smallest;               // smallest�ΨӰO���]�troot�Pchild, �T�̤���Key�̤p��node

    if (left <= length && heap[left].key < heap[node].key)
        smallest = left;
    else
        smallest = node;

    if (right <= length && heap[right].key < heap[smallest].key)
        smallest = right;

    if (smallest != node) {                 // �p�G�ثenode��Key���O�T�̤����̤p
        swap(heap[smallest], heap[node]);   // �N�մ�node�P�T�̤�Key�̤p��node����m
        MinHeapify(smallest, length);       // �վ�s��subtree��Min Heap
    }
}
    void BuildMinHeap(std::vector<int> array){

    // �Narray[]����Ʃ�i heap���x�}��, �ùw�d heap[0] �����ϥ�
    for (int i = 0; i < array.size(); i++) {     
        heap[i + 1].element = i;                 // ��array[]��idx����element
        heap[i + 1].key = array[i];              // ��array[]���ƭȵ���key
    }
    for (int i = (int)heap.size()/2; i >= 1 ; i--) {
        MinHeapify(i, (int)heap.size()-1);     // length�n��@, �]��heap�q�q1�}�l�s����
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

    int index_node = FindPosition(node);      // ���node�Ҧb����mindex

    if (newKey > heap[index_node].key) {      // �p�G���O��node��Key�U��, �K�פ�禡
        std::cout << "new key is larger than current key\n";
        return;
    }
    heap[index_node].key = newKey;            // ��snode��Key��, �ݭn�ˬd�O�_�s��subtree����Min Heap
    while (index_node > 1 && heap[GetParentNode(index_node)].key > heap[index_node].key) {
        swap(heap[index_node], heap[GetParentNode(index_node)]);
        index_node = GetParentNode(index_node);
    }
}
    void MinHeapInsert(int node, int key){

    heap.push_back(HeapNode(node,key));    // �bheap[]���ڷs�W�@��node
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
    int min = heap[1].element;    // ����heap���Ĥ@��node�㦳�̤pkey��
                                  // �K�Hmin�O����element, �̫�^��min
    // delete the first element/vertex
    heap[1] = heap[heap.size()-1];            // ��̫�@��element���Ĥ@�Ӧ�m,
    heap.erase(heap.begin()+heap.size()-1);   // �A�R���̫�@��element
    MinHeapify(1, (int)heap.size());          // �ثe, heap[1]�㦳�̤jKey, �ݭn�i��վ�

    return min;       // �^��heap���㦳�̤pkey��element
}             // �^��vertex����mindex

    // void HeapSort();

    // Max-Priority Queue
};

int main(){
	int A={6,4,5,8,1,9,7}
	BinaryHeap A;
	A.
	cout<<A;
}
