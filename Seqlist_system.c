#include <stdio.h>
#include <stdlib.h>
//const int MaxSize = 100 + 5;  //顺序表的最大长度
#define MaxSize (100+5)
typedef int ElemType; //当前顺序表的数据类型是整型
typedef struct {
    ElemType a[MaxSize];//顺序表的元素
    int n;//顺序表的长度
} SeqList;
//输出系统菜单
void printMenu();
//0.输出顺序表sq 
void print(SeqList sq);
//1.创建顺序表sq，写操作要用指针 
void create(SeqList *sq);
//2.查找一个元素item在顺序表的位置；找不到返回-1
int findPos(SeqList sq, ElemType item);
//3.在顺序表的第i个位置插入一个元素item，插入成功返回1；失败返回-1
int insert(SeqList *sq, int i, ElemType item);
//4.删除顺序表第i个位置的元素
int del(SeqList *sq, int i);
//5.修改顺序表第i个位置的元素
int modify(SeqList *sq, int i, ElemType item);
//6.对顺序表sq排序
void sort(SeqList *sq);
//7.在有序的顺序表中插入一个元素item
void insertSorted(SeqList *sq, ElemType item);
//8.合并2个有序表s1和s2到新表sq
void mergeSorted(SeqList *sq, SeqList s1, SeqList s2);

int main() {
    
    //打印主菜单
    printMenu();
    int choice, p, x;  //用户选择，位置，插入元素
    SeqList sq;        //初始化顺序表为空表 
    sq.n = 0;
    //进入菜单循环 
    while (~scanf("%d", &choice)) {
        switch (choice) {
            case 0:
                printf("0.输出顺序表\n");
                print(sq);
                break;
            case 1:
                printf("1.创建顺序表\n");
                create(&sq);
                printf("创建成功，输出顺序表\n");
                print(sq);
                break;
            case 2:
                printf("2.查找一个元素item在顺序表的位置\n");
                printf("请输入你要查找的元素item:");
                scanf("%d",&x);
                printf("%d\n",findPos(sq, x));
                break;
            case 3:
                printf("3.在顺序表第i个位置插入一个元素item\n");
                printf("请输入插入的位置和元素：");
                scanf("%d%d", &p, &x);
                if (insert(&sq, p, x) == -1) {
                    printf("插入失败！\n");
                } else {
                    printf("插入成功！\n");
                    print(sq);
                }
                break;
            case 4:
                printf("4.删除顺序表第i个位置的元素\n");
                printf("请输入你要删除的位子i:");
                scanf("%d",&p);
                if(del( &sq, p) == -1){
                    printf("删除失败！\n");
                }else{
                    printf("删除成功！\n");
                    print(sq);
                }
                break;
            case 5:
                printf("5.修改顺序表第i个位置的元素\n");
                printf("请输入你要修改的位子i和元素x:");
                scanf("%d %d",&p,&x);
                int ret = modify(&sq,p,x);
                if (ret==-1)printf("修改失败！\n");
                else {
                    printf("修改成功！\n");
                    print(sq);
                }
                break;
            case 6:
                printf("6.对顺序表sq排序\n");
                sort(&sq);
                print(sq);
                break;
            case 7:
                printf("7.在有序的顺序表中插入一个元素item\n");
                printf("请输入你要插入的元素item:");
                scanf("%d",&x);
                insertSorted(&sq,x);
                print(sq);
                break;
            case 8:
                printf("8.合并有序表\n");
                SeqList s1, s2;
                printf("请输入2个有序表(务必从小到大排序):\n");
                create(&s1);
                create(&s2);
                mergeSorted(&sq, s1, s2);
                print(sq);
                break;
            case 19:
                printMenu();
                return 0;
            case 20:
                printf("系统即将退出，欢迎再次使用！\n");
                return 0;
            default:
                printf("你的选择有误，请重新输入！\n");
        }
    }

    return 0;
}

//输出系统菜单
void printMenu() {
    printf("欢迎进入顺序表操作子系统!\n");
    printf("--------------------------------------------\n");
    printf("0.输出顺序表\n");
    printf("1.创建顺序表\n");
    printf("2.查找一个元素item在顺序表的位置\n");
    printf("3.在顺序表第i个位置插入一个元素item\n");
    printf("4.删除顺序表第i个位置的元素\n");
    printf("5.修改顺序表第i个位置的元素\n");
    printf("*******************************************\n");
    printf("6.对顺序表sq排序\n");
    printf("7.在有序的顺序表中插入一个元素item\n");
    printf("8.合并有序表\n");
    printf("*******************************************\n");
    printf("9.预留功能\n");
    printf("*******************************************\n");
    printf("19.输出系统菜单\n");
    printf("20.退出系统\n");
    printf("--------------------------------------------\n");
}

//0.输出顺序表sq
void print(SeqList sq) {
    printf("顺序表的长度是：%d\n", sq.n);
    for (int i = 0; i < sq.n; i++) {
        printf("%d ", sq.a[i]);
    }
    printf("\n");
}

//1.创建顺序表sq，写操作要用指针
void create(SeqList *sq) {
    printf("请输入顺序表的元素(ctrl+z结束输入):\n");
    int n = 0, x;
    while (~scanf("%d", &x)) {
        sq->a[n] = x;
        n++;
    }
    sq->n = n;
}

//2.查找一个元素item在顺序表的位置；找不到返回-1
int findPos(SeqList sq, ElemType item){
    int i=0;
    while(i<=sq.n&&sq.a[i]!=item) i++;
    if(i>sq.n) return -1;
    else return i+1;
}

//3.在顺序表的第i个位置插入一个元素item，插入成功返回1；失败返回-1
int insert(SeqList *sq, int i, ElemType item) {
    if (sq->n == MaxSize || i < 1 || i > sq->n + 1) {
        return -1;
    }
    for (int j = sq->n - 1; j >= i - 1; j--) {
        sq->a[j + 1] = sq->a[j];
    }
    sq->a[i - 1] = item;
    (sq->n)++;
    return 1;
}

//4.删除顺序表第i个位置的元素,成功返回1，失败返回-1
int del(SeqList *sq, int i) {
    int j;
    i--;
    if((i<0)||(i>sq->n-1)) return -1;
    else{
        for(j=i;j<sq->n-1;j++) sq->a[j]=sq->a[j+1];
        sq->n--;
    }
    return 1;
}

//5.修改顺序表第i个位置的元素  
	int modify(SeqList *sq,int i,ElemType item){    
	    if(i>=0&&i<sq->n){
	     	sq->a[i-1]=item;
	     	return 1;
		}                 
	    return -1;    
	}   

int cmp(const void *aa, const void *aaa) {
    const int *a = (const int *)aa;
    const int *b = (const int *)aaa;
    return (*a - *b); // 按升序
}
//6.对顺序表sq排序
void sort(SeqList *sq) {
    qsort(sq->a,sq->n,sizeof(ElemType),cmp);
}

//7.在有序的顺序表中插入一个元素item
void insertSorted(SeqList *sq, ElemType item) {
    int j = sq->n - 1; //插入位置j初始化为表尾
    //从表尾向前查找插入位置
    while(j >= 0 && item < sq->a[j]){
        sq->a[j+1] = sq->a[j]; //元素后移
        j--;
    }
    sq->a[j+1] = item; //插入元素item
    sq->n++; //表长加1
}
//8.合并2个有序表s1和s2到新表sq
void mergeSorted(SeqList *sq, SeqList s1, SeqList s2) {
    int i=0,j=0,k=0;
    //遍历有序表s1和s2
    while(i < s1.n && j < s2.n){
        if(s1.a[i] < s2.a[j]){
            sq->a[k] = s1.a[i];
            i++; //i后移
        }else{
            sq->a[k] = s2.a[j];
            j++; //j后移
        }
        k++;
    }
    //将s1剩余的元素复制到sq中
    while(i < s1.n){
        sq->a[k++] = s1.a[i++];
    }
    //将s2剩余的元素复制到sq中
    while(j < s2.n){
        sq->a[k++] = s2.a[j++];
    }
    sq->n = k; //更新合并后的顺序表长度
}
