clc
clear all

FileName = './pitzDaily_drawSystemCurve/log';
phrase = 'totalPressureLoss = ';
totalPressureLoss = parseOF_Log(FileName, phrase);
phrase = 'vInletNew before update = ';
vInletBeforeUpdate = parseOF_Log(FileName, phrase);
phrase = 'totalPressureLoss before update = ';
totalPressureLossBeforeUpdate = parseOF_Log(FileName, phrase);

figid = 1;
gravity = 10;
inletArea = 2.540000e-05;
outletArea = 3.320000e-05;
pumpCurve = @(X)(-0.2*(X-5).^2+80)/gravity;

figure(figid);
subplot(1,2,1);
X = (1:1:size(totalPressureLoss,1));
plot(X,totalPressureLoss/gravity);
hold on
xlabel('Iteration Count');
ylabel('Total Head Loss');
set(gcf,'color','w');

figure(figid);
subplot(1,2,2);
plot(vInletBeforeUpdate,totalPressureLossBeforeUpdate/gravity);
hold on
plot(vInletBeforeUpdate,pumpCurve(vInletBeforeUpdate),'r');
xlabel('Inlet Flow Speed');
ylabel('Total Head Loss');
legend('System-curve','Pump-curve');
set(gcf,'color','w');

xx = linspace(min(vInletBeforeUpdate),max(vInletBeforeUpdate),10^5);
yy = interp1(vInletBeforeUpdate,totalPressureLossBeforeUpdate/gravity,xx);
[val index] = min(abs(yy-pumpCurve(xx)));
fprintf("Operational velocity = %f\n",xx(index));
fprintf("Operational pressure head = %f\n",yy(index));