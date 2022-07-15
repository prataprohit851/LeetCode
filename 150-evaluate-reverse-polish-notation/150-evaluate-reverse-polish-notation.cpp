class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int num1, num2;
        for(int i = 2; i < tokens.size(); i++){
            int flag = 0;
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                num1 = stoi(tokens[i-1]);
                num2 = stoi(tokens[i-2]);
                flag = 1;
            }
            if(tokens[i] == "+")        tokens[i] = to_string(num1 + num2);
            else if(tokens[i] == "-")   tokens[i] = to_string(num2 - num1);
            else if(tokens[i] == "*")   tokens[i] = to_string(num1 * num2);
            else if(tokens[i] == "/")   tokens[i] = to_string(num2 / num1);
            if(flag){
                tokens.erase(tokens.begin() + i-2, tokens.begin() + i);
                i -= 2;
            }
        }
        return stoi(*tokens.begin());
    }
};