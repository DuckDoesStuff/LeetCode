#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* result = new ListNode(-1);
    ListNode* temp = result;

    while (list1 || list2) {
        if(list1 == nullptr) {
            while(list2 != nullptr) {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
            break;
        }
        if (list2 == nullptr) {
            while(list1 != nullptr) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            break;
        }
        if(list1->val <= list2->val) {
            while(list1 != nullptr && list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
        } else {
            while(list2 != nullptr && list2->val < list1->val) {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
    }
    
    return result->next;
}

int main() {
    ListNode* head1 = new ListNode(-9);//-9, 3
    ListNode* t = head1;
    head1->next = new ListNode(3);
    // for(int i = 2; i < 10; i+=2) {
    //     ListNode* p = new ListNode(i);
    //     t->next = p;
    //     t = t->next;
    // }

    ListNode* head2 = new ListNode(5);//5, 7
    t = head2;
    head2->next = new ListNode(7);
    // for(int i = 2; i < 12; i+=3) {
    //     ListNode* p = new ListNode(i);
    //     t->next = p;
    //     t = t->next;
    // }
    ListNode* result = mergeTwoLists(head1, head2);

    t = result;
    while(t != nullptr) {
        cout << t->val << " ";
        t = t->next;
    }
}