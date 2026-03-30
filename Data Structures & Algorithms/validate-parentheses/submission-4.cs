public class Solution 
{
    
    public bool IsValid(string s) 
    {
        if (s.Length == 0)
        {
            return false;
        }

        Stack<char> stack = new Stack<char>();

        foreach (char c in s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.Push(c);
            }
            else
            {
                if (stack.Count == 0)
                {
                    return false;
                }

                if (IsMatching(stack.Peek(), c))
                {
                    stack.Pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return stack.Count == 0;
    }

    public bool IsMatching(char open, char close)
    {
        return (open == '{' && close == '}'||
                open == '(' && close == ')'||
                open == '[' && close == ']');
    }
}
