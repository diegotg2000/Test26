#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

//Parámetros de la ecuación:
const float k=1.0;
const float g=9.8;
const float pi=3.1415192654;

const float n=3/2;
const float theta=pi/2.5;
const float V=20.0;

//Parámetros de la solución:
const float T=10;

float f0(float vx, float vy);
float f1(float vx, float vy);
float f2(float vx, float vy);
float f3(float vx, float vy);
void rk2(float h);
void explicito(float h);

int main(){
    rk2(T/500);
    
    explicito(T/500);
}






void rk2(float h){
    ofstream outfile;

    outfile.open("rk2.txt");
    
    
    float xn,vxn, yn, vyn;
    float xn1,vxn1, yn1, vyn1;
    int N=T/h;
    //    K1   K2
    float k11, k12;
    float k21, k22;
    float k31, k32;
    float k41, k42;
    //Inicializo valores iniciales
    xn=0;
    yn=100;
    vxn=V*cos(theta);
    vyn=V*sin(theta);
    outfile<<xn<<' '<<yn<<endl;
    
    for(int i=1; i<=N; i++){
        k11=h*f0(vxn,vyn);
        k21=h*f1(vxn,vyn);
        k31=h*f2(vxn,vyn);
        k41=h*f3(vxn,vyn);
    
        k12=h*f0(vxn+k31/2,vyn+k41/2);
        k22=h*f1(vxn+k31/2,vyn+k41/2);
        k32=h*f2(vxn+k31/2,vyn+k41/2);
        k42=h*f3(vxn+k31/2,vyn+k41/2);
        
        xn1=xn+k12;
        yn1=yn+k22;
        vxn1=vxn+k32;
        vyn1=vyn+k42;
        
        xn=xn1;
        yn=yn1;
        vxn=vxn1;
        vyn=vyn1;
        
        outfile<<xn<<' '<<yn<<endl;
    }
    
    outfile.close();
}
void explicito(float h){
    ofstream outfile;

    outfile.open("explicito.txt");
    
    
    float xn,vxn, yn, vyn;
    float xn1,vxn1, yn1, vyn1;
    int N=T/h;
    //    K1   K2

    //Inicializo valores iniciales
    xn=0;
    yn=100;
    vxn=V*cos(theta);
    vyn=V*sin(theta);
    outfile<<xn<<' '<<yn<<endl;
    
    for(int i=1; i<=N; i++){
        xn1=xn+h*f0(vxn,vyn);
        yn1=yn+h*f1(vxn,vyn);
        vxn1=vxn+h*f2(vxn,vyn);
        vyn1=vyn+h*f3(vxn,vyn);
        
        xn=xn1;
        yn=yn1;
        vxn=vxn1;
        vyn=vyn1;
        
        outfile<<xn<<' '<<yn<<endl;
    }
    
    outfile.close();
}
float f0(float vx, float vy){
    return vx;
} 
float f1(float vx, float vy){
    return vy;
}
float f2(float vx, float vy){
    float v;
    v=sqrt(vx*vx + vy*vy);
    return -k*pow(v, n-1)*vx;
}
float f3(float vx, float vy){
    float v;
    v=sqrt(vx*vx + vy*vy);
    return -k*pow(v, n-1)*vy - g;
} 