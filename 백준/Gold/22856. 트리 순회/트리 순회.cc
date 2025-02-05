#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
 
struct node{
    int data;
    node *left = NULL;
    node *right = NULL;
};
 
 
int n;
int Counter = 0;
 
int start_data,end_data;
vector<node> tree(100001);
bool visited[100001];
int parents[100001];
 
void init(){
    cin >> n;
    for(int i = 0;i<n;i++){
        int rootnode;
        int leftnode;
        int rightnode;
        cin >> rootnode >> leftnode >> rightnode;
        tree[rootnode].data = rootnode;
 
        if(leftnode != -1){
            tree[rootnode].left = &tree[leftnode];
            parents[leftnode] = rootnode;
        }
        if(rightnode != -1){
            tree[rootnode].right = &tree[rightnode];
            parents[rightnode] = rootnode;
        }
    }
 
}
 
 
void inorder(node *currentnode){
 
    if(currentnode == NULL){
        return;
    }
    inorder(currentnode->left);
    end_data = currentnode->data;
    inorder(currentnode->right);
}
 
void different_inorder(node *currentnode){
   
    //현재 위치한 노드의 왼쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 왼쪽 자식 노드로 이동한다.
    if(currentnode->left != NULL && visited[currentnode->left->data] == false){
        visited[currentnode->left->data] = true;\
        Counter += 1;
        different_inorder(currentnode->left);
    }
    //그렇지 않고 현재 위치한 노드의 오른쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 
    //오른쪽 자식 노드로 이동한다.
    else if(currentnode->right != NULL && visited[currentnode->right->data] == false){
        visited[currentnode->right->data] = true;
        Counter += 1;
        different_inorder(currentnode->right);
    }
    //그렇지 않고 현재 노드가 유사 중위 순회의 끝이라면, 유사 중위 순회를 종료한다.
    else if(currentnode->data == end_data){
       return;
    }
    //그렇지 않고 부모 노드가 존재한다면, 부모 노드로 이동한다.
    else{
        Counter+=1;
        different_inorder(&tree[parents[currentnode->data]]);
    }
 
}
 
 
 
 
int main(void){
    init();
    parents[1] = 1;
    inorder(&tree[1]);
    different_inorder(&tree[1]);
    cout << Counter;
}