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
	char name[50]; // ��Ʒ����
	int quantity; // ��Ʒ����
	struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
struct ShoppingItem* shoppingList1 = NULL;

int main(){

	
	addItem("����",100);
	addItem("ţ�п�",120);
	addItem("����",110);
	addItem("��Ь",80);
	
	displayList();
	printf("\n");
	
	printf("ɾ����\n"); 
	removeItem("����"); 
	displayList();
	printf("\n");
	
	printf("�޸�������\n");
	updateQuantity("����",150);
	displayList();
	printf("\n");
	
	printf("�����ͣ�\n");
	printf("%d\n",totalQuantity());
	printf("\n");
	
	printf("������Ʒ��\n");
	findItem("����");
	printf("\n");
	findItem("ñ��");
	printf("\n"); 
	
	printf("����\n");
	sortList();
	displayList();
	printf("\n");
	
	printf("������ݺ�\n");
	clearList();
	displayList();
	printf("\n");
	
	printf("�ϲ���\n");
	addItem("����",100);
	addItem("��Ь",80); 
	addItem("ţ�п�",120);
	addItem("��Ь",80);
	addItem("����",110);
	addItem("��Ь",80);
	
	AddItem("ñ��",50);
	AddItem("����",110);
	AddItem("T��",70);
	AddItem("����",110);
	AddItem("����",200);
	mergeLists(&shoppingList,&shoppingList1);
	displayList();
	printf("\n");

	printf("ѡ��ɾ��\n");
	deleteItem("����",0);
	deleteItem("��Ь",1);
	//������Ьȫ��ɾ��
	//��������ɾ����һ�� 
	displayList();
	return 0;
}

//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 
	//�˴���д�������;
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
 
	//�˴���д�������;
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

//2. �ӹ����嵥���Ƴ���Ʒ��
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
	//�˴���д���У�
	previous=current;
	current=current->next;
	}
}

//3. �鿴�����嵥��
void displayList(){
	struct ShoppingItem* current = shoppingList;
	printf("�����嵥:\n");
	while (current != NULL) {
		printf("%s - ������%d\n", current->name, current->quantity);
		//�˴���дһ�䣻
		current=current->next;
	}
}

//4. �޸Ĺ����嵥����Ʒ��������
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
		//�˴���дһ�䡣
			current->quantity=newItemQuantity;
			break;
		}
		current = current->next;
	}
}

//5. ��չ����嵥��
void clearList() {
	while (shoppingList != NULL) {
	//�˴���д���䡣
		struct ShoppingItem *temp=shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}
//6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		//�˴���д���䣻
		total=total+current->quantity;
		current=current->next;
	}
	return total;
}
//7. ���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	printf("������Ʒ \"%s\" ��\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - ������%d\n", current->name, current->quantity);
			return;
			}
			//�˴���дһ�䡣
			current=current->next;
		}
	printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}
//8. �������嵥��
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	while (current != NULL) {
		nextItem = current->next;
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				// ������Ʒ��Ϣ
				//�˴���д 3 �䣻
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
//9. �ϲ������嵥��
//��������������ͬ�Ĺ����嵥����ϣ�������Ǻϲ���һ����
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	// ��������һ�������嵥��ĩβ
	//����ѭ����䣻
	while(current->next!=NULL)
	{
		current=current->next;
	}
	// ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
	current->next = *list2;
	*list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}
//10. ɾ�������嵥�е���Ʒ��
//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ�����ж����ͬ���Ƶ���Ʒ��
//����ѡ��ɾ������һ����ȫ����
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
				// ���Ҫɾ�����ǵ�һ���ڵ�
				struct ShoppingItem* temp = shoppingList;
				//��дһ�䣻
				shoppingList=shoppingList->next; 
				free(temp);
				if (!deleteAll) break;
			} else {
				// ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
				//��дһ�䣻
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
