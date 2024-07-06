/*
--------------------------------------------------
    James William Fletcher (github.com/mrbid)
        June 2024 - esLuma.h v1.0
--------------------------------------------------

    A pretty good color converter: https://www.easyrgb.com/en/convert.php

    Lambertian fragment shaders make a difference, but only if you normalise the
    vertNorm in the fragment shader. Most of the time you won't notice the difference.

    This focuses on using ML generated models from LUMA GENIE, MESHY.AI, or TRIPO3D.AI
    converted to vertex colors and shaded via shadeLambert().
    
    No Textures, No Phong, One view-space light with position, ambient and saturation control.

    Default: ambient = 0.648, saturate = 0.26 or 1.0
    
    https://registry.khronos.org/OpenGL-Refpages/es1.1/xhtml/
    https://registry.khronos.org/OpenGL/specs/es/2.0/GLSL_ES_Specification_1.00.pdf
    https://www.khronos.org/files/webgl/webgl-reference-card-1_0.pdf
*/
#ifndef AUX_H
#define AUX_H

//#define VERTEX_SHADE // uncomment for vertex shaded, default is pixel shaded
//#define MAX_MODELS 32 // uncomment to enable the use of esBindModel(id) and esRenderModel() or just esBindRender(id)
//#define GL_DEBUG // allows you to use esDebug(1); to enable OpenGL errors to the console.
                    // https://gen.glad.sh/ and https://glad.dav1d.de/ might help

// render state id's ~ ( just so you don't need to define them when using shadeLambert() or similar ) ~
GLint projection_id;
GLint modelview_id;
GLint position_id;
GLint normal_id;
GLint color_id;
GLint lightpos_id;
GLint ambient_id;
GLint saturate_id;
GLint opacity_id;
GLint lightness_id;

typedef struct{float x,y,z,w;} vec;  // Vector
typedef struct {float m[4][4];} mat; // Matrix

// render states
mat projection, view, model, modelview;
#define updateModelView(); mMul(&modelview,&model,&view);glUniformMatrix4fv(modelview_id,1,GL_FALSE,(float*)&modelview.m[0][0]);
#define toView(); glUniformMatrix4fv(modelview_id,1,GL_FALSE,(float*)&view.m[0][0]);
#define toModelView(); glUniformMatrix4fv(modelview_id,1,GL_FALSE,(float*)&modelview.m[0][0]);

// ESModel ✨
typedef struct
{
    GLuint vid; // Vertex Array Buffer ID
    GLuint iid;	// Index Array Buffer ID
    GLuint cid;	// Colour Array Buffer ID
    GLuint nid;	// Normal Array Buffer ID
#ifdef MAX_MODELS
    GLuint itp; // Index Type (GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, GL_UNSIGNED_INT)
    GLuint ni;  // Number of Indices
    GLuint nv;  // num vertices
    GLfloat *vertices, *normals; // pointers to model data
    GLubyte *colors; // pointer to color data
    vec pos;    // world pos
    GLfloat rad;// radius
    GLfloat rsq;// radius squared
#endif
} ESModel;

// utility functions
GLuint  esRand(const GLuint min, const GLuint max);
GLfloat esRandFloat(const GLfloat min, const GLfloat max);
void    esBind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage);
void    esRebind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage);

// set shader pipeline: single color for whole object
void shadeFullbrightSolid(GLint* position, GLint* projection, GLint* modelview, GLint* color, GLint* lightness, GLint* opacity);
void shadeLambertSolid(GLint* position, GLint* projection, GLint* modelview, GLint* lightpos, GLint* normal, GLint* color, GLint* ambient, GLint* saturate, GLint* opacity);

// set shader pipeline: color array for whole object
void shadeFullbright(GLint* position, GLint* projection, GLint* modelview, GLint* color, GLint* lightness, GLint* opacity);
void shadeLambert(GLint* position, GLint* projection, GLint* modelview, GLint* lightpos, GLint* normal, GLint* color, GLint* ambient, GLint* saturate, GLint* opacity);

// misc
GLuint debugShader(GLuint shader_program);

// make the shader programs before you use them with shadeFunctions()
void makeAllShaders(); // don't be this lazy!
void makeFullbrightSolid();
void makeLambertSolid();
void makeFullbright();
void makeLambert();

// :: VECTOR
#define PI     3.14159265359f // PI
#define x2PI   6.28318530718f // PI * 2
#define d2PI   1.57079632679f // PI / 2
#define DEGREE 57.2957795131f // 1 Radian as Degrees
#define RADIAN 0.01745329251f // PI / 180 (1 Degree as Radians)
#define RAD2DEG DEGREE
#define DEG2RAD RADIAN
#define FLOAT_MAX 9223372036854775807.f

static inline float randf();  // uniform [0 to 1]
static inline float randfc(); // uniform [-1 to 1]
float randfn(); // box-muller normal [bi-directional]

static inline float fRandFloat(const float min, const float max);
static inline int   fRand(const float min, const float max);

int vec_ftoi(float f); // float to integer quantise

// normalising the result is optional / at the callers responsibility
void vRuv(vec* v);   // Random Unit Vector
void vRuvN(vec* v);  // Normal Random Unit Vector
void vRuvBT(vec* v); // Brian Tung Random Unit Vector (on surface of unit sphere)
void vRuvTA(vec* v); // T.Davison Trial & Error (inside unit sphere)
void vRuvTD(vec* v); // T.Davison Random Unit Vector Sphere

void  vCross(vec* r, const vec v1, const vec v2);
float vDot(const vec v1, const vec v2);
float vSum(const vec v);
float vSumAbs(const vec v);
void  vReflect(vec* r, const vec v, const vec n);

int  vEqualTol(const vec a, const vec b, const float tol);
int  vEqualInt(const vec a, const vec b);
void vMin(vec* r, const vec v1, const vec v2);
void vMax(vec* r, const vec v1, const vec v2);

void  vNorm(vec* v);
float vDist(const vec v1, const vec v2);
float vDistSq(const vec a, const vec b);
float vDistMh(const vec a, const vec b); // manhattan
float vDistLa(const vec a, const vec b); // longest axis
float vMod(const vec v); // modulus
float vMag(const vec v); // magnitude
void  vInv(vec* v); // invert
void  vCopy(vec* r, const vec v);
void  vDir(vec* r, const vec v1, const vec v2); // direction vector from v1 to v2

void vRotX(vec* v, const float radians);
void vRotY(vec* v, const float radians);
void vRotZ(vec* v, const float radians);

void vAdd(vec* r, const vec v1, const vec v2);
void vSub(vec* r, const vec v1, const vec v2);
void vDiv(vec* r, const vec numerator, const vec denominator);
void vMul(vec* r, const vec v1, const vec v2);

void vAddS(vec* r, const vec v1, const float v2);
void vSubS(vec* r, const vec v1, const float v2);
void vDivS(vec* r, const vec v1, const float v2);
void vMulS(vec* r, const vec v1, const float v2);

// :: MATRIX
void mIdent(mat *m);
void mCopy(mat *r, const mat *v);
void mMul(mat *r, const mat *a, const mat *b);
void mMulP(vec *r, const mat *a, const float x, const float y, const float z);
void mMulV(vec *r, const mat *a, const vec v);
void mScale(mat *r, const float x, const float y, const float z);
void mScale1(mat *r, const float s);
void mTranslate(mat *r, const float x, const float y, const float z);
void mRotate(mat *r, const float radians, float x, float y, float z); // rotate axis (rotate X to move Y up and down)
void mRotX(mat *r, const float radians); // rotate on axis
void mRotY(mat *r, const float radians); // rotate on axis
void mRotZ(mat *r, const float radians); // rotate on axis
void mAngleAxisRotate(mat *r, const mat view, const float xrot, const float yrot, const float zrot); // gimbal free rotations
void mFrustum(mat *r, const float left, const float right, const float bottom, const float top, const float nearZ, const float farZ);
void mPerspective(mat *r, const float fovy, const float aspect, const float nearZ, const float farZ);
void mOrtho(mat *r, const float left, const float right, const float bottom, const float top, const float nearZ, const float farZ);
void mLookAt(mat *r, const vec origin, const vec unit_dir);
void mInvert(float *dst, const float *mat);
void mTranspose(mat *r, const mat *m);
void mSetViewDir(mat *r, const vec dir_norm);
void mGetViewDir(vec *r, const mat matrix);
void mGetViewX(vec *r, const mat matrix);
void mGetViewY(vec *r, const mat matrix);
void mGetViewZ(vec *r, const mat matrix);
void mSetDir(mat *r, const vec dir_norm);
void mGetDirX(vec *r, const mat matrix);
void mGetDirY(vec *r, const mat matrix);
void mGetDirZ(vec *r, const mat matrix);
void mGetPos(vec *r, const mat matrix);
void mSetPos(mat *r, const vec pos);
void mDump(const mat matrix);

//*************************************
// UTILITY CODE
//*************************************
GLuint esRand(const GLuint min, const GLuint max){return (rand()%(max+1-min))+min;}
GLfloat esRandFloat(const GLfloat min, const GLfloat max)
{
    static GLfloat rrndmax = 1.f/(GLfloat)RAND_MAX;
    return (((GLfloat)rand()) * rrndmax) * (max-min) + min;
}
void esBind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage)
{
    glGenBuffers(1, buffer);
    glBindBuffer(target, *buffer);
    glBufferData(target, datalen, data, usage);
}
void esRebind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage)
{
    glBindBuffer(target, *buffer);
    glBufferData(target, datalen, data, usage);
}
///
#ifdef GL_DEBUG
// https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDebugMessageControl.xhtml
// https://registry.khronos.org/OpenGL-Refpages/es3/html/glDebugMessageControl.xhtml
// OpenGL ES 3.2 or OpenGL 4.3 and above only.
void GLAPIENTRY MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
    printf("GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}
void esDebug(const GLuint state)
{
    if(state == 1)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(MessageCallback, 0);
        glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
    }
    else
    {
        glDisable(GL_DEBUG_OUTPUT);
        glDisable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    }
}
#endif
/// just hiding this away down here, for the system to load and index models into GPU memory.
#ifdef MAX_MODELS // Once esLoadModel() is called just esBindModel(id) and esRenderModel() or just esBindRender(id)
    ESModel esModelArray[MAX_MODELS]; // just create new "sub - index arrays" of categories that index this master array
    uint esModelArray_index = 0;      // e.g; 0-10 index of fruit 3d models A-Z by name?
    uint esBoundModel = 0;
    void esBindModel(const uint id)
    {
        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].nid);
        glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(normal_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].cid);
        glVertexAttribPointer(color_id, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(color_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esModelArray[id].iid);
        esBoundModel = id;
    }
    void esBindModelF(const uint id) // for Fullbright
    {
        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].cid);
        glVertexAttribPointer(color_id, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(color_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esModelArray[id].iid);
        esBoundModel = id;
    }
    void esRenderModel()
    {
        glDrawElements(GL_TRIANGLES, esModelArray[esBoundModel].ni, esModelArray[esBoundModel].itp, 0);
    }
    /// above is; bind it, draw a few instances of it. ... below is ... bind it, draw it, draw something different.
    void esBindRender(const uint id)
    {
        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].nid);
        glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(normal_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].cid);
        glVertexAttribPointer(color_id, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(color_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esModelArray[id].iid);

        glDrawElements(GL_TRIANGLES, esModelArray[id].ni, esModelArray[id].itp, 0);
    }
    void esBindRenderF(const uint id) // for Fullbright
    {
        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].cid);
        glVertexAttribPointer(color_id, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(color_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esModelArray[id].iid);

        glDrawElements(GL_TRIANGLES, esModelArray[id].ni, esModelArray[id].itp, 0);
    }
#define esLoadModel(x) \
	esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, x##_vertices, sizeof(x##_vertices[0]) * x##_numvert * 3, GL_STATIC_DRAW); \
	esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, x##_normals, sizeof(x##_normals[0]) * x##_numvert * 3, GL_STATIC_DRAW); \
	esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, x##_colors, sizeof(x##_colors[0]) * x##_numvert * 3, GL_STATIC_DRAW); \
	esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, x##_indices, sizeof(x##_indices[0]) * x##_numind * 3, GL_STATIC_DRAW); \
	esModelArray[esModelArray_index].itp = x##_GL_TYPE; \
	esModelArray[esModelArray_index].ni = x##_numind * 3; \
	esModelArray_index++;
#endif // I like this system. It's amost frictionless and you can index what you like off it. 
// but you need the new ptf2.c program: https://gist.github.com/mrbid/35b1d359bddd9304c1961c1bf0fcb882
// or the newer PTF and PTO programs: https://github.com/mrbid/esAux7

//*************************************
// SHADER CODE
//*************************************
const GLchar* v0 = // ShadeFullbrightSolid() ]- vertex shader
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "uniform float lightness;\n"
    "uniform vec3 color;\n"
    "uniform float opacity;\n"
    "attribute vec4 position;\n"
    "varying vec4 fragcolor;\n"
    "void main()\n"
    "{\n"
        "fragcolor = vec4(color*lightness, opacity);\n"
        "gl_Position = projection * modelview * position;\n"
    "}\n";
const GLchar* f0 = // ShadeFullbrightSolid() ]- fragment shader
    "#version 100\n"
    "precision highp float;\n"
    "varying vec4 fragcolor;\n"
    "void main()\n"
    "{\n"
        "gl_FragColor = fragcolor;\n"
    "}\n";
///
const GLchar* v01 = // ShadeFullbright() ]- vertex shader
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "uniform float lightness;\n"
    "attribute vec3 color;\n"
    "uniform float opacity;\n"
    "attribute vec4 position;\n"
    "varying vec3 vertCol;\n"
    "varying float vertOpa;\n"
    "void main()\n"
    "{\n"
        "vertCol = color*lightness;\n"
        "vertOpa = opacity;\n"
        "gl_Position = projection * modelview * position;\n"
    "}\n";
const GLchar* f01 = // ShadeFullbright() ]- fragment shader
    "#version 100\n"
    "precision highp float;\n"
    "varying vec3 vertCol;\n"
    "varying float vertOpa;\n"
    "void main()\n"
    "{\n"
        "gl_FragColor = vec4(vertCol, vertOpa);\n"
    "}\n";
///
#ifdef VERTEX_SHADE // on to ! the fun stuff ;)
///
// solid color + normal array ]- vertex shader
const GLchar* v1 =
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "uniform vec3 color;\n"
    "uniform float ambient;\n"
    "uniform float saturation;\n"
    "uniform float opacity;\n"
    "uniform vec3 lightpos;\n"
    "attribute vec4 position;\n"
    "attribute vec3 normal;\n"
    "varying vec4 fragcolor;\n"
    "void main()\n"
    "{\n"
        "vec4 vertPos4 = modelview * position;\n"
        "vec3 vertNorm = normalize(vec3(modelview * vec4(normal, 0.0)));\n"
        "vec3 lightDir = normalize(lightpos - (vertPos4.xyz / vertPos4.w));\n"
        "fragcolor = vec4((color*ambient) + (color * min(max(dot(lightDir, vertNorm), 0.0), saturation)), opacity);\n"
        "gl_Position = projection * vertPos4;\n"
    "}\n";
// color array + normal array ]- vertex shader
const GLchar* v2 =
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "uniform float ambient;\n"
    "uniform float saturation;\n"
    "uniform float opacity;\n"
    "uniform vec3 lightpos;\n"
    "attribute vec4 position;\n"
    "attribute vec3 normal;\n"
    "attribute vec3 color;\n"
    "varying vec4 fragcolor;\n"
    "void main()\n"
    "{\n"
        "vec4 vertPos4 = modelview * position;\n"
        "vec3 vertNorm = normalize(vec3(modelview * vec4(normal, 0.0)));\n"
        "vec3 lightDir = normalize(lightpos - (vertPos4.xyz / vertPos4.w));\n"
        "fragcolor = vec4((color*ambient) + (color * min(max(dot(lightDir, vertNorm), 0.0), saturation)), opacity);\n"
        "gl_Position = projection * vertPos4;\n"
    "}\n";
const GLchar* f1 =  // fragment shader
    "#version 100\n"
    "precision highp float;\n"
    "varying vec4 fragcolor;\n"
    "void main()\n"
    "{\n"
        "gl_FragColor = fragcolor;\n"
    "}\n";
///
#else /////////////////////////////////////// PIXEL SHADED BELOW ///////////////////////////////////////
///
// solid color + normal array ]- vertex shader
const GLchar* v1 =
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "uniform vec3 color;\n"
    "uniform float ambient;\n"
    "uniform float saturate;\n"
    "uniform float opacity;\n"
    "uniform vec3 lightpos;\n"
    "attribute vec4 position;\n"
    "attribute vec3 normal;\n"
    "varying vec3 vertPos;\n"
    "varying vec3 vertNorm;\n"
    "varying vec3 vertCol;\n"
    "varying float vertAmb;\n"
    "varying float vertSat;\n"
    "varying float vertOpa;\n"
    "varying vec3 vlightPos;\n"
    "void main()\n"
    "{\n"
        "vec4 vertPos4 = modelview * position;\n"
        "vertPos = vertPos4.xyz / vertPos4.w;\n"
        "vertNorm = vec3(modelview * vec4(normal, 0.0));\n"
        "vertCol = color;\n"
        "vertAmb = ambient;\n"
        "vertSat = saturate;\n"
        "vertOpa = opacity;\n"
        "vlightPos = lightpos;\n"
        "gl_Position = projection * vertPos4;\n"
    "}\n";
// color array + normal array ]- vertex shader
const GLchar* v2 =
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "uniform float ambient;\n"
    "uniform float saturate;\n"
    "uniform float opacity;\n"
    "uniform vec3 lightpos;\n"
    "attribute vec4 position;\n"
    "attribute vec3 normal;\n"
    "attribute vec3 color;\n"
    "varying vec3 vertPos;\n"
    "varying vec3 vertNorm;\n"
    "varying vec3 vertCol;\n"
    "varying float vertAmb;\n"
    "varying float vertSat;\n"
    "varying float vertOpa;\n"
    "varying vec3 vlightPos;\n"
    "void main()\n"
    "{\n"
        "vec4 vertPos4 = modelview * position;\n"
        "vertPos = vertPos4.xyz / vertPos4.w;\n"
        "vertNorm = vec3(modelview * vec4(normal, 0.0));\n"
        "vertCol = color;\n"
        "vertAmb = ambient;\n"
        "vertSat = saturate;\n"
        "vertOpa = opacity;\n"
        "vlightPos = lightpos;\n"
        "gl_Position = projection * vertPos4;\n"
    "}\n";
const GLchar* f1 =  // fragment shader
    "#version 100\n"
    "precision highp float;\n"
    "varying vec3 vertPos;\n"
    "varying vec3 vertNorm;\n"
    "varying vec3 vertCol;\n"
    "varying float vertAmb;\n"
    "varying float vertSat;\n"
    "varying float vertOpa;\n"
    "varying vec3 vlightPos;\n"
    "void main()\n"
    "{\n"
        "vec3 lightDir = normalize(vlightPos - vertPos);\n"
        "float lambertian = min(max(dot(lightDir, normalize(vertNorm)), 0.0), vertSat);\n"
        "gl_FragColor = vec4((vertCol*vertAmb) + (vertCol*lambertian), vertOpa);\n"
    "}\n";

#endif
/// <><><> ///
GLuint shdFullbrightSolid;
GLint  shdFullbrightSolid_position;
GLint  shdFullbrightSolid_projection;
GLint  shdFullbrightSolid_modelview;
GLint  shdFullbrightSolid_color;
GLint  shdFullbrightSolid_opacity;
GLint  shdFullbrightSolid_lightness;
GLuint shdFullbright;
GLint  shdFullbright_position;
GLint  shdFullbright_projection;
GLint  shdFullbright_modelview;
GLint  shdFullbright_color;
GLint  shdFullbright_opacity;
GLint  shdFullbright_lightness;
GLuint shdLambertSolid;
GLint  shdLambertSolid_position;
GLint  shdLambertSolid_projection;
GLint  shdLambertSolid_modelview;
GLint  shdLambertSolid_lightpos;
GLint  shdLambertSolid_color;
GLint  shdLambertSolid_normal;
GLint  shdLambertSolid_ambient;
GLint  shdLambertSolid_saturate;
GLint  shdLambertSolid_opacity;
GLuint shdLambert;
GLint  shdLambert_position;
GLint  shdLambert_projection;
GLint  shdLambert_modelview;
GLint  shdLambert_lightpos;
GLint  shdLambert_color;
GLint  shdLambert_normal;
GLint  shdLambert_ambient;
GLint  shdLambert_saturate;
GLint  shdLambert_opacity;
/// <><><> ///
GLuint debugShader(GLuint shader_program)
{
    GLint linked;
    glGetProgramiv(shader_program, GL_LINK_STATUS, &linked);
    if(linked == GL_FALSE) 
    {
        GLint infoLen = 0;
        glGetProgramiv(shader_program, GL_INFO_LOG_LENGTH, &infoLen);
        if(infoLen > 1)
        {
            char* infoLog = malloc(sizeof(char) * infoLen);
            if(infoLog != NULL)
            {
                glGetProgramInfoLog(shader_program, infoLen, NULL, infoLog);
                printf("!!! error linking shader !!!\n%s\n", infoLog);            
                free(infoLog);
            }
        }
        else
        {
            printf("!!! failed to link shader with no returned debug output !!!\n");
        }
        glDeleteProgram(shader_program);
        return linked;
    }
    return linked;
}
/// <><><> ///
void makeFullbrightSolid()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v0, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f0, NULL);
    glCompileShader(fragmentShader);

    shdFullbrightSolid = glCreateProgram();
        glAttachShader(shdFullbrightSolid, vertexShader);
        glAttachShader(shdFullbrightSolid, fragmentShader);
    glLinkProgram(shdFullbrightSolid);

    if(debugShader(shdFullbrightSolid) == GL_FALSE){return;}

    shdFullbrightSolid_position   = glGetAttribLocation(shdFullbrightSolid,  "position");
    
    shdFullbrightSolid_projection = glGetUniformLocation(shdFullbrightSolid, "projection");
    shdFullbrightSolid_modelview  = glGetUniformLocation(shdFullbrightSolid, "modelview");
    shdFullbrightSolid_color      = glGetUniformLocation(shdFullbrightSolid, "color");
    shdFullbrightSolid_opacity    = glGetUniformLocation(shdFullbrightSolid, "opacity");
    shdFullbrightSolid_lightness  = glGetUniformLocation(shdFullbrightSolid, "lightness");
}
void makeFullbright()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v01, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f01, NULL);
    glCompileShader(fragmentShader);

    shdFullbright = glCreateProgram();
        glAttachShader(shdFullbright, vertexShader);
        glAttachShader(shdFullbright, fragmentShader);
    glLinkProgram(shdFullbright);

    if(debugShader(shdFullbright) == GL_FALSE){return;}

    shdFullbright_position   = glGetAttribLocation(shdFullbright,  "position");
    shdFullbright_color      = glGetAttribLocation(shdFullbright,  "color");

    shdFullbright_projection = glGetUniformLocation(shdFullbright, "projection");
    shdFullbright_modelview  = glGetUniformLocation(shdFullbright, "modelview");
    shdFullbright_opacity    = glGetUniformLocation(shdFullbright, "opacity");
    shdFullbright_lightness  = glGetUniformLocation(shdFullbright, "lightness");
}
void makeLambertSolid()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v1, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f1, NULL);
    glCompileShader(fragmentShader);

    shdLambertSolid = glCreateProgram();
        glAttachShader(shdLambertSolid, vertexShader);
        glAttachShader(shdLambertSolid, fragmentShader);
    glLinkProgram(shdLambertSolid);

    if(debugShader(shdLambertSolid) == GL_FALSE){return;}

    shdLambertSolid_position   = glGetAttribLocation(shdLambertSolid,  "position");
    shdLambertSolid_normal     = glGetAttribLocation(shdLambertSolid,  "normal");
    
    shdLambertSolid_projection = glGetUniformLocation(shdLambertSolid, "projection");
    shdLambertSolid_modelview  = glGetUniformLocation(shdLambertSolid, "modelview");
    shdLambertSolid_lightpos   = glGetUniformLocation(shdLambertSolid, "lightpos");
    shdLambertSolid_color      = glGetUniformLocation(shdLambertSolid, "color");
    shdLambertSolid_ambient    = glGetUniformLocation(shdLambertSolid, "ambient");
    shdLambertSolid_saturate   = glGetUniformLocation(shdLambertSolid, "saturate");
    shdLambertSolid_opacity    = glGetUniformLocation(shdLambertSolid, "opacity");
}
void makeLambert()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v2, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f1, NULL);
    glCompileShader(fragmentShader);

    shdLambert = glCreateProgram();
        glAttachShader(shdLambert, vertexShader);
        glAttachShader(shdLambert, fragmentShader);
    glLinkProgram(shdLambert);

    if(debugShader(shdLambert) == GL_FALSE){return;}

    shdLambert_position   = glGetAttribLocation(shdLambert,  "position");
    shdLambert_normal     = glGetAttribLocation(shdLambert,  "normal");
    shdLambert_color      = glGetAttribLocation(shdLambert,  "color");
    
    shdLambert_projection = glGetUniformLocation(shdLambert, "projection");
    shdLambert_modelview  = glGetUniformLocation(shdLambert, "modelview");
    shdLambert_lightpos   = glGetUniformLocation(shdLambert, "lightpos");
    shdLambert_ambient    = glGetUniformLocation(shdLambert, "ambient");\
    shdLambert_saturate   = glGetUniformLocation(shdLambert, "saturate");
    shdLambert_opacity    = glGetUniformLocation(shdLambert, "opacity");
}
/// <><><> ///
void makeAllShaders()
{
    makeFullbrightSolid();
    makeFullbright();
    makeLambertSolid();
    makeLambert();
}
/// <><><> ///
void shadeFullbrightSolid(GLint* position, GLint* iprojection, GLint* imodelview, GLint* color, GLint* lightness, GLint* opacity)
{
    *position = shdFullbrightSolid_position;
    *iprojection = shdFullbrightSolid_projection;
    *imodelview = shdFullbrightSolid_modelview;
    *color = shdFullbrightSolid_color;
    *opacity = shdFullbrightSolid_opacity;
    *lightness = shdFullbrightSolid_lightness;
    glUseProgram(shdFullbrightSolid);
}
void shadeFullbright(GLint* position, GLint* iprojection, GLint* imodelview, GLint* color, GLint* lightness, GLint* opacity)
{
    *position = shdFullbright_position;
    *iprojection = shdFullbright_projection;
    *imodelview = shdFullbright_modelview;
    *color = shdFullbright_color;
    *opacity = shdFullbright_opacity;
    *lightness = shdFullbright_lightness;
    glUseProgram(shdFullbright);
}
void shadeLambertSolid(GLint* position, GLint* iprojection, GLint* imodelview, GLint* lightpos, GLint* normal, GLint* color, GLint* ambient, GLint* saturate, GLint* opacity)
{
    *position = shdLambertSolid_position;
    *iprojection = shdLambertSolid_projection;
    *imodelview = shdLambertSolid_modelview;
    *lightpos = shdLambertSolid_lightpos;
    *color = shdLambertSolid_color;
    *normal = shdLambertSolid_normal;
    *ambient = shdLambertSolid_ambient;
    *saturate = shdLambertSolid_saturate;
    *opacity = shdLambertSolid_opacity;
    glUseProgram(shdLambertSolid);
}
void shadeLambert(GLint* position, GLint* iprojection, GLint* imodelview, GLint* lightpos, GLint* normal, GLint* color, GLint* ambient, GLint* saturate, GLint* opacity)
{
    *position = shdLambert_position;
    *iprojection = shdLambert_projection;
    *imodelview = shdLambert_modelview;
    *lightpos = shdLambert_lightpos;
    *color = shdLambert_color;
    *normal = shdLambert_normal;
    *ambient = shdLambert_ambient;
    *saturate = shdLambert_saturate;
    *opacity = shdLambert_opacity;
    glUseProgram(shdLambert);
}//    <>  / / /
/// <><><> ///
/// <><> ///
/// <> ///
 //////`



/*
    James William Fletcher (github.com/mrbid)
        September 2021 - June 2024

    Portable floating-point Vec4 lib.

    (Don't rely on this, copy and paste functions from this or write your own
    this is just a support lib, relying on it too much will make you dumb.)

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any
    means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

    For more information, please refer to <https://unlicense.org>
*/

#include <math.h>   // sqrtf logf fabsf cosf sinf
#include <string.h> // memset memcpy

//

int srandfq = 74235;
static inline void srandf(const int seed){srandfq = seed;}
static inline float randf()
{
    // https://www.musicdsp.org/en/latest/Other/273-fast-float-random-numbers.html (moc.liamg@seir.kinimod)
    srandfq *= 16807;
    return (float)(srandfq & 0x7FFFFFFF) * 4.6566129e-010f;
}
static inline float randfc()
{
    // https://www.musicdsp.org/en/latest/Other/273-fast-float-random-numbers.html (moc.liamg@seir.kinimod)
    srandfq *= 16807;
    return ((float)(srandfq)) * 4.6566129e-010f;
}
static inline float fRandFloat(const float min, const float max)
{
    return min + randf() * (max-min); 
}
static inline int fRand(const float min, const float max)
{
    return (int)((min + randf() * (max-min))+0.5f); 
}

float randfn()
{
    float u = randfc();
    float v = randfc();
    float r = u * u + v * v;
    while(r == 0.f || r > 1.f)
    {
        u = randfc();
        v = randfc();
        r = u * u + v * v;
    }
    return u * sqrtf(-2.f * logf(r) / r);
}

void vRuv(vec* v)
{
    v->x = randfc();
    v->y = randfc();
    v->z = randfc();
}

void vRuvN(vec* v)
{
    v->x = randfn();
    v->y = randfn();
    v->z = randfn();
}

void vRuvBT(vec* v)
{
    // https://math.stackexchange.com/a/1586185
    // or should I have called this vRuvLR()
    // https://mathworld.wolfram.com/SpherePointPicking.html
    const float y = acosf(randfc()) - d2PI;
    const float p = x2PI * randf();
    v->x = cosf(y) * cosf(p);
    v->y = cosf(y) * sinf(p);
    v->z = sinf(y);
}

void vRuvTA(vec* v)
{
    // T.P.Davison@tees.ac.uk
    while(1)
    {
        v->x = randfc();
        v->y = randfc();
        v->z = randfc();
        const float len = vMag(*v);
        if(len <= 1.0f){return;}
    }
}

void vRuvTD(vec* v)
{
    // T.P.Davison@tees.ac.uk
    v->x = sinf((randf() * x2PI) - PI);
    v->y = cosf((randf() * x2PI) - PI);
    v->z = randfc();
}

void vCross(vec* r, const vec v1, const vec v2)
{
    r->x = (v1.y * v2.z) - (v2.y * v1.z);
    r->y = -((v1.x * v2.z) - (v2.x * v1.z));
    r->z = (v1.x * v2.y) - (v2.x * v1.y);
}

float vDot(const vec v1, const vec v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float vSum(const vec v)
{
    return v.x + v.y + v.z;
}

float vSumAbs(const vec v)
{
    return fabs(v.x) + fabs(v.y) + fabs(v.z);
}

void vInv(vec* v)
{
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;
}

void vNorm(vec* v)
{
    const float len = 1.f/sqrtf(v->x*v->x + v->y*v->y + v->z*v->z);
    v->x *= len;
    v->y *= len;
    v->z *= len;
}

float vDist(const vec v1, const vec v2)
{
    const float xm = (v1.x - v2.x);
    const float ym = (v1.y - v2.y);
    const float zm = (v1.z - v2.z);
    return sqrtf(xm*xm + ym*ym + zm*zm);
}

float vDistSq(const vec a, const vec b)
{
    const float xm = (a.x - b.x);
    const float ym = (a.y - b.y);
    const float zm = (a.z - b.z);
    return xm*xm + ym*ym + zm*zm;
}

float vDistMh(const vec a, const vec b)
{
    return (a.x - b.x) + (a.y - b.y) + (a.z - b.z);
}

float vDistLa(const vec v1, const vec v2)
{
    const float xm = fabsf(v1.x - v2.x);
    const float ym = fabsf(v1.y - v2.y);
    const float zm = fabsf(v1.z - v2.z);

    float dist = xm;
    if(ym > dist)
        dist = ym;
    if(zm > dist)
        dist = zm;

    return dist;
}

void vReflect(vec* r, const vec v, const vec n)
{
    const float angle = vDot(v, n);
    r->x = v.x - (2.f * n.x) * angle;
    r->y = v.y - (2.f * n.y) * angle;
    r->z = v.z - (2.f * n.z) * angle;
}

int vEqualTol(const vec a, const vec b, const float tol)
{
    return  a.x >= b.x - tol && a.x <= b.x + tol &&
            a.y >= b.y - tol && a.y <= b.y + tol &&
            a.z >= b.z - tol && a.z <= b.z + tol;
}

void vMin(vec* r, const vec v1, const vec v2)
{
    if(v1.x < v2.x && v1.y < v2.y && v1.z < v2.z)
    {
        r->x = v1.x;
        r->y = v1.y;
        r->z = v1.z;
    }

    r->x = v2.x;
    r->y = v2.y;
    r->z = v2.z;
}

void vMax(vec* r, const vec v1, const vec v2)
{
    if(v1.x > v2.x && v1.y > v2.y && v1.z > v2.z)
    {
        r->x = v1.x;
        r->y = v1.y;
        r->z = v1.z;
    }

    r->x = v2.x;
    r->y = v2.y;
    r->z = v2.z;
}

int vec_ftoi(float f)
{
    if(f < 0.f)
        f -= 0.5f;
    else
        f += 0.5f;
    return (int)f;
}

int vEqualInt(const vec a, const vec b)
{
    return vec_ftoi(a.x) == vec_ftoi(b.x) && vec_ftoi(a.y) == vec_ftoi(b.y) && vec_ftoi(a.z) == vec_ftoi(b.z);
}

float vMod(const vec v)
{
    return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

float vMag(const vec v)
{
    return v.x*v.x + v.y*v.y + v.z*v.z;
}

void vCopy(vec* r, const vec v)
{
    memcpy(r, &v, sizeof(vec));
}

void vDir(vec* r, const vec v1, const vec v2)
{
    vSub(r, v2, v1);
    vNorm(r);
}

void vRotX(vec* v, const float radians)
{
    v->y = v->y * cosf(radians) + v->z * sinf(radians);
    v->z = v->y * sinf(radians) - v->z * cosf(radians);
}

void vRotY(vec* v, const float radians)
{
    v->x = v->z * sinf(radians) - v->x * cosf(radians);
    v->z = v->z * cosf(radians) + v->x * sinf(radians);
}

void vRotZ(vec* v, const float radians)
{
    v->x = v->x * cosf(radians) + v->y * sinf(radians);
    v->y = v->x * sinf(radians) - v->y * cosf(radians);
}

void vAdd(vec* r, const vec v1, const vec v2)
{
    r->x = v1.x + v2.x;
    r->y = v1.y + v2.y;
    r->z = v1.z + v2.z;
}

void vSub(vec* r, const vec v1, const vec v2)
{
    r->x = v1.x - v2.x;
    r->y = v1.y - v2.y;
    r->z = v1.z - v2.z;
}

void vDiv(vec* r, const vec numerator, const vec denominator)
{
    r->x = numerator.x / denominator.x;
    r->y = numerator.y / denominator.y;
    r->z = numerator.z / denominator.z;
}

void vMul(vec* r, const vec v1, const vec v2)
{
    r->x = v1.x * v2.x;
    r->y = v1.y * v2.y;
    r->z = v1.z * v2.z;
}

void vAddS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x + v2;
    r->y = v1.y + v2;
    r->z = v1.z + v2;
}

void vSubS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x - v2;
    r->y = v1.y - v2;
    r->z = v1.z - v2;
}

void vDivS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x / v2;
    r->y = v1.y / v2;
    r->z = v1.z / v2;
}

void vMulS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x * v2;
    r->y = v1.y * v2;
    r->z = v1.z * v2;
}

/*
    Below is the Matrix Library
    Updated: 2022
    Credit: Aaftab Munshi, Dan Ginsburg, Dave Shreiner, James William Fletcher, Intel, Gabriel Cramer, Test_User
*/

void mIdent(mat *m)
{
    memset(m, 0x0, sizeof(mat));
    m->m[0][0] = 1.0f;
    m->m[1][1] = 1.0f;
    m->m[2][2] = 1.0f;
    m->m[3][3] = 1.0f;
}

void mCopy(mat *r, const mat *v)
{
    memcpy(r, v, sizeof(mat));
}

void mMul(mat *r, const mat *a, const mat *b)
{
    mat tmp;
    for(int i = 0; i < 4; i++)
    {
        tmp.m[i][0] =	(a->m[i][0] * b->m[0][0]) +
                        (a->m[i][1] * b->m[1][0]) +
                        (a->m[i][2] * b->m[2][0]) +
                        (a->m[i][3] * b->m[3][0]) ;

        tmp.m[i][1] =	(a->m[i][0] * b->m[0][1]) + 
                        (a->m[i][1] * b->m[1][1]) +
                        (a->m[i][2] * b->m[2][1]) +
                        (a->m[i][3] * b->m[3][1]) ;

        tmp.m[i][2] =	(a->m[i][0] * b->m[0][2]) + 
                        (a->m[i][1] * b->m[1][2]) +
                        (a->m[i][2] * b->m[2][2]) +
                        (a->m[i][3] * b->m[3][2]) ;

        tmp.m[i][3] =	(a->m[i][0] * b->m[0][3]) + 
                        (a->m[i][1] * b->m[1][3]) +
                        (a->m[i][2] * b->m[2][3]) +
                        (a->m[i][3] * b->m[3][3]) ;
    }
    memcpy(r, &tmp, sizeof(mat));
}

void mMulP(vec *r, const mat *a, const float x, const float y, const float z)
{
    r->x =  (a->m[0][0] * x) +
            (a->m[0][1] * x) +
            (a->m[0][2] * x) +
            (a->m[0][3] * x) ;

    r->y =  (a->m[1][0] * y) +
            (a->m[1][1] * y) +
            (a->m[1][2] * y) +
            (a->m[1][3] * y) ;

    r->z =  (a->m[2][0] * z) +
            (a->m[2][1] * z) +
            (a->m[2][2] * z) +
            (a->m[2][3] * z) ;
}

void mMulV(vec *r, const mat *a, const vec v)
{
    r->x =  (a->m[0][0] * v.x) +
            (a->m[0][1] * v.x) +
            (a->m[0][2] * v.x) +
            (a->m[0][3] * v.x) ;

    r->y =  (a->m[1][0] * v.y) +
            (a->m[1][1] * v.y) +
            (a->m[1][2] * v.y) +
            (a->m[1][3] * v.y) ;

    r->z =  (a->m[2][0] * v.z) +
            (a->m[2][1] * v.z) +
            (a->m[2][2] * v.z) +
            (a->m[2][3] * v.z) ;

    r->w =  (a->m[3][0] * v.w) +
            (a->m[3][1] * v.w) +
            (a->m[3][2] * v.w) +
            (a->m[3][3] * v.w) ;
}

void mScale(mat *r, const float x, const float y, const float z)
{
    r->m[0][0] *= x;
    r->m[0][1] *= x;
    r->m[0][2] *= x;
    r->m[0][3] *= x;

    r->m[1][0] *= y;
    r->m[1][1] *= y;
    r->m[1][2] *= y;
    r->m[1][3] *= y;

    r->m[2][0] *= z;
    r->m[2][1] *= z;
    r->m[2][2] *= z;
    r->m[2][3] *= z;
}
void mScale1(mat *r, const float s){mScale(r, s, s, s);}

void mTranslate(mat *r, const float x, const float y, const float z)
{
    r->m[3][0] += (r->m[0][0] * x + r->m[1][0] * y + r->m[2][0] * z);
    r->m[3][1] += (r->m[0][1] * x + r->m[1][1] * y + r->m[2][1] * z);
    r->m[3][2] += (r->m[0][2] * x + r->m[1][2] * y + r->m[2][2] * z);
    r->m[3][3] += (r->m[0][3] * x + r->m[1][3] * y + r->m[2][3] * z);
}

void mRotate(mat *r, const float radians, float x, float y, float z)
{
    // MIT: Dan Ginsburg, Budirijanto Purnomo, Dave Shreiner, Aaftab Munshi
    const float mag = 1.f/sqrtf(x * x + y * y + z * z);
    const float sinAngle = sinf(radians);
    const float cosAngle = cosf(radians);
    if(mag > 0.0f)
    {
        x *= mag;
        y *= mag;
        z *= mag;

        const float xx = x * x;
        const float yy = y * y;
        const float zz = z * z;
        const float xy = x * y;
        const float yz = y * z;
        const float zx = z * x;
        const float xs = x * sinAngle;
        const float ys = y * sinAngle;
        const float zs = z * sinAngle;
        const float oneMinusCos = 1.0f - cosAngle;

        mat rotMat;
        rotMat.m[0][0] = (oneMinusCos * xx) + cosAngle;
        rotMat.m[0][1] = (oneMinusCos * xy) - zs;
        rotMat.m[0][2] = (oneMinusCos * zx) + ys;
        rotMat.m[0][3] = 0.0F; 

        rotMat.m[1][0] = (oneMinusCos * xy) + zs;
        rotMat.m[1][1] = (oneMinusCos * yy) + cosAngle;
        rotMat.m[1][2] = (oneMinusCos * yz) - xs;
        rotMat.m[1][3] = 0.0F;

        rotMat.m[2][0] = (oneMinusCos * zx) - ys;
        rotMat.m[2][1] = (oneMinusCos * yz) + xs;
        rotMat.m[2][2] = (oneMinusCos * zz) + cosAngle;
        rotMat.m[2][3] = 0.0F; 

        rotMat.m[3][0] = 0.0F;
        rotMat.m[3][1] = 0.0F;
        rotMat.m[3][2] = 0.0F;
        rotMat.m[3][3] = 1.0F;

        mMul(r, &rotMat, r);
    }
}

void mRotX(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);
    const mat t = { c, 0.f, s, 0.f,
                    0.f, 1.f, 0.f, 0.f,
                    -s, 0.f, c, 0.f,
                    0.f, 0.f, 0.f, 1.f };
    mMul(r, &t, r);
}

void mRotY(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);
    const mat t = { 1.f, 0.f, 0.f, 0.f,
                    0.f, c, -s, 0.f,
                    0.f, s, c, 0.f,
                    0.f, 0.f, 0.f, 1.f };
    mMul(r, &t, r);
}

void mRotZ(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);
    const mat t = { c, -s, 0.f, 0.f,
                    s, c, 0.f, 0.f,
                    0.f, 0.f, 1.f, 0.f,
                    0.f, 0.f, 0.f, 1.f };
    mMul(r, &t, r);
}

void mAngleAxisRotate(mat *r, const mat view, const float xrot, const float yrot, const float zrot)
{
    // Test_User angle-axis rotation
    // https://en.wikipedia.org/wiki/Axis%E2%80%93angle_representation
    // https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
    // this is incrementing the rotation of the provided view matrix by the xrot,yrot,zrot
    vec tmp0, tmp1;

    vec vecview[3] = {
        {view.m[0][0], view.m[1][0], view.m[2][0]}, // r
        {view.m[0][1], view.m[1][1], view.m[2][1]}, // u
        {view.m[0][2], view.m[1][2], view.m[2][2]}  // f
    };

    // left/right
    vMulS(&tmp0, vecview[0], cosf(xrot));

    vCross(&tmp1, vecview[1], vecview[0]);
    vMulS(&tmp1, tmp1, sinf(xrot));

    vMulS(&vecview[0], vecview[1], vDot(vecview[1], vecview[0]) * (1.f - cosf(xrot)));

    vAdd(&vecview[0], vecview[0], tmp0);
    vAdd(&vecview[0], vecview[0], tmp1);

    // up/down
    vMulS(&tmp0, vecview[1], cosf(yrot));

    vCross(&tmp1, vecview[0], vecview[1]);
    vMulS(&tmp1, tmp1, sinf(yrot));

    vMulS(&vecview[1], vecview[0], vDot(vecview[0], vecview[1]) * (1.f - cosf(yrot)));

    vAdd(&vecview[1], vecview[1], tmp0);
    vAdd(&vecview[1], vecview[1], tmp1);

    vCross(&vecview[2], vecview[0], vecview[1]);
    vCross(&vecview[1], vecview[2], vecview[0]);

    // roll
    vMulS(&tmp0, vecview[0], cosf(zrot));

    vCross(&tmp1, vecview[2], vecview[0]);
    vMulS(&tmp1, tmp1, sinf(zrot));

    vMulS(&vecview[0], vecview[2], vDot(vecview[2], vecview[0]) * (1.f - cosf(zrot)));

    vAdd(&vecview[0], vecview[0], tmp0);
    vAdd(&vecview[0], vecview[0], tmp1);

    vCross(&vecview[1], vecview[2], vecview[0]);

    vNorm(&vecview[0]);
    vNorm(&vecview[1]);
    vNorm(&vecview[2]);

    *r = (mat){
        vecview[0].x, vecview[1].x, vecview[2].x, 0.f,
        vecview[0].y, vecview[1].y, vecview[2].y, 0.f,
        vecview[0].z, vecview[1].z, vecview[2].z, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

void mFrustum(mat *r, const float left, const float right, const float bottom, const float top, const float nearZ, const float farZ)
{
    // MIT: Dan Ginsburg, Budirijanto Purnomo, Dave Shreiner, Aaftab Munshi
    const float dX = right - left;
    const float dY = top - bottom;
    const float dZ = farZ - nearZ;
    const float rdX = 1.f/dX;
    const float rdY = 1.f/dY;
    const float rdZ = 1.f/dZ;
    mat frust;

    if(nearZ <= 0.0f || farZ <= 0.0f || dX <= 0.0f || dY <= 0.0f || dZ <= 0.0f)
        return;

    frust.m[0][0] = 2.0f * nearZ * rdX;
    frust.m[0][1] = frust.m[0][2] = frust.m[0][3] = 0.0f;

    frust.m[1][1] = 2.0f * nearZ * rdY;
    frust.m[1][0] = frust.m[1][2] = frust.m[1][3] = 0.0f;

    frust.m[2][0] = (right + left) * rdX;
    frust.m[2][1] = (top + bottom) * rdY;
    frust.m[2][2] = -(nearZ + farZ) * rdZ;
    frust.m[2][3] = -1.0f;

    frust.m[3][2] = -2.0f * nearZ * farZ * rdZ;
    frust.m[3][0] = frust.m[3][1] = frust.m[3][3] = 0.0f;

    mMul(r, &frust, r);
}

void mPerspective(mat *r, const float fovy, const float aspect, const float nearZ, const float farZ)
{
    float frustumW, frustumH;
    frustumH = tanf(fovy * 0.00872664625f) * nearZ;
    //frustumH = tanf ( fovy / 360.0f * PI ) * nearZ;
    frustumW = frustumH * aspect;
    mFrustum(r, -frustumW, frustumW, -frustumH, frustumH, nearZ, farZ);
}

void mOrtho(mat *r, const float left, const float right, const float bottom, const float top, const float nearZ, const float farZ)
{
    const float dX = right - left;
    const float dY = top - bottom;
    const float dZ = farZ - nearZ;
    const float rdX = 1.f/dX;
    const float rdY = 1.f/dY;
    const float rdZ = 1.f/dZ;
    mat ortho;

    if(dX == 0.0f || dY == 0.0f || dZ == 0.0f)
        return;

    mIdent(&ortho);
    ortho.m[0][0] = 2.0f * rdX;
    ortho.m[3][0] = -(right + left) * rdX;
    ortho.m[1][1] = 2.0f * rdY;
    ortho.m[3][1] = -(top + bottom) * rdY;
    ortho.m[2][2] = -2.0f * rdZ;
    ortho.m[3][2] = -(nearZ + farZ) * rdZ;

    mMul(r, &ortho, r);
}

void mLookAt(mat *r, const vec origin, const vec unit_dir)
{
    static const vec up = (vec){0.f, 0.f, 1.f};

    vec dirn;
    dirn.x = unit_dir.x;
    dirn.y = unit_dir.y;
    dirn.z = unit_dir.z;

    vec c;
    vCross(&c, up, dirn);
    vNorm(&c);

    vec rup;
    vCross(&rup, dirn, c);

    r->m[0][0] = c.x;
    r->m[0][1] = c.y;
    r->m[0][2] = c.z;

    r->m[1][0] = rup.x;
    r->m[1][1] = rup.y;
    r->m[1][2] = rup.z;

    r->m[2][0] = dirn.x;
    r->m[2][1] = dirn.y;
    r->m[2][2] = dirn.z;

    r->m[3][0] = origin.x;
    r->m[3][1] = origin.y;
    r->m[3][2] = origin.z;
}

void mInvert(float *dst, const float *mat)
{
    // original source: ftp://download.intel.com/design/PentiumIII/sml/24504301.pdf
    // mirrored: https://github.com/esAux/esAux-Menger/raw/main/SIMD%20Matrix%20Inverse.pdf

    // Cramer Invert
    float tmp[12]; /* temp array for pairs */
    float src[16]; /* array of transpose source matrix */
    float det; /* determinant */

    /* transpose matrix */
    for(int i = 0; i < 4; i++)
    {
        src[i] = mat[i*4];
        src[i + 4] = mat[i*4 + 1];
        src[i + 8] = mat[i*4 + 2];
        src[i + 12] = mat[i*4 + 3];
    }

    /* calculate pairs for first 8 elements (cofactors) */
    tmp[0] = src[10] * src[15];
    tmp[1] = src[11] * src[14];
    tmp[2] = src[9] * src[15];
    tmp[3] = src[11] * src[13];
    tmp[4] = src[9] * src[14];
    tmp[5] = src[10] * src[13];
    tmp[6] = src[8] * src[15];
    tmp[7] = src[11] * src[12];
    tmp[8] = src[8] * src[14];
    tmp[9] = src[10] * src[12];
    tmp[10] = src[8] * src[13];
    tmp[11] = src[9] * src[12];

    /* calculate first 8 elements (cofactors) */
    dst[0] = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
    dst[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
    dst[1] = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
    dst[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
    dst[2] = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
    dst[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
    dst[3] = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
    dst[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
    dst[4] = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
    dst[4] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
    dst[5] = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
    dst[5] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
    dst[6] = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
    dst[6] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
    dst[7] = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
    dst[7] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];

    /* calculate pairs for second 8 elements (cofactors) */
    tmp[0] = src[2]*src[7];
    tmp[1] = src[3]*src[6];
    tmp[2] = src[1]*src[7];
    tmp[3] = src[3]*src[5];
    tmp[4] = src[1]*src[6];
    tmp[5] = src[2]*src[5];
    tmp[6] = src[0]*src[7];
    tmp[7] = src[3]*src[4];
    tmp[8] = src[0]*src[6];
    tmp[9] = src[2]*src[4];
    tmp[10] = src[0]*src[5];
    tmp[11] = src[1]*src[4];

    /* calculate second 8 elements (cofactors) */
    dst[8] = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
    dst[8] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
    dst[9] = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
    dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
    dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
    dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
    dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
    dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
    dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
    dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
    dst[13] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
    dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
    dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
    dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
    dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
    dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];

    /* calculate determinant */
    det = src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];

    /* calculate matrix inverse */
    det = 1.0f/det;
    for(int j = 0; j < 16; j++){dst[j] *= det;}
}

void mTranspose(mat *r, const mat *m)
{
    r->m[0][0] = m->m[0][0];
    r->m[1][0] = m->m[0][1];
    r->m[2][0] = m->m[0][2];
    r->m[3][0] = m->m[0][3];

    r->m[0][1] = m->m[1][0];
    r->m[1][1] = m->m[1][1];
    r->m[2][1] = m->m[1][2];
    r->m[3][1] = m->m[1][3];

    r->m[0][2] = m->m[2][0];
    r->m[1][2] = m->m[2][1];
    r->m[2][2] = m->m[2][2];
    r->m[3][2] = m->m[2][3];

    r->m[0][3] = m->m[3][0];
    r->m[1][3] = m->m[3][1];
    r->m[2][3] = m->m[3][2];
    r->m[3][3] = m->m[3][3];
}

//

void mSetViewDir(mat *r, const vec dir_norm)
{
    static const vec up_norm = (vec){0.f, 0.f, 1.f};

    vec c;
    vCross(&c, up_norm, dir_norm);
    vNorm(&c);

    vec rup;
    vCross(&rup, dir_norm, c);

    r->m[0][0] = -c.x;
    r->m[1][0] = -c.y;
    r->m[2][0] = -c.z;

    r->m[0][1] = -rup.x;
    r->m[1][1] = -rup.y;
    r->m[2][1] = -rup.z;

    r->m[0][2] = -dir_norm.x;
    r->m[1][2] = -dir_norm.y;
    r->m[2][2] = -dir_norm.z;
}

void mGetViewDir(vec *r, const mat matrix)
{
    mGetViewZ(r, matrix);
}

void mGetViewX(vec *r, const mat matrix)
{
    r->x = -matrix.m[0][0];
    r->y = -matrix.m[1][0];
    r->z = -matrix.m[2][0];
}

void mGetViewY(vec *r, const mat matrix)
{
    r->x = -matrix.m[0][1];
    r->y = -matrix.m[1][1];
    r->z = -matrix.m[2][1];
}

void mGetViewZ(vec *r, const mat matrix)
{
    r->x = -matrix.m[0][2];
    r->y = -matrix.m[1][2];
    r->z = -matrix.m[2][2];
}

//

void mSetDir(mat *r, const vec dir_norm)
{
    static const vec up_norm = (vec){0.f, 0.f, 1.f};

    vec c;
    vCross(&c, up_norm, dir_norm);
    vNorm(&c);

    vec rup;
    vCross(&rup, dir_norm, c);

    r->m[0][0] = c.x;
    r->m[0][1] = c.y;
    r->m[0][2] = c.z;

    r->m[2][0] = rup.x;
    r->m[2][1] = rup.y;
    r->m[2][2] = rup.z;

    r->m[1][0] = -dir_norm.x;
    r->m[1][1] = -dir_norm.y;
    r->m[1][2] = -dir_norm.z;
}

void mGetDirX(vec *r, const mat matrix)
{
    r->x = matrix.m[0][0];
    r->y = matrix.m[0][1];
    r->z = matrix.m[0][2];
}

void mGetDirY(vec *r, const mat matrix)
{
    r->x = matrix.m[1][0];
    r->y = matrix.m[1][1];
    r->z = matrix.m[1][2];
}

void mGetDirZ(vec *r, const mat matrix)
{
    r->x = matrix.m[2][0];
    r->y = matrix.m[2][1];
    r->z = matrix.m[2][2];
}

void mGetPos(vec *r, const mat matrix)
{
    r->x = matrix.m[3][0];
    r->y = matrix.m[3][1];
    r->z = matrix.m[3][2];
}

void mSetPos(mat *r, const vec pos)
{
    r->m[3][0] = pos.x;
    r->m[3][1] = pos.y;
    r->m[3][2] = pos.z;
}

void mDump(const mat matrix)
{
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[0][0], matrix.m[0][1], matrix.m[0][2], matrix.m[0][3]);
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[1][0], matrix.m[1][1], matrix.m[1][2], matrix.m[1][3]);
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[2][0], matrix.m[2][1], matrix.m[2][2], matrix.m[2][3]);
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[3][0], matrix.m[3][1], matrix.m[3][2], matrix.m[3][3]);
    printf("---\n");
}

#endif