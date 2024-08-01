
LLIST01: Qu?n l? danh sách quy?n sách b?ng danh sách liên k?t ðõn
Ð? bài: s? d?ng danh sách liên k?t ðõn ð? qu?n l? danh sách quy?n sách.

Ð?u vào: (các thông tin trên cùng m?t d?ng cách nhau 1 TAB)
- D?ng ð?u tiên: s? nguyên n là s? lý?ng quy?n sách.
- n d?ng ti?p theo: m?i d?ng là thông tin c?a m?t quy?n sách bao g?m:
+ m? sách: ki?u chu?i (không có SPACE)
+ giá bán: ki?u s? nguyên
+ tên sách: ki?u chu?i (có SPACE)
- D?ng k? ti?p: t? khóa keyword ð? t?m ki?m tên sách (không có SPACE).
- D?ng k? ti?p: m? sách A và thông tin m?t quy?n sách m?i c?n ðý?c thêm vào sau quy?n sách có m? sách A.
- D?ng k? ti?p: m? sách B
- D?ng k? ti?p: m? sách C

Ð?u ra: (các thông tin trên cùng m?t d?ng cách nhau 1 SPACE)
- D?ng th? nh?t: danh sách m? sách sau khi kh?i t?o.
- D?ng th? hai: m? sách c?a nh?ng quy?n sách có tên sách ch?a keyword t?m ki?m; và in ra ch? "NOT FOUND" n?u không có quy?n sách nào ch?a keyword týõng ?ng.
- D?ng th? ba: danh sách m? sách sau khi thêm sách m?i vào sau quy?n sách có m? sách A; và in ra ch? "FAILURE" n?u không thêm ðý?c sách.
- D?ng th? tý: danh sách m? sách sau khi xóa quy?n sách ? ð?u danh sách; và in ra ch? "FAILURE" n?u không xóa ðý?c sách.
- D?ng th? nãm: danh sách m? sách sau khi xóa quy?n sách ð?ng sau quy?n sách có m? sách B; và in ra ch? "FAILURE" n?u không xóa ðý?c sách.
- D?ng th? sáu: danh sách m? sách sau khi xóa quy?n sách có m? sách C; và in ra ch? "FAILURE" n?u không xóa ðý?c sách.

Ví d?:
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
