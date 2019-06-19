Info<< "\nReading parameters for pump curve inlet" << endl;

IOdictionary pumpCurveParameters
(
IOobject
(
    "pumpCurve_Parameters",
    runTime.constant(),
    mesh,
    IOobject::MUST_READ_IF_MODIFIED,
    IOobject::NO_WRITE
)
);

dimensionedScalar vInletMin(pumpCurveParameters.lookup("vInletMin"));
dimensionedScalar vInletMax(pumpCurveParameters.lookup("vInletMax"));
dimensionedScalar interval(pumpCurveParameters.lookup("interval"));

dimensionedScalar vInletNew;
dimensionedScalar tolerance(pumpCurveParameters.lookup("tolerance"));

dimensionedScalar boolSystemCurve(pumpCurveParameters.lookup("boolSystemCurve"));
dimensionedScalar increment(pumpCurveParameters.lookup("increment"));

if(boolSystemCurve.value())
{
vInletNew = vInletMin;
}
else
{
vInletNew = 0.5*(vInletMin+vInletMax);
}
