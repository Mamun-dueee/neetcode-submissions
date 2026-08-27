class Node{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v):key(k), val(v), 
        prev(nullptr), next(nullptr){};

};

class LRUCache {
    int cap;
    unordered_map<int, Node *> cache;
    Node *left;
    Node *right;
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }

    void insert(Node *node){
        Node *prevNode = right->prev;
        node->prev = prevNode;
        node->next = right;
        prevNode->next = node;
        right->prev = node;
    }

    void remove(Node *node){
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node *resNode = cache[key];
            int res = resNode->val;
            remove(resNode);
            insert(resNode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node *curNode = cache[key];
            curNode->val = value;
            remove(curNode);
            insert(curNode);
        }
        else{
            Node *addNode = new Node(key, value);
            cache[key] = addNode;
            insert(addNode);
        }
        if(cache.size() > cap){
            Node *delNode = left->next;
            cache.erase(delNode->key);
            remove(delNode);
            delete(delNode);
        }
        
    }
};
