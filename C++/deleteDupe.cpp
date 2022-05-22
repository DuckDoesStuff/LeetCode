#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode(-1), *dummy = res;
    ListNode* prev = head, *nxt = head->next;

    while(nxt) {
        if(prev->val != nxt->val) {
            dummy->next = prev;
            dummy = dummy->next;
        }
        prev = prev->next;
        nxt = nxt->next;
    }
    dummy->next = prev;

    return res->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for(int i = 2; i <= 9; i++) {
        ListNode* p = new ListNode(i);
        t->next = p;
        t = t->next;

        ListNode* q = new ListNode(i);
        t->next = q;
        t = t->next;
    }

    ListNode* result = deleteDuplicates(head);

    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
}