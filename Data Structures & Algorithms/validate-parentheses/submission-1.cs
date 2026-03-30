public class Solution {
    public bool IsValid(string s) 
    {
        // What do we want to do?
        // if the char is {[( we want to push into the stack, if it's )]} we want to pop.

        // Create a stack
        Stack<char> stack = new Stack<char>();

        foreach (char c in s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                stack.Push(c);
            }
            else
            {
                // If there is no opening parantheses in our stack.
                if (stack.Count == 0)
                    return false;

                // If the next closing paranthese doesn't match the last pushed char.
                if (!IsMatching(stack.Pop(), c))
                {
                    return false;
                }
            }
        }

        // The stack should have a count of 0 if every paranthese had a matching pair.
        return stack.Count == 0;
    }

    public bool IsMatching(char open, char close)
    {
        return 
        (
            open == '{' && close == '}' ||
            open == '(' && close == ')' ||
            open == '[' && close == ']'
        );
    }
}
