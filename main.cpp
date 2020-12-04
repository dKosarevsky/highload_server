#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <regex>
#include <map>
// vcpkg
// uWebSockets

using namespace std;

void to_lower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void bot(const string &text) {
    cout << "[BOT]: " << text << endl;
}

string user() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    to_lower(question);
    return question;
}

int main() {
    cout << "Hello user! What is your question? Please enter:\n";
    string question;  // user question

    map<string, string> database = {
            {"hello",              "Oh, hello to you, human"},
            {"how are you",        "I'm fine"},
            {"what are you doing", "I'm work hard"},
            {"what is your name",  "My name is Bot_2020"},
            {"exit",               "Bye-bye!"},
    };

    while (question != "exit") {
        question = user();
        bool isAnswerFound = false;
        for (const auto &entry:database) {
            regex pattern = regex(".*" + entry.first + ".*");
            if (regex_match(question, pattern)) {
                bot(entry.second);
                isAnswerFound = true;
            }
        }
        if (!isAnswerFound) {
            bot("Sorry, i don't understand You");
        }
    }

    return 0;
}
