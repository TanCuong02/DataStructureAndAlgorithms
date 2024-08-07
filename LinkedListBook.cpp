#include <iostream>
#include <string>
using namespace std;

struct Book {
    string code;
    int price;
    string name;
};

struct Node {
    Book info;
    Node* next;
};

struct List {
    Node* head;
};

void init(List& list) {
    list.head = NULL;
}

Node* createNode(Book book) {
    Node* p = new Node;
    if (p != NULL) {
        p->info = book;
        p->next = NULL;
    }
    return p;
}

void append(List& list, Book book) {
    Node* p = createNode(book);
    if (list.head == NULL) {
        list.head = p;
    } else {
        Node* temp = list.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void printCodes(List list) {
    Node* p = list.head;
    while (p != NULL) {
        cout << p->info.code << " ";
        p = p->next;
    }
    cout << endl;
}

void findBooksByName(List list, string keyword) {
    Node* p = list.head;
    bool found = false;
    while (p != NULL) {
        if (p->info.name.find(keyword) != string::npos) {
            cout << p->info.code << " ";
            found = true;
        }
        p = p->next;
    }
    if (!found) {
        cout << "NOT FOUND";
    }
    cout << endl;
}

bool insertAfter(List& list, string code, Book newBook) {
    Node* p = list.head;
    while (p != NULL) {
        if (p->info.code == code) {
            Node* newNode = createNode(newBook);
            newNode->next = p->next;
            p->next = newNode;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool deleteHead(List& list) {
    if (list.head == NULL) {
        return false;
    }
    Node* temp = list.head;
    list.head = list.head->next;
    delete temp;
    return true;
}

bool deleteAfter(List& list, string code) {
    Node* p = list.head;
    while (p != NULL && p->next != NULL) {
        if (p->info.code == code) {
            Node* temp = p->next;
            p->next = p->next->next;
            delete temp;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool deleteByCode(List& list, string code) {
    if (list.head == NULL) return false;
    if (list.head->info.code == code) return deleteHead(list);
    Node* p = list.head;
    while (p->next != NULL) {
        if (p->next->info.code == code) {
            Node* temp = p->next;
            p->next = p->next->next;
            delete temp;
            return true;
        }
        p = p->next;
    }
    return false;
}

int main() {
    List bookList;
    init(bookList);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Book book;
        cin >> book.code >> book.price;
        cin.ignore();
        getline(cin, book.name);
        append(bookList, book);
    }

    string keyword;
    cin >> keyword;

    Book newBook;
    string afterCode;
    cin >> afterCode >> newBook.code >> newBook.price;
    cin.ignore();
    getline(cin, newBook.name);

    string deleteAfterCode, deleteCode;
    cin >> deleteAfterCode >> deleteCode;

    printCodes(bookList);
    findBooksByName(bookList, keyword);

    if (insertAfter(bookList, afterCode, newBook)) {
        printCodes(bookList);
    } else {
        cout << "FAILURE" << endl;
    }

    if (deleteHead(bookList)) {
        printCodes(bookList);
    } else {
        cout << "FAILURE" << endl;
    }

    if (deleteAfter(bookList, deleteAfterCode)) {
        printCodes(bookList);
    } else {
        cout << "FAILURE" << endl;
    }

    if (deleteByCode(bookList, deleteCode)) {
        printCodes(bookList);
    } else {
        cout << "FAILURE" << endl;
    }

    return 0;
}
