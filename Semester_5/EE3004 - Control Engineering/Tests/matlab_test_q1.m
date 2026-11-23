s=tf('s')
G=21/((s+0.5)*(s+1.5)*(s+8))
T1=feedback(G,1)
stepinfo(T1)

OS=10
tp=1.25

eta=log(100/OS)/sqrt(pi^2+(log(100/OS))^2)
w_n=pi/(tp*sqrt(1-eta^2))

re=-eta*w_n
img=w_n*sqrt(1-eta^2)
p=re+j*img

tangle=rad2deg(-angle(p+0.5)-angle(p+1.5)-angle(p+8))
z=re-img/tand(-180-tangle)

PD=(s-z)

figure
hold on
rlocus(G*PD)
sgrid(eta,[])
hold off

PI=(s+0.25)/s

T=feedback(G*PD*PI,1)
figure
hold on
step(T)
hold off
stepinfo(T)

