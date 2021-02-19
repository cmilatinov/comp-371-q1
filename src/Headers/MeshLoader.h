#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "Mesh.h"

using std::vector;
using std::string;
using glm::vec3;

class MeshLoader {

private:
    vector<const Mesh*> meshes;

public:
    ~MeshLoader();

    const Mesh * load_mesh(const char * objFile);

};


