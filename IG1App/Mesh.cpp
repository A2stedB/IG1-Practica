#include "Mesh.h"

using namespace std;
using namespace glm;
//#include <glm/ext/scalar_constants.hpp>
#include <glm/gtc/constants.hpp>

// Placeholder for the pending index of a GPU object
constexpr GLuint NONE = numeric_limits<GLuint>::max();

Mesh::Mesh()
 : mVAO(NONE)
 , mVBO(NONE)
 , mCBO(NONE)
{
}

Mesh::~Mesh()
{
	unload();
}

void
Mesh::draw() const
{
	glDrawArrays(
	  mPrimitive,
	  0,
	  size()); // primitive graphic, first index and number of elements to be rendered
}

void
Mesh::load()
{
	assert(mVBO == NONE); // not already loaded

	if (vVertices.size() > 0) { // transfer data
		glGenBuffers(1, &mVBO);
		glGenVertexArrays(1, &mVAO);

		glBindVertexArray(mVAO);
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, vVertices.size() * sizeof(vec3), vVertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), nullptr);
		glEnableVertexAttribArray(0);

		if (vColors.size() > 0) {             // upload colors
			glGenBuffers(1, &mCBO);

			glBindBuffer(GL_ARRAY_BUFFER, mCBO);
			glBufferData(GL_ARRAY_BUFFER, vColors.size() * sizeof(vec4), vColors.data(), GL_STATIC_DRAW);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vec4), nullptr);
			glEnableVertexAttribArray(1);
		}
	}
}

void
Mesh::unload()
{
	if (mVAO != NONE) {
		glDeleteVertexArrays(1, &mVAO);
		glDeleteBuffers(1, &mVBO);
		mVAO = NONE;
		mVBO = NONE;

		if (mCBO != NONE) {
			glDeleteBuffers(1, &mCBO);
			mCBO = NONE;
		}
	}
}

void
Mesh::render() const
{
	assert(mVAO != NONE);

	glBindVertexArray(mVAO);
	draw();
}

Mesh*
Mesh::createRGBAxes(GLdouble l)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_LINES;

	mesh->mNumVertices = 6;
	mesh->vVertices.reserve(mesh->mNumVertices);

	// X axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(l, 0.0, 0.0);
	// Y axis vertices
	mesh->vVertices.emplace_back(0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, l, 0.0);
	// Z axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, 0.0, l);

	mesh->vColors.reserve(mesh->mNumVertices);
	// X axis color: red  (Alpha = 1 : fully opaque)
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	// Y axis color: green
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	// Z axis color: blue
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}

Mesh* Mesh::generateRegularPolygon(GLuint numVertex, GLdouble radius)
{
	Mesh* result = new Mesh();


	result->mPrimitive = GL_LINE_LOOP;
	result->mNumVertices = numVertex;
	result->vVertices.reserve(result->mNumVertices);

	const GLdouble angleFactor = 360 / numVertex;
	const GLdouble start = 90;

	for (int i = 0; i < result->mNumVertices; ++i)
	{
		GLdouble x = radius * glm::cos(glm::radians(start + i * angleFactor));
		GLdouble y = radius * glm::sin(glm::radians(start + i * angleFactor));

		result->vVertices.emplace_back(x,y,0);
	}

	//result->vColors.reserve(result->mNumVertices);

	//for (auto& e : result->vColors)
	//{
	//	e = glm::vec4(1, 1, 1, 1);
	//}

	return result;
}

Mesh* Mesh::generateRectangle(GLdouble w, GLdouble h)
{
    Mesh* mesh = new Mesh();
    mesh->mPrimitive = GL_TRIANGLE_STRIP;
    
    mesh->mNumVertices = 4;
    mesh->vVertices.reserve(4);
	
	const GLdouble x = w /2;
	const GLdouble y = h /2;

    mesh->vVertices.emplace_back(-x,y,0);
    mesh->vVertices.emplace_back(x,y,0);
    mesh->vVertices.emplace_back(-x,-y,0);
    mesh->vVertices.emplace_back(x,-y,0);

    //mesh->vVertices.emplace_back(x,y,0);
    //mesh->vVertices.emplace_back(-x,-y,0);


    return mesh;
}

Mesh* Mesh::generateRGBRectangle(GLdouble w, GLdouble h)
{
    Mesh* mesh = generateRectangle(w,h);
    mesh->vColors.emplace_back(1, 0, 0, 1);
    mesh->vColors.emplace_back(0, 1, 0, 1);
    mesh->vColors.emplace_back(0, 1, 0, 1);

    mesh->vColors.emplace_back(0, 0, 1, 1);
    //mesh->vColors.emplace_back(0, 1, 0, 1);
    //mesh->vColors.emplace_back(0, 0, 1, 1);


    return mesh;
}

Mesh* Mesh::generateCube(GLdouble length)
{
	// 1.(0, 0, 0)
	// 2.(length, 0, 0)
	// 3.(0, length, 0)
	// 4.(length, length, 0)
	// 5.(length, length, length)
	// 6.(length, 0, length)
	// 7.(0, 0, length)
	// 8.(0, length, length)

    Mesh* cube = new Mesh();
    cube->mPrimitive = GL_TRIANGLES;
    cube->mNumVertices = 9;
    cube->vVertices.reserve(cube->mNumVertices);

    cube->vVertices.emplace_back(0, 0, 0);
    cube->vVertices.emplace_back(length, 0, 0);
    cube->vVertices.emplace_back(0, length, 0);

    cube->vVertices.emplace_back(0, length, 0);
    cube->vVertices.emplace_back(length, length, 0);
    cube->vVertices.emplace_back(length, 0, 0);

    cube->vVertices.emplace_back(length, 0, 0);
    cube->vVertices.emplace_back(length, length, 0);
    cube->vVertices.emplace_back(length, 0, length);

    cube->vVertices.emplace_back(length, length, length);
    cube->vVertices.emplace_back(length, length, 0);
    cube->vVertices.emplace_back(length, 0, length);

    //cube->vVertices.emplace_back(length, length, length);
    //cube->vVertices.emplace_back(length, 0, length);
    //cube->vVertices.emplace_back(0, length, length);

    //cube->vVertices.emplace_back(0, length, length);
    //cube->vVertices.emplace_back(length, 0, length);
    //cube->vVertices.emplace_back(0, 0, length);

    //cube->vVertices.emplace_back(0, 0, length);
    //cube->vVertices.emplace_back(0, length, length);
    //cube->vVertices.emplace_back(0, 0, 0);

    //cube->vVertices.emplace_back(0, 0, 0);
    //cube->vVertices.emplace_back(0, length, 0);
    //cube->vVertices.emplace_back(0, length, length);

    //cube->vVertices.emplace_back(0, length, 0);
    //cube->vVertices.emplace_back(length, length, length);
    //cube->vVertices.emplace_back(length, length, 0);

    //cube->vVertices.emplace_back(0, length, 0);
    //cube->vVertices.emplace_back(length, length, length);
    //cube->vVertices.emplace_back(0, length, length);

    //cube->vVertices.emplace_back(0, 0, 0);
    //cube->vVertices.emplace_back(length, 0, 0);
    //cube->vVertices.emplace_back(length, 0, length);

    //cube->vVertices.emplace_back(length, 0, 0);
    //cube->vVertices.emplace_back(length, 0, length);
    //cube->vVertices.emplace_back(0, 0, length);

    return cube;
}

Mesh* Mesh::generateRGBCubeTriangles(GLdouble length)
{
    return nullptr;
}
