#include<iostream>
#include<math.h>
#include<map>
#include<stack>
#include<string.h>
#include<cstring>
#include<vector> 
#include<sstream>
#include<queue>
#define faster ios::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
#define For(i, a, b) for(int i = a; i <= b; i++)
#define Fod(i, a, b) for(int i = a; i >= b; i--)

using namespace std;
typedef unsigned long long int lli;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> v_i;
const ll maxn = 1e7 + 4;

class Tree{
private:
    int number = 0;
    char c = '0';
    string subString;
    Tree* leftNode = NULL;
    Tree* rightNode = NULL;
    bool isVisited = false;
 
public:
    Tree* getLeftNode() {return leftNode;}
    Tree* getRightNode() {return rightNode;}
    string getSubString() {return subString;}
    bool getVisited() {return isVisited;}
    void setVisited(bool isVisited) {this->isVisited = isVisited;}
    char getC() {return c;}

    string considerToDeleteBracket(string s) {
        int openBracket = 0, closeBracket = 0;
        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == '(') {
                openBracket++;
            } else if(s[i] == ')') {
                closeBracket++;
            }
            if(openBracket == closeBracket && !(i == 0)) {
                break;
            }
            if(openBracket == closeBracket && i == 0) {
                s.erase(0, 1);
                s.pop_back();
                return s;
            }
        }
        return s;
    }

    Tree* createRoot(string s) {
        Tree* Root = new Tree; bool isFirst = true;
        s = considerToDeleteBracket(s);
        int countOpen = 0, countCLose = 0, firstOperandPosition = s.size() - 1;
        for(int i = (int)s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) {
                if(s[i] == '-' || s[i] == '+') {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i + 1, s.size() - 1);
                    Root->c = s[i];
                    Root->number = 0;
                    Root->subString = s;
                    Root->leftNode = new Tree;
                    Root->leftNode->subString = s1;
                    Root->rightNode = new Tree;
                    Root->rightNode->subString = s2;
                    return Root;
                } else if(isFirst) {
                    firstOperandPosition = i;
                    isFirst = false;
                }
            }
        }

        if(firstOperandPosition != (int)s.size() - 1) {
            string s1 = s.substr(0, firstOperandPosition);
            string s2 = s.substr(firstOperandPosition + 1, s.size() - 1);
            Root->c = s[firstOperandPosition];
            Root->number = 0;
            Root->subString = s;
            Root->leftNode = new Tree;
            Root->leftNode->subString = s1;
            Root->rightNode = new Tree;
            Root->rightNode->subString = s2;
            return Root;
        } else {
            countCLose = countOpen = 0;
            for(int i = (int)s.size() - 1; i >= 0; i --) {
                if(s[i] == ')') {countCLose++;}
                else if(s[i] == '(') {countOpen++;}
                if(countOpen == countCLose && s[i] == '^') {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i + 1, s.size() - 1);
                    Root->c = s[i];
                    Root->number = 0;
                    Root->subString = s;
                    Root->leftNode = new Tree;
                    Root->leftNode->subString = s1;
                    Root->rightNode = new Tree;
                    Root->rightNode->subString = s2;
                    return Root;
                }
            }
        }
        return Root;
    }

    string addBracketToLast(string s) {
        if(s[s.size() - 1] != ')') {
            s += ")";
            for(int i = s.size() - 1; i >= 0; i --) {
                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
                    s.insert(i + 1, "(");
                    break;
                }
            }
        }
        return s;
    } 

    Tree* split(string s, Tree* instantNode) {
        s = considerToDeleteBracket(s);
        s = addBracketToLast(s);
        int countOpen = 0, countCLose = 0, firstOperandPosition = s.size() - 1;
        bool isFirst = true;
        for(int i = (int)s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) {
                if(s[i] == '-' || s[i] == '+') {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i + 1, s.size() - 1);
                    instantNode->c = s[i];
                    instantNode->number = 0;
                    instantNode->subString = s;
                    instantNode->leftNode = new Tree;
                    instantNode->leftNode->subString = s1;
                    instantNode->rightNode = new Tree;
                    instantNode->rightNode->subString = s2;
                    return instantNode;
                } else if(isFirst){
                    firstOperandPosition = i;
                    isFirst = false;
                }
            }
        }
        
        if(firstOperandPosition != (int)s.size() - 1) {
            string s1 = s.substr(0, firstOperandPosition);
            string s2 = s.substr(firstOperandPosition + 1, s.size() - 1);
            instantNode->c = s[firstOperandPosition];
            instantNode->number = 0;
            instantNode->subString = s;
            instantNode->leftNode = new Tree;
            instantNode->leftNode->subString = s1;
            instantNode->rightNode = new Tree;
            instantNode->rightNode->subString = s2;
            return instantNode;
        } else {
            countCLose = countOpen = 0;
            for(int i = (int)s.size() - 1; i >= 0; i --) {
                if(s[i] == ')') {countCLose++;}
                else if(s[i] == '(') {countOpen++;}
                if(countOpen == countCLose && s[i] == '^') {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i + 1, s.size() - 1);
                    instantNode->c = s[i];
                    instantNode->number = 0;
                    instantNode->subString = s;
                    instantNode->leftNode = new Tree;
                    instantNode->leftNode->subString = s1;
                    instantNode->rightNode = new Tree;
                    instantNode->rightNode->subString = s2;
                    return instantNode;
                }
            }
        }
        return instantNode;
    }

    bool notHavingOperand(string s) {
        for(auto x:s) {
            if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^') {
                return false;
            }
        }
        return true;
    }

    void BuildTree(Tree* instantNode) {
        static bool isRoot = true;
        if(instantNode != NULL
        && !notHavingOperand(instantNode->subString)) {
            if(!isRoot) {
                instantNode = split(instantNode->subString, instantNode);
            } else {
                isRoot = false;
            }
            BuildTree(instantNode->leftNode);
            BuildTree(instantNode->rightNode);
        }
    }

    int convertStringToInt(string s) {
        int ans = 0;
        for(auto x:s) {
            if(x >= '0' && x <= '9') {
                ans = ans * 10 + (x - '0');
            }
        }
        return ans;
    }

    void setNumberForLeafNode(Tree* instantNode) {
        if(instantNode->c == '0') {
            instantNode->number = convertStringToInt(instantNode->subString);
            return;
        }
        setNumberForLeafNode(instantNode->leftNode);
        setNumberForLeafNode(instantNode->rightNode);
        return;
    }

    void BuildTreePerfectly(Tree*& Root, string s) {
        Root = createRoot(s);
        BuildTree(Root);
        setNumberForLeafNode(Root);
        return;
    }
};

string PostfixEvaluation(string s) {
    stack<long double> st;
    long double temp = 0;
    for(int i = 0; i < (int)s.size(); i ++) {
        if(!(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')) {
            if(s[i] != ' ') {
                temp = temp * 10 + (s[i] - '0');
            } else if(s[i] == ' ' && (s[i - 1] >= '0' && s[i - 1] <= '9')) {
                st.push(temp);
                temp = 0;
            }
        } else if(s[i] != ' '){
            long double a = st.top(); st.pop();
            long double b = st.top(); st.pop();
            if(s[i] == '+') {
                b += a;
            } else if(s[i] == '-') {
                b -= a;
            } else if(s[i] == '*') {
                b *= a;
            } else if(s[i] == '/') {
                b /= a;
            } else {
                b = pow(b, a);
            }
            st.push(b);
        }
    }
    temp = round(st.top() * 10000.0) / 10000.0;
    string ans = to_string(temp), res = "";
    int j = 0, cnt = 0;
    for(; j < (int)s.size(); j ++) {
        if(ans[j] == '.') {
            res += ans[j];
            break;
        } else {
            res += ans[j];
        }
    }
    for(; cnt < 4; cnt ++) {
        j++;
        res += ans[j];
    }
    while(res[(int)res.size() - 1] == '0') {
        res.pop_back();
    }
    if(res[(int)res.size() - 1] == '.') {
        res.pop_back();
    }
    return res;
}

string PrefixEvaluation(string s) {
    stack<long double> st;
    long double temp = 0;
    int power10 = 1;
    for(int i = (int)s.size() - 1; i >= 0; i --) {
        if(!(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')) {
            if(s[i] != ' ') {
                temp = temp + (s[i] - '0') * power10;
                power10 *= 10;
            } else if(s[i] == ' ' && (s[i + 1] >= '0' && s[i + 1] <= '9')) {
                st.push(temp);
                temp = 0;
                power10 = 1;
            }
        } else if(s[i] != ' '){
            long double b = st.top(); st.pop();
            long double a = st.top(); st.pop();
            if(s[i] == '+') {
                b += a;
            } else if(s[i] == '-') {
                b -= a;
            } else if(s[i] == '*') {
                b *= a;
            } else if(s[i] == '/') {
                b /= a;
            } else {
                b = pow(b, a);
            }
            st.push(b);
        }
    }
    temp = round(st.top() * 10000.0) / 10000.0;
    string ans = to_string(temp), res = "";
    int j = 0, cnt = 0;
    for(; j < (int)s.size(); j ++) {
        if(ans[j] == '.') {
            res += ans[j];
            break;
        } else {
            res += ans[j];
        }
    }
    for(; cnt < 4; cnt ++) {
        j++;
        res += ans[j];
    }
    while(res[(int)res.size() - 1] == '0') {
        res.pop_back();
    }
    if(res[(int)res.size() - 1] == '.') {
        res.pop_back();
    }
    return res;
}


map<char, char> mp;
class LogicTree{
private:
    string c = "0";
    string subString;
    LogicTree* leftNode = NULL;
    LogicTree* rightNode = NULL;
    bool isVisited = false;

public:
    LogicTree* getLeftNode() {return leftNode;}
    LogicTree* getRightNode() {return rightNode;}
    string getSubString() {return subString;}
    bool getVisited() {return isVisited;}
    void setVisited(bool isVisited) {this->isVisited = isVisited;}
    string getC() {return c;}

    string considerToDeleteBracket(string s) {
        int openBracket = 0, closeBracket = 0;
        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == '(') {
                openBracket++;
            } else if(s[i] == ')') {
                closeBracket++;
            }
            if(openBracket == closeBracket && !(i == 0)) {
                break;
            }
            if(openBracket == closeBracket && i == 0) {
                s.erase(0, 1);
                s.pop_back();
                return s;
            }
        }
        return s;
    }

    LogicTree* createRoot(string s) {
        LogicTree* Root = new LogicTree; 
        s = considerToDeleteBracket(s);
        int countOpen = 0, countCLose = 0;

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (i >= 2 && s[i - 1] == '-' && s[i] == '>' && s[i - 2] != '<')) {
                string s1 = s.substr(0, i - 1);
                string s2 = s.substr(i + 1, s.size() - 1);
                Root->c = "->";
                Root->subString = s;
                Root->leftNode = new LogicTree;
                Root->leftNode->subString = s1;
                Root->rightNode = new LogicTree;
                Root->rightNode->subString = s2;
                return Root;
            }
        }

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (i >= 2 && s[i - 2] == '<' && s[i - 1] == '-' && s[i] == '>')) {
                string s1 = s.substr(0, i - 2);
                string s2 = s.substr(i + 1, s.size() - 1);
                Root->c = "<->";
                Root->subString = s;
                Root->leftNode = new LogicTree;
                Root->leftNode->subString = s1;
                Root->rightNode = new LogicTree;
                Root->rightNode->subString = s2;
                return Root;
            }
        }

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (s[i] == '|' || s[i] == '&')) {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i + 1, s.size() - 1);
                Root->c = s[i];
                Root->subString = s;
                Root->leftNode = new LogicTree;
                Root->leftNode->subString = s1;
                Root->rightNode = new LogicTree;
                Root->rightNode->subString = s2;
                return Root;
            }
        }

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && s[i] == '~') {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i + 1, s.size() - 1);
                Root->c = "~";
                Root->subString = s;
                Root->leftNode = new LogicTree;
                Root->leftNode->subString = s1;
                Root->rightNode = new LogicTree;
                Root->rightNode->subString = s2;
                return Root;
            }
        }
        return Root;
    }

    string addBracketToLast(string s) {
        if(s.size() == 2 && s[0] == '~') {
            string ans = ""; ans += s[0];
            ans += "("; ans += s[1]; ans += ")";
            return ans;
        }

        if(s[s.size() - 1] != ')') {
            s += ")";
            for(int i = s.size() - 1; i >= 0; i --) {
                if(s[i] == '&' || s[i] == '|' 
                || (i >= 1 && s[i - 1] == '-' && s[i] == '>')
                || (i >= 2 && s[i - 2] == '<' && s[i - 1] == '-' && s[i] == '>')) {
                    s.insert(i + 1, "(");
                    break;
                }
            }
        }
        return s;
    } 

    LogicTree* split(string s, LogicTree* instantNode) {
        s = considerToDeleteBracket(s);
        s = addBracketToLast(s);
        int countOpen = 0, countCLose = 0;

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (i >= 2 && s[i - 1] == '-' && s[i] == '>' && s[i - 2] != '<')) {
                string s1 = s.substr(0, i - 1);
                string s2 = s.substr(i + 1, s.size() - 1);
                instantNode->c = "->";
                instantNode->subString = s;
                instantNode->leftNode = new LogicTree;
                instantNode->leftNode->subString = s1;
                instantNode->rightNode = new LogicTree;
                instantNode->rightNode->subString = s2;
                return instantNode;
            }
        }

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (i >= 2 && s[i - 2] == '<' && s[i - 1] == '-' && s[i] == '>')) {
                string s1 = s.substr(0, i - 2);
                string s2 = s.substr(i + 1, s.size() - 1);
                instantNode->c = "<->";
                instantNode->subString = s;
                instantNode->leftNode = new LogicTree;
                instantNode->leftNode->subString = s1;
                instantNode->rightNode = new LogicTree;
                instantNode->rightNode->subString = s2;
                return instantNode;
            }
        }        

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && (s[i] == '|' || s[i] == '&')) {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i + 1, s.size() - 1);
                instantNode->c = s[i];
                instantNode->subString = s;
                instantNode->leftNode = new LogicTree;
                instantNode->leftNode->subString = s1;
                instantNode->rightNode = new LogicTree;
                instantNode->rightNode->subString = s2;
                return instantNode;
            }
        }

        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ')') {countCLose++;}
            else if(s[i] == '(') {countOpen++;}
            if(countOpen == countCLose && s[i] == '~') {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i + 1, s.size() - 1);
                instantNode->c = "~";
                instantNode->subString = s;
                instantNode->leftNode = new LogicTree;
                instantNode->leftNode->subString = s1;
                instantNode->rightNode = new LogicTree;
                instantNode->rightNode->subString = s2;
                return instantNode;
            }
        }
        return instantNode;
    }

    bool notHavingOperand(string s) {
        for(int i = 0; i < (int)s.size(); i ++) {
            if(s[i] == '~' || s[i] == '&' || s[i] == '|' 
                || (i >= 1 && s[i - 1] == '-' && s[i] == '>')
                || (i >= 2 && s[i - 2] == '<' && s[i - 1] == '-' && s[i] == '>')) {
                return false;
            }
        }
        return true;
    }

    void BuildTree(LogicTree* instantNode) {
        static bool isRoot = true;
        if(instantNode != NULL
        && !notHavingOperand(instantNode->subString)) {
            if(!isRoot) {
                instantNode = split(instantNode->subString, instantNode);
            } else {
                isRoot = false;
            }
            BuildTree(instantNode->leftNode);
            BuildTree(instantNode->rightNode);
        }
    }

    int convertStringToInt(string s) {
        int ans = 0;
        for(auto x:s) {
            if(x >= '0' && x <= '9') {
                ans = ans * 10 + (x - '0');
            }
        }
        return ans;
    }

    void BuildTreePerfectly(LogicTree*& Root, string s) {
        Root = createRoot(s);
        BuildTree(Root);
        return;
    }
};

string LogicdeleteSpace(string s) {
    string proceedString = "";
    for(auto x:s) {
        if(x != ' ') {
            proceedString += x;
        }
    }
    return proceedString;
}

string LogicPostfixEvaluation(string s) {
    stack<char> st;
    for(int i = 0; i < (int)s.size(); i ++) {
        if(s[i] == '~' || s[i] == '&' || s[i] == '|'
                || (i + 1 < (int)s.size() && s[i] == '-' && s[i + 1] == '>')
                || (i + 2 < (int)s.size() && s[i] == '<' && s[i + 1] == '-' && s[i + 2] == '>')){
            char a = st.top(); st.pop();
            if(s[i] == '~') {
                if(a == '0') {
                    st.push('1');
                } else {
                    st.push('0');
                }
            } else if(s[i] == '&') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp1 = temp1 && temp2;
                if(temp1) {
                    st.push('1');
                } else {
                    st.push('0');
                }
            } else if(s[i] == '|') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp2 = temp1 || temp2;
                if(temp2) {
                    st.push('1');
                } else {
                    st.push('0');
                }
            } else if(i + 2 < (int)s.size() && s[i] == '<' && s[i + 1] == '-' && s[i + 2] == '>') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp2 = (!temp2 || temp1) && (!temp1 || temp2);
                if(temp2) {
                    st.push('1');
                } else {
                    st.push('0');
                }
                i += 2;
            } else if(i + 1 < (int)s.size() && s[i] == '-' && s[i + 1] == '>') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp1 = (!temp2) || temp1;
                if(temp1) {
                    st.push('1');
                } else {
                    st.push('0');
                }
                i++;
            }
        } else {
            st.push(mp[s[i]]);
        }
    }
    if(st.top() == '1') {
        st.pop();
        mp.clear();
        return "TRUE";
    }
    st.pop();
    mp.clear();
    return "FALSE";
}

string LogicPrefixEvaluation(string s) {
    stack<char> st;
    for(int i = (int)s.size() - 1; i >= 0; i --) {
        if(s[i] == '~' || s[i] == '&' || s[i] == '|'
                || (i >= 1 && s[i - 1] == '-' && s[i] == '>')
                || (i >= 2 && s[i - 2] == '<' && s[i - 1] == '-' && s[i] == '>')) {
            char a = st.top(); st.pop();
            if(s[i] == '~') {
                if(a == '0') {
                    st.push('1');
                } else {
                    st.push('0');
                }
            } else if(s[i] == '&') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp1 = temp1 && temp2;
                if(temp1) {
                    st.push('1');
                } else {
                    st.push('0');
                }
            } else if(s[i] == '|') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp2 = temp1 || temp2;
                if(temp2) {
                    st.push('1');
                } else {
                    st.push('0');
                }
            } else if(i >= 2 && s[i - 2] == '<' && s[i - 1] == '-' && s[i] == '>') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp2 = (!temp2 || temp1) && (!temp1 || temp2);
                if(temp2) {
                    st.push('1');
                } else {
                    st.push('0');
                }
                i -= 2;
            } else if(i >= 1 && s[i - 1] == '-' && s[i] == '>') {
                char b = st.top(); st.pop();
                bool temp1, temp2;
                if(a == '1') {
                    temp1 = true;
                } else if(a == '0') {
                    temp1 = false;
                }

                if(b == '1') {
                    temp2 = true;
                } else if(b == '0') {
                    temp2 = false;
                }

                temp1 = (!temp1) || temp2;
                if(temp1) {
                    st.push('1');
                } else {
                    st.push('0');
                }
                i--;
            }
        } else {
            st.push(mp[s[i]]);
        }
    }
    if(st.top() == '1') {
        st.pop();
        mp.clear();
        return "TRUE";
    }
    st.pop();
    mp.clear();
    return "FALSE";
}
