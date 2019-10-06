#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
};

int node_insert(struct node **root, int val){  //return succ or fail
	struct node **curr = root;
	struct node *new1;
	
	while(*curr != NULL  && (*curr)->value < val) curr = &((*curr)->next);
	
	new1 = (struct node*)malloc(sizeof(struct node));
	if(new1 == NULL) return -1;
	new1->value = val;
	
	new1->next = *curr;
	*curr = new1;
	
	return 1;
}

int node_del(struct node **root, int val){
	struct node **curr = root;
	struct node *tmp;
	int flag = -1;
	
	while(*curr){
		if((*curr)->value == val){
			tmp = *curr; 
			*curr = (*curr)->next;
			free(tmp);
			flag = 1;
		}
		else curr = &((*curr)->next);
	}
	return flag;
}

/*
void reverse_node_list(struct node *root){
	struct node *curr = root, *tmp, *front = root;
	
	while(curr->next){
		tmp = curr->next;
		curr->next= tmp->next;
		tmp->next= front;
		front = tmp;
	}
	root = front;
}*/


void reverse_node_list(struct node **root){   //反置链表需要修改root指针的值，所以必须传入**root。 
	struct node **curr = root;
	struct node *front = *root, *tmp;

	while((*curr)->next){
		tmp = (*curr)->next;
		(*curr)->next = tmp->next;
		tmp->next = front;
		front = tmp;
	}
	*root = front;
}

void print_node_list(struct node *root){
	struct node *curr = root;
	while(curr != NULL) {
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	struct node root = {0, NULL};
	struct node *p = &root;
	struct node **q = &p;    //注意二级指针的赋值，因为二级指针必须指向一个地址； 

	node_insert(q, -1);
	node_insert(q, 2);
	node_insert(q, 5);
	print_node_list(*q);
	
	reverse_node_list(q);
	print_node_list(*q);
	
	node_del(q, 2);
	print_node_list(*q);
	
	return 0;
}


