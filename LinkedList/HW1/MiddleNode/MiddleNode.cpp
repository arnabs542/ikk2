/*Find The Middle Node In A Singly Linked List

Problem Statement :
Given an integer singly linked list L, you have to find the middle node of it.L has total n no.of nodes.
If it has even number of nodes, then consider the second of the middle two nodes as the middle node.

Input / Output Format For The Function :

Input Format :
There is only one argument in input, L, denoting head node of input integer singly linked list.

Output Format :
Return the middle node of the given integer singly linked list middle.


Input / Output Format For The Custom Input :

Input Format :
The first line of input should contain an integer n, denoting total number of nodes in L.In the next n lines, ith line should contain an integer Li, denoting a value in ith node of L.
If n = 4 and L: 3 -> 7 -> 2 -> 9->NULL, then input should be :

4
3
7
2
9

Output Format :
There will be one line, containing an integer middle, denoting the result returned by the solution function.
For input n = 4 and L: 3 -> 7 -> 2 -> 9->NULL, output will be :

2

Constraints :

0 <= n <= 10 ^ 5
- 2 * 10 ^ 9 <= value contained in any node <= 2 * 10 ^ 9
Do it in one pass over the linked list.
If given linked list is empty then return null.


Sample Test Case 1 :

Sample Input 1 :
1 -> 2 -> 3 -> 4 -> 5->NULL

Sample Output 1:
Node containing value 3.

Sample Test Case 2:

Sample Input 2 :
1 -> 2 -> 3 -> 4->NULL

Sample Output 2:
Node containing value 3.

Notes :

Suggested time in interview : 20 minutes.

The �Suggested Time� is the time expected to complete this question during a real - life interview, not now in homework 
i.e.For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using,
coding it, as well as identifying any gaps that you can discuss during a TA session.Take your time, but limit yourself to 2 one hour sessions for most problems.

LinkedListNode* find_middle_node(LinkedListNode* head) {
	LinkedListNode *slow = head, *fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

*/

#include <iostream>

using namespace std;
class LinkedListNode {
public:
	int val;
	LinkedListNode *next;

	LinkedListNode(int node_value) {
		val = node_value;
		next = NULL;
	}
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
	if (head == NULL) {
		head = new LinkedListNode(val);
		tail = head;
	}
	else {
		LinkedListNode *node = new LinkedListNode(val);
		tail->next = node;
		tail = tail->next;
	}
	return tail;
}


/*
 * Complete the function below.
 */
 /*
 For your reference:
 LinkedListNode {
	 int val;
	 LinkedListNode *next;
 };
 */
LinkedListNode* find_middle_node(LinkedListNode* head)
{
	if (head == NULL)
		return head;

	LinkedListNode* slow = head;
	LinkedListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

int main()
{
	ostream &fout = cout;

	LinkedListNode* res;
	int head_size = 0;

	LinkedListNode* head = NULL;
	LinkedListNode* head_tail = NULL;

	cin >> head_size;

	for (int i = 0; i < head_size; i++) {
		int head_item;
		cin >> head_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

		if (i == 0) {
			head = head_tail;
		}
	}
	res = find_middle_node(head);
	while (res != NULL) {
		fout << res->val << endl;

		res = res->next;
	}
	return 0;
}




