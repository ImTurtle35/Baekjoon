// Baekjoon 10866
#include <iostream>
#include <string>

using namespace std;

int N;
string input;

struct Node{
	int val;
	Node * pre;
	Node * nxt;
};

struct Deque {
	int size = 0;
	Node* head = NULL;
	Node* tail = NULL;
};

int dq_size(Deque* deq) {
	return deq->size;
}

bool empty(Deque * deq) {
	if (deq->size == 0) return true;
	else return false;
}

int front(Deque* deq) {
	if (empty(deq)) return -1;
	else return deq->head->val;
}

int back(Deque* deq) {
	if (empty(deq))return -1;
	else return deq->tail->val;
}

void push_front(Deque * deq, int x) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode) {
		newnode->val = x;
		newnode->nxt = NULL;
		newnode->pre = deq->head;

		if (empty(deq)) deq->tail = newnode;
		else deq->head->nxt = newnode;

		deq->head = newnode;
		deq->size += 1;
	}
}

void push_back(Deque* deq, int x) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode) {
		newnode->val = x;
		newnode->nxt = deq->tail;
		newnode->pre = NULL;

		if (empty(deq)) deq->head = newnode;
		else deq->tail->pre = newnode;

		deq->tail = newnode;
		deq->size += 1;
	}
}

int pop_front(Deque* deq) {
	if (empty(deq)) return -1;
	else {
		if (deq->size == 1) {
			int p_val = deq->head->val;
			delete(deq->head);
			deq->size -= 1;
			return p_val;
		}
		Node * dnode = deq->head;
		int p_val = dnode->val;
		dnode->pre->nxt = NULL;
		deq->head = dnode->pre;
		delete(dnode);
		deq->size -= 1;
		return p_val;
	}
}

int pop_back(Deque* deq) {
	if (empty(deq)) return -1;
	else {
		if (deq->size == 1) {
			int p_val = deq->tail->val;
			delete(deq->tail);
			deq->size -= 1;
			return p_val;
		}
		Node* dnode = deq->tail;
		int p_val = dnode->val;
		dnode->nxt->pre = NULL;
		deq->tail = dnode->nxt;
		delete(dnode);
		deq->size -= 1;
		return p_val;
	}
}

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	Deque nd;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		if (input == "push_front") {
			int val;
			cin >> val;
			push_front(&nd, val);
		}
		else if (input == "push_back") {
			int val;
			cin >> val;
			push_back(&nd, val);
		}
		else if (input == "pop_front") cout << pop_front(&nd) << "\n";
		else if (input == "pop_back") cout << pop_back(&nd) << "\n";
		else if (input == "size") cout << dq_size(&nd) << "\n";
		else if (input == "empty") cout << empty(&nd) << "\n";
		else if (input == "front") cout << front(&nd) << "\n";
		else if (input == "back") cout << back(&nd) << "\n";
	}
}