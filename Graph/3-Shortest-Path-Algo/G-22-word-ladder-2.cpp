class Solution {
    public:
    // refer- https://www.geeksforgeeks.org/problems/word-ladder-ii/1
      vector<vector<string>> findSequences(string beginWord, string endWord,
                                           vector<string>& wordList) {
          
          queue<vector<string>> q;
          q.push({beginWord});
          
          set<string> st(wordList.begin(), wordList.end());
          vector<vector<string>> ans;
          int level= 0;
          
          vector<string> usedOnLevel;
          usedOnLevel.push_back(beginWord);
          
          while(!q.empty()){
              vector<string> temp;
              temp= q.front();
              q.pop();
              
              // when all the items at some level used up
              // then erase word 
              if(temp.size() > level){
                  level++;
                  for(auto it: usedOnLevel){
                      st.erase(it);
                  }
              }
              // modifying the last word of the temp array
              string word= temp.back();
              
              // before doing modification check if it is target or not
              if(word == endWord){
                  if(ans.size() == 0){
                      // first time pushing
                      ans.push_back(temp);
                  }
                  else if(ans[0].size() == temp.size()){
                      // it must be shortest sequence otherwise it is not oncluded
                      ans.push_back(temp);
                  }
              }
              
              for(int i=0; i<word.size(); i++){
                  char original= word[i];
                  for(char ch='a'; ch <= 'z'; ch++){
                      word[i]= ch;
                      if(st.count(word) > 0){
                          // temp used as strings this word is inserted for now
                          temp.push_back(word);
                          // then this word putted into queue
                          q.push(temp);
                          
                          // this word will be removed from temp so stroed at level array
                          usedOnLevel.push_back(word);
                          // now word need to be removed as at this level other word may come
                          temp.pop_back();
                      }
                  }
                  word[i]= original;
              }
              
          }
          return ans;
      }
  };