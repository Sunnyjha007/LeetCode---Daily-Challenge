class Node
{
    public:
    string data;
    Node *prev,*next;
    
    Node()
    {
        data="";
        prev=next=NULL;
    }
    Node(string _data)
    {
        data=_data;
        prev=next=NULL;
    }
};
class BrowserHistory {
public:
    
    Node *curr=new Node();
    BrowserHistory(string homepage) {
        Node *begin=new Node(homepage);
        begin->prev=curr;
        curr->next=begin;
        curr->prev=NULL;
        curr=curr->next;
        
    }
    
    void visit(string url) {
        Node *newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        newNode->next=NULL;
        curr=curr->next;
    }
    
    string back(int steps) {
        
        while(steps-- and curr->prev->data!="")
        {
            curr=curr->prev;
		}
        return curr->data;
    }
    
    string forward(int steps) {
        
        while(steps-- and curr->next)
        {
            curr=curr->next;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
