#include <stdio.h>  
#include <stdlib.h>       //malloc,free  
typedef char ElemType;  //抽象类型ElemType指的是字符类型   
//1.链表的定义   
typedef struct node{  
    ElemType data;      //数据域   
    struct node *next;  //指针域   
}LNode,*LinkList; //LNode结构体变量，LinkList结构体指针   
//2.链表的常用操作  
//2.1输出链表  
void print(LinkList head);  
//2.2创建链表-尾插法  
LinkList createTail();   
//2.3创建链表-头插法  
LinkList createHead();  
//2.4求链表的长度  
int length(LinkList head);  
//2.5在链表的第i个结点后插入一个数据域为item的新结点，成功返回1，失败返回-1   
int insertAfter(LinkList head,int i,ElemType item);   
//2.6删除链表的第i个结点  
int del(LinkList head,int i); 
//2.7查找链表的第i个结点 
ElemType search(LinkList head,int i); 
int main()  
{  
    printf("欢迎进入链表操作子系统!\n");  
    printf("1.创建链表-尾插法\n");   
    printf("2.创建链表-头插法\n");   
    printf("----------------------------\n");     
    printf("3.输出链表\n");   
    printf("4.求链表的长度\n");     
    printf("5.在链表的第i个结点后插入一个数据域为item的新结点\n");   
    printf("6.删除链表的第i个结点\n");     
    printf("7.查找链表的第i个结点 \n");   
    printf("8.预留功能2\n");      
    printf("9.预留功能3\n");   
    printf("10.退出系统\n");   
    int choice;         //用户选择   
    LinkList head = NULL;   //初始化链表head为NULL   
    while(~scanf("%d",&choice)){  
        switch(choice){  
            case 1: printf("1.创建链表-尾插法\n");  
                    head = createTail(); 
                    print(head);  
                    break;  
            case 2: printf("2.创建链表-头插法\n"); 
                    head = createHead();  
                    print(head);
                    break;  
            case 3: printf("3.输出链表\n");   
                    print(head);  
                    break; 
            case 4: printf("4.求链表的长度\n");
                    int length_list = length(head); 
                    printf("%d\n",length_list);
                    break;
            case 5: printf("5.在链表的第i个结点后插入一个数据域为item的新结点\n");
                    printf("请输入插入的位置和元素：");
                    int i;
                    char item;
                    scanf("%d %c",&i,&item);
                    if(insertAfter(head,i,item) == 1){
                        printf("插入成功\n");
                        print(head);
                    }
                    else{
                        printf("插入失败\n");
                    }
                    break;
            case 6: printf("6.删除链表的第i个结点\n");
                    printf("请输入要删除的位置：");
                    int j;
                    scanf("%d",&j);
                    if(del(head,j) == 1){
                        printf("删除成功\n");
                        print(head);
                    }
                    else{
                        printf("删除失败\n");
                    }
                    break;
            case 7: printf("7.查找链表的第i个结点\n");
                    printf("请输入要查找的位置：");
                    int l;
                    scanf("%d",&l);
                    if(search(head,l) == -1){
                        printf("查找失败\n");
                    }
                    else{
                        printf("查找成功,元素为:%c\n",search(head,l));
                    }
                    break;
            case 10:printf("系统即将退出，欢迎再次使用！\n");  
                    break;  
            default: continue;
        }  
        if(choice == 10){  
            break;  
        }  
    }          
    return 0;  
}   
  
//2.1输出链表  
void print(LinkList head)  
{  
    if(head == NULL){  
        printf("链表为空表!\n");  
        return;  
    }  
    LinkList p = head;  
    while(p->next != NULL){  
        printf("%c->",p->data);  
        p = p->next;  
    }  
    printf("%c\n",p->data);  //输出最后一个结点并换行   
}  
  
//2.2创建链表-尾插法  
LinkList createTail()  
{  
    //head-表头，tail-表尾，p-新结点的指针   
    LinkList head = NULL,tail,p;      
    //1.输入新结点  
    char ch;  
    while(~scanf("%c",&ch)){  
        if(ch == '#'){  
            break;  
        }   
        //过滤空白字符   
        if(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'){  
            continue;   
        }  
        //分配内存  
        p = (LinkList)malloc(sizeof(LNode));  
        p->data = ch;  
        p->next = NULL;      //指针域初始化为空   
        //2.p结点插入到链表的尾部  
        //2.1链表为空，则新结点p就是链表的头结点   
        if(head == NULL){  
            head = p;  
        }  
        else{   //2.2链表不为空，则新结点加入到链表的尾部   
            tail->next = p;  
        }   
        //2.3更新链表的尾指针tail，使其指向新结点p  
        tail = p;  
    }   
    return head;   
}   
//2.3创建链表-头插法  
LinkList createHead()  
{  
    LinkList head = NULL; 
    //printf("Enter elements to create the linked list (enter '#' to end): \n");
    char ch;
    while (~scanf(" %c", &ch)) {
        if (ch == '#') {
            break;
        }
        //过滤空白字符   
        if(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'){  
            continue;   
        }  
        // 建立新结点
        LinkList newNode = (LinkList)malloc(sizeof(LNode));
        /*if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }*/
        // 新结点数据域赋值
        newNode->data = ch;
        newNode->next = head; // 在头部插入新结点
        // 头指针指向下一个结点
        head = newNode;
    }
    return head;   
}  

//2.4求链表的长度  
int length(LinkList head)  
{  
    if(head == NULL){  
        //printf("链表为空表!\n");  
        return 0;  
    }  
    LinkList p = head;
    int len = 1;  
    while(p->next != NULL){  
        len++;
        p = p->next; 
    }  
    return len;
}  
//2.5在链表的第i个结点后插入一个数据域为item的新结点，成功返回1，失败返回-1   
int insertAfter(LinkList head,int i,ElemType item)  
{  
    LinkList p,s;
    p = head;
    int k = 0;
    while((p->next != NULL) &&(k<i-1) ){
        p = p->next;
        k++;
    }
    if(p==NULL){
        printf("插入位置不合法\n");
        return -1;
    }
    else{
        s = (LinkList)malloc(sizeof(LNode));
        s->data = item;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}   
//2.6删除链表的第i个结点,失败返回-1，成功返回1  
int del(LinkList head, int i)  
{  
    LinkList p, q, s;
    p = head;
    int k = 0;
    while ((p != NULL) && (k < i - 1)) {
        p = p->next;
        k++;
    }
    if (p == NULL) {
        printf("第i-1个结点不存在\n");
        return -1;
    } else {
        if (p->next == NULL) {
            printf("第i个结点不存在\n");
            return -1;
        } else {
            s = p->next;
            p->next = s->next;
            free(s);
            return 1;
        }
    }
}
//2.7查找链表的第i个结点 
ElemType search(LinkList head,int i){
    if (head == NULL || i < 0) {
        printf("输入位置不合法\n");
        return -1; // 返回一个特殊值表示错误
    }

    LinkList p = head;
    int k = 0;

    while (p != NULL && k < i) {
        p = p->next;
        k++;
    }

    if (p == NULL) {
        printf("下标越界\n");
        return -1; // 返回一个特殊值表示错误
    }

    return p->data;
}

