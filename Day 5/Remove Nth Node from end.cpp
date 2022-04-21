ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        ListNode* l=head;
        ListNode* r=head;
        while(n--){
            r=r->next;
        }
        if(r==NULL){
            return head->next;
        }
        while(r->next!=NULL){
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;
        return head;
    }
