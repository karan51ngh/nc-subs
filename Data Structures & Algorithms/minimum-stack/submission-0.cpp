class MinStack {
public:
    vector<int> STACK;
    int STACK_SIZE;
    unordered_map<int,int> sizeMinMap;

    MinStack() {
        // this->STACK = NULL;
        // this->SMALLEST = NULL;
        this->STACK_SIZE = 0;
        // this->sizeMinMap = NULL;
        cout << "stack initialized" << endl;
    }
    
    void push(int val) {
        cout << "stack push " << val << endl;;
        this->STACK.push_back(val);
        

        if(this->STACK_SIZE == 0) {
            this->STACK_SIZE++;
            this->sizeMinMap[this->STACK_SIZE] = val;
            return;
        }
        
        this->STACK_SIZE++;
        this->sizeMinMap[this->STACK_SIZE] = min(val, this->sizeMinMap[this->STACK_SIZE - 1]);
    }
    
    void pop() {
        this->STACK.pop_back();
        this->STACK_SIZE--;
        cout << "stack size " << this-> STACK_SIZE << endl;
    }
    
    int top() {
        // return 1;
        return this->STACK[this->STACK_SIZE -1];
    }
    
    int getMin() {
        // return 1;
        return this->sizeMinMap[this->STACK_SIZE];
    }
};
