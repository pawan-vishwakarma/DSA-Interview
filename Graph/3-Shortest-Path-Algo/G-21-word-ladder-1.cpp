class Solution {
    public:
    // refer= https://www.geeksforgeeks.org/problems/word-ladder/1
    // refer- https://leetcode.com/problems/word-ladder/submissions/901118436/

      int wordLadderLength(string startWord, string targetWord,
                           vector<string>& wordList) {
          
          queue<pair<string, int>> q;
          q.push({startWord, 1});
          
          set<string> st;
          
          for(string s: wordList){
              st.insert(s);
          }
          
          while(!q.empty()){
              string wrd= q.front().first;
              int level= q.front().second;
              q.pop();
              
              if(wrd == targetWord) return level;
              // tc- n*wrdlength*26*logn(set lookup)
              for(int i=0; i<wrd.size(); i++){
                  char old= wrd[i];
                  for(char ch='a'; ch <= 'z'; ch++){
                      // ith char of the word is replaced from a to z
                      wrd[i]= ch;
                      if(st.find(wrd) != st.end()){
                          // remove this word as we found it on optimal level 
                          // no need even it found later beaucse we are looking for shortest dist
                          st.erase(wrd);
                          q.push({wrd, level+1});
                      }
                  }
                  // for further process we need to keep original word
                  wrd[i]= old;
              }
              
          }
          return 0;
          
      }
  };