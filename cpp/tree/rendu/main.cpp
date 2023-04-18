#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
typedef int Data;
class BinTreeNode {
    public:
    Data data;
    int visited;
    BinTreeNode *leftChild;
    BinTreeNode *rightChild;
    BinTreeNode():data(0), visited(false), leftChild(NULL), rightChild(NULL){};
    BinTreeNode(Data x):data(x){};
    BinTreeNode(const BinTreeNode &src):data(src.data), leftChild(src.leftChild), rightChild(src.rightChild), visited(src.visited) {};
};
class BinTree {
    private:
    BinTreeNode *rootNode;
    void postFree(BinTreeNode *n) {
        if (n) {
            postFree(n->leftChild);
            postFree(n->rightChild);
            free(n);
            n = NULL;
        }
    };
    BinTreeNode *insertLeftChild(BinTreeNode *parentNode, BinTreeNode &target) {
        BinTreeNode *newNode;
        newNode = new BinTreeNode(target);
        if (!newNode)
            return NULL;
        parentNode->leftChild = newNode;
        return newNode;
    }
    BinTreeNode *insertRightChild(BinTreeNode *parentNode, BinTreeNode &target) {
        BinTreeNode *newNode;
        newNode = new BinTreeNode(target);
        if (!newNode)
            return NULL;
        parentNode->rightChild = newNode;
        return newNode;
    }
    void inOrderBT(BinTreeNode *parentNode, BinTreeNode **target, Data data) {
        if (parentNode) {
            inOrderBT(parentNode->leftChild, target, data);
            if (parentNode->data == data)
                *target= parentNode;
            inOrderBT(parentNode->leftChild, target, data);
        }
    }
    
    public:
    BinTreeNode *getRootNode(){return rootNode;};
    BinTree(BinTreeNode bt) {
        rootNode = new BinTreeNode();
        rootNode->data = bt.data;
        rootNode->leftChild = NULL;
        rootNode->rightChild = NULL;
        rootNode->visited = 0;
    };
    ~BinTree(){
        BinTreeNode *tmp;
        tmp = rootNode;
        postFree(rootNode);
    };
    BinTreeNode *searchBT(Data data) {
        BinTreeNode *tmp = NULL;
        if (rootNode) {
            inOrderBT(rootNode, &tmp ,data);
        }
        return tmp;
    };
    int insertBT(BinTreeNode *n) {
        BinTreeNode *tmp;
        if (searchBT(n->data))
            return FALSE;
        tmp = rootNode;
        while (true) {
            if (tmp->data > n->data) {
                if (!tmp->leftChild) {
                    insertLeftChild(tmp, *n);
                    return TRUE;
                } else {
                    tmp = tmp->leftChild;
                }
            }
            else if (tmp->data < n->data) {
                if (!tmp->rightChild) {
                    insertRightChild(tmp, *n);
                    return TRUE;
                } else {
                    tmp = tmp->rightChild;
                }
            } else {
                return FALSE;
            }
        }
        return TRUE;
    };
    void inOrder(BinTreeNode *parentNode) {
        if (parentNode) {
            inOrder(rootNode->leftChild);
            cout << "[" << parentNode->data <<"]";
            inOrder(parentNode->rightChild);
        }
        cout << endl;
    };
};
int main() {
    BinTreeNode insert;
    insert.data = 7;
    BinTree bt(insert);
    for (int i = 0; i < 15; i++) {
        insert.data = i;
        if (bt.insertBT(&insert) == FALSE)
            cout << "err> duplicated value\n";
    }
    bt.inOrder(bt.getRootNode());
    return 0;
} 