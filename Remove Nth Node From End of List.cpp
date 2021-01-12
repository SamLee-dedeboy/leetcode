#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> node_list;
    for(ListNode* p = head; p!=nullptr; p=p->next) {
        node_list.push_back(p);
    }
    ListNode* p = node_list[node_list.size()-1-n];
    ListNode* tmp = p->next;
    p->next = tmp->next;
    
    //for(ListNode* q = head; q!=nullptr; q=q->next) {
    //    cout << q->val << " ";
    //}
    return head;
}
int main() {
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for(int i = 1; i <= 5; ++i) {
        ListNode* new_node = new ListNode(i);
        cur->next = new_node;
        cur = cur->next;
    }
    for(ListNode* q = head; q!=nullptr; q=q->next) {
        cout << q->val << " ";
    }
    cout << endl;
    removeNthFromEnd(head, 1);
}