//
//  main.cpp
//  OpenGL-01
//
//  Created by 李勇猛 on 2018/3/4.
//  Copyright © 2018年 李勇猛. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "shader_s.h"
//


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //渲染尺寸大小
    glViewport(0,0,width,height);
    
    }

//按下esc停止操作
void processinput(GLFWwindow *window){
    
    if (glfwGetKey(window, GLFW_KEY_ESCAPE)==GLFW_PRESS) {
       
        glfwSetWindowShouldClose(window, true);
    }
}
//普通三角形
//float vertices[] ={
//
//    -0.5f,0.5f,0.0f,
//    0.5f,0.5f,0.0f,
//    -0.5f,-0.5f,0.0f
//};
//int main(int argc, const char * argv[]) {
//    //创建glfw
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    //窗口
//    GLFWwindow *window =glfwCreateWindow(800, 600, "11", NULL, NULL);
//    if (window ==NULL) {
//        std::cout<<"窗口没出现"<<std::endl;
//        return -1;
//    }
//    //创建上下文
//    glfwMakeContextCurrent(window);
//    //创建glad
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//        std::cout<<"初始化glad失败"<<std::endl;
//        return -1;
//    }
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    //定点缓冲对象
//    unsigned int VBO,VAO;
//    glGenBuffers(1,&VBO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定到顶点缓冲对象
//    glGenVertexArrays(1,&VAO);
//    glBindVertexArray(VAO);
//    /*
//
//     参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
//     参数2：数组的大小
//     参数3：数组的地址
//     参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变
//     **/
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
//    glEnableVertexAttribArray(0);
//    glBindVertexArray(0);
//
//      Shader ourShader("/Users/OpenGL跨平台学习/OpenGL-01的副本/OpenGL-01/shader.vs","/Users/OpenGL跨平台学习/OpenGL-01的副本/OpenGL-01/shader.fs");
//
//
//    while (!glfwWindowShouldClose(window)) {
//        ourShader.use();
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES,0,3);
//        processinput(window);
//
//        //颜色缓冲
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        glClearColor(1.0f,0.2f,0.2f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//    }
//
//
//
//    //释放资源
//    glfwTerminate();
//
//    return 0;
//}

//四边形
//float vertices[] = {
//    // 第一个三角形
//    0.5f, 0.5f, 0.0f,   // 右上角
//    0.5f, -0.5f, 0.0f,  // 右下角
//    -0.5f, 0.5f, 0.0f,  // 左上角
//    // 第二个三角形
//    0.5f, -0.5f, 0.0f,  // 右下角
//    -0.5f, -0.5f, 0.0f, // 左下角
//    -0.5f, 0.5f, 0.0f   // 左上角
//};
//int main(int argc, const char * argv[]) {
//    //创建glfw
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    //窗口
//    GLFWwindow *window =glfwCreateWindow(800, 600, "11", NULL, NULL);
//    if (window ==NULL) {
//        std::cout<<"窗口没出现"<<std::endl;
//        return -1;
//    }
//    //创建上下文
//    glfwMakeContextCurrent(window);
//    //创建glad
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//        std::cout<<"初始化glad失败"<<std::endl;
//        return -1;
//    }
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    //定点缓冲对象
//    unsigned int VBO,VAO;
//    glGenBuffers(1,&VBO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定到顶点缓冲对象
//    glGenVertexArrays(1,&VAO);
//    glBindVertexArray(VAO);
//    /*
//
//     参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
//     参数2：数组的大小
//     参数3：数组的地址
//     参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变
//     **/
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
//    glEnableVertexAttribArray(0);
//    glBindVertexArray(0);
//
//    Shader ourShader("/Users/OpenGL跨平台学习/OpenGL-01的副本/OpenGL-01/shader.vs","/Users/OpenGL跨平台学习/OpenGL-01的副本/OpenGL-01/shader.fs");
//
//
//    while (!glfwWindowShouldClose(window)) {
//        ourShader.use();
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES,0,6);
//        processinput(window);
//
//        //颜色缓冲
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        glClearColor(1.0f,0.2f,0.2f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//    }
//
//
//
//    //释放资源
//    glfwTerminate();
//
//    return 0;
//}

////顶点索引的三角形
//float vertices[] = {
//    0.5f, 0.5f, 0.0f,   // 右上角
//    0.5f, -0.5f, 0.0f,  // 右下角
//    -0.5f, -0.5f, 0.0f, // 左下角
//    -0.5f, 0.5f, 0.0f   // 左上角
//};
//
//unsigned int indices[] = { // 注意索引从0开始!
//    0, 1, 3, // 第一个三角形
//    1, 2, 3  // 第二个三角形
//};
//
//int main(int argc, const char * argv[]) {
//    //创建glfw
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    //窗口
//    GLFWwindow *window =glfwCreateWindow(800, 600, "11", NULL, NULL);
//    if (window ==NULL) {
//        std::cout<<"窗口没出现"<<std::endl;
//        return -1;
//    }
//    //创建上下文
//    glfwMakeContextCurrent(window);
//    //创建glad
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//        std::cout<<"初始化glad失败"<<std::endl;
//        return -1;
//    }
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    //定点缓冲对象
//    unsigned int VBO,VAO,EBO;
//    glGenBuffers(1,&VBO);
//    glGenBuffers(1,&EBO);
//
//    glGenVertexArrays(1,&VAO);
//
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定到顶点缓冲对象
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//    /*
//
//     参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
//     参数2：数组的大小
//     参数3：数组的地址
//     参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变
//     **/
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
//
//    glEnableVertexAttribArray(0);
//    glBindVertexArray(0);
//
//    Shader ourShader("/Users/OpenGL跨平台学习/OpenGL-01的副本/OpenGL-01/shader.vs","/Users/OpenGL跨平台学习/OpenGL-01的副本/OpenGL-01/shader.fs");
//
//
//    while (!glfwWindowShouldClose(window)) {
//        ourShader.use();
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
//        processinput(window);
//
//        //颜色缓冲
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        glClearColor(1.0f,0.2f,0.2f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//    }
//
//
//
//    //释放资源
//    glfwTerminate();
//
//    return 0;
//}
//
//不同颜色
//float vertices[] = {
//    // positions         // colors
//    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
//    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
//    0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
//
//};
//int main(int argc, const char * argv[]) {
//    //创建glfw
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    //窗口
//    GLFWwindow *window =glfwCreateWindow(800, 600, "11", NULL, NULL);
//    if (window ==NULL) {
//        std::cout<<"窗口没出现"<<std::endl;
//        return -1;
//    }
//    //创建上下文
//    glfwMakeContextCurrent(window);
//    //创建glad
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//        std::cout<<"初始化glad失败"<<std::endl;
//        return -1;
//    }
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    //定点缓冲对象
//    unsigned int VBO,VAO;
//    glGenBuffers(1,&VBO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定到顶点缓冲对象
//    glGenVertexArrays(1,&VAO);
//    glBindVertexArray(VAO);
//    /*
//
//     参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
//     参数2：数组的大小
//     参数3：数组的地址
//     参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变
//     **/
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glBindVertexArray(0);
//
//      Shader ourShader("/Users/OpenGL跨平台学习/OpenGL-02/OpenGL-01/shader.vs","/Users/OpenGL跨平台学习/OpenGL-02/OpenGL-01/shader.fs");
//
//
//    while (!glfwWindowShouldClose(window)) {
//        ourShader.use();
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES,0,3);
//        processinput(window);
//
//        //颜色缓冲
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        glClearColor(1.0f,0.2f,0.2f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//    }
//
//
//
//    //释放资源
//    glfwTerminate();
//
//    return 0;
//}

float vertices[] ={

    -0.5f,0.5f,0.0f,
    0.5f,0.5f,0.0f,
    -0.5f,-0.5f,0.0f
};
int main(int argc, const char * argv[]) {
    //创建glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //窗口
    GLFWwindow *window =glfwCreateWindow(800, 600, "11", NULL, NULL);
    if (window ==NULL) {
        std::cout<<"窗口没出现"<<std::endl;
        return -1;
    }
    //创建上下文
    glfwMakeContextCurrent(window);
    //创建glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

        std::cout<<"初始化glad失败"<<std::endl;
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    //定点缓冲对象
    unsigned int VBO,VAO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定到顶点缓冲对象
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    /*

     参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
     参数2：数组的大小
     参数3：数组的地址
     参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变
     **/
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

      Shader ourShader("/Users/OpenGL跨平台学习/OpenGL-02/OpenGL-01/shader1.vs","/Users/OpenGL跨平台学习/OpenGL-02/OpenGL-01/shader1.fs");


    while (!glfwWindowShouldClose(window)) {
        
        //颜色缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
        glClearColor(1.0f,0.2f,0.2f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ourShader.use();
        
        float timeValue =glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(ourShader.Shader::ID, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,3);
        processinput(window);

      


    }



    //释放资源
    glfwTerminate();

    return 0;
}


