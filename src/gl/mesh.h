#pragma once

#include <glad/glad.h>

class Mesh {
public:
	Mesh();
	~Mesh();

	void Bind() const;
	void Draw() const;

private:
	GLuint vao_ = 0;
	GLuint vbo_ = 0;
	GLuint ebo_ = 0;
	unsigned int num_indices_ = 0;

};
