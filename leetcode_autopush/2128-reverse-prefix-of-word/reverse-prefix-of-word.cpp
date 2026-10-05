class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t end = word.find(ch);

        if(end != std::string::npos){
            reverse(word.begin(),word.begin()+end+1);
        }

        return word;

        
    }
};