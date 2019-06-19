// Calculating labels
label inletPatch = mesh.boundaryMesh().findPatchID("inlet");
label outletPatch = mesh.boundaryMesh().findPatchID("outlet");

// Calculating area
scalar areaInlet = gSum(mesh.magSf().boundaryField()[inletPatch]);
auto areaElementInlet = mesh.magSf().boundaryField()[inletPatch];
scalar areaOutlet = gSum(mesh.magSf().boundaryField()[outletPatch]);
auto areaElementOutlet = mesh.magSf().boundaryField()[outletPatch];

// Set the new inlet BC at t=0
forAll(U.boundaryFieldRef()[inletPatch], facei)
{
   U.boundaryFieldRef()[inletPatch][facei] = vector(vInletNew.value(), 0, 0);
}
