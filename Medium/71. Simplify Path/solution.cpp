#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
    string token;
    string result = "";

    istringstream pathIn(path);

    while (getline(pathIn, token, '/')) {
        if (!token.empty() && token != "." && token != "..") {
            stack.push_back(token);
        } else if (token == ".." && !stack.empty()) {
            stack.pop_back();
        }
    }

    while (!stack.empty()) {
        result = "/" + stack.back() + result;
        stack.pop_back();
    }

    return result.empty() ? "/" : result;
}

int main() {
    cout << simplifyPath("/../") << endl;
    return 0;
}