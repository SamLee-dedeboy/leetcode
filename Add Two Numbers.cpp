#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res=new ListNode;
    res->val = 0;
    res->next = NULL; 
    int carry = 0;
    ListNode* p = l1;
    ListNode* q= l2;
    ListNode* resptr = res;
    while(p || q) {
        int a=(p?p->val:0);
        int b=(q?q->val:0);
        cout<<a<<", "<<b<<endl;
        ListNode* newListNode = new ListNode;
        newListNode->next = NULL;
        int sum = a+b+carry;
        newListNode->val = sum%10;
        carry = sum/10;
        cout<<"res:"<<newListNode->val<<endl;
        
        resptr->next = newListNode;
        if(p) p=p->next;
        if(q) q=q->next;
        resptr=resptr->next;
    }
    if(carry ==1) {
        ListNode* lastNode = new ListNode;
        lastNode->val = 1;
        lastNode->next = NULL;
        resptr->next = lastNode;
    }
    return res->next;

}
ListNode* createList(int* nums, int n) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* p = head;
    for(int i = 1; i < n; p=p->next,i++) {
        p->next = new ListNode(nums[i]);
    }
    return head;
}
void printList(ListNode* head) {
    for(ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val <<" ";
    }
}
int main() {
    int i1[] = {9,9,9,9,9,9,9};
    int i2[] = {9,9,9,9};
    ListNode* l1 = createList(i1,7);
    ListNode* l2 = createList(i2,4);
    ListNode* res = addTwoNumbers(l1,l2);
    printList(res);
}