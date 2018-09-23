#include <iostream>

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "cases.h"
using namespace std;;


void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
//      char* str="2+3";
    auto * str= const_cast<char *>("1*8+5/5*7+6-7/4-9");
    Tree<string> tree(str);
    cout << tree.start();
}

int main(int argc, char const *argv[]) {

    menu();

    cout << "\nPress enter to continue ..."; 
    cin.get(); 
    return EXIT_SUCCESS;
}

