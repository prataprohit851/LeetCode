class Solution {
public:
    string interpret(string c) {
        int i = 0;
        string ans = "";
        while(i < c.length()){
            if(c[i] == 'G'){
                ans += "G";
                i++;
            }
            else if(c[i] == '(' && c[i+1] == ')'){
                ans += "o";
                i += 2;
            }
            else{
                ans += "al";
                i += 4;
            }
            cout<<i<<" ";
        }
        cout<<endl;
        return ans;
    }
};