#pragma once

#include "PongObject.h"

/**
 * A contact represents two objects in contact (in this case PongObjectContact representing two
 * particles). Resolving a contact removes their interpenetration, and applies sufficient impulse
 * to keep them apart. Colliding bodies may also reobund.
 *
 * The contact has no callable functions, it just holds the contact details. To resolve a set of
 * contacts, use the particle contact resolver class.
 */
class PONG_API PongObjectContact
{
private:
    /**
     * Handles the impulse calculations for this collision.
     */
    void resolveVelocity(float deltaTime);

protected:
    /**
     * Resolves this contact, for both velocity and interpenetration.
     */
    void resolve(float deltaTime);

    /**
     * Calculates the separating velocity at this contact.
     */
    float calculateSeparatingVelocity() const;

public:
    /**
     * Holds the particles that are invovled in the contact. The second of these can be NULL, for
     * contacts with the scenery
     */
    APongObject* pongObject[2];

    /**
     * Holds the normal restitution coefficient at the contact.
     */
    float restitution;

    /**
     * Holds the direction of the contact in world coordinates.
     */
    FVector contactNormal;
};
