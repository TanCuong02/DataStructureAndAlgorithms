#include<iostream>

using namespace std;

#define MAX 10

struct stack{
  int a[MAX];
  int top;
};

void init(stack &s){
	s.top = 0;
}

bool isFull(stack s) {
	if (s.top == MAX) return true;
	return false;
}

bool push(stack &s, int x) {
	if(!isFull(s)) {
	s.a[s.top] = x;
	s.top++;
	return true;
	}
	return false;
}

void display(stack s) {
	for (int i = 0; i < s.top; i++)
	cout << s.a[i] << " ";
}

bool isEmpty(stack s){
	if(s.top == 0) return true;
  	return false;
}

bool pop(stack &s) {
    if (!isEmpty(s)) {
        s.top--;
        return true;
    }
    return false;
}

int main(){
  stack s;
  init(s);
  
  //line 1
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
  	 cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    push(s, a[i]);
  }
  display(s);
  cout << endl;
  
  //line 2
   int m; 
   cin >> m;
   for (int i = 0; i < m; i++) {
      pop(s);
   }
  display(s);
  cout << endl;
  
  //line 3
  int k; 
  cin >> k;
  for (int i = 0; i <= k; i++) {
    int x; cin >> x;
    push(s, x);
  }
  display(s); 
return 0;
}
