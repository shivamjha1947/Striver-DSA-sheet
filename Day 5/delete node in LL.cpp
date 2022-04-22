void deleteNode(ListNode* node) {
    *node = *node->next;
}
// void deleteNode(ListNode* node) {
//     ListNode* t=node;
//     while(t->next->next!=NULL){
//         t->val=t->next->val;
//         t=t->next;
//     }
//     t->val=t->next->val;
//     t->next=NULL;
// }
