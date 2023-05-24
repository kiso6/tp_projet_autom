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
figure(1)
step(FTBF)
title("correction de l'angle en BF")


%% Identification position et commande de la position
K_pos = 0.907; 
TF=tf([K_pos],[1 0 0]);

%Avance de phase
alpha = 2;
tau = 1;
K = 1;
C_pos = K*tf([tau*alpha 1], [tau 1])

%% Correction dans l'espace d'états

%   Modele
A=[0 1;
   0 0];

B=K_pos*[0;
    1];

C=[1 0];

disp("ESPACE D'ETAT")
sys=ss(A,B,C,0);
% Correction par commande lqr
q1=10;q2=1;%(K_pos)^2;

Q=[q1 0
   0 q2];

R=1;

[G,KK,lambda]=lqr(A,B,Q,R)
A_bf=A-B*G;
commande_opt=ss(A_bf,B,-G,0);

figure(2)
sys_corr=ss(A_bf,B,C,0);
step(2*sys_corr)
title("Echelon pour le système corrigé")
figure(3)
step(2*commande_opt)
title("commande lqr")

%% Placement de pôles
%Specifications de notre cahier des charges
tr=6;% 10 sec pour s'établir à 5%
D=0.05;% pourcentage du premier dépassement à 25%
z=sqrt((log(D)^2)/(pi^2+(log(D)^2)));
w0=tr/(6*z);
p1=-z*w0-w0*sqrt((z^2)-1);
p2=-z*w0+w0*sqrt((z^2)-1);

paul=[p1 p2];%[-0.1+0.5i -0.1-0.5i]%[-0.2112+1.235i -0.2112-1.235i];
K= place(A,B,paul)
sys_corr_poles=ss(A-B*K,B,C,0);
commande_poles=ss(A-B*K,B,-K,0);
figure(4)
step(2*sys_corr_poles)
title("Placement de pôles")
figure(5)
step(2*commande_opt)
title("commande placement de pôles")






disp("fin script");
