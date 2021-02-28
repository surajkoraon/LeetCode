class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int> m;
    int pos=0;
    FreqStack() {
    }
    
    void push(int x) {
        pq.emplace(++m[x], make_pair(++pos, x));
    }
    
    int pop() {
        int temp=pq.top().second.second;
        pq.pop();
        m[temp]--;
        return temp;
    }
};
