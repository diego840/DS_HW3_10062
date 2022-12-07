/* 
要清楚了解queue有先進先出的概念
*/
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout <<  q.front() << endl;
    cout <<  q.back() << endl;
    cout <<  q.size() << endl;

    int a = q.front(); //copy
    int &b = q.front(); //reference

    cout << q.front() << " " << &q.front() << endl; //印記體位置
    cout << a << " " << &a << endl;
    cout << b << " " << &b << endl; //與q.front()記憶體位置相同
    /*
    int size = q.size();
    for (int i = 0; i < size; i++){
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    */
    while (!q.empty()){ //當while不等於True的時候繼續執行
        cout << "q.empty():" << q.empty() << " "; 
        cout << "q.fornt():" << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    
    return 0;
}

// q.empty() 檢查是否為空
// q.push() 把值加進尾巴
// q.pop() 移除頭的值
// q.back() 回傳尾巴的值
// q.front() 回傳頭的值
// q.size() 回傳目前長度