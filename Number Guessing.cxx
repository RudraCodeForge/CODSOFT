#include<iostream>
#include<cstdlib>
#include<stdexcept>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    int rm=rand()%100+1;
    int gm;
    while(true){
        cout<<"Enter the number : ";
        try{
            cin>>gm;
            if(cin.fail()){
                throw invalid_argument("Invalid Input. Please enter only integer number");
                }
                if(rm==gm){
                    cout<<"You did it"<<endl;
                    break;
                    }
                else if(rm>gm){
                    cout<<"Guess is to lower than the actual number"<<endl;
                    }
                else{
                    cout<<"Guess is to higher than the actual number"<<endl;
                }
        }
                    catch(const invalid_argument& e){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>:: max(),'\n');
                        cout<<e.what()<<endl;
                        }
            }
            return 0;
}

      
