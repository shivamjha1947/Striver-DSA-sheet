    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* head=NULL;
        ListNode* c1=list1;
        ListNode* c2=list2;
        ListNode* p=NULL;
        if(list1->val<=list2->val){
            head=list1;
            p=c1;
            c1=head->next;
        }else{
            head=list2;
            p=c2;
            c2=head->next;
        }      
        if(c1==NULL){
            head->next=c2;
            return head;
        }else if(c2==NULL){
            head->next=c1;
            return head;
        }
        while(c1!=NULL && c2!=NULL){
            if(c1->val<=c2->val){
                p->next=c1;
                p=c1;
                c1=c1->next;
            }else if(c1->val>c2->val){
                p->next=c2;
                p=c2;
                c2=c2->next;
            }
            
        }
        if(c1==NULL){
            p->next=c2;
        }else if(c2==NULL){
            p->next=c1;
        }
        return head;
    }
