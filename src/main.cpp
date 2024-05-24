#include <iostream>
#include <vector>
#include <sstream>

const int MAX_LINE_LENGTH = 80;    // Maximum characters per line
const int LINES_PER_PAGE = 25;     // Maximum lines per page

using namespace std;

// Function to wrap the text into lines and paginate
void Paginate(const vector<string>& words) {
    string currentLine;
    int pageNumber = 1;  // Page number counter
    int lineCount = 0;   // Line count for pagination

    for (const auto& word : words) {
        // Check if adding the current word exceeds the maximum line length
        if (currentLine.length() + word.length() > MAX_LINE_LENGTH) {
            cout << currentLine << endl;  // Print the current line
            lineCount++;

            // Check if reached maximum lines per page
            if (lineCount == LINES_PER_PAGE) {
                cout << "----- Page " << pageNumber << " -----" << endl;
                pageNumber++;
                lineCount = 0;  // Reset line count for the next page
            }

            currentLine = word;  // Start a new line with the current word
        } else {
            if (!currentLine.empty()) {
                currentLine += " ";  // Add a space if the line is not empty
            }
            currentLine += word;  // Add the current word to the line
        }
    }

    // Print the last line if it exists
    if (!currentLine.empty()) {
        cout << currentLine << endl;
        lineCount++;
    }

    // Print the final page number if needed
    if (lineCount > 0) {
        cout << "----- Page " << pageNumber << " -----" << endl;
    }
}

int main() {
    vector<string> words;
    string word;

    // Read the input words
    while (cin >> word) {
        words.push_back(word);  // Add each word to the vector
    }

    Paginate(words);  // Paginate the input text

    return 0;
}
