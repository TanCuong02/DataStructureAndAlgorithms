#include<iostream>
using namespace std;

struct Student{
	int id;
  	float gpa;
  	string sex;
  	string name; 
};

#define MAX 100

struct Slist{
  int n;
  Student a[MAX]; 
};


void init(Slist& list){
	list.n = 0;
}

void input(Slist& list){
	cin >> list.n;
  	for(int i = 0; i < list.n; i++){
    
    	cin >> list.a[i].id;
      	cin >> list.a[i].gpa;
      	cin >> list.a[i].sex;
      	cin.ignore(); getline(cin, list.a[i].name);
    }
}

void printByID(Slist list){
	for(int i = 0; i < list.n; i++){
      cout << list.a[i].id << " ";
    }
}

bool isFull(Slist list){
  if(list.n == MAX) return true;
  return false;
}

bool insert(Slist& list, int pos, Student newInfo){
  if(!isFull(list) && (0 <= pos && pos <= list.n) ){
	for(int i = list.n; i > pos; i--){
    	list.a[i] = list.a[i-1];
    }
    list.a[pos] = newInfo;
    list.n++;
    return true;
  }
  	return false;
}

bool isEmpty(Slist list){
  if(list.n == 0) return true;
  return false;
}

int indexOf(Slist list, int id){

  for(int i = 0; i < list.n; i++){
  	if(list.a[i].id == id) return i;
  }
  return -1;
}

bool Delete(Slist& list, int pos){
  if(!isEmpty(list) && (0 <= pos && pos < list.n) ){
	for(int i = pos; i < list.n-1; i++){
    	list.a[i] = list.a[i+1];
    }
    list.n--;
    return true;
  }
  	return false;
}

int lastSpacePos(string input){
	for(unsigned int i = input.length()-1; i >= 0; i--){
    	if(input[i] == ' ') return i;
    }
  return -1;
}

string getFirstName(string input){
  int pos = lastSpacePos(input);
  if(pos == -1) return input; 
  string name;
  for(unsigned int i = (pos+1); i < input.length(); i++){
    	name += input[i];
    }
	return name;
}

void findByFirstName(Slist list, string name){
	bool flag = false;
  	for(int i = 0; i < list.n; i++){
    	if(getFirstName(list.a[i].name) == name){
        	flag = true;
          	cout << list.a[i].id << " ";
        }
    }
  if(!flag) cout << "NOT FOUND";
}


int main(){

  Slist students;
  
  init(students);
  
  input(students);
  
  printByID(students);
  cout << endl;
  
  int x; cin >> x;
  Student s; 
  cin >> s.id;
  cin >> s.gpa;
  cin >> s.sex;
  cin.ignore(); getline(cin, s.name);
  int result = insert(students, x, s);
  if(result) printByID(students);
  else cout << "FAILURE";
  cout << endl;
  
  int id; cin >> id;
  int ck = indexOf(students, id);
  result = Delete(students, ck);
  if(result) printByID(students);
  else cout << "FAILURE";
  cout << endl;
  
  string name; cin >> name;
  findByFirstName(students, name);
 return 0;
}
