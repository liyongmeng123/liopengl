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
#include "stb_image.h"
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


float vertices[] = {
    //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
};
unsigned int indices[] = { // 注意索引从0开始!
    0, 1, 3, // 第一个三角形
    1, 2, 3  // 第二个三角形
};
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
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定到顶点缓冲对象
//    /*
//
//     参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
//     参数2：数组的大小
//     参数3：数组的地址
//     参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变
//     **/
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
//    glEnableVertexAttribArray(2);
//    glBindVertexArray(0);
//
//      Shader ourShader("/Users/OpenGL跨平台学习/OpenGL-03/OpenGL-01/shader1.vs","/Users/OpenGL跨平台学习/OpenGL-03/OpenGL-01/shader1.fs");
//    //纹理生成
//    unsigned int texture;
//    glGenTextures(1,&texture);
//    glBindTexture(GL_TEXTURE_2D,texture);
//    //添加纹理过滤纹理环绕
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//    //生成纹理
//    //这个函数首先接受一个图像文件的位置作为输入。接下来它需要三个int作为它的第二、第三和第四个参数，stb_image.h将会用图像的宽度、高度和颜色通道的个数填充这三个变量。我们之后生成纹理的时候会用到的图像的宽度和高度的。
//    int width,height,nrChannels;
//    unsigned char *data=stbi_load("/Users/OpenGL跨平台学习/OpenGL-03/OpenGL-01/container.jpg", &width, &height, &nrChannels, 0);
//    if (data) {
//        /*
//         第一个参数指定了纹理目标(Target)。设置为GL_TEXTURE_2D意味着会生成与当前绑定的纹理对象在同一个目标上的纹理（任何绑定到GL_TEXTURE_1D和GL_TEXTURE_3D的纹理不会受到影响）。
//         第二个参数为纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别。
//         第三个参数告诉OpenGL我们希望把纹理储存为何种格式。我们的图像只有RGB值，因此我们也把纹理储存为RGB值。
//         第四个和第五个参数设置最终的纹理的宽度和高度。我们之前加载图像的时候储存了它们，所以我们使用对应的变量。
//         下个参数应该总是被设为0（历史遗留的问题）。
//         第七第八个参数定义了源图的格式和数据类型。我们使用RGB值加载这个图像，并把它们储存为char(byte)数组，我们将会传入对应值。
//         最后一个参数是真正的图像数据。
//         **/
//        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
//        //多渐行纹理
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }else{
//
//        std::cout<<"创建失败了"<<std::endl;
//    }
//    stbi_image_free(data);
//
//    while (!glfwWindowShouldClose(window)) {
//
//        //颜色缓冲
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        glClearColor(1.0f,0.2f,0.2f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        ourShader.use();
//        glBindTexture(GL_TEXTURE_2D, texture);
//
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        processinput(window);
//
//
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
    unsigned int VBO,VAO,EBO;
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定到顶点缓冲对象
    /*
     
     参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
     参数2：数组的大小
     参数3：数组的地址
     参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变
     **/
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
    
    Shader ourShader("/Users/OpenGL跨平台学习/OpenGL-03/OpenGL-01/shader1.vs","/Users/OpenGL跨平台学习/OpenGL-03/OpenGL-01/shader1.fs");
    //纹理生成
    unsigned int texture;
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    //添加纹理过滤纹理环绕
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //生成纹理
    //这个函数首先接受一个图像文件的位置作为输入。接下来它需要三个int作为它的第二、第三和第四个参数，stb_image.h将会用图像的宽度、高度和颜色通道的个数填充这三个变量。我们之后生成纹理的时候会用到的图像的宽度和高度的。
    int width,height,nrChannels;
    unsigned char *data=stbi_load("/Users/OpenGL跨平台学习/OpenGL-03/OpenGL-01/container.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        /*
         第一个参数指定了纹理目标(Target)。设置为GL_TEXTURE_2D意味着会生成与当前绑定的纹理对象在同一个目标上的纹理（任何绑定到GL_TEXTURE_1D和GL_TEXTURE_3D的纹理不会受到影响）。
         第二个参数为纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别。
         第三个参数告诉OpenGL我们希望把纹理储存为何种格式。我们的图像只有RGB值，因此我们也把纹理储存为RGB值。
         第四个和第五个参数设置最终的纹理的宽度和高度。我们之前加载图像的时候储存了它们，所以我们使用对应的变量。
         下个参数应该总是被设为0（历史遗留的问题）。
         第七第八个参数定义了源图的格式和数据类型。我们使用RGB值加载这个图像，并把它们储存为char(byte)数组，我们将会传入对应值。
         最后一个参数是真正的图像数据。
         **/
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
        //多渐行纹理
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        
        std::cout<<"创建失败了"<<std::endl;
    }
    stbi_image_free(data);
    
    //纹理生成
    unsigned int texture2;
    glGenTextures(1,&texture2);
    glBindTexture(GL_TEXTURE_2D,texture2);
    //添加纹理过滤纹理环绕
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //生成纹理
    //这个函数首先接受一个图像文件的位置作为输入。接下来它需要三个int作为它的第二、第三和第四个参数，stb_image.h将会用图像的宽度、高度和颜色通道的个数填充这三个变量。我们之后生成纹理的时候会用到的图像的宽度和高度的。

    data=stbi_load("/Users/OpenGL跨平台学习/OpenGL-03/OpenGL-01/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data) {
        /*
         第一个参数指定了纹理目标(Target)。设置为GL_TEXTURE_2D意味着会生成与当前绑定的纹理对象在同一个目标上的纹理（任何绑定到GL_TEXTURE_1D和GL_TEXTURE_3D的纹理不会受到影响）。
         第二个参数为纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别。
         第三个参数告诉OpenGL我们希望把纹理储存为何种格式。我们的图像只有RGB值，因此我们也把纹理储存为RGB值。
         第四个和第五个参数设置最终的纹理的宽度和高度。我们之前加载图像的时候储存了它们，所以我们使用对应的变量。
         下个参数应该总是被设为0（历史遗留的问题）。
         第七第八个参数定义了源图的格式和数据类型。我们使用RGB值加载这个图像，并把它们储存为char(byte)数组，我们将会传入对应值。
         最后一个参数是真正的图像数据。
         **/
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
        //多渐行纹理
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        
        std::cout<<"创建失败了"<<std::endl;
    }
    stbi_image_free(data);
    
    ourShader.use();
    glUniform1i(glGetUniformLocation(ourShader.ID,"texture1"),0);
    ourShader.setInt("texture2", 1);
    
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processinput(window);
        
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        
        // render container
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    
    
    //释放资源
    glfwTerminate();
    
    return 0;
}


