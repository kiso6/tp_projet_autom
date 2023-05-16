clc;
close all;

%%
%%IDENTIFICATION


%Pseudo-Random
N       = 5;
Te      = 0.005; 
Tr      = 2;
P       =5;
Plot    = 0;
[u1,t1] = insa.prbs(Te,N,Tr,P,Plot);
%% Commande sur l'angle

%step 1: essai du correcteur proportionnel, on voit que y'a de lerreur
%statique
% step2: on ajoute un integrateur a la suite, on voit que cela genere des autooscillations 
%a partir d'une certaine valeur de gain
%Step3: on choisit d'implementer un PI, pour ça on  regle les gains avec
%sisotools

Kcorr=0.91078; %2.1317;       %6.8341; % Determinés avec sisotool
Kp=5.8*Kcorr;
Ki=Kcorr;
G=-tf_ordre4;
Pi=tf([Kp Ki],[1 0]);

FTBF = feedback(Pi*G, 1);
step(FTBF)


%% Identification position et commande de la position
K_pos = 0.907; 
TF=tf([K_pos],[1 0 0]);

%Avance de phase
alpha = 2;
tau = 1;
K = 1;
C_pos = K*tf([tau*alpha 1], [tau 1])

%%Correction dans l'espace d'états

%Modele
A=[0 1;
   0 0];

B=K_pos*[0;
    1];

C=[1 0];

disp("ESPACE D'ETAT")
sys=ss(A,B,C,0)

%Correction par commande pile
Q=[1 0
   0 1];
R=1;
KK=lqr(A,B,Q,R);






disp("fin script");
