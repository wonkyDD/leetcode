// https://www.acmicpc.net/problem/4344
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    vector<vector<int> > scores;
    vector<double> result;
    cin>>T;
    for(int i=0; i<T; ++i){
        vector<int> v;
        for(int j=0;;++j){
            // v.size()>0 : 이미 첫번째 인덱스로 학생수가 할당
            // 
            if(v.size()>0 && j>v[0]) break;
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        scores.push_back(v);
    }

    for(int i=0; i<scores.size(); ++i){
        vector<int> v = scores[i];
        int sum=0, q=0, p=v[0];
        for(int j=1; j<v.size(); ++j){
            sum+=v[j];
        }
        
        double avg = (double)sum/p;

        for(int j=1; j<v.size(); ++j){
            if(v[j] > avg) q++;
        }

        result.push_back(((double)q/p) * 100);
        // cout<<fixed;
        // cout.precision(3);
        // cout<<avg;
    }

    cout<<fixed;
    cout.precision(3);

    for(auto it=result.begin(); it!=result.end(); ++it){
        cout<<*it<<"%";
        cout<<"\n";
    }
}



// int main() {
//     int T;
//     vector<vector<int> > scores;
//     cin>>T;
//     for(int i=0; i<T; ++i){
//         vector<int> v;
//         for(int j=0;;++j){
//             // v.size()>0 : 이미 첫번째 인덱스로 학생수가 할당
//             // 
//             if(v.size()>0 && j>v[0]) break;
//             int temp;
//             cin>>temp;
//             v.push_back(temp);
//         }
//         scores.push_back(v);
//     }

//     for(int i=0; i<scores.size(); ++i){
//         vector<int> v = scores[i];
//         for(int j=0; j<v.size(); ++j){
//             cout<<v[j]<<" ";
//         }
//         cout<<"\n";
//     }
// }