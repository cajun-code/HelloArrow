//
//  RenderingEngine1.cpp
//  HelloArrow
//
//  Created by Allan Davis on 1/22/13.
//  Copyright (c) 2013 Cajun Code. All rights reserved.
//

#include "RenderingEngine1.h"

IRenderingEngine* CreateRenderer1(){
    return new RenderingEngine1();
}

struct Vertex{
    float Position[2];
    float Color[4];
};

const Vertex Vertices[] = {
    {{-0.5,-0.866}, {1,1,0.5f,1}},
    {{0.5,-0.866}, {1,1,0.5f,1}},
    {{0,1}, {1,1,0.5f,1}},
    {{-0.5,-0.866}, {0.5f,0.5f, 0.5f}},
    {{0.5,-0.866}, {0.5f,0.5f, 0.5f}},
    {{0,-0.4f}, {0.5f,0.5f, 0.5f}},
};

RenderingEngine1::RenderingEngine1(){
    
    glGenRenderbuffersOES(1, &renderBuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, renderBuffer);
    
}

void RenderingEngine1::initialize(int width, int height){
    glGenFramebuffersOES(1, &frameBuffer);
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, frameBuffer);
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES,
                                 GL_COLOR_ATTACHMENT0_OES,
                                 GL_RENDERBUFFER_OES,
                                 renderBuffer);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    const float maxX = 2;
    const float maxY = 3;
    glOrthof(-maxX, +maxX, -maxY, +maxY, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void RenderingEngine1::render() const{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(2, GL_FLOAT, sizeof(Vertex), &Vertices[0].Position[0]);
    glColorPointer(4, GL_FLOAT, sizeof(Vertex), &Vertices[0].Color[0]);
    
    GLsizei vertexCount = sizeof(Vertices) / sizeof(Vertex);
    
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
}