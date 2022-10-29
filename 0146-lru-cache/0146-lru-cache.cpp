class LRUCache {
public:
    struct node{
        public:
            int key,val;
            node *next, *prev;
        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };
    
    //fixed node head and tail to avoid multiple if conditions for NULL
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);

    //directly take a list to avoid DLL implementation
    //list<int> dq;
    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity){
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(node *newnode){
        node *temp = head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    void delNode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delnext->prev = delprev;
        delprev->next = delnext;
    }

    int get(int key){
       if(m.find(key)!=m.end()){
            node *resnode = m[key];
            int res=resnode->val;
            m.erase(key);
            delNode(resnode);
            addNode(resnode);
            m[key]=head->next;
            return res;
       }
       return -1;
    }

    void put(int key, int val){
        if(m.find(key)!=m.end()){
            node *nodeexist = m[key];
            m.erase(key);
            delNode(nodeexist);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new node(key,val));
        m[key] = head->next;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */