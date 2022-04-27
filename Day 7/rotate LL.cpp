ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        int n=0;
        ListNode* t=head;
        while(t!=NULL){
            t=t->next;
            n++;
        }
        
        k=k%n;
        int x=n-k-1;
        t=head;
        while(x--){
            t=t->next;
        }
        ListNode* mid=t;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=head;
        head=mid->next;
        mid->next=NULL;
        return head;
    }
