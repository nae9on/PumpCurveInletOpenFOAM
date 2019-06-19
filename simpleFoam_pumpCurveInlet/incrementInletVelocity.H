if(iter%static_cast<short>(interval.value())==0)
{
Info<< "totalPressureLoss before update = " << totalPressureLoss << "\n";
Info<< "vInletNew before update = " << vInletNew.value() << "\n\n";
vInletNew = vInletNew + increment;
// Set the new inlet BC at t=0
forAll(U.boundaryFieldRef()[inletPatch], facei)
{
   U.boundaryFieldRef()[inletPatch][facei] = vector(vInletNew.value(), 0, 0);
}
}

iter++;
