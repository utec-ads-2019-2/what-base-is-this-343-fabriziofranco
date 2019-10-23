#include <iostream>

using namespace std;
int MAX_BASE=36;


int get_Value(char c){
    if (isdigit(c))
        return int(c) - '0';
    else
        return int(c) - 'A' + 10;
}




long to_Base(string str, int base){
    int size = str.size(), power = 1, num = 0, i;

    for (i = size-1; i >= 0; i--){
        if (get_Value(str[i]) >= base){
            return -1;
        }
        num += get_Value(str[i]) * power;
        power = power * base;
    }
    return num;
}


int min(string x){
    int t1, aux = 1;

    for (size_t i = 0; i <= x.size()-1; ++i) {
        if(isalpha(x[i])){
            t1 = int(x[i]) - 54;
        } else {
            t1 = int(x[i]) - 48 + 1;
        }

        if(t1>aux)
            aux = t1;
    }
    if(aux <= 2)
        return 2;
    if(aux >= MAX_BASE)
        return MAX_BASE;
    return aux;
}

string findBases(const string& num1, const string& num2){

    for (int i = min(num1); i <= MAX_BASE; ++i) {
        for (int j = min(num2); j <= MAX_BASE; ++j) {
            if(to_Base(num1,i) == to_Base(num2,j)){
                return num1 + " (base " + to_string(i) + ") = " + num2 + " (base " + to_string(j) + ")\n";
            }
        }
    }
    return num1 + " is not equal to " + num2 + " in any base 2..36\n";
    
}


int main() {
    string num1,num2;

    while(cin >> num1 >> num2){
        cout<<findBases(num1,num2);
    }


    return 0;
}