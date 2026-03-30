public class Solution
{
    public string Encode(IList<string> strs) 
    {
        StringBuilder res = new StringBuilder();

        foreach (string s in strs)
        {
            int length = s.Length;
            res.Append(length).Append("#").Append(s);
        }

        return res.ToString();
    }

    public List<string> Decode(string s) 
    {
        List<string> res = new List<string>();
        int i = 0;

        while (i < s.Length)
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }

            int length = int.Parse(s.Substring(i, j - i));
            res.Add(s.Substring(j + 1, length));
            i = j + 1 + length;
        }

        return res;
    }
}
