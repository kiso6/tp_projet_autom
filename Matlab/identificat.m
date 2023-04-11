clc;
close all;

%%
%%IDENTIFICATION


%Pseudo-Random
N       = 5;
Te      = 0.01; 
Tr      = 2;
P       =5;
Plot    = 0;
[u1,t1] = insa.prbs(Te,N,Tr,P,Plot);