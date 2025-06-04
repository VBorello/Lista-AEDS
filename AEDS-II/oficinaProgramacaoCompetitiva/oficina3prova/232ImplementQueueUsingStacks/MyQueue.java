import java.util.Stack;

class MyQueue {

    private Stack<Integer> stack1; 
    private Stack<Integer> stack2; 

    public MyQueue() {
    
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void push(int x) {
    
        stack1.push(x);
    }
    
    public int pop() {
    
        if (stack2.isEmpty()) {
            transferElements();
        }
        return stack2.pop();
    }
    
    public int peek() {

        if (stack2.isEmpty()) {
            transferElements();
        }

        return stack2.peek();
    }
    
    public boolean empty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
    
    private void transferElements() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
    }

        public static void main(String[] args) {
    
        MyQueue myQueue = new MyQueue();
        myQueue.push(1); 
        myQueue.push(2); 
        System.out.println(myQueue.peek());
        System.out.println(myQueue.pop()); 
        System.out.println(myQueue.empty()); 
    }
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */