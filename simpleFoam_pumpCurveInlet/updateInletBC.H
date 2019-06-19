if(iter%static_cast<short>(interval.value())==0)
{
// Calculating inlet flow speed
scalar inletFlux = -1.0* sum(phi.boundaryField()[inletPatch]);
scalar avgInflowSpeed = inletFlux/areaInlet;

// Evaluating pump-curve pressure
scalar pc = -0.2*Foam::pow((avgInflowSpeed-5),2)+80;

Info<< "Before updating\n";
Info<< "vInletMin = " << vInletMin.value() << endl;
Info<< "vInletMax = " << vInletMax.value() << endl;
Info<< "vInletNew before update = " << vInletNew.value() << "\n\n";
Info<< "avgInflowSpeed = " << avgInflowSpeed << endl;
Info<< "totalPressureLoss before update = " << totalPressureLoss << "\n";
Info<< "pump-curve pressure head = " << pc << endl;

// Stopping criteria
if(mag(totalPressureLoss - pc) < tolerance.value()) stop = true;

/************************************************************************/
if(totalPressureLoss < pc)
vInletMin = vInletNew;
else
vInletMax = vInletNew;

vInletNew = 0.5*(vInletMin+vInletMax);

// Set the new inlet BC
forAll(U.boundaryFieldRef()[inletPatch], facei)
{
   U.boundaryFieldRef()[inletPatch][facei] = vector(vInletNew.value(), 0, 0);
}
/************************************************************************/

Info<< "\nAfter updating\n";
Info<< "vInletMin = " << vInletMin.value() << endl;
Info<< "vInletMax = " << vInletMax.value() << endl;
Info<< "vInletNew = " << vInletNew.value() << endl << endl;
}

iter++;
