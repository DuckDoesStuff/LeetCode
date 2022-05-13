#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1 = new ListNode(-1);
    p1->next = head;
    ListNode* p2 = head;

    for(int i = 0; i < n; i++) {
        p2 = p2->next;
    }

    if(p2 == nullptr) {
        return head->next;
    }

    while(p2 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }

    p1->next = p1->next->next;

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for(int i = 2; i < 3; i++) {
        ListNode* p = new ListNode(i);
        t->next = p;
        t = t->next;
    }

    ListNode* result = removeNthFromEnd(head, 2);

    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}