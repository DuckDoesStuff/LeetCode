#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr, *curr = head;

    while(curr != nullptr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for(int i = 2; i <= 5; i++) {
        ListNode* p = new ListNode(i);
        t->next = p;
        t = t->next;
    }

    ListNode* result = reverseList(head);

    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}