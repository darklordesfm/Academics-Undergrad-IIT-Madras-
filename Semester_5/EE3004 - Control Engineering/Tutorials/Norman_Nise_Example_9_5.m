clear; clc;
s=tf('s')
G=(1/(s+0.4))*0.7/(s^2+1.7*s+0.25)
H=0.5/(s+0.5)

OS=5/100
t_p=8

zeta=-log(OS)/sqrt(pi^2+log(OS)^2);
wn=pi/(t_p*sqrt(1-zeta^2));
real_p=-zeta*wn
img_p=wn*(1-zeta^2)^0.5
p=real_p+j*img_p

tangle=rad2deg(-angle(p+0.4)-angle(p+0.5)-angle(p^2+1.7*p+0.25))
z=real_p-img_p/tand(-180-tangle)
PD=(s-z)

figure
hold on
rlocus(PD*G*H)
sgrid(zeta,wn)
hold off

Gain=0.584

PI=(s+0.25)/s

T=feedback(Gain*PI*PD*G,H)
figure
hold on
step(T)
hold off
info=stepinfo(T)