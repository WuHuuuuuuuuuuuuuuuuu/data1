#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addItem(char itemName[], int itemQuantity);
void displayList();
void removeItem(char itemName[]);
void updateQuantity(char itemName[], int newItemQuantity);
void clearList();
int totalQuantity();
void findItem(char itemName[]);
void sortList();
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2);
void AddItem(char itemName[], int itemQuantity);
void deleteItem(char itemName[], int deleteAll);

struct ShoppingItem {
	char name[50]; // 商品名称
	int quantity; // 商品数量
	struct ShoppingItem* next; // 指向下一个节点的指针
};

struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
struct ShoppingItem* shoppingList1 = NULL;

int main(){

	
	addItem("衬衫",100);
	addItem("牛仔裤",120);
	addItem("卫衣",110);
	addItem("布鞋",80);
	
	displayList();
	printf("\n");
	
	printf("删除后：\n"); 
	removeItem("衬衫"); 
	displayList();
	printf("\n");
	
	printf("修改数量后：\n");
	updateQuantity("卫衣",150);
	displayList();
	printf("\n");
	
	printf("数量和：\n");
	printf("%d\n",totalQuantity());
	printf("\n");
	
	printf("查找商品：\n");
	findItem("卫衣");
	printf("\n");
	findItem("帽子");
	printf("\n"); 
	
	printf("排序：\n");
	sortList();
	displayList();
	printf("\n");
	
	printf("清空数据后：\n");
	clearList();
	displayList();
	printf("\n");
	
	printf("合并：\n");
	addItem("衬衫",100);
	addItem("布鞋",80); 
	addItem("牛仔裤",120);
	addItem("布鞋",80);
	addItem("卫衣",110);
	addItem("布鞋",80);
	
	AddItem("帽子",50);
	AddItem("卫衣",110);
	AddItem("T恤",70);
	AddItem("卫衣",110);
	AddItem("袜子",200);
	mergeLists(&shoppingList,&shoppingList1);
	displayList();
	printf("\n");

	printf("选择删除\n");
	deleteItem("卫衣",0);
	deleteItem("布鞋",1);
	//三个布鞋全部删除
	//三个卫衣删除第一个 
	displayList();
	return 0;
}

//1. 添加商品到购物清单：
void addItem(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 
	//此处填写若干语句;
	strcpy(newItem->name,itemName);
	newItem->quantity=itemQuantity;
	newItem->next=NULL;
	if(shoppingList==NULL){
		shoppingList=newItem;
	}else{
		struct ShoppingItem *p=shoppingList;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newItem;
	}
}

void AddItem(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 
	//此处填写若干语句;
	strcpy(newItem->name,itemName);
	newItem->quantity=itemQuantity;
	newItem->next=NULL;
	if(shoppingList==NULL){
		shoppingList=newItem;
	}else{
		struct ShoppingItem *p=shoppingList;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newItem;
	}
}

//2. 从购物清单中移除商品：
void removeItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;	
	struct ShoppingItem* previous = NULL;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (previous != NULL) {
				previous->next = current->next;
			} else {
				shoppingList = current->next;
			}
			free(current);
			break;
		}
	//此处填写两行；
	previous=current;
	current=current->next;
	}
}

//3. 查看购物清单：
void displayList(){
	struct ShoppingItem* current = shoppingList;
	printf("购物清单:\n");
	while (current != NULL) {
		printf("%s - 数量：%d\n", current->name, current->quantity);
		//此处填写一句；
		current=current->next;
	}
}

//4. 修改购物清单中商品的数量：
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
		//此处填写一句。
			current->quantity=newItemQuantity;
			break;
		}
		current = current->next;
	}
}

//5. 清空购物清单：
void clearList() {
	while (shoppingList != NULL) {
	//此处填写两句。
		struct ShoppingItem *temp=shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}
//6. 计算购物清单中商品的总数量：
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		//此处填写两句；
		total=total+current->quantity;
		current=current->next;
	}
	return total;
}
//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	printf("查找商品 \"%s\" ：\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
			}
			//此处填写一句。
			current=current->next;
		}
	printf("未找到商品 \"%s\"。\n", itemName);
}
//8. 排序购物清单：
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	while (current != NULL) {
		nextItem = current->next;
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				// 交换商品信息
				//此处填写 3 句；
				strcpy(tempName,current->name);
				strcpy(current->name,nextItem->name);
				strcpy(nextItem->name,tempName);
				tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
		nextItem = nextItem->next;
		}
		current = current->next;
	}
}
//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	// 遍历到第一个购物清单的末尾
	//补充循环语句；
	while(current->next!=NULL)
	{
		current=current->next;
	}
	// 将第二个购物清单连接到第一个清单的末尾
	current->next = *list2;
	*list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}
//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
				// 如果要删除的是第一个节点
				struct ShoppingItem* temp = shoppingList;
				//填写一句；
				shoppingList=shoppingList->next; 
				free(temp);
				if (!deleteAll) break;
			} else {
				// 如果要删除的不是第一个节点
				//填写一句；
				prev->next=current->next;
				free(current);
				current = prev->next;
				if (!deleteAll) break;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}
