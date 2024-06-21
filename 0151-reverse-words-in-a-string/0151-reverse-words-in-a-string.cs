public class Solution {
    public string ReverseWords(string s) {
        string[] l = s.Split(' ', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries);
        s = "";
        for(int i = l.Length-1;i >= 0;i--){
            s += (l[i]);
            if(i>0)
                s += " ";
        }
        return s;
    }
}