#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::cout;
using std::endl;

class BST;
class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    string element;
public:
    TreeNode():leftchild(0),rightchild(0),parent(0),key(0),element(""){};
    TreeNode(int a, string b):leftchild(0),rightchild(0),parent(0),key(a),element(b){};

    int GetKey(){return key;}              // ���F�bmain()�n����˵�node�O�_���T
    string GetElement(){return element;}   // �~�ݭn�o���member functionŪ��private data

    // ��l���p, �]��class BST�Oclass TreeNode��friend class
    // �bclass BST��member function��, �i�H�����s��class TreeNode��private data

    friend class BST;   // ��b private �� public ���i�H 
};

class BST{
private:
    TreeNode *root;
    TreeNode* Leftmost(TreeNode *current){
    while (current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}
    TreeNode* Successor(TreeNode *current);
public:
    BST():root(0){};    

    TreeNode* Search(int key);
    void InsertBST(int key, string element);
    void InorderPrint();        // �i�H�ΨӽT�{BST�O�_�إߦ��\;
    void Levelorder(){

    std::queue<TreeNode*> q;
    q.push(this->root);                     // ��root�@��level-order traversal���_�I
                                            // ���iqueue��
    while (!q.empty()){                     // �Yqueue���O�Ū�, ����٦�node�S��visiting

        TreeNode *current = q.front();      // ���X���i�Jqueue��node
        q.pop();                          
        std::cout << current->str << " ";   // �i��visiting

        if (current->leftchild != NULL){    // �Yleftchild�����, �N����iqueue
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   // �Yrightchild�����, �N����iqueue
            q.push(current->rightchild);
        }
    }
}
	};

TreeNode* BST::Search(int KEY){

    TreeNode *current = root;               // �Ncurent���Vroot�@��traversal�_�I

    while (current != NULL && KEY != current->key) {  // ��ر��p���X�j��G
                                                      // 1.�S��� 2.�����
        if (KEY < current->key){                      
            current = current->leftchild;   // �V����
        }
        else {
            current = current->rightchild;  // �V�k��
        }
    }
    return current;
}

void BST::InsertBST(int key, string element){

    TreeNode *y = 0;        // �Ƿs�⪨��
    TreeNode *x = 0;        // ��L
    TreeNode *insert_node = new TreeNode(key, element);   // insert_node���N�n�s�W��node

    x = root;
    while (x != NULL) {                 // �bwhile��, �H�p�PSearch()���覡�M��A����m       
        y = x;                          // y����s����x����m
        if (insert_node->key < x->key){ // �P�_x�O�n��left- �٬Oright- �e�i
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                   // ���X�j���, x�Y��NULL
                                        // y�Y��insert_node��parent
    insert_node->parent = y;            // �Ninsert_node��parent pointer���Vy

    if (y == NULL){                     // �U���@��if-else, ��insert_node���WBST
        this->root = insert_node;
    }
    else if (insert_node->key < y->key){
        y->leftchild = insert_node;
    }
    else{
        y->rightchild = insert_node;
    }
}

void BST::InorderPrint(){
    TreeNode *current = new TreeNode;
    current = Leftmost(root);
    while(current){
        cout << current->element << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}
/*
void BST::DeleteBST(int KEY){               // �n�R���㦳KEY��node

    TreeNode *delete_node = Search(KEY);    // ���T�{BST���O�_���㦳KEY��node
    if (delete_node == NULL) {
        std::cout << "data not found.\n";
        return;
    }

    TreeNode *y = 0;      // �u���n�Q�R��������O���骺node
    TreeNode *x = 0;      // �n�Q�R����node��"child"

    if (delete_node->leftchild == NULL || delete_node->rightchild == NULL){
        y = delete_node;
    }
    else{
        y = Successor(delete_node);        // �Ny�]��delete_node��Successor
    }                                      // �g�L�o��if-else, y�վ㦨�ܦh�u���@��child
                                           // �����վ㦨case1��case2�ӳB�z
    if (y->leftchild != NULL){
        x = y->leftchild;                  // �Nx�]��y��child, �i��O���İO����,
    }                                      // �]���i��ONULL
    else{
        x = y->rightchild;
    }

    if (x != NULL){                        // �by�Q�R�����e, �o�ӨB�J��x���^BST
        x->parent = y->parent;             // ���Y���ϤG(c)��, ���ñ��^�t�P�H���B�J
    }
                                           // ���ۦA��n�Q����O���骺node��"parent"���V�s��child
    if (y->parent == NULL){                // �Y�R�����O�����root, �N��x���s��root 
        this->root = x;
    }
    else if (y == y->parent->leftchild){    // �Yy�쥻�O��parent��left child
        y->parent->leftchild = x;           // �K��x�Ҧby��parent��left child, ���Ny
    }
    else{                                   // �Yy�쥻�O��parent��right child
        y->parent->rightchild = x;          // �K��x�Ҧby��parent��right child, ���Ny
    }                                       
                                            // �w��case3
    if (y != delete_node) {                 // �Yy�Odelete_node������, �̫�n�A�Ny�����
        delete_node->key = y->key;          // ��^delete_node���O�����m, �ñNy���O�����m����
        delete_node->element = y->element;  // �ϤG(d), y�Y�O�F��, delete_node�Y�O��|
    }

    delete y;                               // �Ny���O�����m����
    y = 0;
}*/

int main() {

    BST T;

    T.InsertBST(8,"�t�P�H");
    T.InsertBST(1000,"����");
    T.InsertBST(2,"�J�L");
    T.InsertBST(513,"��J");


    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    cout << endl;
    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl << endl;

    TreeNode *node = T.Search(1000);
    if(node != NULL){
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
        cout << "no element with Key(1000)" << endl;
    }

    node = T.Search(73);
    if(node != NULL){
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
        cout << "no element with Key(73)" << endl;
    }

    return 0;
}
