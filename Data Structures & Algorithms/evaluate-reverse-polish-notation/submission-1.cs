public class Solution 
{
    public int EvalRPN(string[] tokens) 
    {
        Stack<int> expression = new Stack<int>();

        foreach (string token in tokens)
        {
            if (int.TryParse(token, out int num))
            {
                expression.Push(num);
            }
            else
            {
                int num2 = expression.Pop();
                int num1 = expression.Pop();
                expression.Push(Solve(token, num1, num2));
            }
        }

        return expression.Pop();
    }

    public int Solve(string operatorChar, int num1, int num2)
    {
        switch (operatorChar)
        {
            case "+":
                return num1 + num2;
            case "-":
                return num1 - num2;
            case "*":
                return num1 * num2;
            case "/":
                return num1 / num2;
            default:
                throw new Exception("Unknown Operator");
        }
    }
}
