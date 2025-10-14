// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode();
		ListNode* temp = ans;
		int carry = 0;

		while (l1 != NULL || l2 != NULL || carry) {
			int sum = 0;
			if (l1 != NULL) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				sum += l2->val;
				l2 = l2->next;
			}
			sum += carry;
			carry = sum / 10;

			ListNode* temp2 = new ListNode(sum % 10);
			temp->next = temp2;
			temp = temp->next;
		}
		return ans->next;
	}
};

// Helper function to create linked list from vector
ListNode* createList(vector<int> nums) {
	ListNode* head = new ListNode(nums[0]);
	ListNode* curr = head;
	for (int i = 1; i < nums.size(); i++) {
		curr->next = new ListNode(nums[i]);
		curr = curr->next;
	}
	return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
	while (head != NULL) {
		cout << head->val;
		if (head->next) cout << " -> ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Solution obj;

	// Example Input
	vector<int> num1 = {2, 4, 3};  // represents 342
	vector<int> num2 = {5, 6, 4};  // represents 465

	ListNode* l1 = createList(num1);
	ListNode* l2 = createList(num2);

	cout << "First number: ";
	printList(l1);
	cout << "Second number: ";
	printList(l2);

	ListNode* result = obj.addTwoNumbers(l1, l2);

	cout << "\nSum: ";
	printList(result);

	return 0;
}
