class Node {
public:
    Node* next;
    int value;
    Node(int val = 0 , Node* ptr = nullptr){
        next = ptr;
        value = val; 
    }
};
class LinkedList {
private:
    Node* ptrToHead;
public:
    LinkedList() {
        this->ptrToHead = nullptr;
    }

    int get(int index) {
        Node* current = this->ptrToHead;
        for( int i = 0 ; i < index && current != nullptr; i++){
            current = current->next;
        }
        return current ? current->value : -1;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val, this->ptrToHead);
        this->ptrToHead = newHead;
    }
    
    void insertTail(int val) {
        if (!this->ptrToHead) {
            this->ptrToHead = new Node(val);
            return;
        }
        Node* parse = this->ptrToHead;
        while(parse->next != nullptr){
            parse = parse->next;
        }
        parse->next = new Node(val);
    }

    bool remove(int index) {
        if (!this->ptrToHead) return false;
        if (index == 0) {
            Node* toDelete = this->ptrToHead;
            this->ptrToHead = this->ptrToHead->next;
            delete toDelete;
            return true;
        }
        Node* parse = this->ptrToHead;
        for(int i = 0 ; i < index - 1 && parse != nullptr; i++){
            parse = parse->next;
        }
        if (!parse || !parse->next) return false;
        Node* toDelete = parse->next;
        parse->next = parse->next->next;
        delete toDelete;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = this->ptrToHead;
        while(curr != nullptr){
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }
};
