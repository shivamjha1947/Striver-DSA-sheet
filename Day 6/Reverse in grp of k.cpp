ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex=NULL;
        for(int i = 0; i < k; i++){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
