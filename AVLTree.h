typedef struct _node{
    int data;
    struct _node* left;
    struct _node* right;
}Node;

void insertData(Node** root, int data);
void deleteData(Node* root, int data);
Node* reblanceTree(Node* root);
Node* getParentNode(Node* node, int data);
int isRightNode(Node* node);
int isLeftNode(Node* node);
void destroyTree(Node* root);
int getNodeDepth(Node* node);