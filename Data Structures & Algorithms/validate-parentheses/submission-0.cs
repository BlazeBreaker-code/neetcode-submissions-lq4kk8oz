public class Solution 
{
    /*
    To solve this we are going to have to push {[()]} into our stack and then pop to match them.
    To get the first element we would seek.
    */
    public bool IsValid(string s) 
    {
        Stack<char> stack = new Stack<char>();

        foreach (char c in s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                stack.Push(c);
            }
            else
            {
                if (stack.Count == 0 || !isMatchingPair(stack.Peek(), c))
                {
                    return false;
                }

                stack.Pop();
            }
        }

        return stack.Count == 0;
    }

    public bool isMatchingPair(char open, char close)
    {
        return  (open == '{' && close == '}') ||
                (open == '[' && close == ']') ||
                (open == '(' && close == ')');
    }
}
