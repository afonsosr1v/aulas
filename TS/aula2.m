%%%%%%%%%%%%%% AULA 2

%% ex1

function x=deg(a)
  x=1*(a>0);
end

function x=imp(a)
  x=1*(a==0);
end

timedomain = -10:10;

signal = 2*imp(timedomain+8) + 1*deg(timedomain+6);
signal = signal + 1*imp(timedomain+4) + 1*imp(timedomain+1) + 1*imp(timedomain);
signal = signal + 1*imp(timedomain-1) - 1*imp(timedomain-5);

stem(timedomain, signal)
title('Exemplo 1.a')
xlabel('timedomain')
ylabel('signal(timedomain)')





