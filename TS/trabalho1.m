%%%%%%%%%% TRABALHO 1

%% PARTE 1

%% grafico do enunciado
t=0.01
timedomain = -10:t:10;

degrau1 = 2*((timedomain+4)>=0);
pulso1 = (-(2/3)*(timedomain+2)).*(((timedomain+2)>=0)-((timedomain-1)>=0));
degrau2 = -2*((timedomain-1)>=0);

x = degrau1 + pulso1 +degrau2;

plot(timedomain, x)

%% resposta 1b

degrau1a = 2*(((-2*timedomain -2)+4)>=0);
pulso1a = (-(2/3)*((-2*timedomain -2)+2)).*((((-2*timedomain -2)+2)>=0)-(((-2*timedomain -2)-1)>=0));
degrau2a = -2*(((-2*timedomain -2)-1)>=0);

xa = degrau1a + pulso1a +degrau2a;

r = 2*xa

plot(timedomain, r)

%% resposta 2b

g = 2*cos(4*pi*(timedomain+1))+1;

plot(timedomain, g)

axis([-2.5 2.5 -1 3])




