#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    map<string, string> attributes;
    vector<string> tagStack;

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        if (line.substr(0, 2) == "</") {
            tagStack.pop_back();
        }
        else {
            line = line.substr(1, line.size() - 2);
            stringstream ss(line);

            string tagName;
            ss >> tagName;

            tagStack.push_back(tagName);

            string path = tagStack[0];
            for (int j = 1; j < tagStack.size(); j++) {
                path += "." + tagStack[j];
            }

            string attrName, equalSign, attrValue;

            while (ss >> attrName) {
                ss >> equalSign;
                ss >> attrValue;

                attrValue = attrValue.substr(1, attrValue.size() - 2);
                string key = path + "~" + attrName;
                attributes[key] = attrValue;
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        string query;
        getline(cin, query);
        if (attributes.find(query) != attributes.end())
            cout << attributes[query] << endl;
        else
            cout << "Not Found!" << endl;
    }
    return 0;
}
