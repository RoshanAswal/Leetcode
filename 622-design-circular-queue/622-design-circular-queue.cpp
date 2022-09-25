class MyCircularQueue {
public:
    int f=-1,s=-1,MAX=0;
    vector<int> v;
    MyCircularQueue(int k) {
        MAX=k;
        v=vector<int>(k,-1);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;            
        }
        if(f==-1)
            f++;
        if(s==MAX-1)
            s=0;
        else
            s++;
        v[s]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(f==s){
            f=-1;s=-1;
        }else if(f==MAX-1)
            f=0;
        else
            f++;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return v[f];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return v[s];
    }
    
    bool isEmpty() {
        if(f==-1)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if((f==0 && s==MAX-1) || s==f-1)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */