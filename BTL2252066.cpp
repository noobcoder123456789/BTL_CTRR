#include "BTL2252066.h"

string Infix2Postfix(string infix) {
    bool check = true;
    string ANS = "";
    for(int i = 0; i < (int)infix.size(); i ++) {
        if(infix[i] == '^' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/') {
            check = false;
            break;
        }
        if(infix[i] != '(' && infix[i] != ')') {
            ANS += infix[i];
        }
    }
    if(check) {
        return ANS;
    }
    Tree* Root = new Tree;
    infix = Root->addBracketToLast(infix);
    Root->BuildTreePerfectly(Root, infix);
    stack<Tree*> st;
    vector<string> v;
    st.push(Root);
    while(!st.empty()) {
        Tree* temp = st.top();
        if((temp->getLeftNode() == NULL && temp->getRightNode() == NULL)
            ||(temp->getLeftNode()->getVisited() && temp->getRightNode()->getVisited())) {
            if(temp->getC() == '0') {
                string tempStr1 = temp->getSubString();
                string tempStr2 = "";
                for(int i = 0; i < (int)tempStr1.size(); i ++) {
                    if(tempStr1[i] != '(' && tempStr1[i] != ')') {
                        tempStr2 += tempStr1[i];
                    }
                }
                v.push_back(tempStr2);
            } else {
                string tempStr = ""; tempStr += temp->getC();
                v.push_back(tempStr);
            }
            temp->setVisited(true);
            st.pop();
        } else {
            if(temp->getRightNode() != NULL) {
                st.push(temp->getRightNode());
            }
            if(temp->getLeftNode() != NULL) {
                st.push(temp->getLeftNode());
            }
        }
    }

    string ans = "";
    for(auto x:v) {
        if(x != "") {
            ans += x + ' ';
        }
    }

    return ans;
}

string Infix2Prefix(string infix) {
    bool check = true;
    string ANS = "";
    for(int i = 0; i < (int)infix.size(); i ++) {
        if(infix[i] == '^' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/') {
            check = false;
            break;
        }
        if(infix[i] != '(' && infix[i] != ')') {
            ANS += infix[i];
        }
    }
    if(check) {
        return ANS;
    }
    Tree* Root = new Tree;
    infix = Root->addBracketToLast(infix);
    Root->BuildTreePerfectly(Root, infix);
    stack<Tree*> st;
    vector<string> v;
    st.push(Root);

    while(!st.empty()) {
        Tree* temp = st.top();
        st.pop();
        if(temp->getC() == '0') {
            string tempStr1 = temp->getSubString();
            string tempStr2 = "";
            for(int i = 0; i < (int)tempStr1.size(); i ++) {
                if(tempStr1[i] != '(' && tempStr1[i] != ')') {
                    tempStr2 += tempStr1[i];
                }
            }
            v.push_back(tempStr2);
        } else {
            string tempStr = ""; tempStr += temp->getC();
            v.push_back(tempStr);
        }
        if(temp->getRightNode() != NULL) {
            st.push(temp->getRightNode());
        }
        if(temp->getLeftNode() != NULL) {
            st.push(temp->getLeftNode());
        }
    }

    string ans = "";
    for(auto x:v) {
        ans += x + ' ';
    }

    return ans;
}

string PostfixPrefixCalculator(string input) {
    bool check = true;
    string ANS = "";
    for(int i = 0; i < (int)input.size(); i ++) {
        if(input[i] == '^' || input[i] == '*' || input[i] == '+' || input[i] == '-' || input[i] == '/') {
            check = false;
            break;
        }
        if(input[i] != '(' && input[i] != ')') {
            ANS += input[i];
        }
    }
    if(check) {
        return ANS;
    }
    if(input[0] >= '0' && input[0] <= '9') {
        return PostfixEvaluation(input);
    } 
    return PrefixEvaluation(input);
}

string LogicInfix2Postfix(string infix) {
    LogicTree* Root = new LogicTree;
    infix = LogicdeleteSpace(infix);
    infix = Root->addBracketToLast(infix);
    Root->BuildTreePerfectly(Root, infix);
    stack<LogicTree*> st;
    vector<string> v;
    st.push(Root);
    while(!st.empty()) {
        LogicTree* temp = st.top();
        if((temp->getLeftNode() == NULL && temp->getRightNode() == NULL)
            ||(temp->getLeftNode()->getVisited() && temp->getRightNode()->getVisited())) {
            if(temp->getC() == "0") {
                string tempStr1 = temp->getSubString();
                string tempStr2 = "";
                for(int i = 0; i < (int)tempStr1.size(); i ++) {
                    if(tempStr1[i] != '(' && tempStr1[i] != ')') {
                        tempStr2 += tempStr1[i];
                    }
                }
                v.push_back(tempStr2);
            } else {
                string tempStr = ""; tempStr += temp->getC();
                v.push_back(tempStr);
            }
            temp->setVisited(true);
            st.pop();
        } else {
            if(temp->getRightNode() != NULL) {
                st.push(temp->getRightNode());
            }
            if(temp->getLeftNode() != NULL) {
                st.push(temp->getLeftNode());
            }
        }
    }

    string ans = "";
    for(auto x:v) {
        if(x != "") {
            ans += x;
        }
    }

    return ans;
}

string LogicInfix2Prefix(string infix) {
    LogicTree* Root = new LogicTree;
    infix = LogicdeleteSpace(infix);
    infix = Root->addBracketToLast(infix);
    Root->BuildTreePerfectly(Root, infix);
    stack<LogicTree*> st;
    vector<string> v;
    st.push(Root);

    while(!st.empty()) {
        LogicTree* temp = st.top();
        st.pop();
        if(temp->getC() == "0") {
            string tempStr1 = temp->getSubString();
            string tempStr2 = "";
            for(int i = 0; i < (int)tempStr1.size(); i ++) {
                if(tempStr1[i] != '(' && tempStr1[i] != ')') {
                    tempStr2 += tempStr1[i];
                }
            }
            v.push_back(tempStr2);
        } else {
            string tempStr = ""; tempStr += temp->getC();
            v.push_back(tempStr);
        }
        if(temp->getRightNode() != NULL) {
            st.push(temp->getRightNode());
        }
        if(temp->getLeftNode() != NULL) {
            st.push(temp->getLeftNode());
        }
    }

    string ans = "";
    for(auto x:v) {
        ans += x;
    }

    return ans;
}

string LogicPostfixPrefixCalculator(string input, string value) {
    int j = value.size() / 2 + 1;
    for(int i = 0; i + 1 <= (int)value.size() / 2; i ++) {
        if(value[i] != ' ') {
            mp[value[i]] = value[j];
        }
        j++;
    }
    if((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z')) {
        return LogicPostfixEvaluation(input);
    }
    return LogicPrefixEvaluation(input);
}
