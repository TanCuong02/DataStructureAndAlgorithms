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

int InsertNode(NODE* &p, int x) {
	if (p != NULL) { 
		if (p->info == x) return 0;
		else if (p->info > x) return InsertNode(p->left, x);
		else if (p->info < x) return InsertNode(p->right, x);
	} else {
		p = CreateNode(x);
		if (p == NULL) return -1;
		return 1;
	}
}

void CreateBSTree(NODE* &p) {
	while (true) {
	int x; cin >> x;
	if (x == -1) break;
		InsertNode(p, x);
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

int GetMinValue(NODE* p) {
	if (p->left == NULL) return p->info;
	return GetMinValue(p->left);
}

int GetMaxValue(NODE* p) {
	if (p->right == NULL) return p->info;
  	return GetMaxValue(p->right);
}

NODE* SearchNode(NODE* p, int x, int &level) {
	if (p == NULL) return NULL;
	if (p->info == x) return p;
  	level++;
	if (p->info > x) return SearchNode(p->left, x, level);
	if (p->info < x) return SearchNode(p->right, x, level);	
}

void SearchStandFor(NODE* &q, NODE* &sf) {
	if (sf->left != NULL) SearchStandFor(q, sf->left);
	else {
		q->info = sf->info;
		q = sf;
		sf = sf->right;
	}
}

bool DeleteNode(NODE* &p, int x) {
	if (p == NULL) return false;
	if (p->info > x) return DeleteNode(p->left, x);
	if (p->info < x) return DeleteNode(p->right, x);
	if (p->info == x) {
		NODE* q = p;
	if (p->left == NULL && p->right == NULL)
		p = NULL;
	else if (p->left == NULL)
		p = p->right;
	else if (p->right == NULL)
		p = p->left;
	else
		SearchStandFor(q, p->right);
		delete q; return true;
	}
}

int main(){
  
  Tree tree;
  init(tree);
  CreateBSTree(tree.root);
  NLR(tree.root); cout << endl;
  LNR(tree.root); cout << endl;
  LRN(tree.root); cout << endl;
  cout << GetMinValue(tree.root); cout << " "; 
  cout << GetMaxValue(tree.root); cout << endl;
  int x; cin >> x;
  int level = 0;
  NODE* p =  SearchNode(tree.root, x, level);
  if(p != NULL) cout << level << endl;
  else cout << -1 << endl;
  
  int y; cin >> y;
  int result = DeleteNode(tree.root, y);
  if(result) LNR(tree.root);
  else cout << "FAILURE";
  
return 0;
}
