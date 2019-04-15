#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

//Parámetros de la ecuación:
const float k=1.0;
const float g=9.8;
const float n=1;
const float pi=3.1415192654;
const float theta=pi/4;
const float V=2.0;
float f0(float vx, float vy);
float f1(float vx, float vy);
float f2(float vx, float vy);
float f3(float vx, float vy);
float rk2(float h);









float rk2(float h){
    float xn,vxn, yn, vyn;
    float xn1,vxn1, yn1, vyn1;
    //    K1   K2
    float k11, k12;
    float k21, k22;
    float k31, k32;
    float k41, k42;
    //Inicializo valores iniciales
    x=0;
    y=0;
    vx=V*cos(theta);
    vy=V*sin(theta);
    
    k11=h*f()
    k21=h*f()
    k31=h*f()
    k41=h*f()
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