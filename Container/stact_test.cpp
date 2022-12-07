#include <iostream>
#include <stack>
 
using namespace std;
 
int main() {
    int n;
    while (cin >> n && n){
        while (1){
            int a[n], point = 1;
            stack <int> stk;
            cin >> a[0];
            if (a[0] == 0) break;
            for (int i = 1; i < n; i++){
                cin >> a[i];
            }
            int i;
            for (i = 0; i < n; i++){
                if (!stk.empty() && stk.top() == a[i]){
                    stk.pop();
                }else if (a[i] >= point){
                    for (int j = point; j < a[i]; j++){
                        stk.push(j);
                    }
                    point = a[i] + 1;
                }else{
                    break;
                }
            }
            if (i == n){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}




/*
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int N,n,ans=0,R;
    int sample[1002];
    bool mem = true;
    bool close = true;
    stack<int> q;
    while (cin >> N){
        if (N == 0){
            while (!q.empty()){
                q.pop();
            }
            break ;
        }
        while (1){
            if (N == 0){
                while (!q.empty()){
                    q.pop();
                }
                break ;
            }
            else{
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
                    }
                }
            }
        }
        
    } //while
}
*/