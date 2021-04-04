class MyCircularQueue {
public:
    int front=-1,rear=-1,size;
    vector<int> q;
    MyCircularQueue(int k) {
        size=k;
        for(int i=0;i<k;i++)
            q.push_back(-1);
    }
    bool enQueue(int value) {
        if(front==-1)
        {
            rear=0;
            front=0;
            q[rear]=value;
            return true;
        }
        if((front==0 && rear==size-1) || (rear==front-1))
        {
            return false;
        }
        if(rear==size-1)
        {
            rear=0;
            q[rear]=value;
            return true;
        }
        q[++rear]=value;
        return true;
    }
    
    bool deQueue() {
        front=front%size;
        if(front==-1)
            return false;
        int data=q[front];
        q[front]=-1;
        if(front==rear)
        {
            front=-1;
            rear=-1;
            return true;
        }
        if(front==size-1)
        {
            front=0;
            return true;
        }
        front++;
        return true;
    }
    
    int Front() {
        if(front==-1)
        {
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(rear==-1)
        {
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return ((front==0 && rear==size-1) || (rear==front-1));
    }
};
