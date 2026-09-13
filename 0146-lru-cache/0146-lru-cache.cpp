class LRUCache {
public:

    class Node{
        public:
        int key;
        int value;

        Node* next;
        Node* prev;

        Node(int k,int v){
            key=k;
            value=v;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

   
    int cap;
    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {

        cap=capacity;
        head->next=tail;
        tail->prev=head;



        
    }

    void addnode(Node* newnode){
        Node* temp=head->next;

        head->next=newnode;
        newnode->prev=head;
        temp->prev=newnode;
        newnode->next=temp;
    }

    void deletenode(Node* delnode){

        Node* delprev=delnode->prev;
        Node* delnext=delnode->next;

        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {

        if(mp.find(key)==mp.end()){
            return -1;
        }

        Node* node=mp[key];

        deletenode(node);
        addnode(node);

        return node->value;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){

            Node* node=mp[key];
            
            node->value=value;

            deletenode(node);
            addnode(node);

            return;
        }

        if(mp.size()==cap){
            Node* temp=tail->prev;

            mp.erase(temp->key);
            deletenode(temp);
            delete temp;


        }
        Node* node=new Node(key,value);
        addnode(node);
        mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */