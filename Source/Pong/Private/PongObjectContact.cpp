#include "Pong.h"
#include "PongObjectContact.h"

void PongObjectContact::resolveVelocity(float deltaTime)
{
    // Find the velocity in the direction of the contact.
    float separatingVelocity = calculateSeparatingVelocity();

    // Check whether it needs to be resolved.
    if (separatingVelocity <= 0)
    {
	// We apply the change in velocity to each object in proportion to its inverse mass (i.e.
	// those with lower inverse mass [higher actual mass] get less change in velocity).
	float totalInverseMass = pongObject[0]->getInverseMass();

	if (pongObject[1])
	{
	    totalInverseMass += pongObject[1]->getInverseMass();
	}

	if (totalInverseMass > 0)
	{
	    // Find the amount of impulse per unit of inverse mass.
	    FVector impulsePerIMass = (contactNormal *
				       ((((-separatingVelocity) *
					  restitution) -
					 separatingVelocity) /
					totalInverseMass));

	    pongObject[0]->addImpulse(impulsePerIMass * pongObject[0]->getInverseMass());

	    if (pongObject[1])
	    {
		pongObject[1]->addImpulse(-impulsePerIMass * pongObject[1]->getInverseMass());
	    }
	}
    }
}

void PongObjectContact::resolve(float deltaTime)
{
    resolveVelocity(deltaTime);
}

float PongObjectContact::calculateSeparatingVelocity() const
{
    FVector relativeVelocity = pongObject[0]->getVelocity();

    if (pongObject[1])
    {
	relativeVelocity -= pongObject[1]->getVelocity();
    }

    return FVector::DotProduct(relativeVelocity, contactNormal);
}
