#include<iostream>
#include<stack>
using namespace std;
int main(){
    int N,n,ans=0,R;
    int sample[1010];
    bool mem = true;
    bool close = true;
    stack<int> q;
    while (cin >> N && N){
        while (1){
            if (q.empty()==1){
                for (int i = 0; i < N; i++){
                    cin >> n;
                    q.push(n);
                }
                cout << "Yes" << endl;
            }else{
                for (int i = 0; i < N; i++){
                    cin >> sample[i];
                    if (sample[i] == q.top() && sample[i] > 0 && mem == true){
                        ans++;
                        q.pop();
                    }else if (mem == true && sample[i] > 0){
                        R = i;
                        //cout << i << endl;
                        mem = false;
                    }else if (sample[i] == 0){
                        break;   
                    }
                } //for
                //cout << "ans:" << ans << endl;
                if (ans == N){
                    ans = 0;
                    mem = true;
                    cout << "Yes" << endl;
                    for (int i = N-1; i >= 0 ; i--){
                        q.push(sample[i]);
                    }
                }else if(sample[0]!=0){
                    mem =true;
                    //cout << q.top() << endl;
                    while (R > 0){
                        q.push(sample[R-1]);
                        R--;
                    }
                    ans = 0;
                    //cout << q.top() << endl;
                    cout << "No" << endl;
                }else{
                    mem = true;
                    while (!q.empty()){
                        q.pop();
                    }
                    break;
                } //if(ans==N)的else
            } //if (q.empty()==1)的else
        }  // while(1)
        cout << endl;
    } //while(cin >> N)
} //main()









/*
        if (N==0){
            while (!q.empty()){
                q.pop();
            }
        }else{  
            if (q.empty()){
                for (int i = 0; i < N; i++){
                    int n;
                    cin >> n;
                    q.push(n);
                }
                cout << "Yes" << endl;
            }else{
                int m=N;
                for (int i = 0; i < N; i++){
                    cin >> sample[i];
                }
                
                
            }    
        } //else
*/

// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){
//     stack<int> q;
//     string cmd;
//     int a;
//     while (cin >> cmd){
//         if (cmd == "push"){
//             cin >> a;
//             q.push(a);
//         }else if (cmd == "pop"){
//             if (q.empty()){
//                 cout << "pop : nothing in stack" << endl;
//                 // break;
//             }else{
//                 cout << q.top() << endl;
//                 q.pop();
//             }
//         }
//     }
//     return 0;
// }