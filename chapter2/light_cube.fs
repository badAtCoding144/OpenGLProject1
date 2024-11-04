

#version 330 core


struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform Light light;  



uniform vec3 lightColor;

out vec4 FragColor;

void main()
{
    FragColor = vec4(lightColor,1.0); // set all 4 vector values to 1.0
}

