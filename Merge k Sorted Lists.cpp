#include <iostream>
#include <queue> 
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};  

struct cmp
{
    bool operator ()(const ListNode &q,const ListNode &p)
    {
        return q.val<p.val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) {
        return nullptr;
    } else {
        bool all_null = true;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != nullptr) {
                all_null = false;
                break;
            }
        }
        if(all_null) {
            return nullptr;
        }
    }
    //priority_queue<ListNode, vector<ListNode>, cmp> pq(lists, lists.end());
    //cout << pq.top() << endl;
    ListNode* res_head = new ListNode();
    ListNode* res_ptr = res_head;
    while(true) {
        int min = 2147483647;
        int index = -1;
        int finish_counter = 0;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] == nullptr) {
                ++finish_counter;
                if(finish_counter == lists.size()) {
                    return res_head->next;
                }
            } else if(lists[i]->val<min) {
                min = lists[i]->val;
                index = i;
            } else {
                continue;
            }
        }
        ListNode* new_node = new ListNode(min);
        res_ptr->next = new_node;
        res_ptr = new_node;
        lists[index] = lists[index]->next;
    }
}
int main() {
    
}