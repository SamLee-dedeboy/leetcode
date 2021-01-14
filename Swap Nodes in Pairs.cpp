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
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* first = head;
    ListNode* second = head->next;
    while(true) {
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
        first = second->next;
        if(first == nullptr) {
            break;
        }
        second = first->next;
        if(second == nullptr) {
            break;
        }
    }
    return;
}

int main() {
    
}