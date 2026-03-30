public class MinStack 
{
    // Now lets try the more efficient algo.
    Stack<int> stack;
    Stack<int> minStack;
    public MinStack() 
    {
        stack = new Stack<int>();
        minStack = new Stack<int>();
    }
    
    public void Push(int val) 
    {
        stack.Push(val);
        // Everytime we are adding a val so the top element of the stack will always be the smallest value.
        val = Math.Min(val, minStack.Count == 0 ? val : minStack.Peek());
        minStack.Push(val);
    }
    
    public void Pop() 
    {
        stack.Pop();
        minStack.Pop();
    }
    
    public int Top() 
    {
        return stack.Peek();
    }
    
    public int GetMin() 
    {
        return minStack.Peek();
    }
}
