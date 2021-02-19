#pragma once

#include <vector>

#include <gl/glew.h>
#include <glm/glm.hpp>

using std::vector;

class Mesh {

public:
    const GLuint vao;
    const GLsizei index_count;
    vector<GLuint> vbos;

public:
	Mesh(GLuint vao, GLsizei index_count);
    ~Mesh();

	void render_mesh() const;

	inline Mesh * addVBO(GLuint vbo) {
	    vbos.push_back(vbo);
	    return this;
	}

	inline GLuint get_vao() const {
	    return vao;
	}

};

