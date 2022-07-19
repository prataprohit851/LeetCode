class Solution {
public:
    string capitalizeTitle(string title) {
        int i = 0;
        int j = 0;
        title = " " + title;
        while(j < title.length()){
            while(title[i] != ' ') i++;
            j = i + 1;
            while(j < title.length() && title[j] != ' ') j++;
            if(j - i - 1 < 3){
                while(i < j){
                    title[i] = tolower(title[i]);
                    i++;
                }
            }
            else{
                i++;
                title[i] = toupper(title[i]);
                i++;
                while(i < j){
                    title[i] = tolower(title[i]);
                    i++;
                }
            }
        }
        return title.substr(1);
    }
};