Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* t=head;
        while(t!=NULL){
            Node* n=new Node(t->val);
            n->next=t->next;
            t->next=n;
            t=n->next;
        }
        t=head;
        while(t!=NULL){
            if (t->random != NULL) {
                t->next->random=t->random->next;
            }
            t=t->next->next;
        }
        t=head;
        Node* f=t->next->next;
        Node* res=new Node(0);
        res->next=t->next;
        Node* temp=res->next;
        while(f!=NULL){
            t->next=f;
            temp->next=f->next;
            temp=temp->next;
            t=t->next;
            f=temp->next;
        }
        t->next=temp->next;
        return res->next;
    }
