#include <iostream>
#include <vector>
#include <string>
#include <sstream>    
#include <algorithm>  
#include <iomanip>    

using namespace std;

struct Sentence {
    string front; 
    string back; 
};

bool compareSentence(Sentence a, Sentence b) {

    return a.back < b.back;
}

int main() {
 
    vector<string> inputs = {
        "The quick brown fox",
        "jumped over the fence"
    };

    vector<Sentence> results; 

 
    for (int i = 0; i < inputs.size(); i++) {
        string line = inputs[i];
        stringstream ss(line);
        string word;
        vector<string> words;

     
        while (ss >> word) {
            words.push_back(word);
        }

     
        for (int j = 0; j < words.size(); j++) {
            Sentence temp;

      
            for (int k = 0; k < j; k++) {
                temp.front += words[k] + " ";
            }

    
            for (int k = j; k < words.size(); k++) {
                temp.back += words[k] + " ";
            }

            results.push_back(temp); 
        }
    }


    sort(results.begin(), results.end(), compareSentence);

    cout << "--- 순열 인덱스 ---" << endl;
    for (int i = 0; i < results.size(); i++) {

        cout << setw(20) << results[i].front << "   " << results[i].back << endl;
    }

    return 0;
}
