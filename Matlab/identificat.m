clc;
close all;

%%
%%IDENTIFICATION


%Pseudo-Random
N       = 5;
Te      = 0.001; 
Tr      = 2;
P       =5;
Plot    = 0;
[u1,t1] = insa.prbs(Te,N,Tr,P,Plot);
%% Commande

%step 1: essai du correcteur proportionnel, on voit que y'a de lerreur
%statique
% step2: on ajoute un integrateur a la suite, on voit que cela genere des autooscillations 
%a partir d'une certaine valeur de gain
%Step3: on choisit d'implementer un PI, pour ça on  regle les gains avec
%sisotools

Kcorr=0.91078; %2.1317;       %6.8341; % Determinés avec sisotool
Kp=5.8*Kcorr;
Ki=Kcorr;
G=-tf_ordre3;
Pi=tf([Kp Ki],[1 0]);