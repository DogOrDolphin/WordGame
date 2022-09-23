#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Function headers
int randInt();
vector<string> getWords(string s);
string removePuncuation(string s);
string toLower(string s);
vector<string> loadStopWords();
bool isStopWord(string word, vector<string> list);
vector<string> loadWords(string fileName, vector<string> stopWords);
int countWord(string word, vector<string> words);
string randWord(vector<string> words);
int countWord(string word,vector<string> words);

// Play the word game
int main() {
  // Seed random number
  srand(time(NULL));
  string fileName="Washington1.txt";
  int games=0;
  int score=0;
  char c;
  // Load the stopWords
  vector<string> stopWords, words;
  stopWords=loadStopWords();
  words=loadWords(fileName,stopWords);
  do {
    string w1, w2;  // Two random words
    int wc1, wc2;   // THe word of of the two words
    games++;        // Keep track of games played
    // Get two random words, and ther counts
    w1 = randWord(words);
    wc1 = countWord(w1,words);
    w2 = randWord(words);
    wc2 = countWord(w2,words);
    cout << "Which word is more common:" << endl;
    cout << "1. " << w1 << endl;
    cout << "2. " << w2 << endl;
    cout << "Enter 1, 2 or 0 if same:";
    int ans;
    cin >> ans;
    cout << w1 << " occurs " << wc1 << " times." << endl;
    cout << w2 << " occurs " << wc2 << " times." << endl;
    // Check to se if they got it right
    
    // Add code here
    if(wc1>wc2){
      if(ans==1){
        score++;
        cout<<"You got it!";
      }
      else{
        cout<<"Sorry!";
      }
    }
    else if(wc1<wc2){
      if(ans==2){
        score++;
        cout<<"You got it!";
      }
      else{
        cout<<"Sorry!";
      }
    }
    else{
      if(ans==0){
        score++;
        cout<<"You got it!";
      }
      else{
        cout<<"Sorry!";
      }
    }
    
    cout << score << "/" << games << endl;
    cout << "Go again? (y or n)";

    cin >> c;
  }
  while (c!='n');

}

// Return a random number between 0 and max-1
int randInt(int max) {
  int i = rand()%max;
  return i;
}

// Load vector with stop words
vector<string> loadStopWords() {
  vector<string> stopWords;
  ifstream stopFile;
  stopFile.open("StopWords.txt");
  if (stopFile.is_open()) {
    //  loop, check for end-of-file (eof)
    while (!stopFile.eof()) {
      // read a word
      string word;
      stopFile >> word;
      stopWords.push_back(word);
    }
  } else {
    cout << "Error opening stopword file" << endl;
  }
  return stopWords;

}

bool isStopWord(string word, vector<string> list) {
  // Return true if word is in stopword list
  // add code here ...
  for(int i=0; i<list.size();i++){
    if(list[i]==word){
      return true;
    }
  }
  return false;
}

// Load the speeches words from the given file
// You can just use the >> operator to read each
// word.  Call removePuncuation and toLower 
// on each word.
// Put the word in the vector and return it
vector<string> loadWords(string fileName, vector<string> stopWords) {
  vector<string> words;
  ifstream afile;
  afile.open(fileName);
  if (afile.is_open()) {
    // Read in words, and put in vector
    // Add code
    while (!afile.eof()) {
      // read a word
      string word;
      afile >> word;
      word=removePuncuation(word);
      word=toLower(word);
      if(isStopWord(word,stopWords)==false){
        words.push_back(word);
      }
      else{
        
      }
    }
  } else {
    cout << "Error opening stopword file" << endl;
  } 
  return words;
}

string randWord(vector<string> words) {
  // Pick a random word from the words vector
  // Add code ...
  int randomIndex = randInt(words.size());
  return words[randomIndex];
}

// Count the number of times word appears in words 
int countWord(string word, vector<string> words) {
  int c=0;
  // Count the number of time the word occurs 
  // in the list
  // Add code ....
  for(int i=0;i<words.size();i++){
    if(words[i]==word){
      c++;
    }
  }
  return c;
}


// Remove everything but alpha, space, - and '
string removePuncuation(string s) {
  for (int i = 0; i < s.size(); i++) { 
      
    if (!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || 
        ' ' == s[i] || '-' == s[i] || '\'' == s[i]))
    {    
        // erase function to erase  
        // the character 
        s.erase(i, 1);  
        i--; 
    } 
  } 
  return s;
}

// String to lowercase
string toLower(string s) {
  for (int i = 0; i < s.size(); i++) { 
    if (s[i] <= 'Z' && s[i] >= 'A') {
        s[i] = s[i] - ('Z' - 'z');
    } 
  }
  return s;
}