// Question
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.
// https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/

//---------Code---------
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long ll;

void show(vector<string> vec){
    for(auto x: vec){
        cout << x << " ";
    }cout << endl;
}

//check if a string is a valid segment of ip
bool is_valid(string s){
    if(s.size()<1 || s.size()>3){
        return false;
    }
    ll temp = stoi(s);
    if(temp > 255 || temp < 0){
        return false;
    }
    if(s[0]=='0' && temp!=0){
        return false;
    }
    return true;
}

//makes the dp matrix, dp[i][j] -> true if it is possible to split str[j:] in i+1 valid segments
void make_dp(vector<vector<int>> &dp, string &ip){
    for(int i=0; i<4; i++){
        for(int j=ip.size()-1; j>=0; j--){
            if(i==0){
                if(is_valid(ip.substr(j, ip.size()-j))){
                    dp[i][j] = 1;
                }
            }else{
                string temp = "";
                for(int k=0; k<3 && j+k+1<ip.size(); k++){
                    temp += ip[j+k];
                    if(is_valid(temp) && dp[i-1][j+k+1]){
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
}

//splits ip_str into valid substrs and appends valid ip to ips vector
void split(vector<string> &ips, vector<vector<int>> dp, string ip_str, int idx, int splits, string till_now){
    string temp = "";
    if(splits==1){
        temp = ip_str.substr(idx, ip_str.size()-idx);
        if(is_valid(temp)){
            ips.push_back(till_now + temp);
        }
    }else{
        for(int i=0; i<3 && idx+i+1<ip_str.size(); i++){
            temp += ip_str[idx+i];
            if(is_valid(temp) && dp[splits-2][idx+i+1]){
                till_now = till_now + temp + ".";
                split(ips, dp, ip_str, idx+i+1, splits-1, till_now);
            }
        }
    }
}

//driver code
int main(){
    string ip_str = "25011255255";
    vector<string> ips;
    vector<vector<int>> dp(4, vector<int>(ip_str.size(), 0));
    make_dp(dp, ip_str);
    split(ips, dp, ip_str, 0, 4, "");
    cout << ips.size() << endl;
    show(ips);
    return 0;
}
