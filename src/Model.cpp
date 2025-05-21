#include <cstdlib>
#include <iostream>

#include "Model.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "freeglut.h">
#endif // GLUT Library
using std::vector;
struct V3D { float x, y, z; };
struct V2D { float x, y; };
Model::Model(std::string objFilePath)
{
    std::vector<V3D> position_vector;
    std::vector<V3D> normal_vector;
    std::vector<V2D> texture_coord;

    std::fstream obj;
    std::string input;
    std::vector<std::string> split;
    obj.open(objFilePath);
    if (obj.is_open())
    {
        while (getline(obj, input))
        {
            split = splitString(input, ' ');
            int sz = split.size();
            if (sz == 0)continue;
            if (split[0] == "v")
            {
                V3D vaux{ getFloat(split[1]) ,getFloat(split[2]) ,getFloat(split[3]) };
                position_vector.push_back(vaux);
            }
            else if (split[0] == "vt")
            {
                V2D vaux{ getFloat(split[1]) ,getFloat(split[2]) };
                texture_coord.push_back(vaux);
            }
            else if (split[0] == "vn")
            {
                V3D vaux{ getFloat(split[1]) ,getFloat(split[2]) ,getFloat(split[3]) };
                normal_vector.push_back(vaux);
            }
            else if (split[0] == "f")
            {
                std::vector<std::string> inSplit;
                for (int i = 1; i <= 3; i++)
                {
                    inSplit = splitString(split[i], '/');
                    int index = getInt(inSplit[0]);
                    if (index < 0)index = (int)position_vector.size() + index;
                    else index--;
                    position_texture_normal.push_back(position_vector[index].x);
                    position_texture_normal.push_back(position_vector[index].y);
                    position_texture_normal.push_back(position_vector[index].z);


                    int a = getInt(inSplit[1]);
                    if (a >= 0) {
                        index = getInt(inSplit[1]);
                        if (index < 0)index = (int)texture_coord.size() + index;
                        else index--;
                        position_texture_normal.push_back(texture_coord[index].x);
                        position_texture_normal.push_back(texture_coord[index].y);
                    }
                    else {//no texture
                        position_texture_normal.push_back(0);
                        position_texture_normal.push_back(0);
                    }



                    index = getInt(inSplit[2]);
                    if (index < 0)index = (int)normal_vector.size() + index;
                    else index--;
                    position_texture_normal.push_back(normal_vector[index].x);
                    position_texture_normal.push_back(normal_vector[index].y);
                    position_texture_normal.push_back(normal_vector[index].z);
                }
            }
        }
    }
    sz = position_texture_normal.size() / 8;
}

void Model::Draw()
{
    int index;
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < sz; i++)
    {
        index = 8 * i;
        glNormal3f(position_texture_normal[index + 5], position_texture_normal[index + 6], position_texture_normal[index + 7]);
        glTexCoord2f(position_texture_normal[index + 3], position_texture_normal[index + 4]);
        glVertex3f(position_texture_normal[index], position_texture_normal[index + 1], position_texture_normal[index + 2]);
    }
    glEnd();
    glPopMatrix();
}

Model::~Model()
{
    position_texture_normal.clear();
}

std::vector<std::string> Model::splitString(std::string str, char delimiter)
{
    std::vector<std::string> split;
    int sz = str.length(), lastIdx = -1, i;

    for (i = 0; i < sz; i++)
    {
        if (str[i] == delimiter)
        {
            split.push_back(str.substr(lastIdx + 1, i - lastIdx - 1));
            lastIdx = i;
        }
    }
    if (i == sz && lastIdx != i - 1) split.push_back(str.substr(lastIdx + 1));

    return split;
}

float Model::getFloat(std::string input)
{
    std::istringstream ssinput(input);
    float check;

    ssinput >> check;
    return check;
}

int Model::getInt(std::string input)
{
    std::istringstream ssinput(input);
    int check;

    ssinput >> check;
    return check;
}