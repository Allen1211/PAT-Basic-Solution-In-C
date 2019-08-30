#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *pre;
	struct Node *next;
}Node;

Node* create(int K) {
	Node *head = NULL;
	Node *p1 = NULL, *p2 = NULL;
	while (K--) {
		p1 = (Node*)malloc(sizeof(struct Node));
		scanf("%d", &(p1->val));

		if (head == NULL) {
			p2 = head = p1;
			head->pre = NULL;
			head->next = NULL;
		}
		else {
			p2->next = p1;
			p1->pre = p2;
			p2 = p1;
		}
	}
	p1->next = NULL;
	return head;
}

Node* deleteNode(Node *target, Node *head) {
	if (target == head) {//if it's header
		head = target->next;
		head->pre = NULL;
	}
	else if (target->next == NULL) {	// if it is tail
		target->pre->next = NULL;
	}
	else {
		Node *p_pre = target->pre;
		Node *p_next = target->next;
		p_pre->next = p_next;
		p_next->pre = p_pre;
	}
	return head;
}

void bubble_sort(Node *list) {
	Node *tail = list;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	for (Node* p1 = tail; p1 != NULL; p1 = p1->pre) {
		for (Node *p2 = list; p2 != p1; p2 = p2->next) {
			if (p2->val < p2->next->val) {
				int temp = p2->val;
				p2->val = p2->next->val;
				p2->next->val = temp;
			}
		}
	}

}

int main1005() {
	int K;
	scanf("%d", &K);
	Node* list = create(K);
	
	for (Node *p = list; p != NULL; p = p->next) {
		int n = p->val;
		while (n != 1) {
			if (n & 1)
				n = (3 * n + 1) / 2;
			else
				n /= 2;

			for (Node *p1 = p->pre; p1 != NULL; p1 = p1->pre) {
				if (p1 != NULL && p1->val == n) {
					list = deleteNode(p1, list);
					break;
				}
			}
			for (Node *p2 = p->next; p2 != NULL; p2 = p2->next) {
				if (p2 != NULL && p2->val == n) {
					list = deleteNode(p2, list);
					break;
				}
			}

		}

	}

	bubble_sort(list);
	for (Node *p = list; p != NULL; p = p->next) {
		if (p->next != NULL)
			printf("%d ", p->val);
		else
			printf("%d", p->val);
	}
	return 0;

}
