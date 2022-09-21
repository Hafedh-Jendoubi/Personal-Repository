#include <iostream>

using namespace std;

int main()
{
    const int MAX = 10;
    int n;
    float x;
    bool test = false;
    string message;

    cout<<"donnez un entier et un flottant"<<endl;
    cin>>n>>x;
    if(x>MAX){
        test = true;
        message = "true";
        cout<<"le produit de "<<n<<" par "<<x<<endl<<"est "<<n*x<<endl<<"et message est "<<message<<endl;
    }

    return 0;
}
