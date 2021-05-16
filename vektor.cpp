#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


ifstream in("duomenys.txt");
ofstream out ("rezultatai.txt");

void reading(vector<double>&A);
void avergeWeight(vector<double>&A, double &averageWeight);
void mostHeavy(vector<double>&A, double &heavestPack);
void mostEasy(vector<double>&A, double &easiestPack);
void isWeightOk(vector<double>&A, bool &fit );

int main()
{
    vector<double> A;
    vector<double> B;
    double averageWeight = 0;
    double heavestPack = 0;
    double easiestPack = 0;
    bool fit = false;

    reading(A);
    avergeWeight(A, averageWeight);
    mostHeavy(A, heavestPack);
    mostEasy(A, easiestPack);
    isWeightOk(A, fit);

    in.close();
    out.close();

    return 0;
}

////////skaitymas///////////////////
void reading(vector<double>&A)
 {
     if (in){
        double value;
        while( in>>value)
           {
               A.push_back(value);
           }
     }
 }

 ////////lengviausios dezes radimas///////////////////

 void mostEasy(vector<double>&A, double &easiestPack)
 {
    easiestPack = A[1];
    for (int i = 1; i < A.size(); i++){
        cout<<A[i]<<"elementas"<<i<<endl;
        if(A[i] < easiestPack)
            easiestPack = A[i];
    }
        out<<"Lengviausia yra deze Nr. "<<easiestPack<<endl;
 }

 ////////sunkiausios dezes radimas///////////////////
  void mostHeavy(vector<double>&A, double &heavestPack)
 {
   heavestPack = A[1];
   for (int i = 1; i < A.size(); i++){
        if(A[i] > heavestPack)
            heavestPack = A[i];
        }
   out<<"Sunkiausia yra deze Nr. "<<heavestPack<<endl;
 }

  ////////deziu svorio vidurkio radimas///////////////////

void avergeWeight(vector<double>&A, double &averageWeight)
 {
    double sumWeight=0;
    for (int i = 1; i < A.size(); i++){
        sumWeight=sumWeight+A[i];
    }
        averageWeight=sumWeight/(A.size() - 1);
        out<<"Vidutinis svoris "<<averageWeight<<endl;
 }

  ////////ar keltuvas pakels///////////////////
 void isWeightOk(vector<double>&A, bool &fit)
 {
    for (int i = 1; i < A.size(); i++){
        if(A[i] > A[0]){
            fit = true;
        }
    }
    if(fit==true){
        out<<"Yra deziu, kuriu keltuvas nepaveza"<<endl;
    }else{
        out<<"Nera deziu, kuriu keltuvas nepaveza"<<endl;
    }
 }



