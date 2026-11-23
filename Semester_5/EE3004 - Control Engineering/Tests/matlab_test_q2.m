s=tf('s')
G=2400*(s+4)/((s+2)*(s+6)*(s+8))
figure
hold on
bode(G)
hold off
T1=feedback(G,1)
stepinfo(T1)

OS=20

eta=log(100/OS)/sqrt(pi^2+(log(100/OS))^2)
phi_m=atand(2*eta/sqrt(-2*eta^2+sqrt(1+4*eta^4)))
Phi_n=phi_m+10

C=(s+1)/(16.98*s+1)

T=feedback(G*C,1)
figure
hold on
step(T)
hold off
stepinfo(T)