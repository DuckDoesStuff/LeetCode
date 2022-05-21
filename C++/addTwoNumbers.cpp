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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* temp = result;
        int carry = 0;
        while(l1 || l2 || carry != 0) {
            int n1, n2;

            if(l1 != nullptr) n1 = l1->val;
            else n1 = 0;
            if(l2 != nullptr) n2 = l2->val;
            else n2 = 0;

            int sum = n1 + n2 + carry;

            temp->next = new ListNode(sum%10);
            temp = temp->next;

            carry = sum / 10;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return result->next;
    }
};

int main() {
    return 0;
}