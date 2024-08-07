#include <iostream>
using namespace std;

#define MAX 10

struct Queue {
    int front; 
    int a[MAX]; 
    int count;  
};

void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isEmpty(const Queue &q) {
    return q.count == 0;
}

bool isFull(const Queue &q) {
    return q.count == MAX;
}

bool Push(Queue &q, int x) {
    if (!isFull(q)) {
        q.rear = ( q.rear + 1) % MAX;
        q.a[q.rear] = x;
      	q.count ++;
      	return true;
    }
  return false;
    
}

int Pop(Queue &q) {
    if (!isEmpty(q)) {
        int x = q.a[q.front];
        q.front = (q.front + 1) % MAX;
        q.count--;
        return x;
    }
    return -1; 
}

void Display(Queue q) {
if ( !isEmpty(q) ) {
	if (q.front <= q.rear) { 
	for (int i = q.front; i <= q.rear; i++)
	cout << q.a[i] << " ";
	} else { 
		for (int i = q.front; i <= MAX-1; i++)
		cout << q.a[i] << " ";
		for (int i = 0; i <= q.rear; i++)
		cout << q.a[i] << " ";

		}
	}
}

int main() {
    Queue q;
    init(q);

   
    int n;
    cin >> n;
    
    
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        Push(q, elem);
    }

    
    Display(q);
	cout << endl;
    
    int m;
    cin >> m;
    
    
    for (int i = 0; i < m; i++) {
        Pop(q);
    }

   
    Display(q);
	cout << endl;
   
    int k;
    cin >> k;
    int elem;
   
    for (int i = 0; i < k; i++) {
        cin >> elem;
        Push(q, elem);
    }

   
    Display(q);
	cout << endl;
    return 0;
}

