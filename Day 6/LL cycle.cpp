bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            if(fast==slow){
                return true;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
