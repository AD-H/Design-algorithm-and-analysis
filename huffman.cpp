#include<iostream>
#include<queue>

using namespace std;
struct node{
    char ch;
    int freq;
    node *left, *right;

    node(char c, int f){
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare{
    bool operator()(node *a,node *b){
        return a -> freq > b->freq;
    }
};

void printCode(node *root, string code){
    if(!root)
        return;
    if(!root->left && !root -> right){
        cout << root -> ch <<":"<<code<<endl;
    }
    printCode(root->left,code+'0');
    printCode(root->right,code+'1');
}
int main(){
    char chars[] = {'A','B','C','D','E','F'};
    int freq[] = {5,9,12,13,16,45};
    int n = 6;
    priority_queue<node*, vector<node*>,compare> pq;
    for(int i = 0;i<n;i++){
        pq.push(new node(chars[i],freq[i]));
    }
    while(pq.size()>1){
        node *left = pq.top();pq.pop();
        node *right = pq.top();pq.pop();

        node* merged = new node('$', left->freq+right->freq);
        merged -> left = left;
        merged -> right  = right;
        pq.push(merged);
    }
    printCode(pq.top(),"");
    return 0;
}
