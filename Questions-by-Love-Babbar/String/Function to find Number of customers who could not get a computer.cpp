// Question
// Write a function “runCustomerSimulation” that takes following two inputs 
// a) An integer ‘n’: total number of computers in a cafe and a string: 
// b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer. 
// A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times. 
// Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.
// For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.
// https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/

//------------Code-------------
//------------O(n)-------------

#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long ll;

int count_miss(int, string);

int main(){
    cout << count_miss(2, "ABBAJJKZKZ") << endl;
    cout << count_miss(3, "GACCBDDBAGEE") << endl;
    cout << count_miss(3, "GACCBGDDBAEE") << endl;
    cout << count_miss(1, "ABCBCA") << endl;
    cout << count_miss(1, "ABCBCADEED") << endl;
    return 0;
}

int count_miss(int n, string seq){
    vector<int> cwc(256, 0);
    int ans=0;
    for(auto x: seq){
        if(cwc[x]){
            cwc[x] = 0;
            n++;
        }else if(n>0){
            cwc[x] = 1;
            n--;
        }else{
            ans++;
        }
    }
    return ans/2;
}
