#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

/* 
 AVL Tree(Adelson-Velsky and Landis(개발자 이름) Tree)
  .Insert
  .Delete
  .Search (*)
  .Reblance (*)
   -RR, RL, LR, LL
*/

void insertData(Node** root, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* parentNode = NULL;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL){
        *root = newNode;
    }else{
        parentNode = getParentNode(*root, data);
        if(parentNode->data < data){
            parentNode->right = newNode;
        }else{
            parentNode->left = newNode;
        }
        //reblanceTree(root);
    }
}

Node* getParentNode(Node* node, int data){
    //소스 코드를 더 잘 줄일 수 있을 것 같다.
    Node* tempParentNode = NULL;

    if(node->data < data){
        if(isRightNode(node)){
            tempParentNode = getParentNode(node->right, data);
        }else{
            tempParentNode = node;
        }
    }else{
        if(isLeftNode(node)){
            tempParentNode = getParentNode(node->left, data);
        }else{
            tempParentNode = node;
        }
    }

    return tempParentNode;
}

int isLeftNode(Node* node){
    return node->left != NULL;
}
int isRightNode(Node* node){
    return node->right != NULL;
}

int isEmptyTree(Node* root){
    return root != NULL;
}

int getMinValueInBST(Node* root){
    if(isLeftNode(root)){
        return getMinValueInBST(root->left);
    }else{
        return root->data;
    }
}


Node* searchNodeEqualData(Node* root, int target){
    if(isEmptyTree(root)){
        return NULL;
    }
    if(root-> data == target){
        return root;
    }else if(root->data > target){
        return searchNodeEqualData(root->left, target);
    }else{
        return searchNodeEqualData(root->right, target);
    }
}

// 이진 검색 트리 삭제 함수
void deleteDataInBST(Node* root, int target){
}

void deleteData(Node* root, int data){
}

Node* getLeftSubTree(Node* root){
    return root->left;
}

Node* getRightSubTree(Node* root){
    return root->right;
}

int getHeight(Node* root){
    int leftHeight;
    int rightHeight;

    if( root == NULL ){
        return 0;
    }

    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int getGapOfHeight(Node* root){
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int gapOfHeight = leftHeight - rightHeight;

    return gapOfHeight;
}

Node* reblanceTree(Node* root){
    int gapOfHeight;

    if(root == NULL){
        return;
    }
    //회전 유형은 어떻게 확인할까?
    root->left = reblanceTree(root->left);
    root->right = reblanceTree(root->right);
    gapOfHeight = getGapOfHeight(root);

    if( -1 <= gapOfHeight || gapOfHeight <= 1 ){
        return root;
    }

    if( gapOfHeight > 1){
        root = (( getGapOfHeight(getLeftSubTree(root)) > 0 )) ? rotateLL(root) : rotateLR(root);
    }else{
        root = (( getGapOfHeight(getRightSubTree(root)) < 0)) ? rotateRR(root) : rotateRL(root);
    }

    return root;
}


void destroyTree(Node* root){
    if(root != NULL){
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
    return;
} 
void showTree(Node* root){

}

int main(void){
    printf("hello world");
}
