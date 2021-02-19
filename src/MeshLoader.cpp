#include "MeshLoader.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

MeshLoader::~MeshLoader() {
    for (const Mesh * mesh : meshes)
        delete mesh;
}

const Mesh * MeshLoader::load_mesh(const char * objFile) {

    Assimp::Importer importer;

    std::string path = "models/" + std::string(objFile);

    const aiScene * scene = importer.ReadFile(path.c_str(), aiProcess_Triangulate | aiProcess_JoinIdenticalVertices);

    if (scene->mNumMeshes <= 0)
        return nullptr;

    aiMesh * mesh = scene->mMeshes[0];

    const unsigned int numIndices = mesh->mNumFaces * 3;
    auto * indices = new GLuint[numIndices];
    for (int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        indices[(i * 3)] = face.mIndices[0];
        indices[(i * 3) + 1] = face.mIndices[1];
        indices[(i * 3) + 2] = face.mIndices[2];
    }

    const unsigned int numVertices = mesh->mNumVertices * 3;
    auto * vertices = new GLfloat[numVertices];
    for (int i = 0; i < mesh->mNumVertices; i++) {
        aiVector3D vec = mesh->mVertices[i];
        vertices[(i * 3)] = vec.x;
        vertices[(i * 3) + 1] = vec.y;
        vertices[(i * 3) + 2] = vec.z;
    }

    const unsigned int numNormals = mesh->mNumVertices * 3;
    auto * normals = new GLfloat[numNormals];
    for (int i = 0; i < mesh->mNumVertices; i++) {
        aiVector3D vec = mesh->mNormals[i];
        normals[(i * 3)] = vec.x;
        normals[(i * 3) + 1] = vec.y;
        normals[(i * 3) + 2] = vec.z;
    }

    unsigned int vao, indicesVBO, verticesVBO, normalsVBO;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &indicesVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(GLuint), indices, GL_STATIC_DRAW);

    glGenBuffers(1, &verticesVBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(0));

    glGenBuffers(1, &normalsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBO);
    glBufferData(GL_ARRAY_BUFFER, numNormals * sizeof(GLfloat), normals, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(0));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    const Mesh * meshObj = (new Mesh(vao, numIndices))
            ->addVBO(indicesVBO)
            ->addVBO(verticesVBO)
            ->addVBO(normalsVBO);
    meshes.push_back(meshObj);
    return meshObj;
}
