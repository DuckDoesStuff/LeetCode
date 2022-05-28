#include <iostream>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* temp = head;
        int count = 1;
        while(temp->next != nullptr) {
            temp = temp->next;
            count++;
        }
        temp->next = head;

        k = k % count;
        int times = count - k;
        
        //Traversing inside circle linkedlist
        for(int i = 0; i < times; i++) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    int n = 3;
    for(int i = 2; i <= n; i++) {
        ListNode* p = new ListNode(i);
        t->next = p;
        t = t->next;
    }

    ListNode* res = Solution().rotateRight(head, 2000000000);

    while(res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0; 
}