
LLIST01: Qu?n l? danh s�ch quy?n s�ch b?ng danh s�ch li�n k?t ��n
�? b�i: s? d?ng danh s�ch li�n k?t ��n �? qu?n l? danh s�ch quy?n s�ch.

�?u v�o: (c�c th�ng tin tr�n c�ng m?t d?ng c�ch nhau 1 TAB)
- D?ng �?u ti�n: s? nguy�n n l� s? l�?ng quy?n s�ch.
- n d?ng ti?p theo: m?i d?ng l� th�ng tin c?a m?t quy?n s�ch bao g?m:
+ m? s�ch: ki?u chu?i (kh�ng c� SPACE)
+ gi� b�n: ki?u s? nguy�n
+ t�n s�ch: ki?u chu?i (c� SPACE)
- D?ng k? ti?p: t? kh�a keyword �? t?m ki?m t�n s�ch (kh�ng c� SPACE).
- D?ng k? ti?p: m? s�ch A v� th�ng tin m?t quy?n s�ch m?i c?n ��?c th�m v�o sau quy?n s�ch c� m? s�ch A.
- D?ng k? ti?p: m? s�ch B
- D?ng k? ti?p: m? s�ch C

�?u ra: (c�c th�ng tin tr�n c�ng m?t d?ng c�ch nhau 1 SPACE)
- D?ng th? nh?t: danh s�ch m? s�ch sau khi kh?i t?o.
- D?ng th? hai: m? s�ch c?a nh?ng quy?n s�ch c� t�n s�ch ch?a keyword t?m ki?m; v� in ra ch? "NOT FOUND" n?u kh�ng c� quy?n s�ch n�o ch?a keyword t��ng ?ng.
- D?ng th? ba: danh s�ch m? s�ch sau khi th�m s�ch m?i v�o sau quy?n s�ch c� m? s�ch A; v� in ra ch? "FAILURE" n?u kh�ng th�m ��?c s�ch.
- D?ng th? t�: danh s�ch m? s�ch sau khi x�a quy?n s�ch ? �?u danh s�ch; v� in ra ch? "FAILURE" n?u kh�ng x�a ��?c s�ch.
- D?ng th? n�m: danh s�ch m? s�ch sau khi x�a quy?n s�ch �?ng sau quy?n s�ch c� m? s�ch B; v� in ra ch? "FAILURE" n?u kh�ng x�a ��?c s�ch.
- D?ng th? s�u: danh s�ch m? s�ch sau khi x�a quy?n s�ch c� m? s�ch C; v� in ra ch? "FAILURE" n?u kh�ng x�a ��?c s�ch.

V� d?:
- input:
5
B01 7 Nhap mon lap trinh
B02 17 Cau truc du lieu va giai thuat
B03 13 Lap trinh huong doi tuong
B04 35 Phan tich thiet ke giai thuat
B05 21 Ky thuat lap trinh nang cao
trinh
B03 B06 69 Lap trinh game
B04
B03
- output:
B01 B02 B03 B04 B05
B01 B03 B05
B01 B02 B03 B06 B04 B05
B02 B03 B06 B04 B05
B02 B03 B06 B04
B02 B06 B04
Please choose a language 
C/C++ (g++ 9.2.0)
   Please choose a server 
SERVER 1
  
21
    list.head = NULL;
22
}
23
?
24
void printfID(List list){
25
    NODE* p = list.head;
26
    while(p != NULL){
27
        Book b = p -> info;
28
        cout << b.id << " ";
29
        p  = p -> next;
30
    }
31
}
32
?
33
NODE* createNode(Book b){
34
    NODE* p = new NODE;
35
    if(p != NULL){
36
        p -> info = b;
37
        p -> next = NULL;
38
    }
39
  return p;
40
}
41
?
42
NODE* insertHead(List& list, Book b){
43
    NODE* p = createNode(b);
44
    if( p != NULL ){
45
        p -> next = list.head;
46
        list.head = p;
47
    }
48
  return p;
49
}
50
?
51
NODE* insertAfter(List& list, NODE* q, Book b){
52
    NODE* p = createNode(b);
53
    if( p != NULL ){
54
        p -> next =  q -> next;
55
        q -> next = p;
56
    }
57
  return p;
58
}
59
?
60
void input(List& list){
61
        int n; cin >> n;
62
        NODE* q = NULL;
63
        for(int i = 0; i < n; i++){
64
        Book b;
65
        cin >> b.id;
66
        cin >> b.price;
67
        cin.ignore();
68
        getline(cin, b.name);
69
        
70
        if(i == 0) q = insertHead(list, b);
71
        else q = insertAfter(list, q, b);
72
    } 
73
}
74
?
75
?
76
void findName(List list, string name){
77
    bool flag = false;
78
    for(NODE* p = list.head; p != NULL; p = p->next){
79
        if( (p->info.name) == name){
80
            flag = true;
81
            cout << p -> info.id << " ";
82
        }
83
    }
84
  if(!flag) cout << "NOT FOUND";
85
}
86
?
87
int main(){
88
    List books;
89
    init(books);
90
    input(books);
91
    printfID(books);
92
    cout << endl; 
93
    string fname; cin >> fname;
94
    findName(books, fname);
95
    
96
return 0;
97
}
5
B01 7 Nhap mon lap trinh
B02 17 Cau truc du lieu va giai thuat
B03 13 Lap trinh huong doi tuong
B04 35 Phan tich thiet ke giai thuat
B05 21 Ky thuat lap trinh nang cao
trinh
B01 B02 B03 B04 B05 
NOT FOUND
