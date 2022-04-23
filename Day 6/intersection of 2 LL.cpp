// can be done by set also
    int length(ListNode *head){
        if(head==NULL){
            return 0;
        }
        int count=0;
        ListNode *t=head;
        while(t){
            t=t->next;
            count++;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=length(headA);
        int b=length(headB);
        ListNode *t1=headA;
        ListNode *t2=headB;
        if(a>b){
            for(int i=0;i<a-b;i++){
                t1=t1->next;
            }
        }else if(a<b){
            for(int i=0;i<b-a;i++){
                t2=t2->next;
            }
        }
        while(t1 && t2){
            if(t1==t2){
                return t1;
            }else{
                t1=t1->next;
                t2=t2->next;
            }
        }
        return NULL;
    }
