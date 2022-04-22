ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* res=new ListNode(0);
        ListNode* t=res;
        while(l1 && l2){
            int sum=l1->val+l2->val+c;
            c=sum/10;
            ListNode* n=new ListNode(sum%10);
            t->next=n; 
            t=t->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l2){
            int sum=l2->val+c;
            c=sum/10;
            ListNode* n=new ListNode(sum%10);
            t->next=n;
            t=t->next;
            l2=l2->next;
        }
        
        while(l1){
            int sum=l1->val+c;
            c=sum/10;
            ListNode* n=new ListNode(sum%10);
            t->next=n;
            t=t->next;
            l1=l1->next;
        }
        
        if(l1==NULL && l2==NULL && c!=0){
            ListNode* n=new ListNode(c);
            t->next=n;
        }
        return res->next;
        
    }
