s=tf('s')
G=1/(s*(s+5)*(s+20))
K=1000
L = K*G
figure
hold on
bode(L)
[~,phaseMargin,~,wCrossover] = margin(L)
hold off

OS=10
zeta = -log(OS/100) / sqrt(pi^2 + log(OS/100)^2)
w_pm=atand(2*zeta/((1+4*zeta^4)^0.5-2*zeta^2)^0.5)
phi=w_pm+20-phaseMargin
beta=(1-sind(phi))/(1+sind(phi))
gain=1/beta^0.5
dbgain=20*log10(0.5989)
w_m=8.16
tau=1/(w_m*beta^0.5)

C=1/beta*(s+1/tau)/(s+1/(beta*tau))

figure
hold on
bode(L*C)
grid on
hold off
[~,phaseMarginComp,~,wCrossoverComp] = margin(L*C)

T=feedback(L*C,1)
figure
hold on
step(T)
hold off
stepinfo(T)
