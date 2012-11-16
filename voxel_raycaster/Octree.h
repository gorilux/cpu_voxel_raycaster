#ifndef OCTREE_H_
#define OCTREE_H_
#pragma once

#include "Node.h"
#include "DataPoint.h"
#include <TriMesh.h>
#include <vector>

class Octree
{
public:
	vec3 min;
	vec3 max;
	vec3 size;
	size_t gridlength;

	VoxelData const* data; // just here for reference: not really needed to know which data this tree covers
	DataPoint* leafdata;

	std::vector<Node> nodes;

	Octree(VoxelData const* data, vec3 min, vec3 max, vec3 size, size_t gridlength);
	Octree(vec3 min, vec3 max, vec3 size, size_t gridlength);
	size_t storeNode(Node const n);
	const Node* getNode(size_t index) const;
	const Node* getRootNode() const;
	~Octree(void);
};

// DEPRECATED
inline Octree::Octree(VoxelData const* data, vec3 min, vec3 max, vec3 size, size_t gridlength)
	: data(data),min(min), max(max), size(size), gridlength(gridlength){
		nodes.push_back(Node()); // push back NULL node
}

inline Octree::Octree(vec3 min, vec3 max, vec3 size, size_t gridlength)
	: min(min), max(max), size(size), gridlength(gridlength){
		nodes.push_back(Node()); // push back NULL node
}


inline Octree::~Octree(void)
{
}

inline size_t Octree::storeNode(Node const n){
	nodes.push_back(n);
	return nodes.size()-1;
}

inline const Node* Octree::getNode(size_t index) const{
	return &nodes[index];
}

inline const Node* Octree::getRootNode() const{
	return &nodes.back();
}

#endif /* OCTREE_H_ */