class BrowserHistory {
    static stack<string> bck; //STORES BACKWARD HISTORY
    static stack<string> fore; //STORES FORWARD HISTORY
public:
    BrowserHistory(string homepage) {
        bck.push(homepage);
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

stack<string> BrowserHistory::bck; // Definition of static member variable bck
stack<string> BrowserHistory::fore; // Definition of static member variable fore

/*This error typically occurs when you declare a static member variable in a class but fail to define it outside the class declaration. 
Static member variables need to be defined separately outside the class declaration to allocate memory for them.*/
/*Place these definitions at the global scope in the source file where you implement the member functions of the BrowserHistory class.
 This ensures that memory is allocated for the static member variables, resolving the undefined symbol error during compilation.*/

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */