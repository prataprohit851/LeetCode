class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string res = "";
        int i = 0;
        while(i < s.length()){
            if(isdigit(s[i])){
                int count = 0;
                while(isdigit(s[i])){
                    count = 10 * count + (s[i++]-'0');
                }
                counts.push(count);
            }
            else if(s[i] == '['){
                result.push(res);
                res = "";
                i++;
            }
            else if(s[i] == ']'){
                string temp = result.top();
                result.pop();
                int count = counts.top();
                counts.pop();
                for(int i = 0; i < count; i++){
                    temp += res;
                }
                res = temp;
                i++;
            }
            else{
                res += s[i++];
            }
        }
        return res;
    }
};