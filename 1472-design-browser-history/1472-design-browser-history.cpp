class BrowserHistory {
    stack<string> bck; //STORES BACKWARD HISTORY
    stack<string> fore; //STORES FORWARD HISTORY
public:
    BrowserHistory(string homepage) {
        string s= homepage;
        bck.push(s);
    }
    
    void visit(string url) {
        bck.push(url);
        //IT CLEARS ALL FORWARD HISTORY
        while(!fore.empty()){
            fore.pop();
        }

    }
    
    string back(int steps) {
        if(steps >= bck.size()-1){
            while(bck.size() != 1){
                fore.push(bck.top());
                bck.pop();
                
            }
        }
        else{
            while(steps--){
                fore.push(bck.top());
                bck.pop();
            }
        }

        return bck.top();
    }
    
    string forward(int steps) {
            if(steps >= fore.size()){
            while(!fore.empty()){
                bck.push(fore.top());
                fore.pop();
            }
        }
        else{
            while(steps--){
                bck.push(fore.top());
                fore.pop();
            }
        }

        return bck.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */