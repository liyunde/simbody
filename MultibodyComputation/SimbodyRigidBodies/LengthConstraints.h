#ifndef LENGTH_CONSTRAINTS_H_
#define LENGTH_CONSTRAINTS_H_

#include "simbody/Simbody.h"
using namespace simtk;

class RBDistanceConstraint;
class RBDistanceConstraintRuntime;
class RigidBodyTree;
template<class T> class CDSList;
typedef CDSList<SpatialVec> CDSVecVec6;

#include <cdsIostream.h>

class LengthConstraintsPrivates;
class LengthSet;

class LengthConstraints {
public:
    LengthConstraints(RigidBodyTree&, const double& ctol, int verbose);
    ~LengthConstraints();
    void construct(CDSList<RBDistanceConstraint>&,
                   CDSList<RBDistanceConstraintRuntime>&);

    void enforce(Vector& pos,
                 Vector& vel);

    bool calcConstraintForces() const;
    void addInCorrectionForces(CDSVecVec6& spatialForces) const;

    void fixVel0(Vector&);
    void fixGradient(Vector&);

private:
    //  double tol;
    double bandCut;  //cutoff for calculation of constraint matrix
    int    maxIters;
    int    maxMin;

    RigidBodyTree&             rbTree;
    const int                  verbose;
    LengthConstraintsPrivates* priv;

    friend class LengthSet;
};


#endif /* LENGTH_CONSTRAINTS_H_ */
