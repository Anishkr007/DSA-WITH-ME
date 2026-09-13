class LFUCache {
public:

    // ----------------------------------------
    // NODE
    // ----------------------------------------
    class Node {
    public:
        int key;
        int value;
        int cnt;

        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;

            // Every new node starts with frequency 1
            cnt = 1;
        }
    };


    // ----------------------------------------
    // DOUBLY LINKED LIST
    // ----------------------------------------
    class List {
    public:

        int size;

        Node* head;
        Node* tail;

        List() {

            // Dummy nodes
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }


        // Add node at front
        void addFront(Node* node) {

            Node* temp = head->next;

            node->next = temp;
            node->prev = head;

            head->next = node;
            temp->prev = node;

            size++;
        }


        // Remove a node
        void removeNode(Node* node) {

            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            size--;
        }
    };


    // key → Node*
    unordered_map<int, Node*> keyNode;

    // frequency → List*
    unordered_map<int, List*> freqList;


    int capacity;

    // Smallest frequency currently present
    int minFreq;

    // Current number of elements
    int curSize;


    // ----------------------------------------
    // CONSTRUCTOR
    // ----------------------------------------
    LFUCache(int cap) {

        capacity = cap;

        minFreq = 0;
        curSize = 0;
    }


    // ----------------------------------------
    // UPDATE FREQUENCY
    // ----------------------------------------
    void updateFreqListMap(Node* node) {

        // Current frequency
        int oldFreq = node->cnt;


        // Remove node from old frequency list
        freqList[oldFreq]->removeNode(node);


        // If old frequency list becomes empty
        if (freqList[oldFreq]->size == 0) {

            // If this was minimum frequency
            if (minFreq == oldFreq) {
                minFreq++;
            }
        }


        // Increase frequency
        node->cnt++;


        // If new frequency list doesn't exist
        if (freqList.find(node->cnt) == freqList.end()) {

            freqList[node->cnt] = new List();
        }


        // Add node to new frequency list
        freqList[node->cnt]->addFront(node);
    }


    // ----------------------------------------
    // GET
    // ----------------------------------------
    int get(int key) {

        // Key doesn't exist
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }


        // Find node
        Node* node = keyNode[key];


        // Save value
        int value = node->value;


        // Key was used
        // So increase its frequency
        updateFreqListMap(node);


        return value;
    }


    // ----------------------------------------
    // PUT
    // ----------------------------------------
    void put(int key, int value) {

        // Capacity is zero
        if (capacity == 0)
            return;


        // --------------------------------
        // KEY ALREADY EXISTS
        // --------------------------------
        if (keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            // Update value
            node->value = value;

            // Since it was used,
            // increase frequency
            updateFreqListMap(node);

            return;
        }


        // --------------------------------
        // CACHE IS FULL
        // --------------------------------
        if (curSize == capacity) {

            // List containing least frequency
            List* list = freqList[minFreq];


            // Last node = LRU
            Node* delNode = list->tail->prev;


            // Remove from hashmap
            keyNode.erase(delNode->key);


            // Remove from frequency list
            list->removeNode(delNode);


            // Free memory
            delete delNode;


            curSize--;
        }


        // --------------------------------
        // INSERT NEW NODE
        // --------------------------------

        Node* newNode = new Node(key, value);


        // New node always has frequency 1
        minFreq = 1;


        // Create frequency 1 list if needed
        if (freqList.find(1) == freqList.end()) {

            freqList[1] = new List();
        }


        // Add new node to frequency 1
        freqList[1]->addFront(newNode);


        // Store in hashmap
        keyNode[key] = newNode;


        curSize++;
    }
};