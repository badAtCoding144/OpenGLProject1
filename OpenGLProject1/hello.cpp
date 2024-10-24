//#include "hello.h"
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char* fragmentShaderSource2 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(ourColor,1.0);\n"
//"}\n\0";
//
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"   ourColor = aColor;\n"
//"}\0";
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(ourColor,1.0);\n"
//"}\n\0";
//
//int main()
//{
//	glfwInit(); // Initialize the GLFW
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//set the major version 3.x
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//set the minor version x.3
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//set the library to the core profile
//    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL); //create a window, screen width, screen height, wwindow name, monitor, share resources?
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl; //print error to show no window was initialized
//        glfwTerminate();
//        return -1;
//    }
//
//	glfwMakeContextCurrent(window); //make the window the current context
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //use glad to load opengl functions
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//
//    }
//
//	glViewport(00, 0, 800, 600); //set our viewport size
//
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  //set the function for when we resize the window
//
//
//
//
//    unsigned int fragmentShader2;
//	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
//	glCompileShader(fragmentShader2);
//    int success;
//	char infoLog[512];
//
//	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
//
//    if (!success) 
//    {
//        glGetShaderInfoLog(fragmentShader2,512,NULL,infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    unsigned int vertexShader;      //create our vertex shader pointer
//	vertexShader = glCreateShader(GL_VERTEX_SHADER); //initialize the type of shader
//
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//set the shader source code, pointer to shader, number of shader strings,pointer to the shader code, NB figure out what 4th param is
//    glCompileShader(vertexShader);  //compile our shader
//
//  
//  
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//check if the shader compiled
//
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); //get the info log, shader, size of log, NB no clue, infolog variable of length 512 
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl; //print error message and info log
//    }
//
//    unsigned int fragmentShader;    //create fragment shader
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); //initialize the shader type
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL); //set shader source code, shader, number of strings, pointer to shader code, no clue  NB
//	glCompileShader(fragmentShader); //compile the shader
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//check if our shader compiled
//
//    if (!success)
//    {
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog); //get the info log, shader, size of log, NB no clue, infolog variable of length 512
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl; //print error message and info log
//    }
//
//
//    unsigned int shaderProgram,shaderProgram2;//create shader program
//	shaderProgram2 = glCreateProgram();
//    shaderProgram = glCreateProgram();//initialize shader program
//
//
//    glAttachShader(shaderProgram2, vertexShader);
//	glAttachShader(shaderProgram2, fragmentShader2);
//	glLinkProgram(shaderProgram2);
//	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
//
//    if (!success) {
//		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl; //print error message and info log
//    }
//
//	glDeleteShader(fragmentShader2);
//
//    glAttachShader(shaderProgram, vertexShader);    //attach the vertex shader
//	glAttachShader(shaderProgram, fragmentShader);  //attach our fragment shader
//
//	glLinkProgram(shaderProgram);   //link the shader program
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success); //check if we succeed in linking shader program
//    if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog); //get the info log, shader, size of log, NB no clue, infolog variable of length 512
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl; //print error message and info log
//    }
//
//    glDeleteShader(vertexShader);//delete the shaders to save memory
//    glDeleteShader(fragmentShader);
//
//    //float vertices[] = {
//    //     0.5f,  0.5f, 0.0f,  // top right
//    //     0.5f, -0.5f, 0.0f,  // bottom right
//    //    -0.5f, -0.5f, 0.0f,  // bottom left
//    //    -0.5f,  0.5f, 0.0f   // top left 
//    //};
//    //unsigned int indices[] = {  // note that we start from 0!
//    //0, 1, 3,   // first triangle
//    //1, 2, 3    // second triangle
//    //};
//
//    //float vertices[] = {
//    //    // first triangle
//    //     0.5f,  0.5f, 0.0f,  // top right
//    //     0.5f, -0.5f, 0.0f,  // bottom right
//    //    -0.5f,  0.5f, 0.0f,  // top left 
//    //    // second triangle
//    //     0.5f, -0.5f, 0.0f,  // bottom right
//    //    -0.5f, -0.5f, 0.0f,  // bottom left
//    //    -0.5f,  0.5f, 0.0f   // top left
//    //};
//    float firstTriangle[] = {
//        -0.9f, -0.5f, 0.0f,  // left 
//        -0.0f, -0.5f, 0.0f,  // right
//        -0.45f, 0.5f, 0.0f,  // top 
//    };
//    float secondTriangle[] = {
//        0.0f, -0.5f, 0.0f,  // left
//        0.9f, -0.5f, 0.0f,  // right
//        0.45f, 0.5f, 0.0f   // top 
//    };
//    //DEPRECATEDDDDD
//    float vertices[] = {
//        // positions         // colors
//         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
//        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
//    };
//
//	unsigned int VAO[2], VBO[2], EBO; //create our vertex array object, vertex buffer object, element buffer object
//    
//	//glGenBuffers(1, &EBO); //element buffer object
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //give element buffer object a type GL_ELEMENT_ARRAY_BUFFER
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);    //give the element buffer object the data, type of data, size of data, data, type of draw
//	
//    glGenVertexArrays(1, &VAO[1]);
//    glGenBuffers(1, &VBO[1]);
//    glBindVertexArray(VAO[1]);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); //tell opengl how to interpret the vertex data, location of vertex attribute, number of components, type of data, normalize, stride, offset
//    glEnableVertexAttribArray(0); //enable the vertex attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); //tell opengl how to interpret the vertex data, location of vertex attribute, number of components, type of data, normalize, stride, offset
//	glEnableVertexAttribArray(1); //enable the vertex attribute
//
//
//	glGenVertexArrays(1, &VAO[0]); //generate our vertex array object
//	glGenBuffers(1, &VBO[0]); //generate our vertex buffer object
//	glBindVertexArray(VAO[0]); //bind our vertex array object
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]); //give the vertex buffer object a type GL_ARRAY_BUFFER
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //give the vertex buffer object/ GL_ARRAY_BUFFER the data, type of data, size of data, data, type of draw
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); //tell opengl how to interpret the vertex data, location of vertex attribute, number of components, type of data, normalize, stride, offset
//	glEnableVertexAttribArray(0); //enable the vertex attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); //tell opengl how to interpret the vertex data, location of vertex attribute, number of components, type of data, normalize, stride, offset
//	glEnableVertexAttribArray(1); //enable the vertex attribute
//
//    //glBindBuffer(GL_ARRAY_BUFFER, 0);
//    //                                          OPTIONAL
//    //glBindVertexArray(0);
//
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        processInput(window);
//
//    
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//      
//        glUseProgram(shaderProgram);
//
//
//
//
//
//        float timeValue = glfwGetTime();
//        float greenValue = sin(timeValue) / 2.0f + 0.5f;
//        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//
//        glBindVertexArray(VAO[0]);
//        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//
//
//
//
//		glUseProgram(shaderProgram2);
//         timeValue = glfwGetTime();
//         greenValue = sin(timeValue) / 2.0f + 0.5f;
//         vertexColorLocation = glGetUniformLocation(shaderProgram2, "ourColor");
//        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		glBindVertexArray(VAO[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//     
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(2, VAO);
//    glDeleteBuffers(2, VBO);
//    glDeleteProgram(shaderProgram);
//
//
//    glfwTerminate();
//    return 0;
//}
//
//
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}