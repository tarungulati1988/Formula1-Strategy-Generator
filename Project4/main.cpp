#include <cstdlib>
#include <iostream>

#include "case.h"
#include "input.h"

using namespace std;

int main()
{
    //makeCase();
    cout<<endl<<"Weather:\n1 --> Dry\n2 --> Windy\n3 --> Cloudy";
    cout<<endl<<"TrackID:\n1 --> Australia\n2 --> Malaysia\n3 --> India";
    cout<<endl<<"Current cases in the database: \n";
    getCase();
    cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~USER INPUT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    caseMatchAndAdaptation();
    cout<<endl<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STRATEGY DETAILS~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    getchar();
    return 0;
}
