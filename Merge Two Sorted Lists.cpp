#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res_head = new ListNode();
    ListNode* l1ptr = l1;
    ListNode* l2ptr = l2;
    ListNode* resptr = res_head;
    while(true) {
        if(l1ptr == nullptr) {
            resptr->next = l2ptr;
            break;
        } else if(l2ptr == nullptr){
            resptr->next = l1ptr;
            break;           
        }
        if(l1ptr->val <= l2ptr->val) {
             ListNode* new_node = new ListNode(l1ptr->val);
             resptr->next = new_node;
             resptr = new_node;
             l1ptr = l1ptr->next;
        } else {
            ListNode* new_node = new ListNode(l2ptr->val);
            resptr->next = new_node;
            resptr = new_node;

            l2ptr = l2ptr->next;
        }
        
    }
    return res_head->next;
}
int main() {

}