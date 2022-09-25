class MyCircularQueue {
public:
   int n,size,front,rear;
    vector<int> a;
    
    MyCircularQueue(int k) {
        n=0;
        size=k;
        a.resize(k);
        front=rear=-1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return 0;
        
        rear=(rear+1)%size;
        a[rear]=value;
        n++;
        
        if(front==-1)
            front=0;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return 0;
        
        front=(front+1)%size;
        n--;
        
        return 1;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        
        return a[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        
        return a[rear];
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==size;
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