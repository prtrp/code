#include <iostream>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

class Solution {
public:
    void newNode(ListNode ** &root, int n) {

        ListNode *new_node = nullptr;
        new_node = new ListNode;
        if (new_node == nullptr) {
            exit(1);
        }


        new_node -> next = NULL;
        new_node -> val = n;

        if (root == nullptr) {
            *root = new_node;
            return;
        }

        ListNode *curr = *root;
        while (curr != nullptr) {
            curr = curr -> next;
        }
        curr -> next = new_node;
        
        return ;
    }

    ListNode* mergeTwoLists(ListNode *list1, ListNode* list2) {
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;

        while (curr1 -> next || curr2 -> next) {
            
        }
    }
};


int main() {

}
