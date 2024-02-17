class MyCircularDeque {
public:
    int size,count=0;
    ListNode *last=NULL;
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(count==size) return false;
        ListNode *temp = new ListNode;
        if(temp==nullptr) return false;
        temp->val=value;
        temp->next=NULL;
        if(last==NULL) {
            last=temp;
            last->next=last;
            count++;
            return true;
        }
        if(last->next==last) {
            last->next=temp;
            temp->next=last;
            count++;
            return true;
        }
        temp->next=last->next;
        last->next=temp;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(count==size) return false;
        ListNode *temp = new ListNode;
        if(temp==nullptr) return false;
        temp->val=value;
        temp->next=NULL;
        if(last==NULL) {
            last=temp;
            last->next=last;
            count++;
            return true;
        }
        if(last->next==last) {
            last->next=temp;
            temp->next=last;
            last=last->next;
            count++;
            return true;
        }
        temp->next=last->next;
        last->next=temp;
        last=last->next;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(count==0) return false;
        if(last->next==last) {
            delete last;
            last=NULL;
            count--;
            return true;
        }
        ListNode *temp=last->next;
        last->next=temp->next;
        delete temp;
        temp=NULL;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(count==0) return false;
        if(last->next==last) {
            delete last;
            last=NULL;
            count--;
            return true;
        }
        ListNode *temp=last;
        while(last->next!=temp) {
            last=last->next;
        }
        last->next=temp->next;
        delete temp;
        temp=NULL;
        count--;
        return true;
    }
    
    int getFront() {
        return (count==0)? -1 : last->next->val;
    }
    
    int getRear() {
        return (count==0)? -1 : last->val;
    }
    
    bool isEmpty() {
        return (count==0)? true : false;
    }
    
    bool isFull() {
        return (count==size)? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */