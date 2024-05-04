# OpenGL Bunny Shading

## Theory

Make sure you read through this first. I had to print it out to go through it all.

{% content-ref url="./" %}
[.](./)
{% endcontent-ref %}

Our task:

* [ ] Finish the block "else if" in `functions.h` around lines 130-146.
* [ ] Implement the equation that supposedly adds up the color values for its final product.

$$
color(v) = C_rC_l max(\vec{l} \cdot \vec{n}, 0)  + C_rC_a + C_l C_p \cdot max(\vec{r} \vec{v}, 0)
$$

.

## **Assignment Summary**

You are tasked with creating a realistic 3D rendering of a bunny object using different illumination models to simulate various material appearances. Key components of the assignment include:

* **Understanding Illumination Models:** Familiarize yourself with the diffuse, ambient, and Phong illumination models and how they influence light and material interaction.
* **Shading Implementation:** Apply flat shading, where each triangle on the bunny object has a consistent color. Compute colors based on the chosen illumination models
* **Material Simulation:** Create different material effects (plaster, china, gold) by modifying the parameters of the illumination models, particularly the Phong parameters.

**Goals**

1. **Data Structure Proficiency:**
   * Refine your `data.h` file to ensure correct cross-product calculations, which are essential for determining surface normals.
   * Accurately compute view, light, and normal vectors for correct lighting representation.
2. **Illumination Model Implementation:**
   * Implement the ambient illumination model in `functions.h`. Pay attention to its simple behavior as a constant light contribution.
   * In `functions.h`, precisely implement the diffuse illumination model, ensuring it correctly considers the angle between the surface normal and light direction.
   * Carefully implement the Phong illumination model in `functions.h`, as it's the most complex. Ensure it accurately simulates specular highlights.
3. **Visual Output and Control:**
   * Successfully implement keyboard controls:
     * "0": Display the bunny with no shading.
     * "1": Display with diffuse and ambient terms (plaster-like look).
     * "2": Display with all three illumination terms (simulating materials like china or metal).
     * "M" or "m": Display only the mesh lines.

## Functions & Configurations May 1

Met with Rachit & got this far. Didn't work on my machine...

<details>

<summary>functions.h</summary>

```cpp
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

inline double to_int(std::string const& str) {
    std::istringstream ss(str);
    
    int d;
    ss >> d;
    
    /* eat up trailing whitespace if there was a double read, and ensure
     * there is no character left. the eof bit is set in the case that
     * `std::ws` tried to read beyond the stream. */
    if(!(ss && (ss >> std::ws).eof()))
        exit(1);
    
    return d;
}

inline float to_float(std::string const& str) {
    std::istringstream ss(str);
    
    float f;
    ss >> f;
    
    /* eat up trailing whitespace if there was a double read, and ensure
     * there is no character left. the eof bit is set in the case that
     * `std::ws` tried to read beyond the stream. */
    if(!(ss && (ss >> std::ws).eof()))
        exit(1);
    
    return f;
}


inline char* to_char(string s)
{
    char *a=new char[s.size()+1];
    a[s.size()]=0;
    memcpy(a,s.c_str(),s.size());
    return a;
}


void transformTriangles()
{
    /*Initialize the rotation matrix*/
    Mat Rx, Ry, Rz;
    Mat T;
    
    /*Initially set all the matrix to */
    Rx.eye();
    Ry.eye();
    Rz.eye();
    T.eye();
    
    /*rotation matrix about x axis */
    Rx.elem[1][1] = cos(theta_x);
    Rx.elem[1][2] = -sin(theta_x);
    Rx.elem[2][1] = sin(theta_x);
    Rx.elem[2][2] = cos(theta_x);
    
    
    /*rotation matrix about y axis */
    Ry.elem[0][0] = cos(theta_y);
    Ry.elem[0][2] = sin(theta_y);
    Ry.elem[2][0] = -sin(theta_y);
    Ry.elem[2][2] = cos(theta_y);
    
    /* transaltion matrix*/
    T.elem[0][3] = translate_x;
    T.elem[1][3] = translate_y;
    
    
    /*Final transformation matrix P*/
    Mat P = T * Rx * Ry;
    
    /* Go through each vertex*/
    for(int i = 0; i < vertice_list.size(); i++)
    {
        Vec cur_pt, updated_pt;
        cur_pt.elem[0] = vertice_list[i].x;
        cur_pt.elem[1] = vertice_list[i].y;
        cur_pt.elem[2] = vertice_list[i].z;
        cur_pt.elem[3] = 1.0f;
        updated_pt = P * cur_pt;
        vertice_list[i].x = updated_pt.elem[0]/updated_pt.elem[3];
        vertice_list[i].y = updated_pt.elem[1]/updated_pt.elem[3];
        vertice_list[i].z = updated_pt.elem[2]/updated_pt.elem[3];
        
        vertice_list[i].normalize();
    }
    
    /*Reset the angles and translations */
    theta_x = 0;
    theta_y = 0;
    theta_z = 0;
    translate_x = 0;
    translate_y = 0;
    translate_z = 0;
}

void trianglesShading()
    {
        if(shading_type == 0)
        {
            /*Make all the triangles the same color*/
            for(int i = 0; i < triangles_list.size(); i++) //triangle index
            {
                for(int j = 0; j < 3; j++) //vertex index
                {
                    for(int k = 0; k < 3; k++) //color channel index
                    {
                        triangles_list[i].c[j].channel[k] = bunny_color.channel[k];
                        
                    }
                }
            }
        }
        else if(shading_type == 1 || shading_type == 2)
        {
            for (int i = 0; i < triangles_list.size(); i++) {
                // Initialize triangle color with ambient color
                for (int j = 0; j < 3; j++) {
                    triangles_list[i].c[j].channel[0] = ambient_color.channel[0] * bunny_color.channel[0];
                    triangles_list[i].c[j].channel[1] = ambient_color.channel[1] * bunny_color.channel[1];
                    triangles_list[i].c[j].channel[2] = ambient_color.channel[2] * bunny_color.channel[2];
                }
                
                // Calculate diffuse illumination for the triangle
                for (int j = 0; j < 3; j++) {
                    // Retrieve the vertex indices of the triangle
                    int v0_idx = triangles_list[i].v_idx[j];
                    int v1_idx = triangles_list[i].v_idx[(j + 1) % 3];
                    int v2_idx = triangles_list[i].v_idx[(j + 2) % 3];
                    
                    // Calculate the normal vector of the triangle
                    Vertex v0 = vertice_list[v0_idx];
                    Vertex v1 = vertice_list[v1_idx];
                    Vertex v2 = vertice_list[v2_idx];
                    Vertex normal = v0.normalVector(v1, v2);
                    
                    // Calculate the dot product between the light direction and the normal vector
                    float dot_product = normal.uni_x * light.uni_x + normal.uni_y * light.uni_y + normal.uni_z * light.uni_z;
                    
                    // Ensure the dot product is clamped to [0, 1]
                    dot_product = std::max(0.0f, dot_product);
                    
                    // Scale the intensity of the diffuse illumination based on the dot product
                    float diffuse_intensity = dot_product;
                    
                    // Add the diffuse contribution to the color of the current vertex
                    triangles_list[i].c[j].channel[0] += diffuse_intensity * bunny_color.channel[0];
                    triangles_list[i].c[j].channel[1] += diffuse_intensity * bunny_color.channel[1];
                    triangles_list[i].c[j].channel[2] += diffuse_intensity * bunny_color.channel[2];
                }
            }// Your implementation should be here
            //shading_type == 1: only diffuse + ambient
            //shading_type == 2: diffuse + ambient + phong
        }
    }

void initialize()
{
    light.x = 1;  // tood: try zero
    light.y = 1;
    light.z = 5;
    light.c.channel[0] = 0.7;
    light.c.channel[1] = 0.7;
    light.c.channel[2] = 0.7;
    
    light.normalize();
    
    //light color Cl
    light.c.channel[0] = 0.9;
    light.c.channel[1] = 0.9;
    light.c.channel[2] = 0.9;
    
    //Ambient Ca
    ambient_color.channel[0] = 0.2;
    ambient_color.channel[1] = 0.2;
    ambient_color.channel[2] = 0.2;
    
    //Object surface color Cr
    bunny_color.channel[0] = 0.8;
    bunny_color.channel[1] = 0.8;
    bunny_color.channel[2] = 0.8;
    
    //Specular Color Cs
    phong_color.channel[0] = 0.8;
    phong_color.channel[1] = 0.8;
    phong_color.channel[2] = 0.8;
    
    view_pos.x = 0.0f;
    view_pos.y = 0.0f;
    view_pos.z = 5.0f;
}

void loadObjFiles(char *filename, vector<Vertex> &vertice_list, vector<Triangle> &triangles_list )
{
    ifstream myfile (filename);
    string line;
    string valueX, valueY, valueZ, v;
    string idx0, idx1, idx2, f;
    
    int n = 0;
    while(!myfile.eof())
    {
        getline (myfile, line);
        if (line[0] == 'v')
        {
            std::istringstream iss( line );
            iss >> v >> valueX>> valueY>> valueZ;
            Vertex v;
            v.x = (GLfloat)to_float(valueX);
            v.y = (GLfloat)to_float(valueY);
            v.z = (GLfloat)to_float(valueZ);
            // v.normalize();
            
            
            /* By default, the initial colors for all the vertices are grey */
            for(int c = 0; c < 3; c++)
            {
                v.c.channel[c] = bunny_color.channel[c];
            }
            vertice_list.push_back(v);
        }
        if( line[0] == 'f')
        {
            std::istringstream iss( line );
            iss >> f >> idx0 >> idx1 >> idx2;
            int i0 = to_int(idx0) - 1;
            int i1 = to_int(idx1) - 1;
            int i2 = to_int(idx2) - 1;
            
            Triangle triangle;
            triangle.v_idx[0] = i0;
            triangle.v_idx[1] = i1;
            triangle.v_idx[2] = i2;
            
            triangle.c[0] = vertice_list[i0].c;
            triangle.c[1] = vertice_list[i1].c;
            triangle.c[2] = vertice_list[i2].c;
            triangles_list.push_back(triangle);
        }
    }
    
    
    /* Check what is the centroid value */
    float x = .0f;
    float y = .0f;
    float z = .0f;
    for(int i = 0; i < vertice_list.size(); i++)
    {
        x += vertice_list[i].x;
        y += vertice_list[i].y;
        z += vertice_list[i].z;
    }
    x /= (float)vertice_list.size();
    y /= (float)vertice_list.size();
    z /= (float)vertice_list.size();
}
```

</details>

<details>

<summary>data.h?</summary>

```cpp
#include <iostream>
#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#define PHONG 100


struct Color{
    GLfloat channel[3];
};

struct Vertex{
    float x;
    float y;
    float z;
    
    Color c;
    
    float uni_x; //store the normalized value of this vector (for cos_theta and cross product use
    float uni_y;
    float uni_z;
    
    
    
    // Computes the normal vector
    Vertex normalVector(const Vertex& v1, const Vertex& v2) const{
        Vertex normal;
        Vertex edge1 = v1 - *this;
        Vertex edge2 = v2 - *this;
        normal = edge1.cross(edge2);
        normal.normalize();
        return normal;
    }
    
    /*Normalize the vertex's vector to make the length equal to 1 and store it in uni_x,y,z*/
    void normalize()
    {
        float length = sqrt(x * x + y * y + z * z);
        if (length !=0){
            uni_x = x / length;
            uni_y = y / length;
            uni_z = z / length;
        }
    }
    
    /*Reload dot product */
    // You have to implement it here
    const float operator * (const Vertex& right) const
    {
        float result = 0.0f;
        return result;
    }
    
    
    /*Reload - operator*/
    const Vertex operator - (const Vertex& right) const
    {
        Vertex result;
        result.x = x - right.x;
        result.y = y - right.y;
        result.z = z - right.z;
        return result;
    }
   
    
    /*Reload + operator*/
    const Vertex operator + (const Vertex& right) const
    {
        Vertex result;
        result.x = x + right.x;
        result.y = y + right.y;
        result.z = z + right.z;
        return result;
    }
    
    /*Reload * operator to times a number*/
    const Vertex operator * (const float right) const
    {
        Vertex result;
        result.x = x * right;
        result.y = y * right;
        result.z = z * right;
        
        return result;
    }
    
    /*For normalized vector dot product use*/
    float normDot(const Vertex& right) const
    {
        float result = uni_x * right.uni_x + uni_y * right.uni_y + uni_z * right.uni_z;
        return result;
    }
    
    /*The cross-product */
    Vertex cross(const Vertex& right)
    {
        Vertex result;
      
        return result;
    }
};

struct Triangle{
    int v_idx[3];
    Color c[3];
};

/* Here you need to implement some operations for 4-by-1 vector*/
struct Vec{
    float elem[4];
    
    
};

/* Here you need to implement a 4-by-4 matrix */
struct Mat{
    float elem[4][4];
    
    
    /*Normalize the matrix*/
    void eye()
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(i == j)
                    elem[i][j] = 1.0f;
                else
                    elem[i][j] = 0.0f;
            }
        }
    }
    
    /*This function is to reload the multipliation operator for matrix products*/
    const Mat operator * (const Mat& right) const
    {
        Mat result;
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                result.elem[i][j] = 0;
                for(int k = 0; k < 4; k++)
                {
                    result.elem[i][j] += elem[i][k] * right.elem[k][j];
                }
            }
        }
        
        return result;
    }
    
    /*This function is to reload the multipliation operator for matrix times a 4-by-1 vector*/
    const Vec operator * (const Vec& vec) const
    {
        Vec result;
        
        for(int i = 0; i < 4; i++)
        {
            
            result.elem[i] = 0;
            for(int k = 0; k < 4; k++)
            {
                result.elem[i] += elem[i][k] * vec.elem[k];
            }
            
        }
        
        return result;
    }
    
    void printMat()
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                printf("%.5f, ", elem[i][j]);
            }
            printf("\n");
        }
    }
};


vector<Vertex> vertice_list;
vector<Triangle> triangles_list;

/*Define the light and colors*/
Vertex light;
Color ambient_color;
Color bunny_color;
Color phong_color;

/*Define the viewpoint*/
Vertex view_pos; 

/*Parameter control the rotation*/
float theta_x = .0f;
float theta_y = .0f;
float theta_z = .0f;

/*Parameter control the translation*/
float translate_x = .0f;
float translate_y = .0f;
float translate_z = .0f;


int mesh_only = 0; //control whether a mesh triangle or plane is drawn
int shading_type = 0; //0 - no shading; 1 - ambient + diffuse shading; 2 - ambient + diffuse + phong; 3 - static shading


/*For the mouse control use*/
/* Define data */
int mouse_down = 0; //Represent the left mouse key is clicked down
int change_mode = 0; //0 means rotation; 1 means translation
int current_x = 0, current_y = 0;

```

</details>

<details>

<summary><code>DataManager.h</code> .</summary>

```cpp
#ifndef DATAMANAGER_H
#define DATAMANAGER_H
using namespace std;

// Remove Vertex from DataManager.h: 
// Delete the Vertex struct from DataManager.h. 
// You don't need it there since it's primarily for loading data.
// struct Vertex {
//    float x, y, z;
//    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
// };

struct Triangle {
    int v1_idx, v2_idx, v3_idx;
    Triangle(int p1, int p2, int p3) : v1_idx(p1), v2_idx(p2), v3_idx(p3) {}
};

class DataManager {
public:
    DataManager();
    ~DataManager();

    void loadFromFile(const std::string& filename);
    std::vector<Vertex> getVertices();
    std::vector<Triangle> getTriangles();

private:
    std::vector<Vertex> vertices;
    std::vector<Triangle> triangles;
};

#endif // DATAMANAGER_H

```

</details>

<details>

<summary>DataManager.cpp</summary>

```cpp
#include <fstream>
#include <sstream>
#include <iostream>

DataManager::DataManager() {}

DataManager::~DataManager() {}

void DataManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        std::istringstream iss(line);
        char type;
        iss >> type;
        if (type == 'v') {
            float x, y, z;
            iss >> x >> y >> z;
            vertices.push_back(Vertex(x, y, z));
        } else if (type == 'f') {
            int v1, v2, v3;
            iss >> v1 >> v2 >> v3;
            triangles.push_back(Triangle(v1, v2, v3));
        }
    }
    file.close();
}

std::vector<Vertex> DataManager::getVertices() {
    return vertices;
}

std::vector<Triangle> DataManager::getTriangles() {
    return triangles;
}

```

</details>

<details>

<summary><code>callbackFunctions.h</code> is?</summary>

```cpp
void onKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(1);
            
            break;
        case 'm':
            mesh_only = (mesh_only == 1)?0:1;
            glutPostRedisplay();
            break;
        case '1':
            shading_type = 1;
            glutPostRedisplay();
            break;
        case '0':
            shading_type = 0;
            glutPostRedisplay();
            break;
        case '2':
            shading_type = 2;
            glutPostRedisplay();
            break;
            
        case '3':
            shading_type = 3;
            glutPostRedisplay();
            break;
            
        default:
            break;
    }
}

void onMouse(int button, int state, int x, int y)
{
    
    GLint specialKey = glutGetModifiers();
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                mouse_down = 1;
                current_x = x;
                current_y = y;
                if (specialKey == GLUT_ACTIVE_SHIFT)
                {
                    change_mode = 1;
                }
                else
                {
                    change_mode = 0;
                }
            }
            else if (state == GLUT_UP)
            {
                mouse_down = 0;
            }
            break;
            
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                
                break;
            
        default:
            break;
            
    }
    
}

void onMouseMotion(int x, int y)
{
    if (mouse_down == 1)
    {
        if (change_mode == 0)
        {
            theta_y += static_cast<float>(x - current_x) / 100.f;
            theta_x += static_cast<float>(y - current_y) / 100.f;
        }
        else{
            translate_x += static_cast<float>(x - current_x) / 1000.f;
            translate_y += static_cast<float>(-y + current_y) / 1000.f;
        }
        
        current_x = x;
        current_y = y;
    }
    
    glutPostRedisplay();
}


/*Render all the triangles */
void renderAllTriangles()
{
    for(int i = 0; i < triangles_list.size(); i++)
    {
        if(mesh_only)
        {
            glBegin(GL_LINE_LOOP);
        }
        else
        {
            glBegin(GL_TRIANGLES);
        }
        
        int pt_0 = triangles_list[i].v_idx[0];
        int pt_1 = triangles_list[i].v_idx[1];
        int pt_2 = triangles_list[i].v_idx[2];
        
        //point 1
        glColor3f(triangles_list[i].c[0].channel[0], triangles_list[i].c[0].channel[1], triangles_list[i].c[0].channel[2]);
        glVertex3f(vertice_list[pt_0].x, vertice_list[pt_0].y, vertice_list[pt_0].z);
        
        
        //point 2
        glColor3f(triangles_list[i].c[1].channel[0], triangles_list[i].c[1].channel[1], triangles_list[i].c[1].channel[2]);
        glVertex3f(vertice_list[pt_1].x, vertice_list[pt_1].y, vertice_list[pt_1].z);
        
        //point 3
        glColor3f(triangles_list[i].c[2].channel[0], triangles_list[i].c[2].channel[1], triangles_list[i].c[2].channel[2]);
        glVertex3f(vertice_list[pt_2].x, vertice_list[pt_2].y, vertice_list[pt_2].z);
        
        
        glEnd();
    }
}

/*Define the 3D objects that want to show*/
void onDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, .0); //RGB
    //    glBegin(GL_LINES);
    //    glVertex3f(-5, 0.18, 1.0); //starting point
    //    glVertex3f(5, 0.1, 1.0); //ending point
    //    glEnd();
    
    glColor3f(0.0, 1.0, 0.0);
    
    
    
    /* Transform the points */
    if(mouse_down == 1) //only when the mouse is dragging, this function is called
        transformTriangles();
    
    /* Do the shading on Traingles */
    trianglesShading();
    
    /* Render all the triangles */
    renderAllTriangles();
        
    glFlush(); //clear the memory
}
```

</details>

<details>

<summary>main.cpp Refs your obj file</summary>

* [ ] Put correct file path on line 37.

{% code lineNumbers="true" %}
```cpp
#include <iostream>
#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

using namespace std;

#include "data.h"
#include "functions.h"
#include "callbackFunctions.h"
//#include "DataManager.h"

int main(int argc,  char * argv[]) {
    
    /*Initialize glut stuff*/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Bunny");
    loadObjFiles("bunny_high.obj", vertice_list, triangles_list);
    initialize();
    

    
    /*Initialize gl stuff*/
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.4, 0.4, -0.4 * .48 / .64, 0.4 * .48 / .64, 2, 10); //parallel projection
    gluLookAt( 0, 0, 5, 0, 0.2, 0, 0, 1, 0);
    
    
    /*Register GL stuff with the GLUT*/
    glutDisplayFunc(onDisplay);
    glutMouseFunc(onMouse);
    glutMotionFunc(onMouseMotion);
    glutKeyboardFunc(onKeyboard);
    
    /*Initialize the loop*/
    glutMainLoop();
    
    return 0;
}

```
{% endcode %}



</details>



## UML Diagrams

### Global Variables

<figure><img src="../../../.gitbook/assets/image (743).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (742).png" alt=""><figcaption></figcaption></figure>

### Important Structures

<figure><img src="../../../.gitbook/assets/image (739).png" alt=""><figcaption></figcaption></figure>

<div>

<figure><img src="../../../.gitbook/assets/image (745).png" alt=""><figcaption></figcaption></figure>

 

<figure><img src="../../../.gitbook/assets/image (744).png" alt=""><figcaption></figcaption></figure>

 

<figure><img src="../../../.gitbook/assets/image (740).png" alt=""><figcaption></figcaption></figure>

</div>





<details>

<summary>Links for editing:</summary>

```
@startuml
class Triangle {
  +v_idx[] : int[3]
  +c[] : Color[3]
}
@enduml

@startuml
class Color {
  +channel[] : float[3] 
}
@enduml





@startuml
class Vertex {
  +x : float
  +y : float
  +z : float
  +c : Color
  +uni_x : float
  +uni_y : float
  +uni_z : float 
  +normalVector(v1: Vertex, v2: Vertex) : Vertex 
  +normalize() : void
  +* (right: Vertex) : float  
  +- (right: Vertex) : Vertex 
  ++ (right: Vertex) : Vertex 
  +* (right: float) : Vertex  
  +normDot(right: Vertex) : float 
  +cross(right: Vertex) : Vertex  
}
@enduml 

@startuml
class Material {
  +ambient : Color
  +diffuse : Color
  +specular : Color
  +shininess : float
}
@enduml

@startuml
class Mat {
  +elem[][] : float[4][4] 
  +eye() : void
  +* (right: Mat) : Mat 
  +* (vec: Vec) : Vec
} 
@enduml

@startuml
' Add variables with their types
light : Vertex
ambient_color : Color
bunny_color : Color 
phong_color : Color
view_pos : Vertex
theta_x : float
theta_y : float
theta_z : float
translate_x : float
translate_y : float
translate_z : float
mesh_only : int
shading_type : int
mouse_down: int
change_mode: int
current_x: int
current_y: int
@enduml

```

</details>

### Ambience

<figure><img src="../../../.gitbook/assets/CleanShot 2024-05-03 at 15.48.25.gif" alt=""><figcaption></figcaption></figure>

Ambience is just the background color. All we have to do is take the bunny's original color and multiply it by the bunny's. Something that confused me was the data structure used to represent this. While we have a `Color` class, we just represent this as `c` and iterate through each one of the three through `k`.&#x20;

```cpp
for (int j = 0; j < 3; j++) {
    // Ambient Contribution
    for (int k = 0; k < 3; k++) {
         triangles_list[i].c[j].channel[k] = ambient_color.channel[k] * bunny_color.channel[k];
}
```

If that's all you do in your triangels function, you'll get something that looks like the above gif.

### Diffuse

<figure><img src="../../../.gitbook/assets/CleanShot 2024-05-03 at 19.17.38.gif" alt=""><figcaption></figcaption></figure>

### Fixing Dot & Cross Products

Turns out we've got to implement these too & it's not provided in the `data` class.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-05-03 at 19.52.36@2x.png" alt=""><figcaption></figcaption></figure>

This was the "whoa!!" moment for me. Like- I did this? I made it rotate and look like a real bunny?!

<figure><img src="../../../.gitbook/assets/CleanShot 2024-05-03 at 19.54.55.gif" alt=""><figcaption></figcaption></figure>

### Phong

Phong incorporates more elements. I really had to use drastic values so I'm not sure what that's about.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-05-03 at 23.05.13.gif" alt=""><figcaption></figcaption></figure>

Setting it to ten was a bit better:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-05-03 at 23.07.21.gif" alt=""><figcaption></figcaption></figure>
