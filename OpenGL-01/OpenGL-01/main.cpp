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
    while (!glfwWindowShouldClose(window)) {
        processinput(window);
        //颜色缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
        glClearColor(1.0f,0.2f,0.2f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
   
    }

    
    
    //释放资源
    glfwTerminate();
 
    return 0;
}
