#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr || k == 1) {
        return head;
    }
    ListNode* empty_node = new ListNode(0, head);
    head = empty_node;
    ListNode* first = head->next;
    ListNode* prev_group_tail = head;
    while(true) {
        ListNode* second_group = first;
        for(int i = 0; i < k; ++i) {
            if(second_group == nullptr) {
                return head->next;
            }
            second_group = second_group->next;
        }
        cout << "first second: " << first->val << second_group->val << endl;
        ListNode* prev = first;
        ListNode* child = prev->next;
        ListNode* tmp = child->next;
        for(int i = 0; i < k-1; ++i) {
            child->next = prev;
            prev = child;
            child = tmp;
                if(child!=nullptr) {
                    tmp = child->next;
                }
        }
        first->next = second_group;
        prev_group_tail->next = prev;
        prev_group_tail = first;
        first = second_group;
        if(second_group == nullptr) {
            return head->next;
        }
    }
}
int main() {

}