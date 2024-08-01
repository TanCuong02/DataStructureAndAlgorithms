#include<iostream>
using namespace std;

struct Student{

  int id;
  float gpa;
  string sex;
  string name;
  
};

struct NODE{
	NODE* next;
  	Student info;
};

struct List{
	NODE* head;
};

void init(List& list){
	list.head = NULL;
}

NODE* createNode(Student s){
	NODE* p = new NODE;
  	if( p != NULL ){
    	p -> info = s;
      	p -> next = NULL;
    }
  return p;
}

NODE* insertHead(List& list, Student s){
	NODE* p = createNode(s);
  	if( p != NULL ){
    	p -> next = list.head;
      	list.head = p;
    }
  return p;
}

NODE* insertAfter(List& list, NODE* q,Student s){
	NODE* p = createNode(s);
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
    	Student s;
      	cin >> s.id;
      	cin >> s.gpa;
      	cin >> s.sex;
      	cin.ignore();
      	getline(cin, s.name);
       	
        if(i == 0) q = insertHead(list, s);
        else q = insertAfter(list, q, s);
    } 
  
}

void printfID(List list){
  NODE* p = list.head;
  while( p!=NULL ){
  	Student s = p -> info;
    cout << s.id << " ";
    p = p->next;
  }
}

void swap( Student& a, Student& b){
	Student temp = a;
  	a = b;
  	b = temp;
}

void sort(List list){
	for(NODE* p = list.head; p != NULL; p = p->next){
    	for(NODE* q = p->next; q != NULL; q = q->next){
          	if( p -> info.gpa > q -> info.gpa)
        	swap(p -> info, q -> info);
        }
    }
}

bool isEmpty(List list){
	if(list.head == NULL) return true;
  	return false;
}

bool deleteHead(List& list){
	if(!isEmpty(list)){
    	NODE* p = list.head;
      	list.head = list.head -> next;
      	delete p;
      return true;
    }
  return false;
}

bool deleteAfter(List& list, NODE* q){
	if(q != NULL){
    	NODE* p = q -> next;
      	if(p != NULL){
        	q -> next = p -> next;
          	delete p;
          return true;
        }
    }
  return false;
}

NODE* findByID(List list, int id, NODE* &q){
	NODE* p = list.head;
  	while(p != NULL){
    	if(p -> info.id == id) break;
      	q = p;
      	p = p -> next;
    }
  return p;
}	

bool deleteByID(List& list, int id){
	NODE* q = NULL;
  	NODE* p = findByID(list, id, q);
  	
  	if(p == NULL) return false;
  	
  	if(q == NULL) return deleteHead(list);
  	else return deleteAfter(list, q);
  	
}

void deleteByGPA(List& list, float threshold){
	NODE* p = list.head;
  	while(p != NULL){
    	Student s = p -> info;
      	p = p -> next;
      	if(s.gpa < threshold) deleteByID(list, s.id);
    }
}

int main(){
	List students;
  	init(students);
  	input(students);
  	printfID(students);
  	cout << endl; 
  	sort(students);
  	printfID(students);
 	cout << endl; 
  	deleteByGPA(students, 7.0);
  	printfID(students);
return 0;
}
