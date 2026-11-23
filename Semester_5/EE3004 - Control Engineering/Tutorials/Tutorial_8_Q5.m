clear; clc; close all;
s = tf('s');
G = (s+8)/((s+3)*(s+6)*(s+10));

OS   = 20;
zeta = log(100/OS)/sqrt(pi^2 + log(100/OS)^2);      


figure;
hold on;
rlocus(G);
sgrid(zeta,[]);
hold off;

Gain = 122;
T=feedback(Gain*G,1);
info=stepinfo(T)

peaktime=2/3*0.2976
w_n=pi/(peaktime*(1-zeta^2)^0.5)
pole=-w_n*zeta + j * w_n * (1-zeta^2)^0.5

tangle = rad2deg(angle(pole+8)-angle(pole+3)-angle(pole+6)-angle(pole+10))

z1= -zeta*w_n - w_n * (1-zeta^2)^0.5/(tand(-180-tangle))

G_pd=(s-z1)

G_pi=(s+0.01)/s

figure;
hold on;
rlocus(G*G_pd*G_pi);
sgrid(zeta,[])
hold off;

