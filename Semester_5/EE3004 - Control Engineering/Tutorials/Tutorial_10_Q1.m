s = tf('s')
G=4/(s*(2*s+1))
figure
hold on
bode(G)
hold off

old_phase_margin=20
new_phase_margin=40+10
w_new=0.426
alpha=10^(17.1/20)
tau=10/w_new

C=1/alpha*(s+(1/tau))/(s+1/(alpha*tau))

figure
hold on
bode(G*C)
hold off
