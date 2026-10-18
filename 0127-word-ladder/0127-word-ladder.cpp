class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();

            if(word==endWord) return steps;

            for(int i=0;i<word.size();i++){
                
                char orginal=word[i];

                for(char c='a';c<='z';c++){
                    word[i]=c;

                    if(st.count(word)){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }

                word[i]=orginal;
            }
        }

        return 0;
    }
};