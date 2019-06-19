// Calculating average static pressure at the inlet
auto pElementInlet = p.boundaryField()[inletPatch];
scalar areaWeightedPressureInlet = sum(pElementInlet*areaElementInlet);
scalar avgStaticPressureInlet = areaWeightedPressureInlet/areaInlet;
// Calculating average dynamic pressure at the inlet
auto magUElementInlet = mag(U.boundaryField()[inletPatch]);
scalar areaWeightedMagU2Inlet = sum(magUElementInlet*magUElementInlet*areaElementInlet);
scalar avgDynamicPressureInlet = 0.5*areaWeightedMagU2Inlet/areaInlet;
scalar totalPressureInlet = avgStaticPressureInlet + avgDynamicPressureInlet;
Info<< "avgStaticPressureInlet = " << avgStaticPressureInlet;
Info<< "\navgDynamicPressureInlet = " << avgDynamicPressureInlet;

// Calculating average static pressure at the outlet
auto pElementOutlet = p.boundaryField()[outletPatch];
scalar areaWeightedPressureOutlet = sum(pElementOutlet*areaElementOutlet);
scalar avgStaticPressureOutlet = areaWeightedPressureOutlet/areaOutlet;
// Calculating average dynamic pressure at the outlet
auto magUElementOutlet = mag(U.boundaryField()[outletPatch]);
scalar areaWeightedMagU2Outlet = sum(magUElementOutlet*magUElementOutlet*areaElementOutlet);
scalar avgDynamicPressureOutlet = 0.5*areaWeightedMagU2Outlet/areaOutlet;
scalar totalPressureOutlet = avgStaticPressureOutlet + avgDynamicPressureOutlet;
Info<< "\navgStaticPressureOutlet = " << avgStaticPressureOutlet;
Info<< "\navgDynamicPressureOutlet = " << avgDynamicPressureOutlet;

// Calculating total pressure loss
scalar totalPressureLoss = totalPressureInlet - totalPressureOutlet;
Info<< "\ntotalPressureLoss = " << totalPressureLoss << "\n";
Info<< "vInletNew = " << vInletNew.value() << "\n\n";
