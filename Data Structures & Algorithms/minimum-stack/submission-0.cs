public class MinStack 
{
    Stack<int> stack;

    public MinStack() 
    {
        stack = new Stack<int>();
    }
    
    public void Push(int val) 
    {
        stack.Push(val);
    }
    
    public void Pop() 
    {
        stack.Pop();
    }
    
    public int Top() 
    {
        return stack.Peek();
    }
    
    public int GetMin() 
    {
        Stack<int> temp = new Stack<int>();
        int min = stack.Peek();

        while (stack.Count > 0)
        {
            min = System.Math.Min(min, stack.Peek());
            temp.Push(stack.Pop());
        }

        while (temp.Count > 0)
        {
            stack.Push(temp.Pop());
        }

        return min;
    }
}
