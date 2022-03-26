    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex=head->next;
        while(nex!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nex;
            nex=nex->next;
        }
        curr->next=prev;
        head=curr;
        return head;
    }
