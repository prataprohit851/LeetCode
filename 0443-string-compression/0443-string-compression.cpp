class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1)return 1;
        chars.push_back('|');
        int a = 0;
        int b = 0;
        int count = 1;
        for(b = 1; b < chars.size(); b++){
            if(chars[b] == chars[b-1]){
                count++;
            }
            else{
                chars[a++] = chars[b-1];
                if(count > 1){
                    string strCount = to_string(count);
                    for(int i = 0; i < strCount.length(); i++){
                        chars[a++] = strCount[i];
                    }
                }
                count = 1;
            }
        }
        
        chars.erase(chars.begin()+a, chars.end());
        
         // for (auto it = chars.begin()+a; it != chars.end();++it){
         //     chars.erase(it);
         // }
        
        // for(a; a < chars.size(); a++){
        //     cout<<chars[a]<<" ";
        //     chars.erase(chars.begin()+a);
        // }
        // for(int i = 0; i < chars.size(); i++) cout<<chars[i]<<" ";
        return chars.size();
    }
};