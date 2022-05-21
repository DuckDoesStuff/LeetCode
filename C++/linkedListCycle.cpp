#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode *slow = head, *fast = head->next;

    while(fast != slow) {
        if(fast == nullptr || fast->next == nullptr) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for(int i = 2; i <= 1; i++) {
        ListNode* p = new ListNode(i);
        t->next = p;
        t = t->next;
    }

    cout << hasCycle(head);

    // while(result != nullptr) {
    //     cout << result->val << " ";
    //     result = result->next;
    // }
    return 0;
}