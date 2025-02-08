#pragma once
#include "mathLib.h"
//#include "RigidBody.h"
#include "PhysicsComponent.h"



struct BoundingSphere
{
	vec center;
	float radius;
public:
	/**
	* Creates a new bounding sphere at the given center and radius.
	*/
	BoundingSphere(const vec& center, float radius);
	/**
	* Creates a bounding sphere to enclose the two given bounding
	* spheres.
	*/
	BoundingSphere(const BoundingSphere& one, const BoundingSphere& two);
	/**
	* Checks whether the bounding sphere overlaps with the other given
	* bounding sphere.
	*/
	bool overlaps(const BoundingSphere* other) const;
};




 BoundingSphere::BoundingSphere(const vec& center, float radius)
{
	 this->center = center;
	 this->radius = radius;
}

BoundingSphere::BoundingSphere(const BoundingSphere& one,
	const BoundingSphere& two)
{
	vec centerOffset = two.center - one.center;
	float distance = centerOffset.sqrMag();
	float radiusDiff = two.radius - one.radius;
	// Check whether the larger sphere encloses the small one.
	if (radiusDiff * radiusDiff >= distance)
	{
		if (one.radius > two.radius)
		{
			center = one.center;
			radius = one.radius;
		}
		else
		{
			center = two.center;
			radius = two.radius;
		}
	}
	// Otherwise, we need to work with partially
	// overlapping spheres.
	else
	{
		distance = sqrt(distance);
		radius = (distance + one.radius + two.radius) * ((/*real*/1)*0.5);
		// The new center is based on one’s center, moved toward
		// two’s center by an amount proportional to the spheres’
		// radii.
		center = one.center;
		if (distance > 0)
		{
			center += centerOffset * ((radius - one.radius) / distance);
		}
	}
}
bool BoundingSphere::overlaps(const BoundingSphere* other) const
{
	float distanceSquared = (center - other->center).sqrMag();
	return distanceSquared < (radius + other->radius) * (radius + other
		->radius);
}

struct BoundingBox
{
	vec center;
	vec halfSize;
};


struct PotentialContact
{
	/**
	* Holds the bodies that might be in contact.
	*/

	//RigidBody* body[2];
	PhysicsComponent* physicsComponent[2];


};




template<class BoundingVolumeClass>
class BVHNode
{

public:

	BVHNode* children[2];

	BoundingVolumeClass volume;

	//RigidBody* body;
	PhysicsComponent* physicsComponent;

	bool isLeaf() const
	{
		return (body != NULL);
	}


	unsigned getPotentialContacts(PotentialContact* contacts,
		unsigned limit) const;

	bool overlaps(const BVHNode<BoundingVolumeClass>* other) const;

	unsigned getPotentialContactsWith(const BVHNode<BoundingVolumeClass>* other, PotentialContact* contacts, unsigned limit) const;

};





template<class BoundingVolumeClass>
unsigned BVHNode<BoundingVolumeClass>::getPotentialContacts(
	PotentialContact* contacts, unsigned limit
) const
{
	// Early out if we don’t have the room for contacts, or
	// if we’re a leaf node.
	if (isLeaf() || limit == 0) return 0;
	// Get the potential contacts of one of our children with
	// the other.
	return children[0]->getPotentialContactsWith(
		children[1], contacts, limit
	);
}



