class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> s(wordList.begin(),wordList.end());
        while(!q.empty())
        {
            int step = q.front().second;
            string word = q.front().first;
            q.pop();
            if(word==endWord) return step;
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(char c ='a'; c<='z';c++)
                {
                    word[i]=c;
                    if(s.find(word)!=s.end())
                    {
                        q.push({word,step+1});
                        s.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
