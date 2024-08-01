#include<iostream>
using namespace std;

struct Book{
	string id;
  	int price;
  	string name;
};

struct NODE{
	NODE* next;
  	Book info;
};

struct List{
	NODE* head;
};

void init(List& list){
	list.head = NULL;
}

NODE* createNode(Book b){
	NODE* p = new NODE;
  	if(p != NULL){
    	p -> info = b;
      	p -> next = NULL;
    }
  	return p;
}

NODE* insertHead(List& list, Book b){
	NODE* p = createNode(b);
  	if(p != NULL){
    	p -> next = list.head;
      	list.head = p;
    }
  return p;
}

NODE* insertAfter(List& list, NODE* q, Book b){
	NODE* p = createNode(b);
  	if( p != NULL ){
    	p -> next =  q -> next;
      	q -> next = p;
    }
	return p;
}

void input(List& list){
	int n; cin >> n;
  	NODE* q = NULL;
  	for(int i = 0; i < n; i++){
    	Book b;
      	cin >> b.id;
      	cin >> b.price;
      	cin.ignore();
      	getline(cin, b.name);
      	if(i == 0) q = insertHead(list, b);
      	else q = insertAfter(list, q, b);
    }
}

void printfID(List list){
	NODE* p = list.head;
  	while(p != NULL){
    	Book b = p -> info;
      	cout << b.id << " ";
      	p = p -> next;
    }
}

void findByKeyword(List list, string keyword) {
       	NODE* p = list.head;
        bool found = false;
        while (p) {
            if (p->info.name.find(keyword) != string::npos) {
                cout << p ->info.id << " ";
                found = true;
            }
            p = p->next;
        }
        if (!found) {
            cout << "NOT FOUND";
        }
        cout << endl;
    }
  bool insertAfterUseID(List& list, string id, Book newInfo){
        NODE* p = list.head;
        while (p != NULL) {
            if (p -> info.id == id) {
                NODE* newP = createNode(newInfo);
                newP -> next = p -> next;
                p -> next = newP;
                return true;
            }
            p = p -> next;
        }
        return false;
    }

bool deleteFirstBook(List& list) {
    if (list.head != NULL) {
        NODE* p = list.head;
        list.head = list.head->next;
        delete p;
        return true;
    }
    return false;
}

bool deleteBookAfter(List& list, string id) {
    NODE* p = list.head;
    while (p != NULL && p -> next != NULL) {
        if (p -> info.id == id) {
            NODE* q = p -> next;
            p -> next = q -> next;
            delete q;
            return true;
        }
        p = p -> next;
    }
    return false;
}

bool deleteBookById(List& list, string id) {
    if (list.head == NULL) {
        return false;
    }
    if (list.head -> info.id == id) {
        return deleteFirstBook(list);
    }
    NODE* p = list.head;
    while (p -> next != NULL) {
        if (p -> next -> info.id == id) {
            NODE* q = p -> next;
            p -> next = q -> next;
            delete q;
            return true;
        }
        p = p -> next;
    }
    return false;
}


int main(){
  List books;
  init(books);
  input(books);
  printfID(books);
  cout << endl;
  
  string name; cin >> name;
  findByKeyword(books, name);
 
  string id; cin >> id;
  Book b;
  cin >> b.id;
  cin >> b.price;
  cin.ignore();
  getline(cin, b.name);
  
  
  if (insertAfterUseID(books, id, b)) {
      printfID(books);
   	 cout << endl;
  } else {
      cout << "FAILURE" << endl;
  }
  
  if (deleteFirstBook(books)) {
        printfID(books);
    	cout << endl;
    } else {
        cout << "FAILURE" << endl;
   }
  
  string x; cin >> x;
  if (deleteBookAfter(books, x)) {
       printfID(books);
    	cout << endl;
  } else {
        cout << "FAILURE" << endl;
  }
  
  string y; cin >> y;
  
  if (deleteBookById(books, y)) {
         printfID(books);
    	cout << endl;
    } else {
        cout << "FAILURE" << endl;
    }

  
return 0;
}
