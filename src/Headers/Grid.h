#pragma once

class Grid
{
public:
	// Param[in] Color of the lines
	explicit Grid(const glm::vec3&);
	~Grid();

	void render();

private:
	GLuint VBO, VAO;
};