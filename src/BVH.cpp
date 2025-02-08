#include "BVH.h"









template<class BoundingVolumeClass>
bool BVHNode<BoundingVolumeClass>::overlaps(
	const BVHNode<BoundingVolumeClass>* other
) const
{
	return volume->overlaps(other->volume);
}




template<class BoundingVolumeClass>
unsigned BVHNode<BoundingVolumeClass>::getPotentialContactsWith(
	const BVHNode<BoundingVolumeClass>* other,
	PotentialContact* contacts, unsigned limit
) const
{
	// Early out if we don’t overlap or if we have no room
	// to report contacts.
	if (!overlaps(other) || limit == 0) return 0;
	// If we’re both at leaf nodes, then we have a potential contact.
	if (isLeaf() && other->isLeaf())
	{
		contacts->body[0] = body;
		contacts->body[1] = other->body;
		return 1;
	}
	// Determine which node to descend into. If either is
	// a leaf, then we descend the other. If both are branches,
	// then we use the one with the largest size.
	if (other->isLeaf() ||
		(!isLeaf() && volume->getSize() >= other->volume->getSize()))
	{
		// Recurse into self.
		unsigned count = children[0]->getPotentialContactsWith(
			other, contacts, limit
		);
		// Check that we have enough slots to do the other side too.
		if (limit > count) {
			return count + children[1]->getPotentialContactsWith(
				other, contacts + count, limit - count
			);
		}
		else {
			return count;
		}
	}
	else
	{
		// Recurse into the other node.
		unsigned count = getPotentialContactsWith(
			other->children[0], contacts, limit
		);
		// Check that we have enough slots to do the other side too.
		if (limit > count) {

			return count + getPotentialContactsWith(
				other->children[1], contacts + count, limit - count
			);
		}
		else {
			return count;
		}
	}
}