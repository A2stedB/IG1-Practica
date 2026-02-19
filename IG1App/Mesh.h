#ifndef _H_Mesh_H_
#define _H_Mesh_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

class Mesh
{
    public:
        static Mesh* createRGBAxes(GLdouble l); // creates a new 3D-RGB axes mesh

        static Mesh* generateRegularPolygon(GLuint numVertex, GLdouble radius);
        static Mesh* generateRectangle(GLdouble w, GLdouble h);
        static Mesh* generateRGBRectangle(GLdouble w, GLdouble h);
        static Mesh* generateCube(GLdouble length);
        static Mesh* generateRGBCube(GLdouble length);

        friend class RGBTriangle; // uffff

    public:
        Mesh();
        virtual ~Mesh();

        Mesh(const Mesh& m) = delete;            // no copy constructor
        Mesh& operator=(const Mesh& m) = delete; // no copy assignment

        virtual void render() const;

        GLuint size() const { return mNumVertices; }; // number of elements
        std::vector<glm::vec3> const& vertices() const { return vVertices; };
        std::vector<glm::vec4> const& colors() const { return vColors; };

	static Mesh* generateRectangleTextCor(GLdouble w, GLdouble h);


	Mesh();
	virtual ~Mesh();

        GLuint mVAO; // vertex array object

    private:
        GLuint mVBO; // vertex buffer object
        GLuint mCBO; // color buffer object
};

#endif //_H_Scene_H_
