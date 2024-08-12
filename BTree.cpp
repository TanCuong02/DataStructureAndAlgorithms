#include<iostream>
using namespace std;

struct NODE{
	int info;
  	NODE* left;
  	NODE* right;
};

NODE* CreateNode(int x) {
	NODE* p = new NODE;
	if (p != NULL) {
	p->info = x;
	p->left = NULL;
	p->right = NULL;
}
	return p;
}

struct Tree{
	NODE* root;
};

void init(Tree& tree){
	tree.root = NULL;
}

void CreateTree(NODE* &p) {
	int x; cin >> x;
  	if (x == -1) return;
	p = CreateNode(x);
	if (p != NULL) {
		CreateTree(p->left);
		CreateTree(p->right);
	}
}


void NLR(NODE* p) {
	if (p == NULL) return;
	cout << p->info << " ";
	NLR(p->left);
	NLR(p->right);
}

void LNR(NODE* p) {
	if (p == NULL) return;
	LNR(p->left);
	cout << p->info << " ";
	LNR(p->right);
}

void LRN(NODE* p) {
	if (p == NULL) return;
	LRN(p->left);
	LRN(p->right);
	cout << p->info << " ";
}

int CountNode(NODE* p) {
	if (p == NULL) return 0;
	int a = CountNode(p->left);
	int b = CountNode(p->right);
	return (a + b + 1);
}

int CountLeafNode(NODE* p) {
	if (p == NULL) return 0;
	int a = CountLeafNode(p->left);
	int b = CountLeafNode(p->right);
	if (p->left == NULL && p->right == NULL)
		return (a + b + 1);
	else
		return (a + b);
}
int CountBranchNode(NODE* p) {
	int totalNodes = CountNode(p);
	int leafNodes = CountLeafNode(p);
	return totalNodes - leafNodes;
}

int GetHeight(NODE* p) {
	if (p == NULL) return -1; 
	int a = GetHeight(p->left);
	int b = GetHeight(p->right);
	int max = a > b ? a : b;
	return (max + 1);
}

void DisplayAtLevel(NODE* p, int k) {
	if (p == NULL) return;
	if (k == 0) {
	cout << p->info << " ";
	return;
	}
	DisplayAtLevel(p->left, k - 1);
	DisplayAtLevel(p->right, k - 1);
}

int main(){
  
  Tree tree;
  init(tree);
  CreateTree(tree.root);
  NLR(tree.root); cout << endl;
  LNR(tree.root); cout << endl;
  LRN(tree.root); cout << endl;
  cout << GetHeight(tree.root) << " " << CountNode(tree.root) << " " << CountLeafNode(tree.root) << " " << CountBranchNode(tree.root) << endl;
  DisplayAtLevel(tree.root, GetHeight(tree.root));
return 0;
}
