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

void reorderList(ListNode* head) {
    if(head->next == nullptr) return;
    ListNode* slow = head, *fast = head->next;//used to find where to start reversing the list
    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        if(fast->next == nullptr) break;
        fast = fast->next;
    }
    ListNode* reversedList = reverseList(slow);

    ListNode* dummy = head;

    while(reversedList->next != nullptr && dummy != nullptr) {
        ListNode* nxt = dummy->next;
        ListNode* revNext = reversedList->next;
        dummy->next = reversedList;
        reversedList->next = nxt;
        dummy = nxt;
        reversedList = revNext;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for(int i = 2; i <= 1; i++) {
        ListNode* p = new ListNode(i);
        t->next = p;
        t = t->next;
    }

    reorderList(head);
    ListNode* result = head;

    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}