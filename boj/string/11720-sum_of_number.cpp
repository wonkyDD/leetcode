// https://www.acmicpc.net/problem/11720
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, sum=0;
    string s;
    cin>>N;
    cin>>s;
    //atoi(a.c_str());
    for (int i=0; i<N; ++i){
        int num = (int)s[i]-48;
        sum += num;
    }
    cout<<sum;    
}
