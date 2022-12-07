#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout << "Hello World!" << endl;
    //{用 iterator 來印出 vector 內所有內容}
    //vector<int> vec({1,2,3});
    // for (auto it=vec.begin(); it != vec.end(); ++it){
    //     cout << *it <<" ";
    // }

    //{比較懶人的作法}
    // vector<int> vec({1,2,3});
    // for (auto &v : vec){
    //     cout << v <<" ";
    // }
    return 0;
}
// 名稱.shrink_to_fit() {清空沒有配置到的vector}
// 名稱.reserve(變數a) {變數a宣告的大小事vector配置的大小}
// 名稱.resize(變數a) {變數a宣告的大小事vector配置的大小,並且初始化為零或指定的value}
// 名稱.size() {當下vector存取後配置的空間}
// 名稱.capacity() {vectort初始配置的空間}