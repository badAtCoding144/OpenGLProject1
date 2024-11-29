//#include <glad/glad.h>
//#include <glfw/glfw3.h>
//
//#ifndef stb_image_implementation
//#define stb_image_implementation
//#endif
//
//#include "stb_image.h"
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include "shader.h"
//#include "camera.h"
//#include "model.h"
//
//#include <iostream>
//
//void framebuffer_size_callback(glfwwindow* window, int width, int height);
//void mouse_callback(glfwwindow* window, double xpos, double ypos);
//void scroll_callback(glfwwindow* window, double xoffset, double yoffset);
//void processinput(glfwwindow* window);
//unsigned int loadtexture(const char* path);
//unsigned int loadcubemap(vector<std::string> faces);
//
//// settings
//const unsigned int scr_width = 800;
//const unsigned int scr_height = 600;
//
//// camera
//camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastx = (float)scr_width / 2.0;
//float lasty = (float)scr_height / 2.0;
//bool firstmouse = true;
//
//// timing
//float deltatime = 0.0f;
//float lastframe = 0.0f;
//
//int main()
//{
//
//    
//    glfwinit();
//    glfwwindowhint(glfw_context_version_major, 3);
//    glfwwindowhint(glfw_context_version_minor, 3);
//    glfwwindowhint(glfw_opengl_profile, glfw_opengl_core_profile);
//
//
//
//    // glfw window creation
//    glfwwindow* window = glfwcreatewindow(scr_width, scr_height, "learnopengl", null, null);
//    if (window == null)
//    {
//        std::cout << "failed to create glfw window" << std::endl;
//        glfwterminate();
//        return -1;
//    }
//    glfwmakecontextcurrent(window);
//    glfwsetframebuffersizecallback(window, framebuffer_size_callback);
//    glfwsetcursorposcallback(window, mouse_callback);
//    glfwsetscrollcallback(window, scroll_callback);
//
//    // tell glfw to capture our mouse
//    glfwsetinputmode(window, glfw_cursor, glfw_cursor_disabled);
//
//    // glad: load all opengl function pointers
//    if (!gladloadglloader((gladloadproc)glfwgetprocaddress))
//    {
//        std::cout << "failed to initialize glad" << std::endl;
//        return -1;
//    }
//
//    // configure global opengl state
//    glenable(gl_depth_test);
//
//
//    // build and compile shaders
//
//    shader shader("depthtest.vs", "depthtest.fs");
//    shader normalshader("normalvis.vs", "normalvis.fs", "geometryshader.gs");
//	shader skyboxshader("skybox.vs", "skybox.fs");
//
//
//    float cubevertices[] = {
//        // positions          // normals
//        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//
//        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//    };
//
//    float skyboxvertices[] = {
//        // positions          
//        -1.0f,  1.0f, -1.0f,
//        -1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//         1.0f,  1.0f, -1.0f,
//        -1.0f,  1.0f, -1.0f,
//
//        -1.0f, -1.0f,  1.0f,
//        -1.0f, -1.0f, -1.0f,
//        -1.0f,  1.0f, -1.0f,
//        -1.0f,  1.0f, -1.0f,
//        -1.0f,  1.0f,  1.0f,
//        -1.0f, -1.0f,  1.0f,
//
//         1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//
//        -1.0f, -1.0f,  1.0f,
//        -1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f, -1.0f,  1.0f,
//        -1.0f, -1.0f,  1.0f,
//
//        -1.0f,  1.0f, -1.0f,
//         1.0f,  1.0f, -1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//        -1.0f,  1.0f,  1.0f,
//        -1.0f,  1.0f, -1.0f,
//
//        -1.0f, -1.0f, -1.0f,
//        -1.0f, -1.0f,  1.0f,
//         1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//        -1.0f, -1.0f,  1.0f,
//         1.0f, -1.0f,  1.0f
//    };
//
//    // cube vao
//    unsigned int cubevao, cubevbo;
//    glgenvertexarrays(1, &cubevao);
//    glgenbuffers(1, &cubevbo);
//    glbindvertexarray(cubevao);
//    glbindbuffer(gl_array_buffer, cubevbo);
//    glbufferdata(gl_array_buffer, sizeof(cubevertices), &cubevertices, gl_static_draw);
//    glenablevertexattribarray(0);
//    glvertexattribpointer(0, 3, gl_float, gl_false, 6 * sizeof(float), (void*)0);
//    glenablevertexattribarray(1);
//    glvertexattribpointer(1, 3, gl_float, gl_false, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    // skybox vao
//    unsigned int skyboxvao, skyboxvbo;
//    glgenvertexarrays(1, &skyboxvao);
//    glgenbuffers(1, &skyboxvbo);
//    glbindvertexarray(skyboxvao);
//    glbindbuffer(gl_array_buffer, skyboxvbo);
//    glbufferdata(gl_array_buffer, sizeof(skyboxvertices), &skyboxvertices, gl_static_draw);
//    glenablevertexattribarray(0);
//    glvertexattribpointer(0, 3, gl_float, gl_false, 3 * sizeof(float), (void*)0);
//
//    vector<std::string> faces
//    {
//        "skybox/right.jpg",
//        "skybox/left.jpg",
//        "skybox/top.jpg",
//        "skybox/bottom.jpg",
//        "skybox/front.jpg",
//        "skybox/back.jpg",
//    };
//    unsigned int cubemaptexture = loadcubemap(faces);
//
//    stbi_set_flip_vertically_on_load(true);
//    model ourmodel("resources/objects/backpack/backpack.obj");
//    stbi_set_flip_vertically_on_load(false);
// //   // load textures
//	//const char* path = "resources/textures/container.jpg";
//	//const char* path2 = "resources/textures/metal.png";
// //   unsigned int cubetexture = loadtexture(path);
// //   unsigned int floortexture = loadtexture(path2);
//
//
//    skyboxshader.use();
//    skyboxshader.setint("skybox", 0);
//
//   // glpolygonmode(gl_front_and_back, gl_line);
//
//    // render loop
//
//    while (!glfwwindowshouldclose(window))
//    {
//        // per-frame time logic
//        float currentframe = static_cast<float>(glfwgettime());
//        deltatime = currentframe - lastframe;
//        lastframe = currentframe;
//
//		normalshader.setfloat("time", glfwgettime());
//        // input
//        processinput(window);
//
//        // render
//        glclearcolor(0.1f, 0.1f, 0.1f, 1.0f);
//        glclear(gl_color_buffer_bit | gl_depth_buffer_bit);
//
//        // configure transformation matrices
//        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)scr_width / (float)scr_height, 1.0f, 100.0f);
//        glm::mat4 view = camera.getviewmatrix();;
//        glm::mat4 model = glm::mat4(1.0f);
//        shader.use();
//        shader.setmat4("projection", projection);
//        shader.setmat4("view", view);
//        shader.setmat4("model", model);
//
//        // draw model as usual
//        ourmodel.draw(shader);
//
//        // then draw model with normal visualizing geometry shader
//        normalshader.use();
//        normalshader.setmat4("projection", projection);
//        normalshader.setmat4("view", view);
//        normalshader.setmat4("model", model);
//
//        ourmodel.draw(normalshader);
//
//        // draw skybox as last
//        gldepthfunc(gl_lequal);  // change depth function so depth test passes when values are equal to depth buffer's content
//        skyboxshader.use();
//        view = glm::mat4(glm::mat3(camera.getviewmatrix())); // remove translation from the view matrix
//        skyboxshader.setmat4("view", view);
//        skyboxshader.setmat4("projection", projection);
//        // skybox cube
//        glbindvertexarray(skyboxvao);
//        glactivetexture(gl_texture0);
//        glbindtexture(gl_texture_cube_map, cubemaptexture);
//        gldrawarrays(gl_triangles, 0, 36);
//        glbindvertexarray(0);
//        gldepthfunc(gl_less); // set depth function back to default
//
//        // glfw: swap buffers and poll io events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwswapbuffers(window);
//        glfwpollevents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    gldeletevertexarrays(1, &cubevao);
//    gldeletevertexarrays(1, &skyboxvao);
//    gldeletebuffers(1, &cubevbo);
//    gldeletebuffers(1, &skyboxvbo);
//
//    glfwterminate();
//    return 0;
//}
//
//// process all input: query glfw whether relevant keys are pressed/released this frame and react accordingly
//void processinput(glfwwindow* window)
//{
//    if (glfwgetkey(window, glfw_key_escape) == glfw_press)
//        glfwsetwindowshouldclose(window, true);
//
//    if (glfwgetkey(window, glfw_key_w) == glfw_press)
//        camera.processkeyboard(forward, deltatime);
//    if (glfwgetkey(window, glfw_key_s) == glfw_press)
//        camera.processkeyboard(backward, deltatime);
//    if (glfwgetkey(window, glfw_key_a) == glfw_press)
//        camera.processkeyboard(left, deltatime);
//    if (glfwgetkey(window, glfw_key_d) == glfw_press)
//        camera.processkeyboard(right, deltatime);
//}
//
//// glfw: whenever the window size changed (by os or user resize) this callback function executes
//void framebuffer_size_callback(glfwwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glviewport(0, 0, width, height);
//}
//
//// glfw: whenever the mouse moves, this callback is called
//void mouse_callback(glfwwindow* window, double xposin, double yposin)
//{
//    float xpos = static_cast<float>(xposin);
//    float ypos = static_cast<float>(yposin);
//
//    if (firstmouse)
//    {
//        lastx = xpos;
//        lasty = ypos;
//        firstmouse = false;
//    }
//
//    float xoffset = xpos - lastx;
//    float yoffset = lasty - ypos; // reversed since y-coordinates go from bottom to top
//
//    lastx = xpos;
//    lasty = ypos;
//
//    camera.processmousemovement(xoffset, yoffset);
//}
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//void scroll_callback(glfwwindow* window, double xoffset, double yoffset)
//{
//    camera.processmousescroll(static_cast<float>(yoffset));
//}
//
//// utility function for loading a 2d texture from file
//unsigned int loadtexture(char const* path)
//{
//    unsigned int textureid;
//    glgentextures(1, &textureid);
//
//    int width, height, nrcomponents;
//    unsigned char* data = stbi_load(path, &width, &height, &nrcomponents, 0);
//    if (data)
//    {
//        glenum format;
//        if (nrcomponents == 1)
//            format = gl_red;
//        else if (nrcomponents == 3)
//            format = gl_rgb;
//        else if (nrcomponents == 4)
//            format = gl_rgba;
//
//        glbindtexture(gl_texture_2d, textureid);
//        glteximage2d(gl_texture_2d, 0, format, width, height, 0, format, gl_unsigned_byte, data);
//        glgeneratemipmap(gl_texture_2d);
//
//
//        gltexparameteri(gl_texture_2d, gl_texture_wrap_s, format == gl_rgba ? gl_clamp_to_edge : gl_repeat); // for this tutorial: use gl_clamp_to_edge to prevent semi-transparent borders. due to interpolation it takes texels from next repeat 
//        gltexparameteri(gl_texture_2d, gl_texture_wrap_t, format == gl_rgba ? gl_clamp_to_edge : gl_repeat);
//        gltexparameteri(gl_texture_2d, gl_texture_min_filter, gl_linear_mipmap_linear);
//        gltexparameteri(gl_texture_2d, gl_texture_mag_filter, gl_linear);
//
//        stbi_image_free(data);
//    }
//    else
//    {
//        std::cout << "texture failed to load at path: " << path << std::endl;
//        stbi_image_free(data);
//    }
//
//    return textureid;
//}
//
//unsigned int loadcubemap(vector<std::string> faces)
//{
//    unsigned int textureid;
//    glgentextures(1, &textureid);
//    glbindtexture(gl_texture_cube_map, textureid);
//
//    int width, height, nrchannels;
//    for (unsigned int i = 0; i < faces.size(); i++)
//    {
//        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrchannels, 0);
//        if (data)
//        {
//            glteximage2d(gl_texture_cube_map_positive_x + i,
//                0, gl_rgb, width, height, 0, gl_rgb, gl_unsigned_byte, data
//            );
//            stbi_image_free(data);
//        }
//        else
//        {
//            std::cout << "cubemap tex failed to load at path: " << faces[i] << std::endl;
//            stbi_image_free(data);
//        }
//    }
//    gltexparameteri(gl_texture_cube_map, gl_texture_min_filter, gl_linear);
//    gltexparameteri(gl_texture_cube_map, gl_texture_mag_filter, gl_linear);
//    gltexparameteri(gl_texture_cube_map, gl_texture_wrap_s, gl_clamp_to_edge);
//    gltexparameteri(gl_texture_cube_map, gl_texture_wrap_t, gl_clamp_to_edge);
//    gltexparameteri(gl_texture_cube_map, gl_texture_wrap_r, gl_clamp_to_edge);
//
//    return textureid;
//}
//
//
