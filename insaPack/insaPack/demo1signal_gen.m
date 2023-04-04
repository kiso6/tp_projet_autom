% DEMO SIGNAL GENERATION 
% Author: C. Poussot-Vassal [MOR Digital Systems / Onera]
% Date  : March 2022 (creation)
% 
% Description
% Demonstration script for identification signals construction. This small 
% script illustrates how one can generate different excitation signals in 
% view of model identification. This script is a rather simple one and 
% modifications may be applied by users. Still, it provides a first 
% shot for it, but does not prevent for additional reading and thinking.
% Among others, one can consider, the analysis of the frequency spectra,
% the length, the applicability... of each input/output couples
% 
% Note
% The script uses the "+insa" matlab package.
% 
% INSA demonstrators available in 2022
%  * billes sur rail (4)
%  * moteurs (6)
%  * balle de ping-pong (1)
%  * Soufflerie (1)
%  * Niveau d'eau (plusieurs)
%  * ailettes (3)
% 


clear all, close all, clc;
% >> Graphic settings
%rng(12345)
insa.initGraphics

% >> System to identify
G  = tf([1 -2],[.1 .4 1]);
S  = stepinfo(G);
n  = 5e-2; % noise
Fn = tf(n,[1/10 1]);

% >> PRBS CASE (constructs u1,y1,y1n)
% Generate exciting signal
N       = 5;
Tr      = S.SettlingTime*2;
Ts      = Tr/20;
P       = 4;
Plot    = 0;
[u1,t1] = insa.prbs(Ts,N,Tr,P,Plot);
% Apply to system to be identified
y1      = lsim(G,u1,t1);
% Add noise
y1n     = y1 .* (1 + lsim(Fn,randn(numel(y1),1),t1));
figure
subplot(221), hold on, axis tight
plot(t1,u1,'.-')
plot(t1,y1n,'-')
plot(t1,y1,'--')
xlabel('Time [s]'); ylabel('Amplitude [.]'); title('PRBS')
legend('$u(t_k)$','$y(t_k)+n(t_k)$','$y(t_k)$')

% >> CHIRP CASE (constructs u2,y2,y2n)
% Generate exciting signal
Wmax    = 7/S.SettlingTime;
f1      = 3*Wmax/(2*pi);
t2      = 0:1/f1/10:50;
f0      = 1e-2;
tend    = t2(end);
type    = 'linear';% 'logarithmic';
u2      = insa.chirp(t2,f0,tend,f1,type);
% Apply to system to be identified
y2      = lsim(G,u2,t2);
% Add noise
y2n     = y2 .* (1 + lsim(Fn,randn(numel(y2),1),t2));
subplot(222), hold on, axis tight
plot(t2,u2,'.-')
plot(t2,y2n,'-')
plot(t2,y2,'--')
xlabel('Time [s]'); ylabel('Amplitude [.]'); title('Chirp')
legend('$u(t_k)$','$y(t_k)+n(t_k)$','$y(t_k)$')

% >> RANDOM CASE (constructs u3,y3,y3n)
% Generate exciting signal
t3      = 0:Ts:10;
u3      = rand(1,length(t3))-.5;
% Apply to system to be identified
y3      = lsim(G,u3,t3);
% Add noise
y3n     = y3 .* (1 + lsim(Fn,randn(numel(y3),1),t3));
subplot(223), hold on, axis tight
plot(t3,u3,'.-')
plot(t3,y3n,'-')
plot(t3,y3,'--')
xlabel('Time [s]'); ylabel('Amplitude [.]'); title('Random')
legend('$u(t_k)$','$y(t_k)+n(t_k)$','$y(t_k)$')

% >> IMPULSE CASE (constructs u4,y4,y4n)
% Generate exciting signal
t4      = 0:Ts:10;
u4      = zeros(1,length(t4)); u4(1) = 1/Ts;
% Apply to system to be identified
y4      = lsim(G,u4,t4);
% Add noise
y4n     = y4 .* (1 + lsim(Fn,randn(numel(y4),1),t4));
subplot(224), hold on, axis tight
plot(t4,u4,'.-')
plot(t4,y4n,'-')
plot(t4,y4,'--')
xlabel('Time [s]'); ylabel('Amplitude [.]'); title('Impulse')
legend('$u(t_k)$','$y(t_k)+n(t_k)$','$y(t_k)$')

save('signals','G','t1','u1','y1','y1n', ...
                   't2','u2','y2','y2n', ...
                   't3','u3','y3','y3n', ...
                   't4','u4','y4','y4n')
