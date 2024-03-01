#include <iostream>
#include <stack>
using namespace std;
int main(){
    ostream& operator <<(ostream& out ,const BankAccount& ba){
        return out << ba.name << " " << ba.balance;
    }
}