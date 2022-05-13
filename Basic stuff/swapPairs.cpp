#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* temp = new ListNode(-1 , head);//to keep track of where the list will start(we lost the head after swapping)
    ListNode* curr = head;
    ListNode* prev = temp;

    while(curr != nullptr && curr->next != nullptr) {
        ListNode* second = curr->next;
        ListNode* nxt = curr->next->next;//after swapping we will lose track of where to go next

        curr->next = nxt;
        second->next = curr;

        prev->next = second;

        prev = curr;
        curr = nxt;
    }

    return temp->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for(int i = 2; i < 9; i++) {
        ListNode* p = new ListNode(i);
        t->next = p;
        t = t->next;
    }

    ListNode* p = head;
    // while(p != nullptr) {
    //     cout << p->val << " ";
    //     p = p->next;
    // }

    head = swapPairs(head);

    cout << '\n';
    p = head;
    while(p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
}