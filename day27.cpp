#include<iostream>
#include<stack>
#include<string>
using namespace std;

class infixToPostfix{
    private:
    int precedence(char op){
        if(op =='^') return 3;
        if(op =='*' || op =='/') return 2;
        if(op =='+' || op =='-') return 1;
        return 0;
    }
    public:
    string intopostconvert(string infix){
        stack<char> st;
        string postfix;
        for(int i=0;i<infix.length();i++){
            char c= infix[i];
        
        if(isOperand(c)){
            postfix+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top() != '('){
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top())>= precedence(c)){
                postfix+= st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        postfix+= st.top();
        st.pop();
    }
    return postfix;
}
bool isOperand(char c){
    return (c>='a' && c<='z')|| (c>='A' && c<='Z')|| (c>=0 && c<=9);
    }
};

int main(){
    infixToPostfix obj;
    string str, postr;
    cin>>str;
    postr=obj.intopostconvert(str);
    cout<<"postfix exp: "<<postr;
    return 0;
}