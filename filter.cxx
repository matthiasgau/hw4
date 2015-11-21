#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void read(double*, const int, const string);
void filter(double*, const int);
void write(double*, const int);




int main(){
  int n=20; // not necessary, just to see how effective the filter is
  const string filename="noisy.txt";
  const int N=237;
  double* p= new double[N];
  read(p,N,filename);
  for(int i=1;i<=n;i++)
    filter(p,N);
  write(p,N);
  
  delete []p; 
  
  
  return 0;
}

void read(double* p, const int N, const string fname){
  ifstream in(fname.c_str());
  for(int i=0; i<N;i++)
    in >> p[i];
  in.close();
}
void filter(double* p, const int N){
  double p1=p[0];
  double p2=p[1];
  double p3=(p[N-2]+p[N-1]+p[0])/3; //have to store the value, because we need the original p[N-1] in the for-loop
  p[0]=(p[N-1]+p[0]+p[1])/3;  //initial and periodic condition
  
  
  for(int i=1;i<N;i++){
    p2=p[i]; //saves p[i] before its overwritten
    p[i]=(p1+p[i]+p[i+1])/3;
    p1=p2;  //previous data i-1
  }
  p[N-1]=p3;
}
void write(double*p, const int N){
  ofstream out("cool.txt");
  for(int i=0;i<N;i++)
    out << p[i] <<endl;
  out.close();
}